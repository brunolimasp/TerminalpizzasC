#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "MenuFinalizar.c"
#include "MenuEntregas.c"
#include "MenuRelatorios.c"

int venda_principal(){
	int opc;
	

	verde_limpar();
	logo();
	printf("\n");
	printf("\t>MENUPRINCIPAL\\VENDAS\n");
	printf("\t#################################################################\n\n");
	printf("\t\tFAÇA SEU PEDIDO ESCOLHENDO AS OPÇÕES:\n\n");
	printf("\t#################################################################\n\n");
	printf("\t[1] PEDIDO MESA | [2] ENTREGAS | [3] VOLTAR  \n\n");
	printf("\t#################################################################\n");
	printf("\n");
	printf("\t->");
	scanf("\t%d",&opc);

	switch (opc){
		case 1:
			verde_limpar();
			venda_produtos();
			break;
		case 2:
			verde_limpar();
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
					menu_principal();
					break;		
				case 2:
					verde_limpar();
					venda_principal();
					break;
			}
		default:
			verde_limpar();
			logo();
			printf("\t##########################################################\n\n");
			printf("\t\t\tOPÇÃO INVALIDA!!\n");
			printf("\t\t\tVESCOLHA UMA DAS 4 OPÇÕES ACIMA!\n\n");
			printf("\t##########################################################\n");
			sleep(2);
			venda_principal();
			break;
	}


}



int venda_produtos(){
	int cont, opc, i, linha;
	char tipo [40], codigo[10], quant[10], valor[10];

	verde_limpar();
	logo();
	printf("\n");
	printf("\t>MENUPRINCIPAL\\VENDAS\\PRODUTOS\n");
	printf("\t################################################################\n\n");
	printf("\t\tFAÇA SEU PEDIDO ESCOLHENDO AS OPÇÕES:\n\n");
	printf("\t################################################################\n\n");
	printf("\t[1] PIZZA | [2] BEBIDA | [3] CERVEJA | [4] FINALIZAR  \n\n");
	printf("\t################################################################\n");
	printf("\n");
	printf("\t->");
	scanf("\t%d",&opc);

	switch (opc){
		case 1:
			verde_limpar();
			pizza_venda();
			break;
		case 2:
			verde_limpar();
			bebida_venda();
			break;
		case 3:
			verde_limpar();
			cerveja_venda();
			break;
		case 4:
			verde_limpar();
			menu_finalizar();
			break;
		default:
			verde_limpar();
			logo();
			printf("\t##########################################################\n\n");
			printf("\t\t\tOPÇÃO INVALIDA!!\n");
			printf("\t\t\tVESCOLHA UMA DAS 4 OPÇÕES ACIMA!\n\n");
			printf("\t##########################################################\n");
			sleep(2);
			main();
			break;
	}


}

struct lista_venda // tipo de dado
{
	char tipo[40];
	int codigo;
	int quant;
	float valor;

}venda; // variavel usando o tipo de dado da struct global "STRUCT LISTAPIZZA"

	struct lista_venda vetorvenda [100];



pizza_venda(){

	int tam, opc, opc2, cod, i, cont, linha = 0, esc, baixa;

	char tipo [40], codigo[10], quant[10], valor[10];

	FILE *vendaler;

	verde_limpar();
	logo();

	vendaler = fopen("banco/estoquepizza.txt", "r");
	if(vendaler == NULL){
		printf("O ARQUIVO NAO PODE SER ABERTO!");
		getchar();
  		exit(1);
   	}
   	while(!feof(vendaler)){
		fgets(tipo, 40, vendaler);
		tipo[strcspn(tipo, "\n")] = '\0';

		fgets(codigo, sizeof(codigo), vendaler);
		fgets(quant, sizeof(quant), vendaler);
		fgets(valor, sizeof(valor), vendaler);

		strcpy(vetorvenda[i].tipo,tipo);
		vetorvenda[i].codigo = atoi(codigo);
		vetorvenda[i].quant = atoi(quant);
		vetorvenda[i].valor = atof(valor);
		i++;
	}

	printf("\n");
	printf("\t>MENUPRINCIPAL\\VENDAS\\VENDAPIZZA\n");
	printf("###############################################################################\n\n");
	printf("\tID      | SABOR                       | CÓDIGO | QUANTIDADE | VALOR \n\n");
	printf("###############################################################################\n\n");

	for(cont =0; cont <(i-1); cont++){
		printf("\t%*i\t%-*s\t%*i%*i%*.2f\n", 1, ++linha, 22, vetorvenda[cont].tipo, 11, vetorvenda[cont].codigo, 12, vetorvenda[cont].quant, 12, vetorvenda[cont].valor);

	}

	printf("###############################################################################\n\n");
	printf("\tESCOLHA O [ID] DA PIZZA: \n");
	printf("\t->");
	scanf("\t%d",&opc);
	opc--;
    //--------------------------------------------------------------------------------------------------------------
	verde_limpar();
	logo();
	printf("###############################################################################\n\n");
	printf("\tSABOR:       \t%s\n", vetorvenda[opc].tipo);
	printf("\tCÓDIGO:      \t%d\n", vetorvenda[opc].codigo);
	printf("\tQUANTIDADE:  \t%i\n", vetorvenda[opc].quant);
	printf("\tVALOR:       \t%.2f\n\n", vetorvenda[opc].valor);
	printf("###############################################################################\n\n");
	printf("\tQUANTIDADES: ");
	printf("\t->");
	scanf("\t%i",&baixa);
	
	vendaler = fopen("banco/Venda.txt", "a");
	fprintf(vendaler, "%s\n%i\n%i\n%.2f\n", strupr(vetorvenda[opc].tipo), vetorvenda[opc].codigo, baixa, vetorvenda[opc].valor);
	fclose(vendaler);
	
	//---------------------------------------------- PIZZAS MAIS VENDIDAS ------------------------------------------------
	vendaler = fopen("relatorio/maisvendidos.txt", "a");
	for(cont = 0; cont< baixa; ++cont){	
		fprintf(vendaler, "%i\n", vetorvenda[opc].codigo);
	}
	fclose(vendaler);
	
	//---------------------------------------------------------------------------------------------------------------------
	
	vendaler = fopen("temp/estoquepizzatemp.txt", "w");
	for(cont = 0; cont< (i-1); ++cont){
		fprintf(vendaler, "%s\n%i\n%i\n%.2f\n", strupr(vetorvenda[cont].tipo), vetorvenda[cont].codigo, vetorvenda[cont].quant, vetorvenda[cont].valor);
	}
	fclose(vendaler);
	
	vetorvenda[opc].quant = vetorvenda[cont].quant - baixa;
	vendaler = fopen("banco/estoquepizza.txt", "w");
	for(cont = 0; cont< (i-1); ++cont){
		fprintf(vendaler, "%s\n%i\n%i\n%.2f\n", strupr(vetorvenda[cont].tipo), vetorvenda[cont].codigo, vetorvenda[cont].quant, vetorvenda[cont].valor);
	}
	fclose(vendaler);
	venda_produtos();

}

bebida_venda(){

	int tam, opc, opc2, cod, i, cont, linha = 0, esc, baixa;

	char tipo [40], codigo[10], quant[10], valor[10];

	FILE *vendaler;

	verde_limpar();
	logo();

	vendaler = fopen("banco/estoquebebida.txt", "r");
	if(vendaler == NULL){
		printf("O ARQUIVO NAO PODE SER ABERTO!");
		getchar();
  		exit(1);
   	}
   	while(!feof(vendaler)){
		fgets(tipo, 40, vendaler);
		tipo[strcspn(tipo, "\n")] = '\0';

		fgets(codigo, sizeof(codigo), vendaler);
		fgets(quant, sizeof(quant), vendaler);
		fgets(valor, sizeof(valor), vendaler);

		strcpy(vetorvenda[i].tipo,tipo);
		vetorvenda[i].codigo = atoi(codigo);
		vetorvenda[i].quant = atoi(quant);
		vetorvenda[i].valor = atof(valor);
		i++;
	}

	printf("\n");
	printf("\t>MENUPRINCIPAL\\VENDAS\\VENDABEBIDA\n");
	printf("###############################################################################\n\n");
	printf("\tID      | SABOR                       | CÓDIGO | QUANTIDADE | VALOR \n\n");
	printf("###############################################################################\n\n");

	for(cont =0; cont <(i-1); cont++){
		printf("\t%*i\t%-*s\t%*i%*i%*.2f\n", 1, ++linha, 22, vetorvenda[cont].tipo, 11, vetorvenda[cont].codigo, 12, vetorvenda[cont].quant, 12, vetorvenda[cont].valor);

	}

	printf("###############################################################################\n\n");
	printf("\tESCOLHA O NUMERO DA BEBIDA: \n");
	printf("\t->");
	scanf("\t%d",&opc);
	opc--;
    //--------------------------------------------------------------------------------------------------------------
	verde_limpar();
	logo();
	printf("###############################################################################\n\n");
	printf("\tSABOR:       \t%s\n", vetorvenda[opc].tipo);
	printf("\tCÓDIGO:      \t%d\n", vetorvenda[opc].codigo);
	printf("\tQUANTIDADE:  \t%i\n", vetorvenda[opc].quant);
	printf("\tVALOR:       \t%.2f\n\n", vetorvenda[opc].valor);
	printf("###############################################################################\n\n");

	printf("QUANTIDADES: ");
	scanf("\t%i", &baixa);


	vendaler = fopen("banco/Venda.txt", "a");
	fprintf(vendaler, "%s\n%i\n%i\n%.2f\n", strupr(vetorvenda[opc].tipo), vetorvenda[opc].codigo, baixa, vetorvenda[opc].valor);
	fclose(vendaler);
	
	vendaler = fopen("temp/estoquebebidatemp.txt", "w");
	for(cont = 0; cont< (i-1); ++cont){
		fprintf(vendaler, "%s\n%i\n%i\n%.2f\n", strupr(vetorvenda[cont].tipo), vetorvenda[cont].codigo, vetorvenda[cont].quant, vetorvenda[cont].valor);
	}
	fclose(vendaler);

	vetorvenda[opc].quant = vetorvenda[cont].quant - baixa;
	vendaler = fopen("banco/estoquebebida.txt", "w");
	for(cont = 0; cont< (i-1); ++cont){
		fprintf(vendaler, "%s\n%i\n%i\n%.2f\n", strupr(vetorvenda[cont].tipo), vetorvenda[cont].codigo, vetorvenda[cont].quant, vetorvenda[cont].valor);
	}
	fclose(vendaler);
	venda_produtos();

}

cerveja_venda(){

	int tam, opc, opc2, cod, i, cont, linha = 0, esc, baixa;

	char tipo [40], codigo[10], quant[10], valor[10];

	FILE *vendaler;

	verde_limpar();
	logo();

	vendaler = fopen("banco/estoquecerveja.txt", "r");
	if(vendaler == NULL){
		printf("O ARQUIVO NAO PODE SER ABERTO!");
		getchar();
  		exit(1);
   	}
   	while(!feof(vendaler)){
		fgets(tipo, 40, vendaler);
		tipo[strcspn(tipo, "\n")] = '\0';

		fgets(codigo, sizeof(codigo), vendaler);
		fgets(quant, sizeof(quant), vendaler);
		fgets(valor, sizeof(valor), vendaler);

		strcpy(vetorvenda[i].tipo,tipo);
		vetorvenda[i].codigo = atoi(codigo);
		vetorvenda[i].quant = atoi(quant);
		vetorvenda[i].valor = atof(valor);
		i++;
	}

	printf("\n");
	printf("\t>MENUPRINCIPAL\\VENDAS\\VENDACERVEJA\n");
	printf("###############################################################################\n\n");
	printf("\tID      | SABOR                       | CÓDIGO | QUANTIDADE | VALOR \n\n");
	printf("###############################################################################\n\n");

	for(cont =0; cont <(i-1); cont++){
		printf("\t%*i\t%-*s\t%*i%*i%*.2f\n", 1, ++linha, 22, vetorvenda[cont].tipo, 11, vetorvenda[cont].codigo, 12, vetorvenda[cont].quant, 12, vetorvenda[cont].valor);
	}

	printf("###############################################################################\n\n");
	printf("\tESCOLHA O NUMERO DA CERVEJA: \n");
	printf("\t->");
	scanf("\t%d",&opc);
	opc--;
    //--------------------------------------------------------------------------------------------------------------
	verde_limpar();
	logo();
	printf("###############################################################################\n\n");
	printf("\tSABOR:       \t%s\n", vetorvenda[opc].tipo);
	printf("\tCÓDIGO:      \t%d\n", vetorvenda[opc].codigo);
	printf("\tQUANTIDADE:  \t%i\n", vetorvenda[opc].quant);
	printf("\tVALOR:       \t%.2f\n\n", vetorvenda[opc].valor);
	printf("###############################################################################\n\n");

	printf("QUANTIDADES: ");
	scanf("\t%i", &baixa);

	
	vendaler = fopen("banco/Venda.txt", "a");
	fprintf(vendaler, "%s\n%i\n%i\n%.2f\n", strupr(vetorvenda[opc].tipo), vetorvenda[opc].codigo, baixa, vetorvenda[opc].valor);
	fclose(vendaler);
	
	vendaler = fopen("temp/estoquecervejatemp.txt", "w");
	for(cont = 0; cont< (i-1); ++cont){
		fprintf(vendaler, "%s\n%i\n%i\n%.2f\n", strupr(vetorvenda[cont].tipo), vetorvenda[cont].codigo, vetorvenda[cont].quant, vetorvenda[cont].valor);
	}
	fclose(vendaler);

	vetorvenda[opc].quant = vetorvenda[cont].quant - baixa;
	vendaler = fopen("banco/estoquecerveja.txt", "w");
	for(cont = 0; cont< (i-1); ++cont){
		fprintf(vendaler, "%s\n%i\n%i\n%.2f\n", strupr(vetorvenda[cont].tipo), vetorvenda[cont].codigo, vetorvenda[cont].quant, vetorvenda[cont].valor);
	}

	fclose(vendaler);
	venda_produtos();

}


