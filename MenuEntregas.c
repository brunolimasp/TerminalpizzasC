#include <locale.h>
#include <tchar.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

menu_entregas(){
	int opc;
	
	verde_limpar();
	logo();
	printf("\n");
	printf("\t>MENUPRINCIPAL\\VENDAS\\ENTREGAS\n");
	printf("\t#################################################################\n\n");
	printf("\t\tFAÇA SEU PEDIDO ESCOLHENDO AS OPÇÕES:\n\n");
	printf("\t#################################################################\n\n");
	printf("\t[1] CADASTRAR | [2] LISTAR / EDITAR | [3] FINALIZAR | [4] VOLTAR \n\n");
	printf("\t#################################################################\n");
	printf("\n");
	printf("\t->");
	scanf("\t%d",&opc);
	
	switch (opc){
		case 1:
			verde_limpar();
			cadastro_cliente();
			break;
		case 2:
			verde_limpar();
			cliente_editar();
			break;
		case 3:
			verde_limpar();
			cliente_finalizar();
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
					venda_principal();
					break;		
				case 2:
					verde_limpar();
					menu_entregas();
					break;
			}
		default:
			verde_limpar();
			logo();
			printf("\t##########################################################\n\n");
			printf("\t\t\tOPÇÃO INVALIDA!!\n");
			printf("\t\t\tVESCOLHA UMA DAS 2 OPÇÕES ACIMA!\n\n");
			printf("\t##########################################################\n");
			sleep(1);
			menu_entregas();
			break;
	}
	
}


struct cadastro_cliente // tipo de dado
	{

		char nome[40];
		char telefone[40];
		char endereco[40];


	}cliente; // variavel usando o tipo de dado da struct global "STRUCT LISTAPIZZA"

	struct cadastro_cliente vetorcliente [1000];
	
cadastro_cliente(){
	
	char nome[40], telefone[40], endereco[40];
	int opc;
	
	do{
		verde_limpar();
		logo();
		FILE *listacliente = fopen("banco/clientes.txt", "a");
		if(listacliente == NULL){
        	printf("O ARQUIVO NÃO PODE SER ABERTO!\n");
       		printf("REDIRECIONADO PARA MENU DE CADASTRO...");
			sleep(2);
			menu_entregas();
    	}
		
		limparlixo1();
    	printf("\tNOME: ");
		gets(cliente.nome);
   	 	
		printf("\tTELEFONE: ");
    	gets(cliente.telefone);
    		    
    	printf("\tENDEREÇO: ");
    	gets(cliente.endereco);
    	
		fprintf(listacliente, "%s \n%s \n%s \n", strupr(cliente.nome), cliente.telefone, strupr(cliente.endereco));

		
		
		printf("\n");
		printf("###############################################################################\n\n");
		printf("\tCLIENTE CADASTRADO:\n\n");
		printf("###############################################################################\n\n");
		printf("\tNOME CADASTRADO:      %s\n", cliente.nome);
		printf("\tTELEFONE CADASTRADO:  %s\n", cliente.telefone);
		printf("\tENDEREÇO CADASTRADA:  %s\n", cliente.endereco);
		printf("###############################################################################\n");
		fclose(listacliente);
			
		printf("\tDESEJA CADASTRAR OUTRO PRODUTO?\n \t[1] SIM\n \t[2] NAO\n");
		printf("\t->");
		scanf("\t%d",&opc);
	}while(opc == 1);
	
		verde_limpar();
		menu_entregas();
			
}

int cliente_editar(){
	
	
		int tam, opc, j, cod, i, cont, linha = 0, esc;
		
		char nome[40], telefone[40], endereco[40];
		
		FILE *clienteler;
		
		verde_limpar();
		logo();
		printf("\t>MENUPRINCIPAL\\VENDAS\\ENTREGAS\\LISTAR / EDITAR\n");
		printf("###############################################################################\n\n");
		printf("\t\t\t LISTAR / EDITAR		 			\n\n");
		printf("###############################################################################\n\n");
		printf("\t\t\t [1] LISTAR	 					\n");
		printf("\t\t\t [2] EDITAR						\n");
		printf("\t\t\t [3] VOLTAR 						\n\n");
		printf("###############################################################################\n");
		printf("\n");
		printf("\t->");
		scanf("\t%d",&opc);
						
		switch (opc){
			case 1:
				verde_limpar();
				logo();
				clienteler = fopen("banco/clientes.txt", "r");
				if(clienteler == NULL){
        	        printf("O ARQUIVO NÃO PODE SER ABERTO!\n");
        	        printf("REDIRECIONADO PARA MENU DE CADASTRO...");
		            sleep(2);
		            menu_entregas();
    			}
    			while(!feof(clienteler)){
				fgets(nome, 40, clienteler);
				nome[strcspn(nome, "\n")] = '\0';
				
				fgets(telefone, 40, clienteler);
				telefone[strcspn(telefone, "\n")] = '\0';
				
				fgets(endereco, 40, clienteler);
				endereco[strcspn(endereco, "\n")] = '\0';
			
				
									
				strcpy(vetorcliente[i].nome,nome);
				strcpy(vetorcliente[i].telefone,telefone);
				strcpy(vetorcliente[i].endereco,endereco);
				
				
				i++;
				}
		
				printf("\n");
				printf("###############################################################################\n\n");
				printf("\tID      | CLIENTES                        \n\n");
				printf("###############################################################################\n\n");

				for(cont =0; cont <(i-1); cont++){
					printf("\t%i\n", ++linha);
					printf("\t%s\n", vetorcliente[cont].nome);
					printf("\t%s\n", vetorcliente[cont].telefone);
					printf("\t%s\n", vetorcliente[cont].endereco);
					printf("-----------------------------------------\n");
				}
				printf("###############################################################################\n\n");
				printf("\t\t[1] SAIR	 	\n\n");
				printf("###############################################################################\n");
				printf("\t\n");
				printf("\t->");
				scanf("\t%d",&opc);
				
				switch (opc){
					case 1:
						verde_limpar();
						cliente_editar();		
						break;	
					default:
						verde_limpar();
						logo();
						printf("###############################################################################\n\n");
						printf("\t\t\tOPÇÃO INVALIDA!!\n");
						printf("\t\t\tVOLTANDO PARA O MENU LISTA / EDITAR...\n\n");
						printf("###############################################################################\n");
						sleep(1);
						menu_entregas();
						break;
				}
				break;	
			case 2:
				verde_limpar();
				logo();
				
				clienteler = fopen("banco/clientes.txt", "r");
				if(clienteler == NULL){
        	        printf("O ARQUIVO NÃO PODE SER ABERTO!\n");
        	        printf("REDIRECIONADO PARA MENU DE CADASTRO...");
		            sleep(2);
		            menu_entregas();
    			}
    			while(!feof(clienteler)){
				fgets(nome, 40, clienteler);
				nome[strcspn(nome, "\n")] = '\0';
				
				fgets(telefone, 40, clienteler);
				telefone[strcspn(telefone, "\n")] = '\0';
				
				fgets(endereco, 40, clienteler);
				endereco[strcspn(endereco, "\n")] = '\0';
			
				
									
				strcpy(vetorcliente[i].nome,nome);
				strcpy(vetorcliente[i].telefone,telefone);
				strcpy(vetorcliente[i].endereco,endereco);
				
				
				i++;
				}
				
			printf("\n");
				printf("###############################################################################\n\n");
				printf("\tID      | CLIENTES                        \n\n");
				printf("###############################################################################\n\n");

				for(cont =0; cont <(i-1); cont++){
					printf("\t%i\n", ++linha);
					printf("\t%s\n", vetorcliente[cont].nome);
					printf("\t%s\n", vetorcliente[cont].telefone);
					printf("\t%s\n", vetorcliente[cont].endereco);
					printf("-----------------------------------------\n");
				}
				printf("###############################################################################\n\n");
				
				printf("\t\n");
				printf("\t->");
				scanf("\t%d",&opc);
				fflush(stdin);
				opc--;
		
				printf("###############################################################################\n\n");
		
				verde_limpar();
				logo();
				printf("###############################################################################\n\n");
						
					printf("ANTIGO NOME: %s\n", vetorcliente[opc].nome);
					printf("DIGITE UM NOVO NOME: ");
					gets(vetorcliente[opc].nome);
					
						
					printf("ANTIGO TELEFONE: %s\n", vetorcliente[opc].telefone);
					printf("DIGITE UM NOVO TELEFONE: ");
					gets(vetorcliente[opc].telefone);
				
					
					printf("ANTIGO ENDEREÇO: %s\n", vetorcliente[opc].endereco);
					printf("DIGITE UM NOVO ENDEREÇO: ");
					gets(vetorcliente[opc].endereco);
					
	
				printf("###############################################################################\n\n");
				
				clienteler = fopen("banco/cliente.txt", "w");
		
				for(cont = 0; cont< (i-1); ++cont){
					fprintf(clienteler, "%s\n%s\n%s\n",vetorcliente[opc].nome, vetorcliente[opc].telefone, vetorcliente[opc].endereco);
				}
				fclose(clienteler);
				menu_entregas();
				break;		
			case 3:
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
						menu_entregas();;// VOLTAR PARA MENU ENTREGAS DO PROGRAMA**
						break;		
					case 2:
						verde_limpar();
						cliente_editar();// VOLTAR PARA MENU CLIENTE EDITAR DO PROGRAMA**
						break;
					default:
						verde_limpar();
						logo();
						printf("###############################################################################\n\n");
						printf("\t\t\tOPÇÃO INVALIDA!!\n");
						printf("\t\t\tVOLTANDO PARA O MENU LISTAR / EDITAR...\n\n");
						printf("###############################################################################\n");
						sleep(1);
						cliente_editar();
						break;
				}
			
			default:
				verde_limpar();
				logo();
				printf("###############################################################################\n\n");
				printf("\t\t\tOPÇÃO INVALIDA!!\n");
				printf("\t\t\tVOLTANDO PARA O MENU LISTA / EDITAR...\n\n");
				printf("###############################################################################\n");
				sleep(1);
				cliente_editar();
				break;
				
		}
	}
	
cliente_finalizar(){
	
	int tam, opc, h, cod, i, cont, linha = 0, esc;
	char nome[40], telefone[40], endereco[40];
	
	verde_limpar();
	logo();
	FILE *clienteler = fopen("banco/clientes.txt", "r");
	if(clienteler == NULL){
        printf("O ARQUIVO NÃO PODE SER ABERTO!\n");
        printf("REDIRECIONADO PARA MENU DE CADASTRO...");
	    sleep(2);
	    menu_entregas();
    }
    while(!feof(clienteler)){
    	
		fgets(nome, 40, clienteler);
		nome[strcspn(nome, "\n")] = '\0';
		fgets(telefone, 40, clienteler);
		telefone[strcspn(telefone, "\n")] = '\0';
		fgets(endereco, 40, clienteler);
		endereco[strcspn(endereco, "\n")] = '\0';
		strcpy(vetorcliente[i].nome,nome);
		strcpy(vetorcliente[i].telefone,telefone);
		strcpy(vetorcliente[i].endereco,endereco);
		i++;
	}
		
	printf("\n");
	printf("###############################################################################\n\n");
	printf("\tID      | CLIENTES                        \n\n");
	printf("###############################################################################\n\n");

	for(cont =0; cont <(i-1); cont++){
		printf("\t%i\n", ++linha);
		printf("\t%s\n", vetorcliente[cont].nome);
		printf("\t%s\n", vetorcliente[cont].telefone);
		printf("\t%s\n", vetorcliente[cont].endereco);
		printf("-----------------------------------------\n");
	}
	printf("###############################################################################\n\n");
	
	printf("\t\n");
	printf("\t->");
	scanf("\t%d",&opc);
	fflush(stdin);
	opc--;
	
	printf("###############################################################################\n\n");
	
	verde_limpar();
	logo();
	
	printf("###############################################################################\n\n");			
	clienteler = fopen("pedido/pedido.txt", "a");
	fprintf(clienteler, "--------------------\nENTREGAR PARA:\n%s\n%s\n%s\n--------------------\n",vetorcliente[opc].nome, vetorcliente[opc].telefone, vetorcliente[opc].endereco);
	
	fclose(clienteler);
	
	printf("\n");
	
	printf("\tCLIENTE ADICIONADO COM SUCESSO NO PEDIDO!\n\n");
	
	printf("###############################################################################\n\n");
	sleep(6);
	menu_entregas();
	

	}

