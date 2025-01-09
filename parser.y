%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include <math.h>
    #include "symbolTable.h"
    #include "quadruplet.h"
    #include "pile.h"

    //declarations 

    typedef struct {
    int baseType;      // ENTIER, FLOTTANT, STRING, etc.
    bool isArray;      // Whether it's an array
    bool isConst;      // Whether it's a constant
    int arraySize;     // Size if it's an array
    char* structName;  // Name if it's a struct
} TypeInfo;
    TableSymbole *TS;
    qTable *TQ;
    qPile *P;

    qNoeud* quad;
    Symbole* node;

    int sauvLabel;

    int qC = 0;

    extern int colnum ;
    extern int lignenum ;

    extern FILE *yyin;
    int yylex();
    void yyerror(const char *s);
    int line = 1;        // Numéro de ligne courant
    int linecol = 0;         // Numéro de colonne courant
    char *yyin_filename = NULL;
    int sauv = 0;
    int sauvline = 1;

    #define TYPE_ENTIER "ENTIER"
#define TYPE_FLOTTANT "FLOTTANT"
#define TYPE_CHAR "CHAR"
#define TYPE_STRING "STRING"
#define TYPE_BOOLEAN "BOOLEAN"

// Modified type checking function to work with your symbol table
bool areTypesCompatible(const char* type1, const char* type2) {
    if (strcmp(type1, type2) == 0) {
        return true;
    }
    
    // Allow implicit conversion from int to float
    if (strcmp(type1, TYPE_FLOTTANT) == 0 && strcmp(type2, TYPE_ENTIER) == 0) {
        return true;
    }
    
    return false;
}

// Modified function to check if an identifier is declared
bool isDeclared(const char* id) {
    Symbole* found;
    return rechercherSymbole(TS, id, &found);
}

// Function to get type of an identifier
char* getIdentifierType(const char* id) {
    Symbole* found;
    if (rechercherSymbole(TS, id, &found)) {
        return found->type;
    }
    return NULL;
}

// Function to determine if a literal is valid for a given type
bool isValidLiteralForType(const char* literal, const char* type) {
    if (strcmp(type, TYPE_ENTIER) == 0) {
        // Check if string contains only digits
        for (int i = 0; literal[i] != '\0'; i++) {
            if (!isdigit(literal[i])) return false;
        }
        return true;
    }
    else if (strcmp(type, TYPE_FLOTTANT) == 0) {
        // Check if string is a valid float
        char* endptr;
        strtof(literal, &endptr);
        return *endptr == '\0';
    }
    // Add more type checks as needed
    return false;
}
%}


%union
{
int type;
char str[255];
char charv;
int intv ; 
float flt;
bool boolean;
struct {
        char* valeur;
        char* nom;
        int type;
    } structure;
}

%token  DEBUT FIN WHILE FOR
%token  PRINT INPUT FONCTION VIDE RETURN
%token  COMMENT COMMENT_PLUS
%token  OR AND NOT
%token  IF ELSE ELIF
%token  DEB_CORPS FIN_CORPS
%token<boolean> TRUE FALSE
%token  PAR_OUV PAR_FERM
%token<charv> CARACTERE
%token<str> CHAINE
%token<intv> INT
%token<flt> FLOAT 
%token  DEB_TABLEAU FIN_TABLEAU TABLE ENREGISTREMENT POINTEUR
%token<type> CONST ENTIER FLOTTANT STRING CHAR BOOLEAN
%token<str> ID
%token INCREM DECREM PLUS DIV MOINS MULT MOD PUISS ASSIGN
%token  SEMICOLON
%token  INF INF_EGAL SUP SUPP_EGAL EQUAL NOT_EQUAL
%token  FROM
%token  TO
%token  VIRGULE 

%type<type> type
%type<structure> tableau
%type<structure> type_Struct
%type<structure> variable
%type<structure> expression
%type<structure> declaration
%type<structure> incrementation
%type<structure> assignment
%type<structure> parametreCall
%type<structure> fonction
%type<structure> parametre

%right OU
%right ET
%right NOT INCREM DECREM
%right INF INF_EGAL SUPP SUPP_EGAL EGALE PASEGALE
%right PLUS MOINS
%right MUL DIV MOD
%left  PUISS 
%right PAR_OUV DEB_TABLEAU DEB_CORPS
%right PAR_FERM FIN_TABLEAU FIN_CORPS


%start programme

%%

programme:
    {
        TS = creerTableSymbole();  
        TQ = initialiserTQ() ;
        P = initialiserP();
    }
    functions DEBUT DEB_CORPS declarations instructions FIN SEMICOLON FIN_CORPS {
        qC++;
        quad = creer_Q("fin", "", "", "", qC);
        inserer_TQ(TQ, quad); 
        afficherTableSymbole(TS); // afficher TS pour confirmer
        afficherTQ(TQ);  // afficher TQ pour confirmer
        afficherTQDansFichier(TQ, "output.txt");
        printf("\nProgramme accepte.");
    }
    ;

type:
    ENTIER {
        currentType.baseType = ENTIER;
        currentType.isArray = false;
        currentType.isConst = false;
        $$ = ENTIER;
    }
    | FLOTTANT {
        currentType.baseType = FLOTTANT;
        currentType.isArray = false;
        currentType.isConst = false;
        $$ = FLOTTANT;
    }
    | STRING {
        currentType.baseType = STRING;
        currentType.isArray = false;
        currentType.isConst = false;
        $$ = STRING;
    }
    | CHAR {
        currentType.baseType = CHAR;
        currentType.isArray = false;
        currentType.isConst = false;
        $$ = CHAR;
    }
    | BOOLEAN {
        currentType.baseType = BOOLEAN;
        currentType.isArray = false;
        currentType.isConst = false;
        $$ = BOOLEAN;
    }
    | CONST type {
        currentType.isConst = true;
        $$ = $2;
    }
    ;


tableau :
    TABLE ID DEB_TABLEAU INT FIN_TABLEAU
    ;

type_Struct : 
    ENREGISTREMENT ID DEB_CORPS declarations FIN_CORPS
    ;
valeur:
    INT
    | FLOAT
    | CARACTERE 
    | CHAINE
    | TRUE
    | FALSE
    ;
variable:
    ID DEB_TABLEAU INT FIN_TABLEAU 
    | ID DEB_TABLEAU ID FIN_TABLEAU 
    | ID POINTEUR ID
    | ID
    ;
expression:
    valeur 
    | variable
    | expression PLUS expression
    | expression MOINS expression
    | expression MULT expression
    | expression DIV expression
    | expression MOD expression
    | expression PUISS expression 
    | NOT expression 
    | PAR_OUV expression PAR_FERM
    | expression INF expression
    | expression INF_EGAL expression
    | expression SUPP expression
    | expression SUPP_EGAL expression
    | expression EQUAL expression
    | expression NOT_EQUAL expression
    | expression ET expression
    | expression OU expression
    ; 

incrementation:
    variable INCREM 
    | variable DECREM
    ;

declarations:
    /* empty */
    | declarations declaration 
    ;

declaration:
    type ID SEMICOLON {
        Symbole* found;
        if (rechercherSymbole(TS, $2, &found)) {
            semanticError("Variable already declared", line);
        }
        
        // Convert the type token to string
        char* typeStr;
        switch($1) {
            case ENTIER: typeStr = TYPE_ENTIER; break;
            case FLOTTANT: typeStr = TYPE_FLOTTANT; break;
            case CHAR: typeStr = TYPE_CHAR; break;
            case STRING: typeStr = TYPE_STRING; break;
            case BOOLEAN: typeStr = TYPE_BOOLEAN; break;
            default: typeStr = TYPE_ENTIER; // default case
        }
        
        Symbole* sym = creerSymbole(
            VARIABLE,    // category
            $2,         // name
            typeStr,    // type
            "",         // initial value
            line,       // line number
            0          // memory address
        );
        insererSymbole(TS, sym);
    }
    | tableau SEMICOLON {printf("declaration correcte syntaxiquement\n");}
    | type_Struct SEMICOLON {printf("declaration correcte syntaxiquement\n");}
    ;
functions:
    /* empty */
    | functions fonction 
    ;
fonction:
    type FONCTION ID PAR_OUV parametres PAR_FERM corps {printf("fonction correcte syntaxiquement\n");}
    | FONCTION ID PAR_OUV parametres PAR_FERM corps {printf("fonction correcte syntaxiquement\n");}
    ;

parametres:
    /* empty */
    | parametre VIRGULE parametres {printf("parametres correcte syntaxiquement\n");}
    | parametre
    ;
    
parametre:
    type ID
    | TABLE ID
    | ENREGISTREMENT ID {printf("parametre correcte syntaxiquement\n");}
    ;
instructions:
    /* empty */
    | instructions instruction 
    ;   
instruction:
    | assignment 
    | COMMENT
    | COMMENT_PLUS
    | condition
    | loop
    | read
    | write 
    | incrementation SEMICOLON
    | retourner SEMICOLON
    | call SEMICOLON
    ;
read:
    INPUT PAR_OUV ID PAR_FERM SEMICOLON {printf("read correcte syntaxiquement\n");}
    ;

write:
    PRINT PAR_OUV CHAINE VIRGULE ID PAR_FERM SEMICOLON
    |PRINT PAR_OUV ID PAR_FERM SEMICOLON
    |PRINT PAR_OUV CHAINE PAR_FERM SEMICOLON{printf("write correcte syntaxiquement\n");}
    ;

retourner:
    RETURN expression {printf("retourner correcte syntaxiquement\n");}
    ;

assignment:
    parametre ASSIGN expression SEMICOLON
    | ID ASSIGN expression SEMICOLON 
    | parametre ASSIGN call SEMICOLON
    | ID ASSIGN call SEMICOLON
    ;

condition:
    IF PAR_OUV expression PAR_FERM corps elsebloc  {printf("condition correcte syntaxiquement\n");}
    ;

loop:
    WHILE PAR_OUV expression PAR_FERM corps   {printf("condition correcte syntaxiquement\n");}
    | FOR PAR_OUV ID FROM INT TO INT PAR_FERM corps
    {
        printf("For loop recognized\n");
    }
    ;
corps :
    DEB_CORPS declarations instructions FIN_CORPS
    | instruction
    ;
elsebloc:
    /* empty */
    | ELSE corps
    | ELIF PAR_OUV expression PAR_FERM corps elsebloc
    ;


call:
    ID PAR_OUV parametresCall PAR_FERM 
    ;
 
     

parametresCall:
    /* empty */
    | parametreCall VIRGULE parametresCall
    | parametreCall
    {printf("parametres de l'appel du fonction correcte syntaxiquement\n");}
    ;
    
parametreCall:
    valeur
    | variable {printf("parametre correcte syntaxiquement\n");}
    ;

%%

void yyerror(const char *s) {
    if (sauvline == line){
        line = line -1 ;
    }
    fprintf(stderr, "File \"%s\", line %d, character %d: %s\n", 
            yyin_filename, line,sauv - linecol, s);
    exit(EXIT_FAILURE);
}


int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <nom_fichier>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    yyin_filename = argv[1];
    FILE *file = fopen(yyin_filename, "r");
    if (!file) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
    yyin = file;
    yyparse();
    fclose(yyin);

    return 0;
}

