%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "cminus.tab.h"

int line_num = 1;
int error_count = 0;

extern void print_error(char *type, char *msg);

%}

%option noyywrap

DIGIT           [0-9]
LETTER          [a-zA-Z]
ID              {LETTER}({LETTER}|{DIGIT})*

DECIMAL         {DIGIT}+
OCTAL           0[0-7]+
HEX             0[xX][0-9a-fA-F]+

FLOAT1          {DIGIT}+\.{DIGIT}*
FLOAT2          \.{DIGIT}+
FLOAT3          {DIGIT}+\.{DIGIT}*[eE][+-]?{DIGIT}+
FLOAT4          \.{DIGIT}+[eE][+-]?{DIGIT}+
FLOAT5          {DIGIT}+[eE][+-]?{DIGIT}+

%%

"/*"            {
                    int c;
                    while ((c = input()) != EOF) {
                        if (c == '\n') line_num++;
                        if (c == '*') {
                            if ((c = input()) == '/') break;
                            if (c == '\n') line_num++;
                            unput(c);
                        }
                    }
                    if (c == EOF) {
                        print_error("A", "Unterminated comment");
                    }
                }

"//"            {
                    int c;
                    while ((c = input()) != EOF && c != '\n') ;
                    if (c == '\n') line_num++;
                }

"int"           { return TYPE_INT; }
"float"         { return TYPE_FLOAT; }
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"return"        { return RETURN; }

"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return STAR; }
"/"             { return DIV; }
"<"             { return LT; }
"<="            { return LE; }
">"             { return GT; }
">="            { return GE; }
"=="            { return EQ; }
"!="            { return NE; }
"&&"            { return AND; }
"||"            { return OR; }
"!"             { return NOT; }
"="             { return ASSIGNOP; }
";"             { return SEMI; }
","             { return COMMA; }
"("             { return LP; }
")"             { return RP; }
"["             { return LB; }
"]"             { return RB; }
"{"             { return LC; }
"}"             { return RC; }

{HEX}           {
                    yylval.ival = (int)strtol(yytext, NULL, 16);
                    return INT;
                }

{OCTAL}         {
                    yylval.ival = (int)strtol(yytext, NULL, 8);
                    return INT;
                }

0{DIGIT}+       {
                    print_error("A", "Invalid octal number");
                }

0[xX][0-9a-fA-F]*[g-zG-Z]?[0-9a-fA-F]* {
                    print_error("A", "Invalid hexadecimal number");
                }

{FLOAT3}|{FLOAT4}|{FLOAT5} {
                    yylval.fval = atof(yytext);
                    return FLOAT;
                }

{FLOAT1}|{FLOAT2} {
                    yylval.fval = atof(yytext);
                    return FLOAT;
                }

{DIGIT}+[eE][+-]? {
                    print_error("A", "Invalid floating-point number");
                }

{DECIMAL}       {
                    yylval.ival = atoi(yytext);
                    return INT;
                }

{ID}            {
                    strncpy(yylval.sval, yytext, sizeof(yylval.sval)-1);
                    yylval.sval[sizeof(yylval.sval)-1] = '\0';
                    return ID;
                }

"\n"            { line_num++; }

[ \t\r]+        { /* ignore whitespace */ }

.               {
                    char msg[100];
                    snprintf(msg, sizeof(msg), "Mysterious character \"%c\"", yytext[0]);
                    print_error("A", msg);
                }

%%
