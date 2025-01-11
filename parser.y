%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include <math.h>
    #include "symbolTable.h"
    #include "quadruplet.h"
    #include "pile.h"
    #include  <ctype.h>


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
TypeInfo currentType; 
    char currentFunction[256]; 
    bool inLoop = false; 
    int loopNestingLevel = 0;
void semanticError(const char* message, int line) { 
    fprintf(stderr, "Semantic error at line %d: %s\n", line, message); 
    exit(1);
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
%type<structure> valeur
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
    INT { 
        $$.type = ENTIER;
        char buffer[256];
        sprintf(buffer, "%d", $1);
        $$.valeur = strdup(buffer);
    }
    | FLOAT {
        $$.type = FLOTTANT;
        char buffer[256];
        sprintf(buffer, "%f", $1);
        $$.valeur = strdup(buffer);
    }
    | CARACTERE {
        $$.type = CHAR;
        char buffer[256];
        sprintf(buffer, "%c", $1);
        $$.valeur = strdup(buffer);
    }
    | CHAINE {
        $$.type = STRING;
        $$.valeur = strdup($1);
    }
    | TRUE {
        $$.type = BOOLEAN;
        $$.valeur = strdup("true");
    }
    | FALSE {
        $$.type = BOOLEAN;
        $$.valeur = strdup("false");
    }
    ;
variable:
    ID DEB_TABLEAU INT FIN_TABLEAU {
        $$.nom = $1;
        $$.type = ENTIER;  // assuming array of integers
    }
    | ID POINTEUR ID {
        $$.nom = $1;
        $$.type = ENTIER;  // modify based on your needs
    }
    | ID {
        $$.nom = strdup($1);
        Symbole* found;
        if (rechercherSymbole(TS, $1, &found)) {
            switch(found->type[0]) {
                case 'E': $$.type = ENTIER; break;
                case 'F': $$.type = FLOTTANT; break;
                case 'S': $$.type = STRING; break;
                case 'C': $$.type = CHAR; break;
                case 'B': $$.type = BOOLEAN; break;
                default: $$.type = ENTIER;
            }
            $$.valeur = strdup(found->valeur);
            }
            else{
                semanticError("Variable non declaree", line);
            }
        }
    ;
expression:
    valeur  
    | variable
    | expression PLUS expression {
        char bff[255]; 
        Symbole* found1;
        Symbole* found2;
        
        // Initialize result structure
        $$.nom = NULL;
        $$.valeur = malloc(255);
        if ($$.valeur == NULL) {
            semanticError("Memory allocation failed", line);
        }

        // Get values for operands
        char *val1, *val2;
        val1 = $1.valeur;
        val2 = $3.valeur;            
        // Perform addition based on types
        if ($1.type == ENTIER && $3.type == ENTIER) {
            int result = atoi(val1) + atoi(val2);
            sprintf($$.valeur, "%d", result);
            $$.type = ENTIER;
        } else if ($1.type == FLOTTANT || $3.type == FLOTTANT) {
            float result = atof(val1) + atof(val2);
            sprintf($$.valeur, "%f", result);
            $$.type = FLOTTANT;
        } else if (($1.type == FLOTTANT && $3.type == ENTIER) || ($1.type == ENTIER && $3.type == FLOTTANT)) {
            float result = atof(val1) + atof(val2);
            sprintf($$.valeur, "%f", result);
            $$.type = FLOTTANT;
        } else {
            semanticError("Invalid types for addition", line);
        }

        // Generate quadruplet
        qC++;
        char resultVarName[20];
        sprintf(resultVarName, "%s%d", "R",qC);
        $$.nom=resultVarName;
        quad = creer_Q("+", 
                      $1.nom ? $1.nom : $1.valeur,
                      $3.nom ? $3.nom : $3.valeur,
                      $$.nom,
                      qC);        
        afficherQ(quad);        
        inserer_TQ(TQ, quad);

        afficherTableSymbole(TS);
        afficherTQ(TQ);
        afficherTQDansFichier(TQ, "output.txt");
    }
    | expression MOINS expression {
        char bff[255]; 
        Symbole* found1;
        Symbole* found2;
        
        // Initialize result structure
        $$.nom = NULL;
        $$.valeur = malloc(255);
        if ($$.valeur == NULL) {
            semanticError("Memory allocation failed", line);
        }

        // Get values for operands
        char *val1, *val2;
        val1 = $1.valeur;
        val2 = $3.valeur;            
        // Perform subtraction based on types
        if ($1.type == ENTIER && $3.type == ENTIER) {
            int result = atoi(val1) - atoi(val2);
            sprintf($$.valeur, "%d", result);
            $$.type = ENTIER;
        } else if ($1.type == FLOTTANT || $3.type == FLOTTANT) {
            float result = atof(val1) - atof(val2);
            sprintf($$.valeur, "%f", result);
            $$.type = FLOTTANT;
        } else if (($1.type == FLOTTANT && $3.type == ENTIER) || ($1.type == ENTIER && $3.type == FLOTTANT)) {
            float result = atof(val1) - atof(val2);
            sprintf($$.valeur, "%f", result);
            $$.type = FLOTTANT;
        } else {
            semanticError("Invalid types for subtraction", line);
        }

        // Generate quadruplet
        qC++;
        char resultVarName[20];
        sprintf(resultVarName, "%s%d", "R",qC);
        $$.nom=resultVarName;
        quad = creer_Q("-", 
                      $1.nom ? $1.nom : $1.valeur,
                      $3.nom ? $3.nom : $3.valeur,
                      $$.nom,
                      qC);        
        afficherQ(quad);        
        inserer_TQ(TQ, quad);

        afficherTableSymbole(TS);
        afficherTQ(TQ);
        afficherTQDansFichier(TQ, "output.txt");
    }
    | expression MULT expression {
        char bff[255]; 
        Symbole* found1;
        Symbole* found2;
        
        // Initialize result structure
        $$.nom = NULL;
        $$.valeur = malloc(255);
        if ($$.valeur == NULL) {
            semanticError("Memory allocation failed", line);
        }

        // Get values for operands
        char *val1, *val2;
        val1 = $1.valeur;
        val2 = $3.valeur;            
        // Perform multiplication based on types
        if ($1.type == ENTIER && $3.type == ENTIER) {
            int result = atoi(val1) * atoi(val2);
            sprintf($$.valeur, "%d", result);
            $$.type = ENTIER;
        } else if ($1.type == FLOTTANT || $3.type == FLOTTANT) {
            float result = atof(val1) * atof(val2);
            sprintf($$.valeur, "%f", result);
            $$.type = FLOTTANT;
        } else if (($1.type == FLOTTANT && $3.type == ENTIER) || ($1.type == ENTIER && $3.type == FLOTTANT)) {
            float result = atof(val1) * atof(val2);
            sprintf($$.valeur, "%f", result);
            $$.type = FLOTTANT;
        } else {
            semanticError("Invalid types for multiplication", line);
        }

        // Generate quadruplet
        qC++;
        char resultVarName[20];
        sprintf(resultVarName, "%s%d", "R",qC);
        $$.nom=resultVarName;
        quad = creer_Q("*", 
                      $1.nom ? $1.nom : $1.valeur,
                      $3.nom ? $3.nom : $3.valeur,
                      $$.nom,
                      qC);        
        afficherQ(quad);        
        inserer_TQ(TQ, quad);

        afficherTableSymbole(TS);
        afficherTQ(TQ);
        afficherTQDansFichier(TQ, "output.txt");
    }
    | expression DIV expression {
        char bff[255]; 
        Symbole* found1;
        Symbole* found2;
        
        // Initialize result structure
        $$.nom = NULL;
        $$.valeur = malloc(255);
        if ($$.valeur == NULL) {
            semanticError("Memory allocation failed", line);
        }

        // Get values for operands
        char *val1, *val2;
        val1 = $1.valeur;
        val2 = $3.valeur;            
        // Perform division based on types
        if ($1.type == ENTIER && $3.type == ENTIER) {
            if (atoi(val2) == 0) {
                semanticError("Division by zero", line);
            }
            int result = atoi(val1) / atoi(val2);
            sprintf($$.valeur, "%d", result);
            $$.type = ENTIER;
        } else if ($1.type == FLOTTANT || $3.type == FLOTTANT) {
            if (atof(val2) == 0.0) {
                semanticError("Division by zero", line);
            }
            float result = atof(val1) / atof(val2);
            sprintf($$.valeur, "%f", result);
            $$.type = FLOTTANT;
        } else if (($1.type == FLOTTANT && $3.type == ENTIER) || ($1.type == ENTIER && $3.type == FLOTTANT)) {
            if (atof(val2) == 0.0) {
                semanticError("Division by zero", line);
            }
            float result = atof(val1) / atof(val2);
            sprintf($$.valeur, "%f", result);
            $$.type = FLOTTANT;
        } else {
            semanticError("Invalid types for division", line);
        }

        // Generate quadruplet
        qC++;
        char resultVarName[20];
        sprintf(resultVarName, "%s%d", "R",qC);
        $$.nom=resultVarName;
        quad = creer_Q("/", 
                      $1.nom ? $1.nom : $1.valeur,
                      $3.nom ? $3.nom : $3.valeur,
                      $$.nom,
                      qC);        
        afficherQ(quad);        
        inserer_TQ(TQ, quad);

        afficherTableSymbole(TS);
        afficherTQ(TQ);
        afficherTQDansFichier(TQ, "output.txt");
    }
    | expression MOD expression {
        char bff[255]; 
        Symbole* found1;
        Symbole* found2;
        
        // Initialize result structure
        $$.nom = NULL;
        $$.valeur = malloc(255);
        if ($$.valeur == NULL) {
            semanticError("Memory allocation failed", line);
        }

        // Get values for operands
        char *val1, *val2;
        val1 = $1.valeur;
        val2 = $3.valeur;            
        // Perform modulo based on types
        if ($1.type == ENTIER && $3.type == ENTIER) {
            if (atoi(val2) == 0) {
                semanticError("Modulo by zero", line);
            }
            int result = atoi(val1) % atoi(val2);
            sprintf($$.valeur, "%d", result);
            $$.type = ENTIER;
        } else {
            semanticError("Invalid types for modulo", line);
        }

        // Generate quadruplet
        qC++;
        char resultVarName[20];
        sprintf(resultVarName, "%s%d", "R",qC);
        $$.nom=resultVarName;
        quad = creer_Q("%", 
                      $1.nom ? $1.nom : $1.valeur,
                      $3.nom ? $3.nom : $3.valeur,
                      $$.nom,
                      qC);        
        afficherQ(quad);        
        inserer_TQ(TQ, quad);

        afficherTableSymbole(TS);
        afficherTQ(TQ);
        afficherTQDansFichier(TQ, "output.txt");
    }
    | expression PUISS expression {
        char bff[255]; 
        Symbole* found1;
        Symbole* found2;
        
        // Initialize result structure
        $$.nom = NULL;
        $$.valeur = malloc(255);
        if ($$.valeur == NULL) {
            semanticError("Memory allocation failed", line);
        }

        // Get values for operands
        char *val1, *val2;
        val1 = $1.valeur;
        val2 = $3.valeur;            
        // Perform power based on types
        if ($1.type == ENTIER && $3.type == ENTIER) {
            int result = pow(atoi(val1), atoi(val2));
            sprintf($$.valeur, "%d", result);
            $$.type = ENTIER;
        } else if ($1.type == FLOTTANT || $3.type == FLOTTANT) {
            float result = pow(atof(val1), atof(val2));
            sprintf($$.valeur, "%f", result);
            $$.type = FLOTTANT;
        } else {
            semanticError("Invalid types for power", line);
        }

        // Generate quadruplet
        qC++;
        char resultVarName[20];
        sprintf(resultVarName, "%s%d", "R",qC);
        $$.nom=resultVarName;
        quad = creer_Q("^", 
                      $1.nom ? $1.nom : $1.valeur,
                      $3.nom ? $3.nom : $3.valeur,
                      $$.nom,
                      qC);        
        afficherQ(quad);        
        inserer_TQ(TQ, quad);

        afficherTableSymbole(TS);
        afficherTQ(TQ);
        afficherTQDansFichier(TQ, "output.txt");
    }
    | NOT expression 
    | PAR_OUV expression PAR_FERM
    | expression INF expression
    | expression INF_EGAL expression
    | expression SUPP expression
    | expression SUPP_EGAL expression
    | expression EQUAL expression {
        char bff[255]; 
        Symbole* found1;
        Symbole* found2;
        
        // Initialize result structure
        $$.nom = NULL;
        $$.valeur = malloc(255);
        if ($$.valeur == NULL) {
            semanticError("Memory allocation failed", line);
        }

        // Get values for operands
        char *val1, *val2;
        val1 = $1.valeur;
        val2 = $3.valeur;            
        // Perform equality check based on types
        if ($1.type == ENTIER && $3.type == ENTIER) {
            bool result = atoi(val1) == atoi(val2);
            sprintf($$.valeur, "%s", result ? "true" : "false");
            $$.type = BOOLEAN;
        } else if ($1.type == FLOTTANT || $3.type == FLOTTANT) {
            bool result = atof(val1) == atof(val2);
            sprintf($$.valeur, "%s", result ? "true" : "false");
            $$.type = BOOLEAN;
        } else if ($1.type == CHAR && $3.type == CHAR) {
            bool result = val1[0] == val2[0];
            sprintf($$.valeur, "%s", result ? "true" : "false");
            $$.type = BOOLEAN;
        } else if ($1.type == STRING && $3.type == STRING) {
            bool result = strcmp(val1, val2) == 0;
            sprintf($$.valeur, "%s", result ? "true" : "false");
            $$.type = BOOLEAN;
        } else {
            semanticError("Invalid types for equality check", line);
        }

        // Generate quadruplet
        qC++;
        char resultVarName[20];
        sprintf(resultVarName, "%s%d", "R", qC);
        $$.nom = resultVarName;
        quad = creer_Q("==", 
                      $1.nom ? $1.nom : $1.valeur,
                      $3.nom ? $3.nom : $3.valeur,
                      $$.nom,
                      qC);        
        afficherQ(quad);        
        inserer_TQ(TQ, quad);

        afficherTableSymbole(TS);
        afficherTQ(TQ);
        afficherTQDansFichier(TQ, "output.txt");
    }
    | expression NOT_EQUAL expression
    | expression ET expression
    | expression OU expression
    ; 

incrementation:
    variable INCREM {

        char bff[255]; 
        Symbole* found1;
        
        // Initialize result structure
        $$.nom = NULL;
        $$.valeur = malloc(255);
        if ($$.valeur == NULL) {
            semanticError("Memory allocation failed", line);
        }

        // Get value for operand
        char *val1;
        val1 = $1.valeur;        
        // Perform addition based on types
        if ($1.type == ENTIER ) {
            int result = atoi(val1) + 1;
            sprintf($$.valeur, "%d", result);
            $$.type = ENTIER;
        } else if ($1.type == FLOTTANT ) {
            float result = atof(val1) + 1;
            sprintf($$.valeur, "%f", result);
            $$.type = FLOTTANT;
        } else {
            semanticError("Invalid types for addition", line);
        }

        // Generate quadruplet
        qC++;
        char resultVarName[20];
        sprintf(resultVarName, "%s%d", "R",qC);
        $$.nom=resultVarName;
        quad = creer_Q("++", 
                      $1.nom ? $1.nom : $1.valeur,
                      "",
                      $$.nom,
                      qC);        
        afficherQ(quad);        
        inserer_TQ(TQ, quad);

        afficherTableSymbole(TS);
        afficherTQ(TQ);
        afficherTQDansFichier(TQ, "output.txt");
    }
    | variable DECREM
    {
        char bff[255]; 
        Symbole* found1;
        
        // Initialize result structure
        $$.nom = NULL;
        $$.valeur = malloc(255);
        if ($$.valeur == NULL) {
            semanticError("Memory allocation failed", line);
        }

        // Get value for operand
        char *val1;
        val1 = $1.valeur;        
        // Perform subtraction based on types
        if ($1.type == ENTIER ) {
            int result = atoi(val1) - 1;
            sprintf($$.valeur, "%d", result);
            $$.type = ENTIER;
        } else if ($1.type == FLOTTANT ) {
            float result = atof(val1) - 1;
            sprintf($$.valeur, "%f", result);
            $$.type = FLOTTANT;
        } else {
            semanticError("Invalid types for subtraction", line);
        }

        // Generate quadruplet
        qC++;
        char resultVarName[20];
        sprintf(resultVarName, "%s%d", "R",qC);
        $$.nom=resultVarName;
        quad = creer_Q("--", 
                      $1.nom ? $1.nom : $1.valeur,
                      "",
                      $$.nom,
                      qC);        
        afficherQ(quad);        
        inserer_TQ(TQ, quad);

        afficherTableSymbole(TS);
        afficherTQ(TQ);
        afficherTQDansFichier(TQ, "output.txt");
    }
    ;

declarations:
    /* empty */
    | declarations declaration 
    ;

declaration:
    type ID  {
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
        afficherTableSymbole(TS); // afficher TS pour confirmer
        afficherTQ(TQ);
    } SEMICOLON
    | tableau SEMICOLON {printf("declaration correcte syntaxiquement\n");}
    | type_Struct SEMICOLON {printf("declaration correcte syntaxiquement\n");}
    | type ID ASSIGN expression SEMICOLON {
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
        
        // Check if the expression is valid for the type
        if (!isValidLiteralForType($4.valeur, typeStr)) {
            semanticError("Invalid literal for type", line);
        }
        
        Symbole* sym = creerSymbole(
            VARIABLE,    // category
            $2,         // name
            typeStr,    // type
            $4.valeur,  // initial value
            line,       // line number
            0          // memory address
        );
        insererSymbole(TS, sym);
        afficherTableSymbole(TS); // afficher TS pour confirmer
        afficherTQ(TQ);
    }
    
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
    declaration
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
    | ID ASSIGN expression {
        Symbole* found;
        if (rechercherSymbole(TS, $1, &found)) { // is declared
            if (found->categorie == VARIABLE) {  
                qC++;
                
                // Create a buffer for the value
                char buffer[256];
                sprintf(buffer, "%s", $3.valeur ? $3.valeur : "");
                
                // Update the symbol's value
                SetValueSymbol(found, buffer);
                
                // Create quadruplet
                quad = creer_Q(":=", $1, " ", buffer, qC);
                inserer_TQ(TQ, quad);
                 afficherTQ(TQ);
                
                // Convert expression type to string for comparison
                char* exprType = NULL;
                switch($3.type) {
                    case ENTIER: exprType = TYPE_ENTIER; break;
                    case FLOTTANT: exprType = TYPE_FLOTTANT; break;
                    case CHAR: exprType = TYPE_CHAR; break;
                    case STRING: exprType = TYPE_STRING; break;
                    case BOOLEAN: exprType = TYPE_BOOLEAN; break;
                    default: exprType = TYPE_ENTIER;
                }
                
                if (!areTypesCompatible(found->type, exprType)) {
                    semanticError("Type incompatible dans l'affectation.", line);
                }
            } else {
                semanticError("Identifier is not a variable", line);
            }
        } else {
            semanticError("Variable non declaree", line);
        }
    } SEMICOLON
    | parametre ASSIGN call SEMICOLON
    | ID ASSIGN call SEMICOLON
    ;

condition:
    ifstatement corps elsebloc  
        {
        while (!Pempty(P)) {
            quad = pop(P);
            updateLabel(quad, qC);
        }
        
        quad = creer_Q("finIf","", " ", "", qC);
        inserer_TQ(TQ, quad);
        qC++;
    }
    ;
ifstatement:
    IF PAR_OUV expression PAR_FERM{
        //vérifier si le resultat de l'expression est un boolean
        if($3.type != BOOLEAN){
            semanticError("L'expression doit être un boolean", line);
        }else{
            qC++;
            //branchement en cas de faux
            quad = creer_Q("BZ","temp", " ", $3.valeur, qC);
            inserer_TQ(TQ, quad);
            //sauvegarder qC pour la mise a jour de l'adresse de branchement dans la pile des adresses
            push(P, quad);
            
        }
    }

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
    /* empty */ {
        //maj de l'adresse de branchement dans la pile des adresses
        qC++;
        quad = pop(P);
        updateLabel(quad, qC);
        printf("\nelsebloc correcte syntaxiquement qc = %d\n", qC);
    }
    | elsestatement corps {
        qC++;
        //maj de l'adresse de branchement dans la pile des adresses
        quad = pop(P);
        updateLabel(quad, qC);
        //maj de l'adresse de branchement dans la pile des adresses
       
    }
    | elifstatement corps elsebloc
    
    ;
elsestatement :
    ELSE {
        //maj de l'adresse de branchement dans la pile des adresses
        qC++;
        quad = pop(P);
        updateLabel(quad, qC+1);
        //branchement vers la fin
        
        quad = creer_Q("BR","temp", " ", "", qC);
        inserer_TQ(TQ, quad);
        push(P, quad);
        
    }
elifstatement:
    elifkey PAR_OUV expression PAR_FERM {
        if($3.type != BOOLEAN){
            semanticError("L'expression doit être un boolean", line);
        }else{
            qC++;
            //branchement en cas de faux
            quad = creer_Q("BZ","temp", " ", $3.valeur, qC);
            inserer_TQ(TQ, quad);
            //sauvegarder qC pour la mise a jour de l'adresse de branchement dans la pile des adresses
            push(P, quad);
            
        }
    }
elifkey:
    ELIF{
        //maj de l'adresse de branchement dans la pile des adresses
        qC++;
        quad = pop(P);
        updateLabel(quad, qC+1);
        //branchement vers la fin
        
        quad = creer_Q("BR","temp", " ", "", qC);
        inserer_TQ(TQ, quad);
        push(P, quad);
    }
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

