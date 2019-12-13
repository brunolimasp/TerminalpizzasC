#include <locale.h>
#include <tchar.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include "CadastroUsuarios.c"
#include "Feedback.c"
#include "MenuCadastro.c"
#include "RegistroAdm.c"
#include "CabecalhoData.c"
#include "Venda.c"
#include "Data.c"


int main(){


	logo();
	void tela();
 	tela();
	return 0;
}


int opcaologin;
void tela (){
	setlocale(LC_ALL,"");
    tela:
    system("cls");
    logo();
	printf("\n\t\t\tESCOLHA SEU TIPO DE USUARIO\n\n");
	printf("###############################################################################\n\n");
	printf("\t\tUSUARIO COMUM [1]\t\tUSUARIO ADM [2]\n\n");
	printf("###############################################################################\n\n");
    printf("\t\t->");
    scanf ("%d", &opcaologin);
    if (opcaologin == 1){
    	system("cls");
		login();
	}
	if (opcaologin == 2){
		system("cls");
		logina();
	}
    else {
        tela();
    }
	system ("pause");
}


int logo(){

	char dateStr[9];
	char timeStr[9];

	printf("\n\t\t\t\t   V 2.0.0 E");
    printf("\n");
    system("color A");
    printf("\n\t######## ######## ########  ##     ## #### ##    ##    ###    ##\n");
    printf("\t   ##    ##       ##     ## ###   ###  ##  ###   ##   ## ##   ##\n");
    printf("\t   ##    ##       ##     ## #### ####  ##  ####  ##  ##   ##  ##\n");
    printf("\t   ##    ######   ########  ## ### ##  ##  ## ## ## ##     ## ##\n");
    printf("\t   ##    ##       ##   ##   ##     ##  ##  ##  #### ######### ##\n");
    printf("\t   ##    ##       ##    ##  ##     ##  ##  ##   ### ##     ## ##\n");
    printf("\t   ##    ######## ##     ## ##     ## #### ##    ## ##     ## ########\n\n");
    printf("\t >PIZZAS_\n\n\n");


	// pega a data atual
	//_strdate( dateStr);
	//printf_s( "\t\t\t\t%s", dateStr);
	DataAgora();

	// pega a hora atual
	_strtime( timeStr );
	printf_s( "%s\n", timeStr);

	return(0);
}

void load(){
	system("cls");
	logo();
	system("color 17");
	printf("\n\n\nCONECTANDO NO BANCO DE DADOS...\n");
	printf(">>>>>>>>>\n");
	printf(">>>>>>>>>");
	sleep(1);
	system("cls");
	logo();
	system("color 17");
	printf("\n\n\nCARREGANDO MODULOS...\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	sleep(1);
	system("cls");
	logo();
	system("color 17");
	printf("\n\n\nVERIFICANDO SISTEMA...\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	sleep(1);
	system("cls");
	logo();
	system("color 17");
	printf("\n\n\nINICIANDO...\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	sleep(1);
	system("cls");

}


//-------------------VALIDA USUARIO COMUM---------------

int login() {

	inicio:
	printf("\n");
	FILE *file;
	file = fopen("banco/comum.txt","r");
	if(file == NULL){
		printf("FALHA NA CONEXAO COM O BANCO DE DADOS");
	}

	char nome[20],senha[9];
	char dados[100];
	char *sub;
	int cont = 0;

	logo();
	printf("\t\t################## LOGIN ###################### \n");
	printf("\t\t->");
	scanf("%s",nome);
	while(fgets(dados,100,file) !=NULL){
		cont = cont + 1 ;
		sub = strtok(dados,"\n");
	//	printf(sub);
			while(sub != NULL){
				//printf("%s",sub);
				sub = strtok(NULL,"\n");
				if(strcmp(nome,dados) == 0){
					printf("\t\t############ DIGITE SUA SENHA ################# \n");
					printf("\t\t->");
					scanf("%s",senha);
					while(fgets(dados,100,file) !=NULL){
						sub = strtok(dados,"\n");
						while(sub != NULL){
						//	printf("%s",sub);
							sub = strtok(NULL,"\n");
							if(strcmp(senha,dados) == 0){
								menu_principal(); // PROGRAMA INICIA AQUI
							}else{
								system("color 4");
								printf("---- SENHA OU USUARIO INCORRETOS ----");
							}
						}
					}
				}else{
				//	printf(" JOGA LA P CIMAAAAAAAA");
			}
		}
	}
	system("cls");
	printf("\n\t\t--------- SENHA OU USUARIO INCORRETO  -------------");
	goto inicio;
	return 0;
}
//-------------------VALIDA USUARIO ADM---------------
int logina() {
	inicio:
	printf("\n");
	FILE *file;
	file = fopen("banco/adm.txt","r");
	if(file == NULL){
		printf("FALHA NA CONEXAO COM O BANCO DE DADOS");
	}
	char nome[20],senha[9];
	char dados[100];
	char *sub;
	int cont = 0;
	logo();
	printf("\t\t################## LOGIN ###################### \n");
	printf("\t\t->");
	scanf("%s",nome);
	while(fgets(dados,100,file) !=NULL){
		cont = cont + 1 ;
		sub = strtok(dados,"\n");
	//	printf(sub);
			while(sub != NULL){
				//printf("%s",sub);
				sub = strtok(NULL,"\n");
				if(strcmp(nome,dados) == 0){
					printf("\t\t############ DIGITE SUA SENHA ################# \n");
					printf("\t\t->");
					scanf("%s",senha);
					while(fgets(dados,100,file) !=NULL){
						sub = strtok(dados,"\n");
						while(sub != NULL){
						//	printf("%s",sub);
							sub = strtok(NULL,"\n");
							if(strcmp(senha,dados) == 0){
								menu_principal(); // PROGRAMA INICIA AQUI
							}else{
								system("color 4");
								printf("---- SENHA OU USUARIO INCORRETOS ----");
							}
						}
					}
				}else{
				//	printf(" JOGA LA P CIMAAAAAAAA");
			}
		}
	}
	fclose(file);
	system("cls");
	printf("\n\t\t--------- SENHA OU USUARIO INCORRETO  -------------");
	goto inicio;
	return 0;
}



//	FUNï¿½ï¿½ES PINCIPAIS
//------------------------------------------------------------------------------------------


//SETOR DE FUNï¿½ï¿½O CADASTRO "MENU PRINCIPAL"
//--------------------------------------------------------------------------------------------
int menu_principal(){
	int opc;
	verde_limpar();
	load();
	logo();
	

	printf("\n");
	printf("\t>MENUPRINCIPAL\n");
	printf("###############################################################################\n\n");
	if(opcaologin == 2){
		printf("\t\t\t [0] REGISTRAR NOVO USUARIO\n");
	}

	printf("\t\t\t [1] VENDAS	 	\n");
	printf("\t\t\t [2] REGISTRAR FEEDBACK DE CLIENTES 	\n");
	printf("\t\t\t [3] ESTOQUE E PRODUTOS 	\n");
	printf("\t\t\t [4] RELATÓRIO DE VENDAS\n");
	printf("\t\t\t [5] VOLTAR   	\n\n");
	printf("###############################################################################\n\n");
	printf("\n");
	printf("\t->");
	scanf("\t%d",&opc);
// SE O USUARIO FOR ADM VAI ENTRAR NESSE CASE
	if(opcaologin == 2){

		switch(opc){
		case 0:
			logo();
			mainCadastroUsuario();
			break;
		default:
			system("cls");
			printf("\t\t\tOPÇÃO INVALIDA!!\n");
			printf("\t\t\tVOLTANDO PARA O MENU PRINCIPAL...\n");
			break;
		}
	}


	switch(opc){
		case 1:
			system("cls");
			logo();
			//inserirCabecalhoData();
			verde_limpar();
			venda_principal();
			break;
		case 2:
			system("cls");
			logo();
			feedback();
			break;
		case 3:
			system("cls");
			logo();
			menu_cadastro();
			break;
		case 4:
			verde_limpar();
			menu_relatorios();
			break;
	    case 5:
			system("cls");
			logo();
			printf("\n");
			printf("\tDESEJA REALMENTE SAIR?\n \t[1] SIM\n \t[2] NAO\n");
			printf("\t->");
			scanf("\t%d",&opc);


			switch (opc){
				case 1:
					system("cls");
					logo();
					printf("###############################################################################\n\n");
					printf("\t\t\tVFAZENDO LOGOFF...\n\n");
					printf("###############################################################################\n\n");
					sleep(1);
					main();// VOLTAR PARA O INICIO DO PROGRAMA**
					break;
				case 2:
					system("cls");
					logo();
					printf("###############################################################################\n\n");
					printf("\t\t\tVOLTANDO PARA O MENU PRINCIPAL...\n\n");
					printf("###############################################################################\n\n");
					sleep(1);
					menu_principal();
					break;
				default:
					system("cls");
					logo();
					printf("###############################################################################\n\n");
					printf("\t\t\tOPÇÃO INVALIDA!!\n");
					printf("\t\t\tVOLTANDO PARA O MENU PRINCIPAL...\n\n");
					printf("###############################################################################\n\n");
					sleep(1);
					menu_principal();
					break;
			}
			break;

		default:
			system("cls");
			logo();
			printf("###############################################################################\n\n");
			printf("\t\t\tOPÇÃO INVALIDA!!\n");
			printf("\t\t\tVOLTANDO PARA O MENU PRINCIPAL...\n\n");
			printf("###############################################################################\n\n");
			sleep(1);
			menu_principal();
			break;
	}

	printf("\n");

	system("pause");
	return 0;
}
//--------------------------------------------------------------------------------------------

int opcuser(){
	system("cls");
	logo();
	printf("###############################################################################\n\n");
	printf("\t\t\t [0] CADASTRAR ADM\n");
	printf("\t\t\t [1] CADASTRAR USUARIO COMUM\n\n");
	printf("###############################################################################\n\n");
}

//SETOR DE FUNï¿½ï¿½O CADASTRO "MENU PRINCIPAL"
//--------------------------------------------------------------------------------------------
















