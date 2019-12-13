#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "CadastroPizza.c"
#include "CadastroBebidas.c"
#include "CadastroCervejas.c"

//------------------------------------------------------------------------------------------
//	FUN합ES PINCIPAIS 
//------------------------------------------------------------------------------------------
verde_limpar()
{
	system("cls");
	system("color 2");
}
//SETOR DE FUN플O CADASTRO "MENU PRINCIPAL"
menu_cadastro()
{
	int opc;
	
	verde_limpar();
	logo();
	printf("\n");
	printf("\t>MENUPRINCIPAL\\ESTOQUEEPRODUTOS\n");
	printf("\t##########################################################\n");
	printf("\t\t\t  ESTOQUE E PRODUTOS   	\n");
	printf("\t##########################################################\n");
	printf("\t\t\t [1] PIZZA	 		\n");
	printf("\t\t\t [2] BEBIDAS 			\n");
	printf("\t\t\t [3] CERVEJAS 		\n");
	printf("\t\t\t [4] VOLTAR 			\n");
	printf("\t##########################################################\n");
	printf("\n");
	printf("\t->");
	scanf("\t%d",&opc);
	
	switch(opc){	
		case 1:
			verde_limpar();
			logo();
			int pizza_menu();
			pizza_menu();
			break;
		case 2:
			verde_limpar();
			logo();
			bebida_menu();
			break;
		case 3:
			verde_limpar();
			logo();
			cervejas_menu();
			break;
	    case 4:
			verde_limpar();
			logo();
			printf("\n");
			printf("\tDESEJA REALMENTE SAIR?\n \t[1] SIM\n \t[2] NAO\n");
			printf("\t->");
			scanf("\t%d",&opc);
			
			switch (opc)
			{
				case 1:
					verde_limpar();
					menu_principal();// VOLTAR PARA MENU PRINCIAL DO PROGRAMA**
					break;		
				case 2:
					verde_limpar();
					menu_cadastro();// VOLTAR PARA MENU ESTOQUE E PRODUTOS DO PROGRAMA**
					break;
				default:
					verde_limpar();
					logo();
					printf("\t##########################################################\n");
					printf("\t\t\tOP플O INVALIDA!!\n");
					printf("\t\t\tVOLTANDO PARA O MENU CADASTRO...\n");
					printf("\t##########################################################\n");
					sleep(1);
					menu_cadastro();
					break;
			}
			default:
				verde_limpar();
				logo();
				printf("\t##########################################################\n");
				printf("\t\t\tOP플O INVALIDA!!\n");
				printf("\t\t\tVOLTANDO PARA O MENU CADASTRO...\n");
				printf("\t##########################################################\n");
				sleep(1);
				menu_cadastro();
				break;
	}
	
	printf("\n");
	
	system("pause");		
}
//-------------------------------------------------------------------------------------------





