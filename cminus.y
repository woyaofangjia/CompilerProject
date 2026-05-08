%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

extern int line_num;
extern int error_count;
extern FILE *yyin;

int syntax_error = 0;

void print_error(char *type, char *msg) {
    printf("Error type %s at Line %d: %s\n", type, line_num, msg);
    error_count++;
    syntax_error = 1;
}

#define INDENT(n) for(int i=0; i<n; i++) printf("  ")

Node* create_node(char *name, char *value, int line) {
    Node *node = (Node*)malloc(sizeof(Node));
    strncpy(node->name, name, sizeof(node->name)-1);
    node->name[sizeof(node->name)-1] = '\0';
    strncpy(node->value, value, sizeof(node->value)-1);
    node->value[sizeof(node->value)-1] = '\0';
    node->line = line;
    node->child_count = 0;
    return node;
}

void add_child(Node *parent, Node *child) {
    if (parent->child_count < 10) {
        parent->children[parent->child_count++] = child;
    }
}

void print_tree(Node *node, int indent) {
    if (!node) return;
    
    INDENT(indent);
    
    if (strcmp(node->name, "TYPE") == 0) {
        printf("%s: %s\n", node->name, node->value);
    } else if (strcmp(node->name, "ID") == 0) {
        printf("%s: %s\n", node->name, node->value);
    } else if (strcmp(node->name, "INT") == 0) {
        printf("%s: %s\n", node->name, node->value);
    } else if (strcmp(node->name, "FLOAT") == 0) {
        printf("%s: %s\n", node->name, node->value);
    } else {
        printf("%s (%d)\n", node->name, node->line);
    }
    
    for (int i = 0; i < node->child_count; i++) {
        print_tree(node->children[i], indent + 1);
    }
}

void free_tree(Node *node) {
    if (!node) return;
    for (int i = 0; i < node->child_count; i++) {
        free_tree(node->children[i]);
    }
    free(node);
}

%}

%union {
    int ival;
    float fval;
    char sval[100];
    Node *node;
}

%token TYPE_INT TYPE_FLOAT IF ELSE WHILE RETURN
%token PLUS MINUS STAR DIV LT LE GT GE EQ NE AND OR NOT ASSIGNOP SEMI COMMA
%token LP RP LB RB LC RC
%token <sval> ID
%token <ival> INT
%token <fval> FLOAT

%type <node> Program ExtDefList ExtDef ExtDecList Specifier VarDec FunDec 
%type <node> VarList ParamDec CompSt DefList Def DecList Dec StmtList Stmt
%type <node> Exp Args

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%start Program

%%

Program : ExtDefList { 
            Node *node = create_node("Program", "", 1);
            add_child(node, $1);
            if (!syntax_error) print_tree(node, 0);
            free_tree(node);
        }
        ;

ExtDefList : ExtDef ExtDefList {
            if ($1 == NULL) {
                $$ = $2;
            } else {
                Node *node = create_node("ExtDefList", "", $1->line);
                add_child(node, $1);
                add_child(node, $2);
                $$ = node;
            }
        }
        | { $$ = NULL; }
        ;

ExtDef : Specifier ExtDecList SEMI {
            Node *node = create_node("ExtDef", "", $1->line);
            add_child(node, $1);
            if ($2) add_child(node, $2);
            Node *semi = create_node("SEMI", "", line_num);
            add_child(node, semi);
            $$ = node;
        }
        | Specifier FunDec CompSt {
            Node *node = create_node("ExtDef", "", $1->line);
            add_child(node, $1);
            add_child(node, $2);
            add_child(node, $3);
            $$ = node;
        }
        | error SEMI { 
            print_error("B", "Invalid external definition");
            $$ = NULL;
        }
        ;

ExtDecList : VarDec { $$ = $1; }
           | VarDec COMMA ExtDecList {
            Node *node = create_node("ExtDecList", "", $1->line);
            add_child(node, $1);
            Node *comma = create_node("COMMA", "", line_num);
            add_child(node, comma);
            add_child(node, $3);
            $$ = node;
        }
        ;

Specifier : TYPE_INT {
            Node *node = create_node("Specifier", "", line_num);
            Node *type = create_node("TYPE", "int", line_num);
            add_child(node, type);
            $$ = node;
        }
          | TYPE_FLOAT {
            Node *node = create_node("Specifier", "", line_num);
            Node *type = create_node("TYPE", "float", line_num);
            add_child(node, type);
            $$ = node;
        }
          ;

VarDec : ID {
            Node *node = create_node("VarDec", "", line_num);
            Node *id = create_node("ID", $1, line_num);
            add_child(node, id);
            $$ = node;
        }
       | VarDec LB INT RB {
            Node *node = create_node("VarDec", "", $1->line);
            add_child(node, $1);
            Node *lb = create_node("LB", "", line_num);
            add_child(node, lb);
            char buf[20];
            sprintf(buf, "%d", $3);
            Node *int_node = create_node("INT", buf, line_num);
            add_child(node, int_node);
            Node *rb = create_node("RB", "", line_num);
            add_child(node, rb);
            $$ = node;
        }
       | VarDec LB error {
            print_error("B", "Missing ']'");
            $$ = $1;
        }
       ;

FunDec : ID LP VarList RP {
            Node *node = create_node("FunDec", "", line_num);
            Node *id = create_node("ID", $1, line_num);
            add_child(node, id);
            Node *lp = create_node("LP", "", line_num);
            add_child(node, lp);
            if ($3) add_child(node, $3);
            Node *rp = create_node("RP", "", line_num);
            add_child(node, rp);
            $$ = node;
        }
       | ID LP RP {
            Node *node = create_node("FunDec", "", line_num);
            Node *id = create_node("ID", $1, line_num);
            add_child(node, id);
            Node *lp = create_node("LP", "", line_num);
            add_child(node, lp);
            Node *rp = create_node("RP", "", line_num);
            add_child(node, rp);
            $$ = node;
        }
       | ID LP error RP {
            print_error("B", "Invalid parameter list");
            $$ = NULL;
        }
       ;

VarList : ParamDec COMMA VarList {
            Node *node = create_node("VarList", "", $1->line);
            add_child(node, $1);
            Node *comma = create_node("COMMA", "", line_num);
            add_child(node, comma);
            add_child(node, $3);
            $$ = node;
        }
        | ParamDec { $$ = $1; }
        ;

ParamDec : Specifier VarDec {
            Node *node = create_node("ParamDec", "", $1->line);
            add_child(node, $1);
            add_child(node, $2);
            $$ = node;
        }
        ;

CompSt : LC DefList StmtList RC {
            Node *node = create_node("CompSt", "", line_num);
            Node *lc = create_node("LC", "", line_num);
            add_child(node, lc);
            if ($2) add_child(node, $2);
            if ($3) add_child(node, $3);
            Node *rc = create_node("RC", "", line_num);
            add_child(node, rc);
            $$ = node;
        }
       | LC error RC {
            print_error("B", "Invalid compound statement");
            $$ = NULL;
        }
       ;

DefList : Def DefList {
            Node *node = create_node("DefList", "", $1->line);
            add_child(node, $1);
            add_child(node, $2);
            $$ = node;
        }
        | { $$ = NULL; }
        ;

Def : Specifier DecList SEMI {
            Node *node = create_node("Def", "", $1->line);
            add_child(node, $1);
            if ($2) add_child(node, $2);
            Node *semi = create_node("SEMI", "", line_num);
            add_child(node, semi);
            $$ = node;
        }
     | error SEMI {
            print_error("B", "Invalid definition");
            $$ = NULL;
        }
     ;

DecList : Dec { $$ = $1; }
        | Dec COMMA DecList {
            Node *node = create_node("DecList", "", $1->line);
            add_child(node, $1);
            Node *comma = create_node("COMMA", "", line_num);
            add_child(node, comma);
            add_child(node, $3);
            $$ = node;
        }
        ;

Dec : VarDec { $$ = $1; }
    | VarDec ASSIGNOP Exp {
            Node *node = create_node("Dec", "", $1->line);
            add_child(node, $1);
            Node *assign = create_node("ASSIGNOP", "", line_num);
            add_child(node, assign);
            add_child(node, $3);
            $$ = node;
        }
    ;

StmtList : Stmt StmtList {
            if ($1 == NULL) {
                $$ = $2;
            } else {
                Node *node = create_node("StmtList", "", $1->line);
                add_child(node, $1);
                add_child(node, $2);
                $$ = node;
            }
        }
         | { $$ = NULL; }
         ;

Stmt : Exp SEMI {
            Node *node = create_node("Stmt", "", $1->line);
            add_child(node, $1);
            Node *semi = create_node("SEMI", "", line_num);
            add_child(node, semi);
            $$ = node;
        }
     | CompSt { $$ = $1; }
     | RETURN Exp SEMI {
            Node *node = create_node("Stmt", "", line_num);
            Node *ret = create_node("RETURN", "", line_num);
            add_child(node, ret);
            add_child(node, $2);
            Node *semi = create_node("SEMI", "", line_num);
            add_child(node, semi);
            $$ = node;
        }
     | IF LP Exp RP Stmt %prec LOWER_THAN_ELSE {
            Node *node = create_node("Stmt", "", line_num);
            Node *if_node = create_node("IF", "", line_num);
            add_child(node, if_node);
            Node *lp = create_node("LP", "", line_num);
            add_child(node, lp);
            add_child(node, $3);
            Node *rp = create_node("RP", "", line_num);
            add_child(node, rp);
            add_child(node, $5);
            $$ = node;
        }
     | IF LP Exp RP Stmt ELSE Stmt {
            Node *node = create_node("Stmt", "", line_num);
            Node *if_node = create_node("IF", "", line_num);
            add_child(node, if_node);
            Node *lp = create_node("LP", "", line_num);
            add_child(node, lp);
            add_child(node, $3);
            Node *rp = create_node("RP", "", line_num);
            add_child(node, rp);
            add_child(node, $5);
            Node *else_node = create_node("ELSE", "", line_num);
            add_child(node, else_node);
            add_child(node, $7);
            $$ = node;
        }
     | IF LP Exp RP Exp ELSE {
            print_error("B", "Missing ';'");
            $$ = NULL;
        }
     | WHILE LP Exp RP Stmt {
            Node *node = create_node("Stmt", "", line_num);
            Node *while_node = create_node("WHILE", "", line_num);
            add_child(node, while_node);
            Node *lp = create_node("LP", "", line_num);
            add_child(node, lp);
            add_child(node, $3);
            Node *rp = create_node("RP", "", line_num);
            add_child(node, rp);
            add_child(node, $5);
            $$ = node;
        }
     | error SEMI {
            $$ = NULL;
        }
     | IF LP error RP Stmt {
            print_error("B", "Invalid expression in if");
            $$ = NULL;
        }
     | WHILE LP error RP Stmt {
            print_error("B", "Invalid expression in while");
            $$ = NULL;
        }
     ;

Exp : Exp ASSIGNOP Exp {
            Node *node = create_node("Exp", "", $1->line);
            add_child(node, $1);
            Node *assign = create_node("ASSIGNOP", "", line_num);
            add_child(node, assign);
            add_child(node, $3);
            $$ = node;
        }
    | Exp AND Exp {
            Node *node = create_node("Exp", "", $1->line);
            add_child(node, $1);
            Node *and_node = create_node("AND", "", line_num);
            add_child(node, and_node);
            add_child(node, $3);
            $$ = node;
        }
    | Exp OR Exp {
            Node *node = create_node("Exp", "", $1->line);
            add_child(node, $1);
            Node *or_node = create_node("OR", "", line_num);
            add_child(node, or_node);
            add_child(node, $3);
            $$ = node;
        }
    | Exp LT Exp {
            Node *node = create_node("Exp", "", $1->line);
            add_child(node, $1);
            Node *lt = create_node("LT", "", line_num);
            add_child(node, lt);
            add_child(node, $3);
            $$ = node;
        }
    | Exp LE Exp {
            Node *node = create_node("Exp", "", $1->line);
            add_child(node, $1);
            Node *le = create_node("LE", "", line_num);
            add_child(node, le);
            add_child(node, $3);
            $$ = node;
        }
    | Exp GT Exp {
            Node *node = create_node("Exp", "", $1->line);
            add_child(node, $1);
            Node *gt = create_node("GT", "", line_num);
            add_child(node, gt);
            add_child(node, $3);
            $$ = node;
        }
    | Exp GE Exp {
            Node *node = create_node("Exp", "", $1->line);
            add_child(node, $1);
            Node *ge = create_node("GE", "", line_num);
            add_child(node, ge);
            add_child(node, $3);
            $$ = node;
        }
    | Exp EQ Exp {
            Node *node = create_node("Exp", "", $1->line);
            add_child(node, $1);
            Node *eq = create_node("EQ", "", line_num);
            add_child(node, eq);
            add_child(node, $3);
            $$ = node;
        }
    | Exp NE Exp {
            Node *node = create_node("Exp", "", $1->line);
            add_child(node, $1);
            Node *ne = create_node("NE", "", line_num);
            add_child(node, ne);
            add_child(node, $3);
            $$ = node;
        }
    | Exp PLUS Exp {
            Node *node = create_node("Exp", "", $1->line);
            add_child(node, $1);
            Node *plus = create_node("PLUS", "", line_num);
            add_child(node, plus);
            add_child(node, $3);
            $$ = node;
        }
    | Exp MINUS Exp {
            Node *node = create_node("Exp", "", $1->line);
            add_child(node, $1);
            Node *minus = create_node("MINUS", "", line_num);
            add_child(node, minus);
            add_child(node, $3);
            $$ = node;
        }
    | Exp STAR Exp {
            Node *node = create_node("Exp", "", $1->line);
            add_child(node, $1);
            Node *star = create_node("STAR", "", line_num);
            add_child(node, star);
            add_child(node, $3);
            $$ = node;
        }
    | Exp DIV Exp {
            Node *node = create_node("Exp", "", $1->line);
            add_child(node, $1);
            Node *div = create_node("DIV", "", line_num);
            add_child(node, div);
            add_child(node, $3);
            $$ = node;
        }
    | LP Exp RP {
            Node *node = create_node("Exp", "", line_num);
            Node *lp = create_node("LP", "", line_num);
            add_child(node, lp);
            add_child(node, $2);
            Node *rp = create_node("RP", "", line_num);
            add_child(node, rp);
            $$ = node;
        }
    | MINUS Exp {
            Node *node = create_node("Exp", "", line_num);
            Node *minus = create_node("MINUS", "", line_num);
            add_child(node, minus);
            add_child(node, $2);
            $$ = node;
        }
    | NOT Exp {
            Node *node = create_node("Exp", "", line_num);
            Node *not_node = create_node("NOT", "", line_num);
            add_child(node, not_node);
            add_child(node, $2);
            $$ = node;
        }
    | ID LP Args RP {
            Node *node = create_node("Exp", "", line_num);
            Node *id = create_node("ID", $1, line_num);
            add_child(node, id);
            Node *lp = create_node("LP", "", line_num);
            add_child(node, lp);
            if ($3) add_child(node, $3);
            Node *rp = create_node("RP", "", line_num);
            add_child(node, rp);
            $$ = node;
        }
    | ID LP RP {
            Node *node = create_node("Exp", "", line_num);
            Node *id = create_node("ID", $1, line_num);
            add_child(node, id);
            Node *lp = create_node("LP", "", line_num);
            add_child(node, lp);
            Node *rp = create_node("RP", "", line_num);
            add_child(node, rp);
            $$ = node;
        }
    | Exp LB Exp RB {
            Node *node = create_node("Exp", "", $1->line);
            add_child(node, $1);
            Node *lb = create_node("LB", "", line_num);
            add_child(node, lb);
            add_child(node, $3);
            Node *rb = create_node("RB", "", line_num);
            add_child(node, rb);
            $$ = node;
        }
    | Exp LB error RB {
            print_error("B", "Missing \"]\"");
            $$ = $1;
        }
    | Exp LB error SEMI {
            print_error("B", "Missing \"]\"");
            $$ = $1;
        }
    | Exp LB error ASSIGNOP {
            print_error("B", "Missing \"]\"");
            $$ = $1;
        }
    | ID {
            Node *node = create_node("Exp", "", line_num);
            Node *id = create_node("ID", $1, line_num);
            add_child(node, id);
            $$ = node;
        }
    | INT {
            Node *node = create_node("Exp", "", line_num);
            char buf[20];
            sprintf(buf, "%d", $1);
            Node *int_node = create_node("INT", buf, line_num);
            add_child(node, int_node);
            $$ = node;
        }
    | FLOAT {
            Node *node = create_node("Exp", "", line_num);
            char buf[30];
            sprintf(buf, "%f", $1);
            Node *float_node = create_node("FLOAT", buf, line_num);
            add_child(node, float_node);
            $$ = node;
        }
    ;

Args : Exp COMMA Args {
            Node *node = create_node("Args", "", $1->line);
            add_child(node, $1);
            Node *comma = create_node("COMMA", "", line_num);
            add_child(node, comma);
            add_child(node, $3);
            $$ = node;
        }
     | Exp { $$ = $1; }
     ;

%%

void yyerror(const char *msg) {
    // 禁用默认的语法错误消息，我们在语法规则中处理错误
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        fprintf(stderr, "Cannot open file: %s\n", argv[1]);
        return 1;
    }
    
    yyparse();
    
    fclose(yyin);
    return 0;
}
