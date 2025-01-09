%{
    #include <stdio.h>
    #include <stdlib.h>
    extern FILE *yyin;
    int yylex();
    void yyerror(const char *s);
    int line = 1;        // Numéro de ligne courant
int linecol = 0;         // Numéro de colonne courant
char *yyin_filename = NULL;
int sauv = 0;
int sauvline = 1;

%}


%union
{
char str[100];
char charv;
int intv ; 
float flt;
}

%token  DEBUT FIN WHILE FOR
%token  PRINT INPUT FONCTION VIDE RETURN
%token  COMMENT COMMENT_PLUS
%token  OR AND NOT
%token  IF ELSE ELIF
%token  DEB_CORPS FIN_CORPS
%token  TRUE FALSE
%token  PAR_OUV PAR_FERM
%token  CARACTERE CHAINE
%token  INT FLOAT 
%token  DEB_TABLEAU FIN_TABLEAU TABLE ENREGISTREMENT POINTEUR
%token  CONST ENTIER FLOTTANT STRING CHAR BOOLEAN
%token  ID INCREM DECREM PLUS DIV MOINS MULT MOD PUISS ASSIGN
%token  SEMICOLON
%token  INF INF_EGAL SUP SUPP_EGAL EQUAL NOT_EQUAL
%token  FROM
%token  TO
%token  VIRGULE 

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
    functions DEBUT DEB_CORPS declarations instructions FIN SEMICOLON FIN_CORPS {printf("programme correcte syntaxiquement\n");}
    ;

type :
    ENTIER
    | FLOTTANT
    | STRING
    | CHAR
    | CONST
    | BOOLEAN
    ;

tableau :
    type ID DEB_TABLEAU INT FIN_TABLEAU
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
    type ID SEMICOLON {printf("declaration correcte syntaxiquement\n");}
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
    | PRINT PAR_OUV CHAINE PAR_FERM SEMICOLON{printf("write correcte syntaxiquement\n");}
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
