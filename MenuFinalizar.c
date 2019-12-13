#include <locale.h>
#include <tchar.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "GerarNumerosAleatorios.c"

struct lista_finalizar // tipo de dado
	{

		char tipo[40];
		int codigo;
		int quant;
		float valor;
        float total;


	}finalizar; // variavel usando o tipo de dado da struct global "STRUCT LISTAPIZZA"

	struct lista_finalizar vetorfinalizar [1000];



menu_finalizar(){

    int tam, opc, j, cod, i, cont, linha = 0, esc, numeros[100], parcela = 1;
    char data[10], tipo[100], codigo[10], quant[10], valor[10], dateStr[9], timeStr[9], leitor [1000];
    float vfinal = 0,dinheiro = 0, cartao = 0, troco = 0, dinheiro1 = 0;
    
	FILE *finalizarler;

	
	finalizarler = fopen("banco/Venda.txt", "r");
	if(finalizarler == NULL){
      	printf("O ARQUIVO NÃO PODE SER ABERTO!\n");
    	printf("REDIRECIONADO PARA MENU DE CADASTRO...");

    }

    while(!feof(finalizarler)){
    fgets(tipo, 40, finalizarler);
	tipo[strcspn(tipo, "\n")] = '\0';

	fgets(codigo, sizeof(codigo), finalizarler);
	fgets(quant, sizeof(quant), finalizarler);
	fgets(valor, sizeof(valor), finalizarler);

	strcpy(vetorfinalizar[i].tipo,tipo);
	vetorfinalizar[i].codigo = atoi(codigo);
	vetorfinalizar[i].quant = atoi(quant);
	vetorfinalizar[i].valor = atof(valor);
	vetorfinalizar[i].total = vetorfinalizar[i].quant * vetorfinalizar[i].valor;

	i++;
	}
	fclose(finalizarler);
	verde_limpar();
	logo();
	printf("\n");
	printf("\t>MENUPRINCIPAL\\VENDAS\\FINALIZAR\n");
	printf("###############################################################################\n\n");
	printf("\t\t\tFECHAMENTO DO PEDIDO  \n\n");
	printf("###############################################################################\n");
	printf("| SABOR                       | CÓDIGO | QUANTIDADE | VALOR |   TOTAL \n");
	printf("###############################################################################\n");

	for(cont =0; cont <(i-1); cont++){

		printf("|%-*s\t%*i%*i%*.2f%*.2f\n", 22, vetorfinalizar[cont].tipo, 11, vetorfinalizar[cont].codigo, 12, vetorfinalizar[cont].quant, 12, vetorfinalizar[cont].valor, 10, vetorfinalizar[cont].total);

	}
    printf("###############################################################################\n\n");
    for(i =0; i < cont ; i++){
        vfinal = vfinal + vetorfinalizar[i].total;
    }
    printf("\t\tVALOR TOTAL: R$%.2f\n", vfinal);
    printf("###############################################################################\n\n");

	
	finalizarler = fopen("pedido/Pedido.txt", "w");
	fprintf(finalizarler, "TERMINAL >PIZZAS_\n");
	time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    fprintf(finalizarler, "%d/%d/%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    _strtime( timeStr );
	fprintf(finalizarler, "%s\n", timeStr);
	fprintf(finalizarler, "--------------------\n");
	fclose(finalizarler);
	FILE *arq1;
	FILE *arq2;
	
	
	printf("\t[1] FINALIZAR O PEDIDO | [2] CANCELAR PEDIDO \n");
	printf("\t#################################################################\n\n");
	printf("\t->");
	scanf("\t%d",&opc);
	switch (opc){
		case 1:
			verde_limpar();
			logo();
			printf("\t#################################################################\n\n");
			printf("\t\t\tMEIOS DE PAGAMENTO\n\n");
			printf("\t#################################################################\n\n");
			printf("\t\t\t[1] DINHEIRO | [2] CARTÃO\n");
			printf("\t#################################################################\n");
			printf("\n");
			printf("\t->");
			scanf("\t%d",&opc);
			switch(opc){
				case 1:
					verde_limpar();
					logo();
					
										
					finalizarler = fopen("pedido/Pedido.txt", "a");
					for(cont = 0; cont< i; ++cont){
						fprintf(finalizarler, "PRODUTO: %s\nCÓDIGO: %i\nQUANTIDADE: %i\nVALOR: R$%.2f\n", vetorfinalizar[cont].tipo, vetorfinalizar[cont].codigo, vetorfinalizar[cont].quant, vetorfinalizar[cont].valor);
					}
					fclose(finalizarler);
					
					printf("\t#################################################################\n\n");
					printf("\t\t\tTOTAL A PAGAR:   R$%.2f\n\n", vfinal * (-1));
					printf("\t#################################################################\n\n");
					printf("\t\t\tDIGITE O VALOR:  R$");
					scanf("%f", &dinheiro);
					troco = dinheiro - vfinal;
					if(troco < 0){
						troco = troco * (-1);
						do{
							printf("\t\t\tVALOR QUE FALTA RECEBER: R$%.2f\n", troco);
								do{
									printf("\t\t\tDIGITE O VALOR RECEBIDO: R$");
									scanf("%f", &dinheiro);
								}while(dinheiro > troco);
							troco = troco - dinheiro;
						}while(troco != 0);					
						printf("\t\t\tTROCO: R$%.2f\n", troco);
					}
					else{
						printf("\t\t\tTROCO: R$%.2f\n", troco) ;
					}
					
					
    				GeraAleatorios(numeros,100,101);
					for(i = 0;i<1;i++){
     					printf("\t#################################################################\n\n");
     					printf("\t\t\tPEDIDO REALIZADO COM SUCESSO! \n\t\t\tNUMERO DO PEDIDO: %i -\n\n", numeros[1]);
    					printf("\t#################################################################\n\n");
					}
					
					//-------------------------------- RELATÓRIO -------------------------------------
					arq1 = fopen("relatorio/totaldinheiro.txt", "a");
					fprintf(finalizarler, "%d/%d/%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
					fprintf(finalizarler, "%s\n", timeStr);
					fprintf(finalizarler, "%.2f\n", vfinal);
					fclose(arq1);
					//---------------------------------------------------------------------------------
						
					finalizarler = fopen("pedido/Pedido.txt", "a");
					fprintf(finalizarler, "---------------------\n");
					fprintf(finalizarler, "NUMERO DO PEDIDO: %i\n", numeros[1]);
					fprintf(finalizarler, "TOTAL A PAGAR: R$%.2f\n", vfinal);
					fprintf(finalizarler, "PAGAMENTO EM DINHEIRO\n");
					fprintf(finalizarler, "VALOR PAGO: R$%.2f\n", dinheiro);
					fprintf(finalizarler, "TROCO: R$%.2f\n", troco); 
					fprintf(finalizarler, "---------------------\n");
					fprintf(finalizarler, "VOLTE SEMPRE =)\n");
					fclose(finalizarler);
					sleep(6);
				
					arq1 = fopen("banco/Venda.txt", "w");
					fclose(arq1);
					venda_principal();			
					break;
				case 2:
					verde_limpar();
					logo();
					
										
					finalizarler = fopen("pedido/Pedido.txt", "a");
					for(cont = 0; cont< (i); ++cont){
						fprintf(finalizarler, "PRODUTO: %s\nCÓDIGO: %i\nQUANTIDADE: %i\nVALOR: R$%.2f\n", vetorfinalizar[cont].tipo, vetorfinalizar[cont].codigo, vetorfinalizar[cont].quant, vetorfinalizar[cont].valor);
					}
					fclose(finalizarler);
					
					printf("\t#################################################################\n\n");
					printf("\t\t\tTOTAL A PAGAR:   R$%.2f\n\n", vfinal);
					printf("\t#################################################################\n\n");
					printf("\t\t\tDIGITE O VALOR: R$");
					scanf("%f", &cartao);
					printf("\t\t\t-----------------------------------\n");
					if(vfinal >= 100){
						printf("\t\t\tPARCELAMENTO: ");
						scanf("%i", &parcela);
						troco = vfinal / parcela;
						printf("\t\t\tVALOR TOTAL DA PARCELA: R$%.2f\n", troco);
						printf("\t\t\tVALOR PAGO: %i VEZES DE R$%.2f \n", parcela, troco);
					}
					else{
						printf("VALOR PAGO: R$%.2f \n", troco);
    				}
					
					GeraAleatorios(numeros,100,101);
					for(i = 0;i<1;i++){
     					printf("\t#################################################################\n\n");
     					printf("\t\t\tPEDIDO REALIZADO COM SUCESSO! \n\t\t\tNUMERO DO PEDIDO: %i -\n\n", numeros[1]);
    					printf("\t#################################################################\n\n");
					}
					
					//-------------------------------- RELATÓRIO -------------------------------------
					arq1 = fopen("relatorio/totalcartao.txt", "a");
					fprintf(finalizarler, "%d/%d/%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
					fprintf(finalizarler, "%s\n", timeStr);
					fprintf(finalizarler, "%.2f\n", vfinal);
					fprintf(finalizarler, "--------------------\n");
					fclose(arq1);
        			//--------------------------------------------------------------------------------
						
					finalizarler = fopen("pedido/Pedido.txt", "a");
					fprintf(finalizarler, "---------------------\n");
					fprintf(finalizarler, "NUMERO DO PEDIDO: %i\n", numeros[1]);
					fprintf(finalizarler, "*TOTAL A PAGAR: R$%.2f\n", vfinal);
					fprintf(finalizarler, "PAGAMENTO EM CARTÃO\n");
					fprintf(finalizarler, "VALOR PAGO: R$%.2f\n", cartao);
					fprintf(finalizarler, "---------------------\n");
					fprintf(finalizarler, "VOLTE SEMPRE =)\n");
					fclose(finalizarler);
					sleep(6);
					
					
					
					arq1 = fopen("banco/Venda.txt", "w");
					fclose(arq1);
					
				
					venda_principal();			
					break;
				default:
					verde_limpar();
					logo();
					printf("\t#################################################################\n\n");
					printf("\t\t\tOPÇÃO INVALIDA!!\n");
					printf("\t\t\tVESCOLHA UMA DAS 4 OPÇÕES ACIMA!\n\n");
					printf("\t#################################################################\n\n");
					sleep(4);
					menu_finalizar();
			}
		case 2:
			
			//--------------------- PIZZA -------------------
			arq1 = fopen("temp/estoquepizzatemp.txt", "r");
		
			if (arq1 == NULL){
				printf("NÃO É POSSIVEL ABRIR O ARQUIVO.");
				return 1;
			}
	
			arq2 = fopen("banco/estoquepizza.txt", "w");
			
			while(fgets(leitor, 1000, arq1) != NULL)
		
			fputs(leitor, arq2);
	
			fclose(arq1);
			fclose(arq2);
			
			//--------------------- BEBIDA -------------------
			
			arq1 = fopen("temp/estoquebebidatemp.txt", "r");
		
			if (arq1 == NULL){
				printf("NÃO É POSSIVEL ABRIR O ARQUIVO.");
				return 1;
			}
	
			arq2 = fopen("banco/estoquebebida.txt", "w");
			
			while(fgets(leitor, 1000, arq1) != NULL)
		
			fputs(leitor, arq2);
	
			fclose(arq1);
			fclose(arq2);
			//--------------------- CERVEJA -------------------
			
			arq1 = fopen("temp/estoquecervejatemp.txt", "r");
		
			if (arq1 == NULL){
				printf("NÃO É POSSIVEL ABRIR O ARQUIVO.");
				return 1;
			}
	
			arq2 = fopen("banco/estoquecerveja.txt", "w");
			
			while(fgets(leitor, 1000, arq1) != NULL)
		
			fputs(leitor, arq2);
	
			fclose(arq1);
			fclose(arq2);
			
			verde_limpar();
			logo();
			printf("\t#################################################################\n\n");
			printf("\t\t\tPEDIDO CANCELADO!\n\n");
			arq1 = fopen("banco/Venda.txt", "w");
			fclose(arq1);
			arq1 = fopen("temp/estoquepizzatemp.txt", "w");
			fclose(arq1);
			printf("\t#################################################################\n\n");
			sleep(4);
			venda_principal();
			break;
		default:
			verde_limpar();
			logo();
			printf("\t#################################################################\n\n");
			printf("\t\t\tOPÇÃO INVALIDA!!\n");
			printf("\t\t\tVESCOLHA UMA DAS 2 OPÇÕES ACIMA!\n\n");
			printf("\t#################################################################\n\n");
			sleep(4);
			menu_finalizar();
			break;
	}
}
	


	
	
		


