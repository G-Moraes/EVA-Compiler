
















/*Compilador Eva*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

int main(void)
{
	int nomeTemporarioInt0;
	int temp0;
	int nomeTemporarioInt1;
	int temp1;
	int nomeTemporarioInt2;
	int temp2;
	int temp4;
	int temp5;



	nomeTemporarioInt0 = 10;
	temp0 = nomeTemporarioInt0;
	nomeTemporarioInt1 = 0;
	temp1 = nomeTemporarioInt1;

//for

	nomeTemporarioInt1 = 0;
	temp1 = nomeTemporarioInt1;
	nomeTemporarioInt2 = 10;
	temp2 = temp1 < nomeTemporarioInt2;

	comeco1:

	loop1: temp2 = temp1 < nomeTemporarioInt2;
temp5 = !temp2;
	if(temp5) goto final1;
	std::cout  <<10;
	temp1 = temp1 + 1;

	goto loop1;
	final1:




	return 0;
}

