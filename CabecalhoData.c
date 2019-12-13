#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>


void inserirCabecalhoData()
{
	char cabecalho_data[11];
    char dateStr[9];
	int opc;


	printf("\t#################################################################\n\n");
    printf("\tBEM VINDO!\n");
    printf("\t#################################################################\n\n");
	printf("  \t ", _strdate( dateStr ));
    printf("\tESTE E O PRIMEIRO ACESSO AO SISTEMA HOJE? \n\t[1]SIM, VOU INSERIR A DATA PARA INICIAR ATENDIMENTO \n\t[2]NAO\n");
    printf("\t#################################################################\n\n");
    printf("\n");
	printf("\t->");
	scanf("\t%d",&opc);

    verde_limpar();
    logo();
    //SE FOR O PRIMEIRO ACESSO DO DIA, FAÇA ABAIXO
    if(opc == 1)
	{
		printf("\t#################################################################\n\n");
		printf("\tINSIRA POR FAVOR A DATA DO DIA CORRENTE PARA A ORGANIZAÇÃO \n\tDAS VENDAS.\n");
		printf("\tATENÇÃO: IMPORTANTE INSERIR A DATA NESTE EXATO FORMATO COM A \n\tTECLA UNDERLINE ' _ ' SEPARANDO\n");
		printf("\tFORMATO: DD_MM_YYYY: ");
		//getchar();
	    //gets(cabecalho_data);
		printf("\t#################################################################\n\n");
	    FILE *pizza = fopen( _strdate( dateStr ),"a");
	    if(pizza == NULL)
	    {
	        printf("ERROR...");
	    }

			/*//SE O ARQUIVO ABRIR
			fprintf(pizza, "________________________________________\n");
		    fprintf(pizza, "\t\t%s\n", cabecalho_data);
		    fprintf(pizza, "________________________________________\n");
		    fclose(pizza);*/


	}else{
		//SE NÃO FOR O PRIMEIRO ACESSO DO DIA
		// chamar menu pricipal

		int venda_principal();
		venda_principal();
		printf("Menu Principal");
	}

}


