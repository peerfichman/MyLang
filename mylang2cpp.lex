%{
    #include<vector>
    #include "sentence.h"
    #include "literal.h"
    #include "word.h"
    #include <iostream>
    #include <string>
    #include <map>
    #include <cstdlib> 
    #include "mylang2cpp.tab.hpp"
    #include <cstdio>
    extern map<string ,Literal* > vars;
    #define _I_ 0
    #define _C_ 1
    #define _S_ 2
    #define _W_ 3
    using namespace std;

    int id_type(int type){
        switch(type)
            {
                case _I_:
                return N_ID;
                case _C_:
                return C_ID;
                case _S_:
                return S_ID;
                case _W_:
                return W_ID;
            }
            return ID;
    }
    int r_id(char *yy)
    {
    
        if (vars.find(yy) == vars.end()){
            yylval.l = new Literal(yy,yy,-1 );
            return ID;
            } else {
                yylval.l = vars[yy];
                return id_type(vars[yy]->type);
                }
    }


    int yylex();
    
%}

%option noyywrap


word                     \"[^"]*\"
sentence                 \^[^\^]*\^
id                       [a-zA-Z_][_a-zA-Z0-9]*
char                     \'.\'
number                   [\-0-9]+[0-9]* 
%%

"{"                     { return OBRAC;}
"}"                     {return CBRAC;}
"\("                    {return OPAREN;}
"\)"                    {return CPAREN;}
"if"                    {return IF;}
"else"                  {return ELSE;}
"while"                 {return WHILE;}
"loop"                  {return LOOP;}
"input"                 {return INPUT;}
"int"                   {return N_DECL;}
"char"                  {return C_DECL;}
"word"                  {return W_DECL;}
"sentence"              {return S_DECL;}
"output"                {return OUTPUT;}
"exit"                  {return EXIT;}
"=="                    {return EQ;}
"<="                    {return GEQ;}
">="                    {return LEQ;}
[\>]                    {return GT;}
[\<]                    {return LT;}                         
[!]                     {return NOT;}
[=]                     {return ASS;}
[#]                     {return CONCAT;}
[+]                     {return PLUS;}
[-]                     {return MINUS;}
[:]                     {return IDX;}
[,]                     {return COMMA;}
{char}                  {yylval.l = new Literal("",yytext,_C_);return CH;}
{id}                    {return r_id(yytext);}
{word}                  {yylval.l = new Literal("", yytext,_W_ ); return WORD;}
{sentence}              {yylval.l = new Literal("", yytext,_S_ ); return SENT;}
{number}                {yylval.l = new Literal("", yytext,_I_ ); return NUM;}
[;]                     {return SEMI;}
[ \t\n\cr]			    {;}

%%


