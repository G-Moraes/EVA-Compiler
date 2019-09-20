%{
#include <string>

%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]

DELIM {ESPACO}+
INT {DIGITO}+
REAL {INT}+("."{INT}+)?
CHAR \'({LETRA}|{INT})\'
ID {LETRA}({LETRA}|{INT})*
BOOL {"TRUE"|"FALSE"}

%%

"\n"		{}

{DELIM} 	{}

"main"		{return TK_MAIN;}

"int"		{return TK_TIPO_INT;}

"char"      {return TK_TIPO_CHAR;}

"float"     {return TK_TIPO_FLOAT;}

"var"       {return TK_DEC_VAR;}

"(f)"		{return TK_CONV_FLOAT;}

"(i)"		{return TK_CONV_INT;}

"bool"		{ yylval.label = "bool"; yylval.traducao = yytext; return TK_TIPO_BOOL;}

[(){}[\];,=]	{ return *yytext; }

[+\-*/]		{ return *yytext; }


{CHAR}      { yylval.traducao = yytext; return TK_CHAR; }
{REAL}      { yylval.traducao = yytext; return TK_FLOAT;}
{INT}		{ yylval.traducao = yytext; return TK_INT;  }
{ID}		{ yylval.label = yytext; return TK_ID;      }

.			{ *yytext; }

%%
