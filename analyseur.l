%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "parser.tab.h"
extern YYSTYPE yylval;
extern char *yyin_filename;
int lignenum = 1 ;

int column = 0 ; 
int current_column = 0; 
int yyerror(const char *s);
%}

%option noyywrap

lettre    [قفكهعمنلءىوأ-ي]
quote "'"
dquote "\""

%%
"بداية"    { 
     printf("here is the begining of the program\n");
     column=column+5;
     return DEBUT;
}
"انتهى"   {
     printf("mot de fin\n");
     column=column+5; 
     return FIN; 
}
"صحيح"     { 
     yylval.type = 1; 
     column=column+4;
     return ENTIER; 
}

"عشري"     {
    yylval.type = 2; 
    column=column+4; 
    return FLOTTANT; }
"منطقي"   { 
     column=column+5;
     yylval.type = 5;
     return BOOLEAN; }
"نص"      { 
    column=column+2;
    yylval.type = 4;
    strcpy(yylval.str,yytext); 
    return STRING; }
"حرف"      { 
    column=column+3;
    yylval.type = 3;  
    return CHAR; }
"ثابت"     { 
     column=column+4;
     yylval.type = 0; 
     return CONST; }
"إذا"     { 
     column=column+3;
     return IF; }
"وإلا"  { 
     column=column+4;
     return ELSE; }
"وإلا إذا" { 
     column=column+8;
     return ELIF; }
"طالما"    { 
     column=column+5;
     return WHILE; }
"لكل"      { 
     column=column+3;
     return FOR; }
"اطبع"     { 
     column=column+4;
     return PRINT; }
"أدخل"     { 
     column=column+5;
     return INPUT; }
"جدول"     { 
    column=column+4;
    yylval.type = 6;
    return TABLE; }
"سجل"      {
     column=column+3;
     yylval.type = 7;
     return ENREGISTREMENT; }
"دالة"     { 
    column=column+4;
    return FONCTION; }
"صح"       { 
     column=column+2;
     yylval.boolean = true;
     return TRUE; }
"خطأ"      {
     column=column+3;
     yylval.boolean = false; 
     return FALSE; }
"لا شيء"  {
    column=column+6;
    return VIDE; }
"ارجع"     { 
     column=column+4;
     return RETURN; }
"من"        { 
     column=column+2;
     return FROM; }
"إلى"       { 
    column=column+3;
    return TO; }
"،"        { 
     column=column+1;
     return VIRGULE; }
"؛"  {
     printf("semi colon \n");
     column=column+1; 
     return SEMICOLON; } 

{quote}[^\"]*{quote}   { 
     column=column+yyleng;
     strcpy(yylval.str,yytext);
     return CHAINE; }
{dquote}[^\"]*{dquote}       {
     column=column+yyleng;
     strcpy(yylval.str,yytext);
     return CHAINE; }
[0-9]+      { 
    column=column+yyleng;
    yylval.intv = atoi(yytext);
    return INT; }
[0-9]+"."[0-9]* {
      column=column+yyleng; 
      yylval.flt = atof(yytext);
      return FLOAT; }
{lettre}{lettre}*  {
     strcpy(yylval.str,yytext);
     column=column+yyleng;
     return ID; }
"//".*          { 
     column=1;
     return COMMENT; }
"\"\"\""(\\.|[^\"])*"\"\"\""   {
     column=column+3; // ajoute 3 pour les caractères ' """ '
     int len = strlen(yytext)-3;
     for (int i = 0; i < len; i++) {
        if (yytext[i] == '\n') {
            column = 1; // Réinitialise la colonne pour chaque nouvelle ligne
            lignenum++;
        } else {
            column++;
        }
     } 
      return COMMENT_PLUS;  }
"."      {
    column=column+1;
    return POINTEUR;
} 
"["      {
    printf("debut de tableau \n");
    column=column+1;
    return DEB_TABLEAU;
}    

"]"    {
    column=column+1;
    return FIN_TABLEAU;
}  
"+"         {
     column=column+1;
     return PLUS; }
"-"         {
    column=column+1;
     return MOINS; }
"*"         { 
      column=column+1;
      return MULT; }
"/"         { 
     column=column+1;
     return DIV; }
"%"         { 
      column=column+1;
      return MOD; }
"^"         { 
      column=column+1;
      return PUISS; }
"++"        { 
      column=column+2;
      return INCREM; }
"--"        { 
     column=column+2;
     return DECREM; }
"=="        { 
     column=column+2;
     return EQUAL; }
"!="        { 
     column=column+2;
      return NOT_EQUAL; }
"!"        { 
      column=column+1;
      return NOT; }
"="         { 
      column=column+1;
      return ASSIGN; }
"=<"         { 
    column=column+2;
     return INF_EGAL; }
"=>"         {
     column=column+2;
     return SUPP_EGAL; }
"<"         {
     column=column+1;
      return INF; }
">"         { 
      column=column+1;
      return SUP; }
"||"        { 
     column=column+2;
     return OR; } 
"&&"        { 
     column=column+2;
     return AND; } 
"("        { 
      column=column+1;
      return PAR_OUV; } 
")"        { 
      column=column+1;
      return PAR_FERM; } 
"{"        { 
      column=column+1;
      return DEB_CORPS; } 
"}"        { 
      column=column+1;
      return FIN_CORPS; } 

[ \t\r]+   {
     // Ignorer les espaces, tabulations 
    column=column+yyleng;

} 

\n {
    // Ignorer retours à la ligne
     lignenum++;
     column=0;
}
. {
    current_column = column+1;
    fprintf(stderr, "File \"%s\", line %d, character %d: Unrecognized symbol '%s'\n", yyin_filename, lignenum, current_column, yytext);
    exit(1);
}
%%


