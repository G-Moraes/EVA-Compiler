%{
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include <list>
using std::string;
using std::getline;


#define YYSTYPE atributos

using namespace std;

typedef struct Variable{

	string tipo;
	string nome;
	string valor;
} variable;

typedef struct Atributos
{
	string tipo;
	string label;
	string traducao;
} atributos;

typedef struct{

	string implicita; //tradução após conversão 
	string nomeVar; //nome da variável
	string varConvertida; //nome da variável que foi convertida
} structAux; //struct auxiliar utilizada para conversões

int valorVar = 0;
int valorTemp = 0;
int valorLoops = 0;
int mapAtual = 0;
unordered_map <string, variable> globalTabSym;
vector <string> tempVector;
vector <string> globalTempVector;
stack <int> stackLoops;
stack <string> stackCommands;
vector <unordered_map<string, variable>> contextoVariaveis;

//funções yacc
int yylex(void);
void yyerror(string);

//função geradora de label
string genLabel();

//funções de conversão
structAux implicitConversion(string tipo0, string tipo1, string nome0, string nome1);
string explicitConversion(string tipo0, string tipo1);

//funções para checar tipos específicos
string isBoolean(string tipo0, string tipo1);
int erroTipo(string tipo0, string tipo1);

//funções para acessar o vetor de variáveis
void addVarToTempVector(string nomeVar);
void addVarToTempVector(string nomeVar);
void addVarToGlobalTempVector(string nomeVar);
void printVector();
void printGlobalVector();

//funções para acessar tabela de simbolos
void addMapToStack();
string addVarToTabSym(string nomeDado, string conteudoVar, string tipoVar);
string addVarToGlobalTabSym(string nomeDado, string conteudoVar, string tipoVar);
variable searchForVariable(string nome);
void checkForVariable(string nome);
void printGlobalVariables();
%}

//lista de tokens
%token TK_MAIN
%token TK_IF TK_ELSE TK_THEN TK_END_LOOP TK_WHILE TK_DO TK_FOR TK_BREAK TK_CONTINUE TK_ENTRADA TK_SAIDA
%token TK_ID TK_DEC_VAR TK_GLOBAL
%token TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_BOOL TK_TIPO_CHAR TK_TIPO_STRING
%token TK_UN_SUM TK_CONV_FLOAT TK_CONV_INT TK_LE TK_HE TK_EQ TK_DIFF
%token TK_CHAR TK_FLOAT TK_BOOL TK_NUM
%token TK_STRING TK_FIM TK_ERROR

//estado inicial
%start S

//ordem de precedência
%right '=' '!'
%left '|'
%left '&'
%left TK_EQ TK_DIFF
%left '<' '>' TK_HE TK_LE
%left '+' '-'
%left '*' '/'
%left '(' ')'
%%

S 		: BLOCOGLOBAL BLOCOCONTEXTO TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				printGlobalVariables();
				cout << "/*Compilador Eva*/\n" << "#include <iostream>\n#include <string.h>\n#include <stdio.h>\n#define TRUE 1\n#define FALSE 0\n\nint main(void)\n{" <<endl;
				printVector();
				cout << $7.traducao << "\treturn 0;\n}" << endl;
			}
			;

BLOCO		  : '{' COMANDOS '}'
				{
					$$.traducao = $2.traducao;
				}
				;

BLOCOGLOBAL   :
							{
								contextoVariaveis.push_back(globalTabSym);
							}

BLOCOCONTEXTO :
							{
								addMapToStack();
							}

COMANDOS	  : COMANDO COMANDOS
					{
						$$.traducao = $1.traducao + $2.traducao;
					}

					|
					{
						$$.traducao = "";
					}
					;

COMANDO 	  : E ';'
						{
							$$ = $1;
						}

						| ATRIBUICAO ';'
						{
							$$ = $1;
						}

						| DECLARACAO ';'
						{
							$$ = $1;
						}

						| ENTRADA ';'
						{
							$$ = $1;
						}

						| SAIDA ';'
						{
							$$ = $1;
						}

						| BLOCOCONTEXTO IF
						{
							$$ = $2;
						}

						| BLOCOCONTEXTO ELSE
						{
							$$ = $2;
						}

						| BLOCOCONTEXTO WHILE
						{
							$$ = $2;
						}

						| BLOCOCONTEXTO DOWHILE ';'
						{
							$$ = $2;
						}

						| BLOCOCONTEXTO FOR
						{
							$$ = $2;
						}

						|	BREAK ';'
						{
							$$ = $1;
						}

						|	CONTINUE ';'
						{
							$$ = $1;
						}
						;

ENTRADA 	: TK_ID '=' TK_ENTRADA
			{
				$$.label = genLabel();
				$$.tipo = $1.tipo;
				variable Var = searchForVariable($1.label);
				cout << "$3.label = " << $3.label << endl;
				$$.traducao = "\tstd::cin" + $$.traducao + $1.traducao + ";\n";
			};

SAIDA 		: TK_SAIDA '=' TK_ID
			{
				$$.label = genLabel();
				variable Var = searchForVariable($3.label);
				$$.traducao = "\tstd::cout " + $3.traducao + ";\n";
			}

CONDICIONAL : TK_ID '>' E
			{
				$$.label = genLabel();
				$$.tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				variable Var = searchForVariable($1.label);
				structAux aux = implicitConversion(Var.tipo, $3.tipo, $1.label, $3.label);

				if(aux.varConvertida == $1.label){

					$$.traducao = $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " > " + $3.label + ";\n";
				}
				else if(aux.varConvertida == $3.label){

					$$.traducao = $3.traducao + aux.implicita + "\t" + $$.label + " = " + Var.nome + " > " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo

					$$.traducao = $3.traducao + "\t" + $$.label + " = " + Var.nome + " > " + $3.label + ";\n";
				}

				addVarToTempVector("\tint " + $$.label + ";\n");
			}

			| TK_ID '<' E
			{
				$$.label = genLabel();
				$$.tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				variable Var = searchForVariable($1.label);
				structAux aux = implicitConversion(Var.tipo, $3.tipo, $1.label, $3.label);

				if(aux.varConvertida == $1.label){

					$$.traducao = $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " < " + $3.label + ";\n";
				}
				else if(aux.varConvertida == $3.label){

					$$.traducao = $3.traducao + aux.implicita + "\t" + $$.label + " = " + Var.nome + " < " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo

					$$.traducao = $3.traducao + "\t" + $$.label + " = " + Var.nome + " < " + $3.label + ";\n";
				}

				addVarToTempVector("\tint " + $$.label + ";\n");
			}

			| TK_ID TK_HE E
			{
				$$.label = genLabel();
				$$.tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				variable Var = searchForVariable($1.label);
				structAux aux = implicitConversion(Var.tipo, $3.tipo, $1.label, $3.label);

				if(aux.varConvertida == $1.label){

					$$.traducao = $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " >= " + $3.label + ";\n";
				}
				else if(aux.varConvertida == $3.label){

					$$.traducao = $3.traducao + aux.implicita + "\t" + $$.label + " = " + Var.nome + " >= " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo

					$$.traducao = $3.traducao + "\t" + $$.label + " = " + Var.nome + " >= " + $3.label + ";\n";
				}

				addVarToTempVector("\tint " + $$.label + ";\n");
			}

			| TK_ID TK_LE E
			{
				$$.label = genLabel();
				$$.tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				variable Var = searchForVariable($1.label);
				structAux aux = implicitConversion(Var.tipo, $3.tipo, $1.label, $3.label);

				if(aux.varConvertida == $1.label){

					$$.traducao = $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " <= " + $3.label + ";\n";
				}
				else if(aux.varConvertida == $3.label){

					$$.traducao = $3.traducao + aux.implicita + "\t" + $$.label + " = " + Var.nome + " <= " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo

					$$.traducao = $3.traducao + "\t" + $$.label + " = " + Var.nome + " <= " + $3.label + ";\n";
				}
			}

			| TK_ID TK_EQ E
			{
				$$.label = genLabel();
				$$.tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				variable Var = searchForVariable($1.label);
				structAux aux = implicitConversion(Var.tipo, $3.tipo, $1.label, $3.label);

				if(aux.varConvertida == $1.label){

					$$.traducao = $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " == " + $3.label + ";\n";
				}
				else if(aux.varConvertida == $3.label){

					$$.traducao = $3.traducao + aux.implicita + "\t" + $$.label + " = " + Var.nome + " == " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo

					$$.traducao = $3.traducao + "\t" + $$.label + " = " + Var.nome + " == " + $3.label + ";\n";
				}
			}

			| TK_ID TK_DIFF E
			{
				$$.label = genLabel();
				$$.tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				variable Var = searchForVariable($1.label);
				structAux aux = implicitConversion(Var.tipo, $3.tipo, $1.label, $3.label);

				if(aux.varConvertida == $1.label){

					$$.traducao = $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " != " + $3.label + ";\n";
				}
				else if(aux.varConvertida == $3.label){

					$$.traducao = $3.traducao + aux.implicita + "\t" + $$.label + " = " + Var.nome + " != " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo

					$$.traducao = $3.traducao + "\t" + $$.label + " = " + Var.nome + " != " + $3.label + ";\n";
				}
			}
			;

ATRIBUICAO 	: TK_DEC_VAR TK_ID TK_TIPO_CHAR '=' E
						{
							erroTipo("char", $5.tipo);
							string nomeAuxID = addVarToTabSym($2.label, $5.traducao, "char");
							$$.traducao = $5.traducao + "\t" + nomeAuxID + " = " + $5.label + ";\n";
							addVarToTempVector("\tchar " + nomeAuxID + ";\n");
						}

						/*| TK_DEC_VAR TK_ID TK_TIPO_STRING '=' E
						{
							erroTipo("string", $5.tipo);
							string nomeAuxID = addVarToTabSym($2.label, $5.traducao, "string");
							$$.traducao =  $5.traducao +  "\t" + nomeAuxID + " = " + $5.label + ";\n";
							addVarToTempVector("\tstring " + nomeAuxID + ";\n");
						}
						*/
						| TK_DEC_VAR TK_ID TK_TIPO_INT '=' E
						{
							$$.tipo = "int";
							if($$.tipo != $5.tipo){

								if($5.tipo == "char" || $5.tipo == "string"){
									yyerror("Declaração de char/string em int não permitido!");
								}

								else{

									string nomeAuxID = addVarToTabSym($2.label, $5.traducao, "int");
									$$.traducao = $5.traducao + "\t" + nomeAuxID + " = (int) " + $5.label  + ";\n";
									addVarToTempVector("\tint " + nomeAuxID +  ";\n");
								}
							}

							else{

								string nomeAuxID = addVarToTabSym($2.label, $5.traducao, "int");
								$$.traducao = $5.traducao + "\t" + nomeAuxID + " = " + $5.label  + ";\n";
								addVarToTempVector("\tint " + nomeAuxID +  ";\n");
							}
						}

						| TK_DEC_VAR TK_ID TK_TIPO_FLOAT '=' E
						{
							$$.tipo = "float";
							if($$.tipo != $5.tipo){
								if($5.tipo == "char" || $5.tipo == "string"){
									yyerror("Declaração de char/string em float não permitido!");
								}
								else{
									string nomeAuxID = addVarToTabSym($2.label, $5.traducao, "float");
									$$.traducao = $5.traducao + "\t" + nomeAuxID + " = (float) " + $5.label  + ";\n";
									addVarToTempVector("\tfloat " + nomeAuxID +  ";\n");
								}
							}
							else{
								string nomeAuxID = addVarToTabSym($2.label, $5.traducao, "float");
								$$.traducao = $5.traducao + "\t" + nomeAuxID + " = " + $5.label  + ";\n";
								addVarToTempVector("\tint " + nomeAuxID +  ";\n");
							}
						}

						| TK_DEC_VAR TK_ID TK_TIPO_BOOL '=' E
						{
							$$.tipo = "bool";
							if($$.tipo != $5.tipo){
								yyerror("Tipo booleano somente aceita boleano!");
							}
							else{
								string nomeAuxID = addVarToTabSym($2.label, $5.traducao, "int");
								$$.traducao = $5.traducao + "\t" + nomeAuxID + " = " + $5.label  + ";\n";
								addVarToTempVector("\tint " + nomeAuxID +  ";\n");
							}
						}

						//globais

						| TK_DEC_VAR TK_GLOBAL TK_ID TK_TIPO_CHAR '=' E
						{
							erroTipo("char", $6.tipo);
							string nomeAuxID = addVarToGlobalTabSym($2.label, $6.traducao, "char");
							$$.traducao = $6.traducao + "\t" + nomeAuxID + " = " + $6.label + ";\n";
						}

						/*| TK_DEC_VAR TK_GLOBAL TK_ID TK_TIPO_STRING '=' E
						{
							erroTipo("string", $6.tipo);
							string nomeAuxID = addVarToGlobalTabSym($2.label, $6.traducao, "string");
							$$.traducao =  $6.traducao +  "\t" + nomeAuxID + " = " + $6.label + ";\n";
						}
						*/

						| TK_DEC_VAR TK_GLOBAL TK_ID TK_TIPO_INT '=' E
						{
							$$.tipo = "int";
							if($$.tipo != $6.tipo){

								if($6.tipo == "char" || $6.tipo == "string"){
									yyerror("Declaração de char/string em int não permitido!");
								}

								else{
									string nomeAuxID = addVarToGlobalTabSym($2.label, $6.traducao, "int");
									$$.traducao = $6.traducao + "\t" + nomeAuxID + " = (int) " + $6.label  + ";\n";
								}
							}

							else{
								string nomeAuxID = addVarToGlobalTabSym($2.label, $6.traducao, "int");
								$$.traducao = $6.traducao + "\t" + nomeAuxID + " = " + $6.label  + ";\n";
							}
						}

						| TK_DEC_VAR TK_GLOBAL TK_ID TK_TIPO_FLOAT '=' E
						{
							$$.tipo = "float";
							if($$.tipo != $6.tipo){
								if($6.tipo == "char" || $6.tipo == "string"){
									yyerror("Declaração de char/string em float não permitido!");
								}
								else{
									string nomeAuxID = addVarToGlobalTabSym($2.label, $6.traducao, "float");
									$$.traducao = $6.traducao + "\t" + nomeAuxID + " = (float) " + $6.label  + ";\n";
								}
							}
							else{
								string nomeAuxID = addVarToGlobalTabSym($2.label, $6.traducao, "float");
								$$.traducao = $6.traducao + "\t" + nomeAuxID + " = " + $6.label  + ";\n";
							}
						}

						| TK_DEC_VAR TK_GLOBAL TK_ID TK_TIPO_BOOL '=' E
						{
							$$.tipo = "bool";
							if($$.tipo != $6.tipo){
								yyerror("Tipo booleano somente aceita boleano!");
							}
							else{
								string nomeAuxID = addVarToGlobalTabSym($2.label, $6.traducao, "int");
								$$.traducao = $6.traducao + "\t" + nomeAuxID + " = " + $6.label  + ";\n";
							}
						}

						//atribuicao sem declaracao

						| TK_ID '=' E
						{
							variable Var = searchForVariable($1.label);
							cout << "\n\nNome expressão: " << $3.label << "\nTipo expressão: " << $3.tipo << endl;

							if(($3.tipo != Var.tipo)){

								if(($3.tipo == "char" && Var.tipo != "char") || ($3.tipo == "bool" && Var.tipo != "bool") || ($3.tipo == "string" && Var.tipo != "string")){
									string msgError = "Atribuição de " + $3.tipo + " em " + Var.tipo  + " é inválida!\n";
									yyerror(msgError);
								}

								else{

									$$.tipo = Var.tipo;
									$$.traducao = $3.traducao + "\t" + Var.nome + " = " + "(" + Var.tipo + ") " + $3.label + ";\n";
								}
							}

							else{

								$$.tipo = $3.tipo;
								$$.traducao = $3.traducao + "\t" + Var.nome + " = " + $3.label + ";\n";
							}
						}

						| TK_ID '=' TK_CONV_FLOAT E
						{
							variable Var = searchForVariable($1.label);
							//unordered_map<string, variable> tabSym = contextoVariaveis.back();
							if(($4.tipo == "char" && Var.tipo != "char") || ($4.tipo == "bool" && Var.tipo != "bool")){
								string msgError = "Atribuição de " + $4.tipo + " em " + Var.tipo  + " é inválida!\n";
								yyerror(msgError);
							}

							else{

								if((Var.tipo == "int") && $4.tipo == "float"){

									cout << "Conversão para float em "<< Var.nome << " não suportada! Resultado será armazenado como inteiro!\n" << endl;
									$$.tipo = "int";
									$$.traducao = $4.traducao + "\t" + Var.nome + " = " + $4.label + ";\n";
								}
								else{
										$$.tipo = "float";
										$$.traducao = $4.traducao + "\t" + Var.nome + " = (float) " + $4.label + ";\n";
								}
							}
						}

						| TK_ID '=' TK_CONV_INT E
						{
							variable Var = searchForVariable($1.label);
							//unordered_map<string, variable> tabSym = contextoVariaveis.back();
							if(($4.tipo == "char" && Var.tipo != "char") || ($4.tipo == "bool" && Var.tipo != "bool")){
								string msgError = "Atribuição de " + $4.tipo + " em " + Var.tipo  + " é inválida!\n";
								yyerror(msgError);
							}

							else{

								$$.traducao = $4.traducao + "\t" + Var.nome + " = (int) " + $4.label + ";\n";
							}
						}
						;

DECLARACAO	: TK_DEC_VAR TK_ID TK_TIPO_CHAR
						{
							string nomeAuxID = addVarToTabSym($2.label, "none", "char");
							$$.traducao = "\t";
							addVarToTempVector("\tchar " + nomeAuxID +  ";\n");
						}

						/*| TK_DEC_VAR TK_ID TK_TIPO_STRING
						{
							string nomeAuxID = addVarToTabSym($2.label, "none", "string");
							$$.traducao = "\t";
							addVarToTempVector("\tstring " + nomeAuxID +  ";\n");
						}*/

						| TK_DEC_VAR TK_ID TK_TIPO_INT
						{
							string nomeAuxID = addVarToTabSym($2.label, "0", "int");
							$$.traducao = "\t";
							addVarToTempVector("\tint " + nomeAuxID + ";\n");
						}

						| TK_DEC_VAR TK_ID TK_TIPO_FLOAT
						{
							string nomeAuxID = addVarToTabSym($2.label, "0.0", "float");
							$$.traducao = "\t";
							addVarToTempVector("\tfloat " + nomeAuxID + ";\n");
						}

						| TK_DEC_VAR TK_ID TK_TIPO_BOOL
						{
							string nomeAuxID = addVarToTabSym($2.label, "TRUE", "bool");
							$$.traducao = "\t";
							addVarToTempVector("\tint " + nomeAuxID + ";\n");
						}

						//globais

						| TK_DEC_VAR TK_GLOBAL TK_ID TK_TIPO_CHAR
						{
							string nomeAuxID = addVarToGlobalTabSym($2.label, "none", "char");
							$$.traducao = "\t";
						}

						/*| TK_DEC_VAR TK_GLOBAL TK_ID TK_TIPO_STRING
						{
							string nomeAuxID = addVarToGlobalTabSym($2.label, "none", "string");
							$$.traducao = "\t";
						}*/

						| TK_DEC_VAR TK_GLOBAL TK_ID TK_TIPO_INT
						{
							string nomeAuxID = addVarToGlobalTabSym($2.label, "0", "int");
							$$.traducao = "\t";
						}

						| TK_DEC_VAR TK_GLOBAL TK_ID TK_TIPO_FLOAT
						{
							string nomeAuxID = addVarToGlobalTabSym($2.label, "0.0", "float");
							$$.traducao = "\t";
						}

						| TK_DEC_VAR TK_GLOBAL TK_ID TK_TIPO_BOOL
						{
							string nomeAuxID = addVarToGlobalTabSym($2.label, "TRUE", "bool");
							$$.traducao = "\t";
						}
						;

IF			  : TK_IF {valorLoops++; stackLoops.push(valorLoops);} CONDICIONAL TK_THEN COMANDOS TK_END_LOOP ';'
					{
						if($3.tipo != "bool"){
							yyerror("Condicional sem declaração do tipo booleano!\n");
						}

						else{
							string auxVar = "temp" + to_string(valorVar++);
							addVarToTempVector("\tint " + auxVar + ";\n");
							string auxVar2 = "!" + $3.label;
							$$.traducao = "\n//if\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + $3.traducao + "\n\t" + auxVar + " = " +
							auxVar2 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n" + $5.traducao + "\tfinal" +
							to_string(stackLoops.top()) + ":\n";
							stackLoops.pop();
							contextoVariaveis.pop_back();
							mapAtual--;
						}
					}

					| TK_IF {valorLoops++; stackLoops.push(valorLoops);} E TK_THEN COMANDOS TK_END_LOOP ';'
					{
						if($3.tipo != "bool"){
							yyerror("Condicional sem declaração do tipo booleano!\n");
						}

						else{
							string auxVar = "temp" + to_string(valorVar++);
							addVarToTempVector("\tint " + auxVar + ";\n");
							string auxVar2 = "!" + $3.label;
							$$.traducao = "\n//if\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + $3.traducao + "\n\t" + auxVar + " = " +
							auxVar2 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n" + $5.traducao + "\tfinal" +
							to_string(stackLoops.top()) + ":\n";
							stackLoops.pop();
							contextoVariaveis.pop_back();
							mapAtual--;
						}
					}
					;

ELSE		  : IF {valorLoops++; stackLoops.push(valorLoops);} TK_ELSE TK_THEN COMANDOS TK_END_LOOP ';'
				{
					int posiAlteracao = $1.traducao.rfind("final");
					string auxRetorno = $1.traducao;
					auxRetorno.insert(posiAlteracao, "goto final" + to_string(stackLoops.top()) + ";\n\n\t");
					$$.traducao = auxRetorno + $5.traducao + "\tfinal" + to_string(stackLoops.top()) + ":\n";
					stackLoops.pop();
					contextoVariaveis.pop_back();
					mapAtual--;
				}
				;

WHILE 		: TK_WHILE {valorLoops++; stackLoops.push(valorLoops); stackCommands.push("while");} '(' CONDICIONAL ')' BLOCO
					{
						if($4.tipo != "bool"){
							yyerror("Condicional sem declaração do tipo booleano!\n");
						}

						else{
							string auxVar = "temp" + to_string(valorVar++);
							addVarToTempVector("\tint " + auxVar + ";\n");
							string auxVar2 = "!" + $4.label;
							$$.traducao = "\n//while:\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + $4.traducao + "\n\tloop" + to_string(stackLoops.top()) + ": " + auxVar + " = " +
							auxVar2 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n" + $6.traducao + "\tgoto loop" + to_string(stackLoops.top()) +
							";\n\tfinal" + to_string(stackLoops.top()) + ":\n";
							stackLoops.pop();
							contextoVariaveis.pop_back();
							mapAtual--;
						}
					}

					/*| TK_WHILE {valorLoops++; stackLoops.push(valorLoops); stackCommands.push("while");} '(' E ')' BLOCO
					{
						if($4.tipo != "bool"){
							yyerror("Condicional sem declaração do tipo booleano!\n");
						}

						else{
							string auxVar = "temp" + to_string(valorVar++);
							addVarToTempVector("\tint " + auxVar + ";\n");
							string auxVar2 = "!" + $4.label;
							$$.traducao = "\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + $4.traducao + "\n\tloop" + to_string(stackLoops.top()) + ": " + auxVar + " = " +
							auxVar2 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n" + $6.traducao + "\tgoto loop" + to_string(stackLoops.top()) +
							";\n\tfinal" + to_string(stackLoops.top()) + ":\n";
							stackLoops.pop();
							contextoVariaveis.pop_back();
							mapAtual--;
						}
					}*/
					;

DOWHILE		: TK_DO {valorLoops++; stackLoops.push(valorLoops); stackCommands.push("while");} BLOCO TK_WHILE '(' CONDICIONAL ')'
					{
						if($6.tipo != "bool"){
							yyerror("Condicional sem declaração do tipo booleano!\n");
						}

						else{
							string auxVar = "temp" + to_string(valorVar++);
							addVarToTempVector("\tint " + auxVar + ";\n");
							string auxVar2 = "!" + $6.label;
							$$.traducao = "\n//do while:\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + $3.traducao + "\n\tloop" + to_string(stackLoops.top()) + ":\n" + $6.traducao +
							"\t" + auxVar + " = " + auxVar2 + ";\n\tif (" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n\tgoto comeco" + to_string(stackLoops.top()) +
							";\n\tfinal" + to_string(stackLoops.top()) + ":\n";
							stackLoops.pop();
							contextoVariaveis.pop_back();
							mapAtual--;
						}
					}
					/*
					| TK_DO {valorLoops++; stackLoops.push(valorLoops); stackCommands.push("while");} BLOCO TK_WHILE '(' E ')'
					{
						if($6.tipo != "bool"){
							yyerror("Condicional sem declaração do tipo booleano!\n");
						}

						else{
							string auxVar = "temp" + to_string(valorVar++);
							addVarToTempVector("\tint " + auxVar + ";\n");
							string auxVar2 = "!" + $6.label;
							$$.traducao = "\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + $3.traducao + "\n\tloop" + to_string(stackLoops.top()) + ":\n" + $6.traducao +
							"\t" + auxVar + " = " + auxVar2 + ";\n\tif (" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n\tgoto comeco" + to_string(stackLoops.top()) +
							";\n\tfinal" + to_string(stackLoops.top()) + ":\n";
							stackLoops.pop();
							contextoVariaveis.pop_back();
							mapAtual--;
						}
					}*/
					;

FOR 		  :	TK_FOR {valorLoops++; stackLoops.push(valorLoops); stackCommands.push("for");} FORMODES 
			  {
			  	$$ = $3;
			  }

FORMODES 		: TK_ID ';' CONDICIONAL ';' E BLOCO
				{

					variable Var = searchForVariable($3.label);

			  		if($3.tipo != "bool"){
			  			string msgError = "For somente itera sobre booleano! Tentativa de iterar sobre " + $3.tipo + " inválida!\n";
			  			yyerror(msgError);
			  		}

			  		string nomeVar = genLabel();
					addVarToTempVector("\tint " + nomeVar + ";\n");

			  		string auxVar = "temp" + to_string(valorVar++);
					addVarToTempVector("\tint " + auxVar + ";\n");

					string auxVar2 = genLabel();
					string auxVar3 = "!" + $3.label;

					$$.traducao = "\n//for\n" + $1.traducao + "\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + $3.traducao + "\n\tloop" + to_string(stackLoops.top()) + ": " + auxVar + " = " +
					auxVar3 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n" + $6.traducao +"\t"+ nomeVar + " = " + Var.nome + " + 1;\n" +
					"\tgoto loop" + to_string(stackLoops.top()) + ";\n\tfinal" + to_string(stackLoops.top()) + ":\n";
					stackLoops.pop();
					contextoVariaveis.pop_back();
					mapAtual--;
				}

				| ATRIBUICAO ';' E ';' E BLOCO
			  	{
					
					variable Var = searchForVariable($3.label);

				  	if($3.tipo != "bool"){
				  		string msgError = "For somente itera sobre booleano! Tentativa de iterar sobre " + $3.tipo + " inválida!\n";
				  		yyerror(msgError);
				  	}

				  	string nomeVar = genLabel();
					addVarToTempVector("\tint " + nomeVar + ";\n");

				  	string auxVar = "temp" + to_string(valorVar++);
					addVarToTempVector("\tint " + auxVar + ";\n");

					string auxVar2 = genLabel();
					string auxVar3 = "!" + $3.label;

					$$.traducao = "\n//for\n" + $1.traducao + "\n\tcomeco" + to_string(stackLoops.top()) + ":\n" + $3.traducao + "\n\tloop" + to_string(stackLoops.top()) + ": " + auxVar + " = " +
					auxVar3 + ";\n\tif(" + auxVar + ") goto final" + to_string(stackLoops.top()) + ";\n" + $6.traducao +"\t"+ nomeVar + " = " + Var.nome + " + 1;\n" +
					"\tgoto loop" + to_string(stackLoops.top()) + ";\n\tfinal" + to_string(stackLoops.top()) + ":\n";
					stackLoops.pop();
					contextoVariaveis.pop_back();
					mapAtual--;
				}
				;

BREAK			: TK_BREAK
					{
						if(stackLoops.empty()){
							$$.traducao = "";
						}

						else if(stackCommands.empty()){
							yyerror("Break fora de um laço. Erro!");
						}

						else{
							$$.traducao = "\tgoto final" + to_string(stackLoops.top()) + ";// isso é um break\n";
						}
					}

CONTINUE 	:	TK_CONTINUE
					{
						if(stackLoops.empty()){
							$$.traducao = "";
						}

						else if(stackCommands.empty()){
							yyerror("Continue fora de um laço. Erro!");
						}

						else{
							$$.traducao = "\tgoto inicio" + to_string(stackLoops.top()) + ";// isso é um continue\n";
						}
					}

E 			  : E '+' E
			{
				$$.label = genLabel();

				if($$.tipo != "string" && $1.tipo != "string" && $3.tipo != "string")
				{
					cout << $$.tipo << endl;
					structAux aux = implicitConversion($1.tipo, $3.tipo, $1.label, $3.label);
					if(aux.varConvertida == $1.label){
						$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " + " + $3.label + ";\n";
					}
					else if(aux.varConvertida == $3.label){
						$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " + " + aux.nomeVar + ";\n";
					}
					else{ //se as duas variáveis são do mesmo tipo
						$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " + " + $3.label + ";\n";
				}				}

				else
				{
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " + " + $3.label + ";\n";
					cout << "aqui" << endl;
				}
				addVarToTempVector("\t" + $$.tipo + " " + $$.label  + ";\n");
			}

			| E '-' E
			{
				$$.label = genLabel();
				structAux aux = implicitConversion($1.tipo, $3.tipo, $1.label, $3.label);
				if(aux.varConvertida == $1.label){
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " - " + $3.label + ";\n";
				}
				else if(aux.varConvertida == $3.label){
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " - " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " - " + $3.label + ";\n";
				}
				addVarToTempVector("\t" + $$.tipo + " " + $$.label + ";\n");
			}

			| E '*' E
			{
				$$.label = genLabel();
				structAux aux = implicitConversion($1.tipo, $3.tipo, $1.label, $3.label);
				if(aux.varConvertida == $1.label){
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " * " + $3.label + ";\n";
				}
				else if(aux.varConvertida == $3.label){
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " * " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " * " + $3.label + ";\n";
				}
				addVarToTempVector("\t" + $$.tipo + " " + $$.label + ";\n");
			}

			| E '/' E
			{
				$$.label = genLabel();
				structAux aux = implicitConversion($1.tipo, $3.tipo, $1.label, $3.label);
				if(aux.varConvertida == $1.label){
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " / " + $3.label + ";\n";
				}
				else if(aux.varConvertida == $3.label){
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " / " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " / " + $3.label + ";\n";
				}
				addVarToTempVector("\t" + $$.tipo + " " + $$.label + ";\n");
			}

			| TK_ID TK_UN_SUM
			{

				variable Var = searchForVariable($1.label);
				$$.tipo = Var.tipo;
				$$.traducao = "\t" + $1.label + " = " + $1.label + " + 1;\n";
			}

			| E '<' E
			{
				$$.label = genLabel();
				$$.tipo = "bool";
				//cout << "carai " << $1.traducao << endl;
				structAux aux = implicitConversion($1.tipo, $3.tipo, $1.label, $3.label);

				if(aux.varConvertida == $1.label){
					string abacate = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " < " + $3.label + ";\n";
					cout << "SAI DESSA MANO" << abacate << endl;
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " < " + $3.label + ";\n";
				}
				else if(aux.varConvertida == $3.label){
					string caraioo = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " < " + aux.nomeVar + ";\n";
					cout << "TODO DIA ISSO" << caraioo << endl;
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " < " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					
					cout << "carai " << $1.traducao << $3.traducao << "\t" << $$.label << " = " << $1.label << " < " << $3.label << ";\n";
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " < " + $3.label + ";\n";
					

				}

				addVarToTempVector("\tint " + $$.label + ";\n");
			}

			| E '>' E
			{
				$$.label = genLabel();
				$$.tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				structAux aux = implicitConversion($1.tipo, $3.tipo, $1.label, $3.label);

				if(aux.varConvertida == $1.label){
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " > " + $3.label + ";\n";
				}
				else if(aux.varConvertida == $3.label){
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " > " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " > " + $3.label + ";\n";
				}

				addVarToTempVector("\tint " + $$.label + ";\n");
			}

			| E TK_LE E
			{
				$$.label = genLabel();
				$$.tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				structAux aux = implicitConversion($1.tipo, $3.tipo, $1.label, $3.label);
				if(aux.varConvertida == $1.label){
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " <= " + $3.label + ";\n";
				}
				else if(aux.varConvertida == $3.label){
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " <= " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " <= " + $3.label + ";\n";
				}

				addVarToTempVector("\tint " + $$.label + ";\n");
			}

			| E TK_HE E
			{
				$$.label = genLabel();
				$$.tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				structAux aux = implicitConversion($1.tipo, $3.tipo, $1.label, $3.label);
				if(aux.varConvertida == $1.label){
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " >= " + $3.label + ";\n";
				}
				else if(aux.varConvertida == $3.label){
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " >= " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " >= " + $3.label + ";\n";
				}

				addVarToTempVector("\tint " + $$.label + ";\n");
			}

			| E '|' E
			{
				$$.label = genLabel();
				$$.tipo = isBoolean($1.tipo, $3.tipo);
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " || " + $3.label + ";\n";
				addVarToTempVector("\tint " + $$.label + ";\n");
			}

			| E '&' E
			{
				$$.label = genLabel();
				$$.tipo = isBoolean($1.tipo, $3.tipo);
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " && " + $3.label + ";\n";
				addVarToTempVector("\tint " + $$.label + ";\n");
			}

			| '!' E
			{
				$$ = $2;
				$$.tipo = isBoolean("bool", $2.tipo);
				$$.label = genLabel();
				$$.traducao = $2.traducao + "\t" + $$.label + " = !" + $2.label + ";\n";
				addVarToTempVector("\tint " + $$.label + ";\n");
			}

			| E TK_EQ E
			{
				$$.label = genLabel();
				$$.tipo = "bool";
				//cout << "SOU DO TIPO " << $$.tipo << endl;
				structAux aux = implicitConversion($1.tipo, $3.tipo, $1.label, $3.label);
				if(aux.varConvertida == $1.label){
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " == " + $3.label + ";\n";
				}
				else if(aux.varConvertida == $3.label){
					$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " == " + aux.nomeVar + ";\n";
				}
				else{ //se as duas variáveis são do mesmo tipo
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " == " + $3.label + ";\n";
				}

				addVarToTempVector("\tint " + $$.label + ";\n");
			}

			| E TK_DIFF E
			{
				$$.label = genLabel();
				$$.tipo = "bool";

				if(($1.tipo == "bool" && $3.tipo == "bool") || ($1.tipo == "char" && $3.tipo == "char")){

					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " != " + $3.label + ";\n";
				}

				else{

					structAux aux = implicitConversion($1.tipo, $3.tipo, $1.label, $3.label);
					if(aux.varConvertida == $1.label){
						$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + aux.nomeVar + " != " + $3.label + ";\n";
					}
					else if(aux.varConvertida == $3.label){
						$$.traducao = $1.traducao + $3.traducao + aux.implicita + "\t" + $$.label + " = " + $1.label + " != " + aux.nomeVar + ";\n";
					}
					else{ //se as duas variáveis são do mesmo tipo
						$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " != " + $3.label + ";\n";
					}
					addVarToTempVector("\tint " + $$.label + ";\n");
				}
			}

			| '(' E ')'
			{
				$$ = $2;
			}

			| TK_NUM
			{
				$$.label = "nomeTemporarioInt" + to_string(valorTemp++);
				$$.tipo = "int";
				addVarToTempVector("\t" + $$.tipo + " " + $$.label + ";\n");
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
			}

			| TK_FLOAT
		 	{
				$$.label = "nomeTemporarioFloat" + to_string(valorTemp++);
				$$.tipo = "float";
				addVarToTempVector("\tfloat " + $$.label + ";\n");
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
		 	}

			| TK_CHAR
			{
				$$.label = "nomeTemporarioChar" + to_string(valorTemp++);
				$$.tipo = "char";
				addVarToTempVector("\tchar "  + $$.label + ";\n");
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
			}

			| TK_BOOL
			{
				$$.label = "nomeTemporarioBool" + to_string(valorTemp++);
				$$.tipo = "bool";
				addVarToTempVector("\tint " + $$.label + ";\n");
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
			}

			| TK_STRING
			{
				$$.label = "nomeTemporarioString" + to_string(valorTemp++);
				$$.tipo = "string";
				addVarToTempVector("\tstring "  + $$.label + ";\n");
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
			}

			| TK_ID
			{
				variable auxVar = searchForVariable($1.label);
				$$.label = auxVar.nome;
				$$.tipo = auxVar.tipo;
				$$.traducao;
			}
			;
%%

#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{
	//yydebug = 1;
	yyparse();
	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}

string genLabel(){

	return "temp" + to_string(valorVar++);
}

string addVarToTabSym(string nomeDado, string conteudoVar, string tipoVar){

	checkForVariable(nomeDado);
	unordered_map<string, variable> tabSym = contextoVariaveis.back();
	cout << "\ntabSym antes " << (tabSym.empty() ? "is empty" : "is not empty" ) << endl;
	cout << "\nconteudo da variavel: " << conteudoVar << endl;
	unordered_map<string, variable>::const_iterator got = tabSym.find(nomeDado);
	string nomeGerado;

	if(got == tabSym.end()){

		variable Var2;
		nomeGerado = genLabel();

		Var2 =	{
					.tipo = tipoVar,
					.nome = nomeGerado,
					.valor = conteudoVar
		  		};

		tabSym[nomeDado] = Var2;
		contextoVariaveis.pop_back();
		contextoVariaveis.push_back(tabSym);
		cout << "tabSym depois " << (contextoVariaveis.empty() ? "is empty" : "is not empty" ) << endl;
		cout << "\nAdicionado " << tabSym[nomeDado].nome << " de tipo "<< tabSym[nomeDado].tipo <<" na tabela de simbolos " << mapAtual << "!\n" << endl;
		return tabSym[nomeDado].nome;
	}

	else {

		return tabSym[nomeDado].nome;
	}

	return "";
}

string addVarToGlobalTabSym(string nomeDado, string conteudoVar, string tipoVar){

	checkForVariable(nomeDado);
	//unordered_map<string, variable> tabSym = contextoVariaveis.back();
	cout << "\nglobalTabSym antes " << (globalTabSym.empty() ? "is empty" : "is not empty" ) << endl;
	unordered_map<string, variable>::const_iterator got = globalTabSym.find(nomeDado);
	string nomeGerado;

	if(got == globalTabSym.end()){

		variable Var;
		nomeGerado = genLabel();

		Var =	{
					.tipo = tipoVar,
				   	.nome = nomeGerado,
					.valor = conteudoVar
		  		};

		globalTabSym[nomeDado] = Var;
		//contextoVariaveis.pop_back();
		//ScontextoVariaveis.push_back(abSym);
		cout << "globalTabSym depois " << (globalTabSym.empty() ? "is empty" : "is not empty" ) << endl;
		cout << "\nAdicionado " << globalTabSym[nomeDado].nome << " de tipo "<< globalTabSym[nomeDado].tipo <<" na tabela global de simbolos!\n" << endl;
		return globalTabSym[nomeDado].nome;
	}

	/*else {

		return tabSym[nomeDado].nome;
	}*/

	return "";
}

void printGlobalVariables(){

	unordered_map<string, variable> auxMap = globalTabSym;

	for (auto& it: globalTabSym){

		addVarToGlobalTempVector("\t" + it.second.tipo + " " + it.second.nome + ";\n");
	}

	printGlobalVector();
}

structAux implicitConversion(string tipo0, string tipo1, string nome0, string nome1){

	if(tipo0 == "float" && tipo1 == "int"){ //se a primeira variável for float e segunda for int

		string nomeAuxID = "nomeTemporarioFloat" + to_string(valorTemp);
		addVarToTempVector("\tfloat " + nomeAuxID + ";\n");
		string stringRetorno = "\t" + nomeAuxID + " = (float) " + nome1 + ";\n";

		structAux aux = {

							.implicita = stringRetorno,
							.nomeVar = nomeAuxID,
							.varConvertida = nome1
						};

		return aux;
	}

	else if(tipo0 == "int" && tipo1 == "float") //se a primeira variável for int e a segunda for float
  	{

	  	string nomeAuxID = "nomeTemporarioFloat" + to_string(valorTemp);
		addVarToTempVector("\tfloat " + nomeAuxID + ";\n");
		string stringRetorno = "\t" + nomeAuxID + " = (float) " + nome0 + ";\n";

		structAux aux = {

							.implicita = stringRetorno,
							.nomeVar = nomeAuxID,
							.varConvertida = nome0
						};

		return aux;

  }

  else if(tipo0 == "float" && tipo1 == "float") //se as duas são float
  {

	string nomeAuxID = "nomeTemporarioFloat" + to_string(valorTemp);
	string stringRetorno = "";
	structAux aux = {

						.implicita = stringRetorno,
						.nomeVar = nomeAuxID,
						.varConvertida = nome0
					};
	return aux;
   }

  else if(tipo0 == "int" && tipo1 == "int") //se as duas são int
  {

	string nomeAuxID = "nomeTemporarioInt" + to_string(valorTemp);
	string stringRetorno = "";
	structAux aux = {

						.implicita = stringRetorno,
						.nomeVar = nomeAuxID,
						.varConvertida = nome0
					};
	return aux;
  }

  else
  {
    yyerror("Nao e possivel realizar operacoes com tipos nao numericos!\n");
  }
}

string explicitConversion(string tipo0, string tipo1){

	if (tipo0 == "char" || tipo0 == "bool")
	{
		yyerror("não é possivel converter em char ou booleano!\n");
	}

	else
	{
		string nomeAuxID = "nomeTemporario" + tipo1 + to_string(valorTemp);
    	addVarToTempVector("\t" + tipo1 + " " + nomeAuxID + ";\n");
    	return tipo1;
	}

	return "";
}

void addVarToTempVector(string nomeVar)
{
	tempVector.push_back(nomeVar);
}

void addVarToGlobalTempVector(string nomeVar)
{
	globalTempVector.push_back(nomeVar);
}

void printVector()
{
	for(auto i: tempVector)
	{
		cout << i;
	}
	cout << "\n\n" << endl;
}

void printGlobalVector()
{
	cout << "\n" << endl;
	for(auto i: globalTempVector)
	{
		cout << i;
	}
	cout << "\n\n" << endl;
}

string isBoolean(string tipo0, string tipo1)
{
	if (tipo1 != "bool" || tipo0 != "bool")
	{
		yyerror("Operacao logica sem tipo booleano!\n");
	}

	else{

		return "bool";
	}

	return "";
}

int erroTipo(string tipo0, string tipo1)
{
	if (tipo1 != tipo0)
	{
		yyerror("tipo de variaveis incompativeis\n");

	}
			return 0;
}

void addMapToStack(void){

	unordered_map<string, variable> auxMap;
	contextoVariaveis.push_back(auxMap);
	mapAtual++;
	cout << "adicionei o map de numero " << mapAtual << " na tabela de mapas!\n" << endl;
}

variable searchForVariable(string nome){

	int i = mapAtual; //inteiro para percorrer o vetor de mapas
	vector<unordered_map<string, variable>> auxVector; //vetor auxiliar para percorrer
	auxVector = contextoVariaveis; //atribuo o vetor de contexto global para o vetor auxiliar
	unordered_map<string, variable> auxMap; //mapa auxiliar para checar as variáveis dele

	cout << "\ncontextoVariaveis " << (contextoVariaveis.empty() ? "is empty" : "is not empty" ) << endl;
	cout << "quantidade de contextos: " << i << endl;
	cout << "variavel buscando: " << nome << endl;
	cout << "auxVector " << (auxVector.empty() ? "is empty" : "is not empty" ) << endl;

	for(i; i > 0; i--){

		auxMap = auxVector.back();
		auxVector.pop_back();

		cout << "auxMap search iteração " << i << " " << (auxMap.empty() ? "is empty" : "is not empty" ) << endl;

		unordered_map<string, variable>::const_iterator got = auxMap.find(nome); //procuro a variável pelo nome no map mais interno

		if(got != auxMap.end()){ //se esse if for verdade, quer dizer que encontrei a variável no map

			cout << "\n\nEncontrada variável!\nNome: " << nome << "\nTipo: " << auxMap[nome].tipo << endl;
			cout << "Conteudo: " << auxMap[nome].valor << endl;
			variable auxVar = auxMap[nome];
			return auxVar; //se for, retorno essa variável
		}
	}
}

void checkForVariable(string nome){

	int i = mapAtual; //inteiro para percorrer o vetor de mapas
	vector<unordered_map<string, variable>> auxVector; //vetor auxiliar para percorrer
	auxVector = contextoVariaveis; //atribuo o vetor de contexto global para o vetor auxiliar
	unordered_map<string, variable> auxMap; //mapa auxiliar para checar as variáveis dele

	cout << "\ncontextoVariaveis " << (contextoVariaveis.empty() ? "is empty" : "is not empty" ) << endl;
	cout << "quantidade de contextos: " << i << endl;
	cout << "variavel buscando: " << nome << endl;
	cout << "auxVector " << (auxVector.empty() ? "is empty" : "is not empty" ) << endl;

	for(i; i > 0; i--){

		auxMap = auxVector.back();
		auxVector.pop_back();

		cout << "auxMap check iteração " << i << " " << (auxMap.empty() ? "is empty" : "is not empty" ) << endl;

		unordered_map<string, variable>::const_iterator got = auxMap.find(nome); //procuro a variável pelo nome no map mais interno

		if(got != auxMap.end()){ //se esse if for verdade, quer dizer que encontrei a variável no map

			string errorMessage = "\n\nEncontrada variável!\nNome: " + nome + "\nTipo: " + auxMap[nome].tipo + "\n";
			yyerror(errorMessage);
		}
	}
}
