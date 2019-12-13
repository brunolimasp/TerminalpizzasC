#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

limparlixo1() {
  int ch;

	do
	{
	ch = getchar();
	}while (ch != EOF && ch != '\n');

clearerr(stdin);
}

//--------------------------------------------------------------------------------------------

//	STRUTURA PRINCIPAL 
//--------------------------------------------------------------------------------------------
struct lista_cadastro1 // tipo de dado
	{
		char tipo[40];
		int codigo;
		int quant; 
		float valor;
		
		
	}pizzas; // variavel usando o tipo de dado da struct global "STRUCT LISTAPIZZA"
	
	struct lista_cadastro1 cadastro1 [100];
//--------------------------------------------------------------------------------------------



//SETOR DE FUNÇÃO CADASTRO "MENU PRINCIPAL"
//--------------------------------------------------------------------------------------------

int pizza_menu()
{	// Variaves desta função:
	; // vairiavel para laço "DO WHILE"
	int opc, opcsair; // variavel para "SWITCH CASE"
	
	
	 
	
	// Sub menu cadastro da opção "PIZZA"
	verde_limpar();
	logo();
	printf("\n");
	printf("\t>MENUPRINCIPAL\\ESTOQUEEPRODUTOS\\CADASTROPIZZA\n");
	printf("###############################################################################\n\n");
	printf("\t\t\t   CADASTRO - PIZZA		   		\n\n");
	printf("###############################################################################\n\n");
	printf("\t\t\t [1] CADASTRAR	 				\n");
	printf("\t\t\t [2] LISTAR / EDITAR				\n");
	printf("\t\t\t [3] VOLTAR 						\n\n");
	printf("###############################################################################\n");
	printf("\n");
	printf("\t->");
	scanf("\t%d",&opc);
	switch(opc){	
		case 1:
			verde_limpar();
			logo();
			int pizza_cadastro();
			pizza_cadastro();
			verde_limpar();
			logo();
			printf("\n\n");
			printf("\t\t\tCADASTRO REALIZADO COM SUCESSO!");
			break;
		case 2:
			verde_limpar();
			logo();
			int pizza_editar();
			pizza_editar();
			break;
			
	    case 3:
			verde_limpar();
			logo();
			printf("\n");
			printf("\tDESEJA REALMENTE SAIR?\n \t[1] SIM\n \t[2] NAO\n");
			printf("\t->");
			scanf("\t%d",&opc);
			
			
			switch (opc){
				case 1:
					verde_limpar();
					menu_cadastro();// VOLTAR PARA MENU PRINCIAL DO PROGRAMA**
					break;		
				case 2:
					verde_limpar();
					pizza_menu();// VOLTAR PARA pizza menu DO PROGRAMA**
					break;
				default:
					verde_limpar();
					logo();
					printf("###############################################################################\n\n");
					printf("\t\t\tOPÇÃO INVALIDA!!\n");
					printf("\t\t\tVOLTANDO PARA O MENU CADASTRO PIZZA...\n\n");
					printf("###############################################################################\n");
					sleep(1);
					pizza_menu();
					break;
			}
			break;
		
		default:
			verde_limpar();
			logo();
			printf("###############################################################################\n\n");
			printf("\t\t\tOPÇÃO INVALIDA!!\n");
			printf("\t\t\tVOLTANDO PARA O MENU CADASTRO PIZZA...\n\n");
			printf("###############################################################################\n");
			sleep(1);
			pizza_menu();
			break;	
	}

	return (0);
}


	
//SETOR DE TODAS AS FUNÇÕES DO CADASTRO "PIZZA"
//--------------------------------------------------------------------------------------------
int pizza_cadastro(){
	
	
		int opc;
	
	do{
		verde_limpar();
		logo();
		FILE *pizza = fopen("banco/estoquepizza.txt", "a");
		if(pizza == NULL){
            printf("O ARQUIVO NÃO PODE SER ABERTO!\n");
        	printf("REDIRECIONADO PARA MENU DE CADASTRO...");
			sleep(2);
			pizza_cadastro();
    	}
		
		limparlixo1();
    	printf("\tSABOR: ");
		gets(pizzas.tipo);
    	
		printf("\tCODIGO: ");
    	scanf("%d", &pizzas.codigo);
    			    
    	printf("\tQUANTIDADE: ");
    	scanf("%d", &pizzas.quant);
    	
    	
		printf("\tPRECO: ");
    	scanf("%f", &pizzas.valor);
	    
	    
		fprintf(pizza, "%s \n%d\n%d\n%.2f\n", strupr(pizzas.tipo), pizzas.codigo, pizzas.quant, pizzas.valor);

		
		
		printf("\n");
			printf("###############################################################################\n\n");
			printf("\tPRODUTO CADASTRADO:\n\n");
			printf("###############################################################################\n\n");
			printf("\tSABOR CADASTRADO:      %s\n", pizzas.tipo);
			printf("\tCODIGO CADASTRADO:     %d\n", pizzas.codigo);
			printf("\tQUANTIDADE CADASTRADA: %d\n", pizzas.quant);
			printf("\tPRECO CADASTRADO:      R$%.2f\n\n", pizzas.valor);
			printf("###############################################################################\n");
			fclose(pizza);
			
		printf("\tDESEJA CADASTRAR OUTRO PRODUTO?\n \t[1] SIM\n \t[2] NAO\n");
		printf("\t->");
		scanf("\t%d",&opc);
	}while(opc == 1);
		verde_limpar();
		pizza_menu();
			
}

int pizza_editar(){
	
	
		int tam, opc, j, cod, i, cont, linha = 0, esc;
		
		char tipo [40], codigo[10], quant[10], valor[10];
		
		FILE *pizzaler;
		
		verde_limpar();
		logo();
		printf("\t>MENUPRINCIPAL\\ESTOQUEEPRODUTOS\\CADASTROPIZZA\\LISTAREDITAR\n");
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
				pizzaler = fopen("banco/estoquepizza.txt", "r");
				if(pizzaler == NULL){
        	        printf("O ARQUIVO NÃO PODE SER ABERTO!\n");
        	        printf("REDIRECIONADO PARA MENU DE CADASTRO...");
		            sleep(2);
		            pizza_cadastro();
    			}
    			while(!feof(pizzaler)){
				fgets(tipo, 40, pizzaler);
				tipo[strcspn(tipo, "\n")] = '\0';
			
				fgets(codigo, sizeof(codigo), pizzaler);
				fgets(quant, sizeof(quant), pizzaler);
				fgets(valor, sizeof(valor), pizzaler);
									
				strcpy(cadastro1[i].tipo,tipo);
				cadastro1[i].codigo = atoi(codigo);
				cadastro1[i].quant = atoi(quant);
				cadastro1[i].valor = atof(valor);
				i++;
				}
		
				printf("\n");
				printf("###############################################################################\n\n");
				printf("\tID      | SABOR                       | CÓDIGO | QUANTIDADE | VALOR \n\n");
				printf("###############################################################################\n\n");

				for(cont =0; cont <(i-1); cont++){
					printf("\t%*i\t%-*s\t%*i%*i%*.2f\n", 1, ++linha, 22, cadastro1[cont].tipo, 11, cadastro1[cont].codigo, 12, cadastro1[cont].quant, 12, cadastro1[cont].valor);
				}
				printf("###############################################################################\n\n");
				
				printf("###############################################################################\n\n");
				printf("\t\t[1] SAIR	 	\n\n");
				printf("###############################################################################\n");
				printf("\t\n");
				printf("\t->");
				scanf("\t%d",&opc);
				
				switch (opc){
					case 1:
						verde_limpar();
						pizza_editar();		
						break;	
					default:
						verde_limpar();
						logo();
						printf("###############################################################################\n\n");
						printf("\t\t\tOPÇÃO INVALIDA!!\n");
						printf("\t\t\tVOLTANDO PARA O MENU LISTA / EDITAR...\n\n");
						printf("###############################################################################\n");
						sleep(1);
						pizza_editar();
						break;
				}
				break;	
			case 2:
				verde_limpar();
				logo();
				
				pizzaler = fopen("banco/estoquepizza.txt", "r");
				if(pizzaler == NULL){
        			printf("O ARQUIVO NÃO PODE SER ABERTO!\n");
        	        printf("REDIRECIONADO PARA MENU DE CADASTRO...");
			        sleep(2);
			        pizza_cadastro();
    			}
    			while(!feof(pizzaler)){
				fgets(tipo, 40, pizzaler);
				tipo[strcspn(tipo, "\n")] = '\0';
			
				fgets(codigo, sizeof(codigo), pizzaler);
				fgets(quant, sizeof(quant), pizzaler);
				fgets(valor, sizeof(valor), pizzaler);
			
						
				strcpy(cadastro1[i].tipo,tipo);
				cadastro1[i].codigo = atoi(codigo);
				cadastro1[i].quant = atoi(quant);
				cadastro1[i].valor = atof(valor);
				i++;
				}
				
				printf("\n");
				printf("###############################################################################\n\n");
				printf("\tID      | SABOR                       | CÓDIGO | QUANTIDADE | VALOR \n\n");
				printf("###############################################################################\n\n");

				for(cont =0; cont <(i-1); cont++){
					printf("\t%*i\t%-*s\t%*i%*i%*.2f\n", 1, ++linha, 22, cadastro1[cont].tipo, 11, cadastro1[cont].codigo, 12, cadastro1[cont].quant, 12, cadastro1[cont].valor);
				}
				
		
				printf("###############################################################################\n\n");
				printf("\tESCOLHA O NUMERO DA PIZZA: ");
				printf("\n\t##[");
				scanf("\t%d", &opc);
				fflush(stdin);
				opc--;
		
				printf("###############################################################################\n\n");
		
				verde_limpar();
				logo();
				printf("###############################################################################\n\n");
		
				do{			
					printf("ANTIGO SABOR: %s\n", cadastro1[opc].tipo);
					printf("DIGITE UM SABOR: ");
					gets(cadastro1[opc].tipo);
					tam = strlen(cadastro1[opc].tipo);
					if(tam >= 15)
					{
						printf("###SÓ É PERMITIDO 14 CARACTERES!!###");
					}	
				}while(tam >= 15);
													
				printf("ANTIGO CODIGO: %d\n", cadastro1[opc].codigo);
				printf("DIGITE UM NOVO CODIGO: ");
				scanf("%d%*c", &cadastro1[opc].codigo);
				fflush(stdin);
	
				printf("ANTIGA QUANTIDADE: %d\n", cadastro1[opc].quant);
				printf("DIGITE UMA QUANTIDADE: ");
				scanf("%d%*c", &cadastro1[opc].quant);		
		
				printf("ANTIGO VALOR: %.2f\n", cadastro1[opc].valor);
				printf("DIGITE UM VALOR: ");
				scanf("%f%*c", &cadastro1[opc].valor);
		
				printf("###############################################################################\n\n");
				
				pizzaler = fopen("banco/estoquepizza.txt", "w");
		
				for(cont = 0; cont< (i-1); ++cont){
					fprintf(pizzaler, "%s\n%d\n%d\n%.2f\n", strupr(cadastro1[cont].tipo),cadastro1[cont].codigo, cadastro1[cont].quant, cadastro1[cont].valor);
				}
				fclose(pizzaler);
				pizza_menu();
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
						pizza_menu();// VOLTAR PARA PIZZA MENU DO PROGRAMA**
						break;		
					case 2:
						verde_limpar();
						pizza_editar();// VOLTAR PARA PIZZA EDITAR DO PROGRAMA**
						break;
					default:
						verde_limpar();
						logo();
						printf("###############################################################################\n\n");
						printf("\t\t\tOPÇÃO INVALIDA!!\n");
						printf("\t\t\tVOLTANDO PARA O MENU LISTAR / EDITAR...\n\n");
						printf("###############################################################################\n");
						sleep(1);
						pizza_editar();
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
				pizza_editar();
				break;
				
		}
	}
	
		

