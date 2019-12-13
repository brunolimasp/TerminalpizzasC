#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

limparlixo2() 
{
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
struct lista_cadastro2 // tipo de dado
	{
		char tipo[40];
		int codigo;
		int quant; 
		float valor;
		
		
	}bebidas; // variavel usando o tipo de dado da struct global "STRUCT LISTABEBIDA"
	
	struct lista_cadastro2 cadastro2 [100];
//--------------------------------------------------------------------------------------------



//SETOR DE FUNÇÃO CADASTRO "MENU PRINCIPAL"
//--------------------------------------------------------------------------------------------

int bebida_menu()
{	// Variaves desta função:
	; // vairiavel para laço "DO WHILE"
	int opc, opcsair; // variavel para "SWITCH CASE"
	
	
	 
	
	// Sub menu cadastro da opção "BEBIDA"
	verde_limpar();
	logo();
	printf("\n");
	printf("\t>MENUPRINCIPAL\\ESTOQUEEPRODUTOS\\CADASTROBEBIDA\n");
	printf("###############################################################################\n\n");
	printf("\t\t\t   CADASTRO - BEBIDA		   		\n\n");
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
			int bebida_cadastro();
			bebida_cadastro();
			verde_limpar();
			logo();
			printf("\n\n");
			printf("\t\t\tCADASTRO REALIZADO COM SUCESSO!");
			break;
		case 2:
			verde_limpar();
			logo();
			int bebida_editar();
			bebida_editar();
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
					bebida_menu();// VOLTAR PARA BEBIDA menu DO PROGRAMA**
					break;
				default:
					verde_limpar();
					logo();
					printf("###############################################################################\n\n");
					printf("\t\t\tOPÇÃO INVALIDA!!\n");
					printf("\t\t\tVOLTANDO PARA O MENU CADASTRO BEBIDAS...\n\n");
					printf("###############################################################################\n");
					sleep(1);
					bebida_menu();
					break;
			}
			break;
		
		default:
			verde_limpar();
			logo();
		printf("###############################################################################\n\n");
			printf("\t\t\tOPÇÃO INVALIDA!!\n");
			printf("\t\t\tVOLTANDO PARA O MENU CADASTRO DE BEBIDAS...\n\n");
			printf("###############################################################################\n");
			sleep(1);
			bebida_menu();
			break;	
	}

	return (0);
}


	
//SETOR DE TODAS AS FUNÇÕES DO CADASTRO "BEBIDAS"
//--------------------------------------------------------------------------------------------
int bebida_cadastro(){
	
	
		int opc;
	
	do{
		verde_limpar();
		logo();
		FILE *bebida = fopen("banco/estoquebebida.txt", "a");
		if(bebida == NULL){
            printf("O ARQUIVO NÃO PODE SER ABERTO!\n");
        	printf("REDIRECIONADO PARA MENU DE CADASTRO...");
			sleep(2);
			bebida_cadastro();
    	}
		
		limparlixo2();
    	printf("\tSABOR: ");
		gets(bebidas.tipo);
    	
		printf("\tCODIGO: ");
    	scanf("%d", &bebidas.codigo);
    			    
    	printf("\tQUANTIDADE: ");
    	scanf("%d", &bebidas.quant);
    	
    	
		printf("\tPRECO: ");
    	scanf("%f", &bebidas.valor);
	    
	    
		fprintf(bebida, "%s \n%d\n%d\n%.2f\n", strupr(bebidas.tipo), bebidas.codigo, bebidas.quant, bebidas.valor);

		
		
		printf("\n");
			printf("###############################################################################\n\n");
			printf("\tPRODUTO CADASTRADO:\n\n");
			printf("###############################################################################\n\n");
			printf("\tSABOR CADASTRADO:      %s\n", bebidas.tipo);
			printf("\tCODIGO CADASTRADO:     %d\n", bebidas.codigo);
			printf("\tQUANTIDADE CADASTRADA: %d\n", bebidas.quant);
			printf("\tPRECO CADASTRADO:      R$%.2f\n\n", bebidas.valor);
			printf("###############################################################################\n");
			fclose(bebida);
			
		printf("\tDESEJA CADASTRAR OUTRO PRODUTO?\n \t[1] SIM\n \t[2] NAO\n");
		printf("\t->");
		scanf("\t%d",&opc);
	}while(opc == 1);
		verde_limpar();
		bebida_menu();
			
}

int bebida_editar(){
	
	
		int tam, opc, j, cod, i, cont, linha = 0, esc;
		
		char tipo [40], codigo[10], quant[10], valor[10];
		
		FILE *bebidaler;
		
		verde_limpar();
		logo();
		printf("\n");
		printf("\t>MENUPRINCIPAL\\ESTOQUEEPRODUTOS\\CADASTROBEBIDA\\LISTAREDITAR\n");
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
				bebidaler = fopen("banco/estoquebebida.txt", "r");
				if(bebidaler == NULL){
        		    printf("O ARQUIVO NÃO PODE SER ABERTO!\n");
        	        printf("REDIRECIONADO PARA MENU DE CADASTRO...");
			        sleep(2);
			        bebida_cadastro();
    			}
    			while(!feof(bebidaler)){
				fgets(tipo, 40, bebidaler);
				tipo[strcspn(tipo, "\n")] = '\0';
			
				fgets(codigo, sizeof(codigo), bebidaler);
				fgets(quant, sizeof(quant), bebidaler);
				fgets(valor, sizeof(valor), bebidaler);
									
				strcpy(cadastro2[i].tipo,tipo);
				cadastro2[i].codigo = atoi(codigo);
				cadastro2[i].quant = atoi(quant);
				cadastro2[i].valor = atof(valor);
				i++;
				}
		
				printf("\n");
				printf("###############################################################################\n\n");
				printf("\tID      | SABOR                       | CÓDIGO | QUANTIDADE | VALOR \n\n");
				printf("###############################################################################\n\n");

				for(cont =0; cont <(i-1); cont++){
					printf("\t%*i\t%-*s\t%*i%*i%*.2f\n", 1, ++linha, 22, cadastro2[cont].tipo, 11, cadastro2[cont].codigo, 12, cadastro2[cont].quant, 12, cadastro2[cont].valor);
				}
				
				printf("###############################################################################\n\n");
			
				printf("###############################################################################\n\n");
				printf("\t\t\t[1] SAIR	 	\n\n");
				printf("###############################################################################\n");
				printf("\t\n");
				printf("\t->");
				scanf("\t%d",&opc);
				
				switch (opc){
					case 1:
						verde_limpar();
						bebida_editar();		
						break;	
					default:
						verde_limpar();
						logo();
						printf("###############################################################################\n\n");
						printf("\t\t\tOPÇÃO INVALIDA!!\n");
						printf("\t\t\tVOLTANDO PARA O MENU LISTA / EDITAR...\n\n");
						printf("###############################################################################\n");
						sleep(1);
						bebida_editar();
						break;
				}
				break;	
			case 2:
				verde_limpar();
				logo();
				
				bebidaler = fopen("banco/estoquebebida.txt", "r");
				if(bebidaler == NULL){
        			printf("O ARQUIVO NÃO PODE SER ABERTO!\n");
        	        printf("REDIRECIONADO PARA MENU DE CADASTRO...");
			        sleep(2);
			        bebida_cadastro();
    			}
    			while(!feof(bebidaler)){
				fgets(tipo, 40, bebidaler);
				tipo[strcspn(tipo, "\n")] = '\0';
			
				fgets(codigo, sizeof(codigo), bebidaler);
				fgets(quant, sizeof(quant), bebidaler);
				fgets(valor, sizeof(valor), bebidaler);
			
						
				strcpy(cadastro2[i].tipo,tipo);
				cadastro2[i].codigo = atoi(codigo);
				cadastro2[i].quant = atoi(quant);
				cadastro2[i].valor = atof(valor);
				i++;
				}
		
				printf("\n");
				printf("###############################################################################\n\n");
				printf("\tID      | SABOR                       | CÓDIGO | QUANTIDADE | VALOR \n\n");
				printf("###############################################################################\n\n");

				for(cont =0; cont <(i-1); cont++){
					printf("\t%*i\t%-*s\t%*i%*i%*.2f\n", 1, ++linha, 22, cadastro2[cont].tipo, 11, cadastro2[cont].codigo, 12, cadastro2[cont].quant, 12, cadastro2[cont].valor);
				}				
		
				printf("###############################################################################\n\n");
				printf("\tESCOLHA O NUMERO DA BEBIDA: ");
				printf("\n\t##[");
				scanf("\t%d", &opc);
				fflush(stdin);
				opc--;
		
				printf("###############################################################################\n\n");
		
				verde_limpar();
				logo();
				printf("###############################################################################\n\n");
		
				do{			
					printf("ANTIGO SABOR: %s\n", cadastro2[opc].tipo);
					printf("DIGITE UM SABOR: ");
					gets(cadastro2[opc].tipo);
					tam = strlen(cadastro2[opc].tipo);
					if(tam >= 15)
					{
						printf("###SO E PERMITIDO 14 CARACTERES!!###");
					}	
				}while(tam >= 15);
													
				printf("ANTIGO CODIGO: %d\n", cadastro2[opc].codigo);
				printf("DIGITE UM NOVO CODIGO: ");
				scanf("%d%*c", &cadastro2[opc].codigo);
				fflush(stdin);
	
				printf("ANTIGA QUANTIDADE: %d\n", cadastro2[opc].quant);
				printf("DIGITE UMA QUANTIDADE: ");
				scanf("%d%*c", &cadastro2[opc].quant);		
		
				printf("ANTIGO VALOR: %.2f\n", cadastro2[opc].valor);
				printf("DIGITE UM VALOR: ");
				scanf("%f%*c", &cadastro2[opc].valor);
		
				printf("###############################################################################\n\n");
				
				bebidaler = fopen("banco/estoquebebida.txt", "w");
		
				for(cont = 0; cont< (i-1); ++cont){
					fprintf(bebidaler, "%s\n%d\n%d\n%.2f\n", strupr(cadastro2[cont].tipo),cadastro2[cont].codigo, cadastro2[cont].quant, cadastro2[cont].valor);
				}
				fclose(bebidaler);
				bebida_menu();
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
						bebida_menu();// VOLTAR PARA BEBIDA MENU DO PROGRAMA**
						break;		
					case 2:
						verde_limpar();
						bebida_editar();// VOLTAR PARA BEBIDA EDITAR DO PROGRAMA**
						break;
					default:
						verde_limpar();
						logo();
						printf("###############################################################################\n\n");
						printf("\t\t\tOPÇÃO INVALIDA!!\n");
						printf("\t\t\tVOLTANDO PARA O MENU LISTAR / EDITAR...\n\n");
						printf("###############################################################################\n");
						sleep(1);
						bebida_editar();
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
				bebida_editar();
				break;
				
		}
	}
	

