#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

limparlixo3() {
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
struct lista_cadastro3 // tipo de dado
	{
		char tipo[40];
		int codigo;
		int quant; 
		float valor;
		
		
	}cervejas; // variavel usando o tipo de dado da struct global "STRUCT LISTACERVEJA"
	
	struct lista_cadastro3 cadastro3 [100];
//--------------------------------------------------------------------------------------------



//SETOR DE FUNÇÃO CADASTRO "MENU PRINCIPAL"
//--------------------------------------------------------------------------------------------

int cervejas_menu()
{	// Variaves desta função:
	; // vairiavel para laço "DO WHILE"
	int opc, opcsair; // variavel para "SWITCH CASE"
	
	
	 
	
	// Sub menu cadastro da opção "CERVEJA"
	verde_limpar();
	logo();
	printf("\n");
	printf("\t>MENUPRINCIPAL\\ESTOQUEEPRODUTOS\\CADASTROCERVEJA\n");
	printf("###############################################################################\n\n");
	printf("\t\t\t   CADASTRO - CERVEJA	   		\n\n");
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
			cerveja_cadastro();
			verde_limpar();
			logo();
			printf("\n\n");
			printf("\t\t\tCADASTRO REALIZADO COM SUCESSO!");
			break;
		case 2:
			verde_limpar();
			logo();
			cerveja_editar();
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
					
					cervejas_menu();// VOLTAR PARA CERVEJA MENU DO PROGRAMA**
					break;
				default:
					verde_limpar();
					logo();
					printf("###############################################################################\n\n");
					printf("\t\t\tOPÇÃO INVALIDA!!\n");
					printf("\t\t\tVOLTANDO PARA O MENU CADASTRO CERVEJA...\n\n");
					printf("###############################################################################\n");
					sleep(1);
					
					cervejas_menu();
					break;
			}
			break;
		
		default:
			verde_limpar();
			logo();
			printf("###############################################################################\n\n");
			printf("\t\t\tOPÇÃO INVALIDA!!\n");
			printf("\t\t\tVOLTANDO PARA O MENU CADASTRO CERVEJA..\n\n");
			printf("###############################################################################\n");
			sleep(1);
			cervejas_menu();
			break;	
	}


}


	
//SETOR DE TODAS AS FUNÇÕES DO CADASTRO "CERVEJA"
//--------------------------------------------------------------------------------------------
int cerveja_cadastro(){
	
	
		int opc;
	
	do{
		verde_limpar();
		logo();
		FILE *cerveja = fopen("banco/estoquecerveja.txt", "a");
		if(cerveja == NULL){
        	printf("O ARQUIVO NÃO PODE SER ABERTO!\n");
        	printf("REDIRECIONADO PARA MENU DE CADASTRO...");
			sleep(2);
			cerveja_cadastro();
    	}
		
		limparlixo3();
    	printf("\tMARCA: ");
		gets(cervejas.tipo);
    	
		printf("\tCODIGO: ");
    	scanf("%d", &cervejas.codigo);
    			    
    	printf("\tQUANTIDADE: ");
    	scanf("%d", &cervejas.quant);
    	
    	
		printf("\tPRECO: ");
    	scanf("%f", &cervejas.valor);
	    
	    
		fprintf(cerveja, "%s \n%d\n%d\n%.2f\n", strupr(cervejas.tipo), cervejas.codigo, cervejas.quant, cervejas.valor);

		
		
		printf("\n");
			printf("###############################################################################\n\n");
			printf("\tPRODUTO CADASTRADO:\n");
			printf("###############################################################################\n\n");
			printf("\tMARCA CADASTRADO:      %s\n", cervejas.tipo);
			printf("\tCODIGO CADASTRADO:     %d\n", cervejas.codigo);
			printf("\tQUANTIDADE CADASTRADA: %d\n", cervejas.quant);
			printf("\tPRECO CADASTRADO:      R$%.2f\n\n", cervejas.valor);
			printf("###############################################################################\n");
			fclose(cerveja);
			
		printf("\tDESEJA CADASTRAR OUTRO PRODUTO?\n \t[1] SIM\n \t[2] NAO\n");
		printf("\t->");
		scanf("\t%d",&opc);
	}while(opc == 1);
		verde_limpar();
		cervejas_menu();
			
}

int cerveja_editar(){
	
	
		int tam, opc, j, cod, i, cont, linha = 0, esc;
		
		char tipo [40], codigo[10], quant[10], valor[10];
		
		FILE *cervejaler;
		
		verde_limpar();
		logo();
		printf("\n");
		printf("\t>MENUPRINCIPAL\\ESTOQUEEPRODUTOS\\CADASTROCERVEJA\\LISTAREDITAR\n");
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
				cervejaler = fopen("banco/estoquecerveja.txt", "r");
				if(cervejaler == NULL){
                	printf("O ARQUIVO NÃO PODE SER ABERTO!\n");
                	printf("REDIRECIONADO PARA MENU DE CADASTRO...");
		        	sleep(2);
		        	cerveja_cadastro();
    	        }
    			while(!feof(cervejaler)){
				fgets(tipo, 40, cervejaler);
				tipo[strcspn(tipo, "\n")] = '\0';
			
				fgets(codigo, sizeof(codigo), cervejaler);
				fgets(quant, sizeof(quant), cervejaler);
				fgets(valor, sizeof(valor), cervejaler);
									
				strcpy(cadastro3[i].tipo,tipo);
				cadastro3[i].codigo = atoi(codigo);
				cadastro3[i].quant = atoi(quant);
				cadastro3[i].valor = atof(valor);
				i++;
				}
				
				printf("\n");
				printf("###############################################################################\n\n");
				printf("\tID      | SABOR                       | CÓDIGO | QUANTIDADE | VALOR \n\n");
				printf("###############################################################################\n\n");

				for(cont =0; cont <(i-1); cont++){
					printf("\t%*i\t%-*s\t%*i%*i%*.2f\n", 1, ++linha, 22, cadastro3[cont].tipo, 11, cadastro3[cont].codigo, 12, cadastro3[cont].quant, 12, cadastro3[cont].valor);
				}
					
				
				printf("###############################################################################\n");
				printf("\n");
				printf("###############################################################################\n");
				printf("\t\t\t[1] SAIR	 	\n\n");
				printf("###############################################################################\n");
				printf("\t\n");
				printf("\t->");
				scanf("\t%d",&opc);
				
				switch (opc){
					case 1:
						verde_limpar();
						cerveja_editar();		
						break;	
					default:
						verde_limpar();
						logo();
						printf("###############################################################################\n\n");
						printf("\t\t\tOPÇÃO INVALIDA!!\n");
						printf("\t\t\tVOLTANDO PARA O MENU LISTA / EDITAR...\n\n");
						printf("###############################################################################\n");
						sleep(1);
						cerveja_editar();
						break;
				}
				break;	
			case 2:
				verde_limpar();
				logo();
				
				cervejaler = fopen("banco/estoquecerveja.txt", "r");
				if(cervejaler == NULL){
                    printf("O ARQUIVO NÃO PODE SER ABERTO!\n");
                    printf("REDIRECIONADO PARA MENU DE CADASTRO...");
		            sleep(2);
		            cerveja_cadastro();
    	        }
    			while(!feof(cervejaler)){
				fgets(tipo, 40, cervejaler);
				tipo[strcspn(tipo, "\n")] = '\0';
			
				fgets(codigo, sizeof(codigo), cervejaler);
				fgets(quant, sizeof(quant), cervejaler);
				fgets(valor, sizeof(valor), cervejaler);
			
						
				strcpy(cadastro3[i].tipo,tipo);
				cadastro3[i].codigo = atoi(codigo);
				cadastro3[i].quant = atoi(quant);
				cadastro3[i].valor = atof(valor);
				i++;
				}
		
				printf("\n");
				printf("###############################################################################\n\n");
				printf("\tID      | SABOR                       | CÓDIGO | QUANTIDADE | VALOR \n\n");
				printf("###############################################################################\n\n");

				for(cont =0; cont <(i-1); cont++){
					printf("\t%*i\t%-*s\t%*i%*i%*.2f\n", 1, ++linha, 22, cadastro3[cont].tipo, 11, cadastro3[cont].codigo, 12, cadastro3[cont].quant, 12, cadastro3[cont].valor);
				}
		
				printf("###############################################################################\n\n");
				printf("\tESCOLHA O NUMERO DA CERVEJA: ");
				printf("\n\t##[");
				scanf("\t%d", &opc);
				fflush(stdin);
				opc--;
		
				printf("###############################################################################\n\n");
		
				verde_limpar();
				logo();
				printf("###############################################################################\n\n");
		
				do{			
					printf("ANTIGO MARCA: %s\n", cadastro3[opc].tipo);
					printf("DIGITE UM MARCA: ");
					gets(cadastro3[opc].tipo);
					tam = strlen(cadastro3[opc].tipo);
					if(tam >= 15){
						printf("###SO E PERMITIDO 14 CARACTERES!!###");
					}	
				}while(tam >= 15);
													
				printf("ANTIGO CODIGO: %d\n", cadastro3[opc].codigo);
				printf("DIGITE UM NOVO CODIGO: ");
				scanf("%d%*c", &cadastro3[opc].codigo);
				fflush(stdin);
	
				printf("ANTIGA QUANTIDADE: %d\n", cadastro3[opc].quant);
				printf("DIGITE UMA QUANTIDADE: ");
				scanf("%d%*c", &cadastro3[opc].quant);		
		
				printf("ANTIGO VALOR: %.2f\n", cadastro3[opc].valor);
				printf("DIGITE UM VALOR: ");
				scanf("%f%*c", &cadastro3[opc].valor);
		
				printf("###############################################################################\n\n");
				
				cervejaler = fopen("banco/estoquecerveja.txt", "w");
		
				for(cont = 0; cont< (i-1); ++cont){
					fprintf(cervejaler, "%s\n%d\n%d\n%.2f\n", strupr(cadastro3[cont].tipo),cadastro3[cont].codigo, cadastro3[cont].quant, cadastro3[cont].valor);
				}
				fclose(cervejaler);
				cervejas_menu();
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
						cervejas_menu();// VOLTAR PARA CERVEJA MENU DO PROGRAMA**
						break;		
					case 2:
						verde_limpar();
						cerveja_editar();// VOLTAR PARA CERVEJA EDITAR DO PROGRAMA**
						break;
					default:
						verde_limpar();
						logo();
						printf("###############################################################################\n\n");
						printf("\t\t\tOPÇÃO INVALIDA!!\n");
						printf("\t\t\tVOLTANDO PARA O MENU LISTAR / EDITAR...\n\n");
						printf("###############################################################################\n");
						sleep(1);
						cerveja_editar();
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
				cerveja_editar();
				break;
				
		}
	}
	

