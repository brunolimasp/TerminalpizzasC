#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>


menu_relatorios(){
	int opc;
	
	verde_limpar();
	logo();
	printf("\n");
	printf("\t>MENUPRINCIPAL\\RELATÓRIOS\n");
	printf("\t#################################################################\n\n");
	printf("\t\tRELATÓRIOS\n\n");
	printf("\t#################################################################\n\n");
	printf("\t[1] CAIXA | [2] MAIS VENDIDOS | [3] VOLTAR  \n\n");
	printf("\t#################################################################\n");
	printf("\n");
	printf("\t->");
	scanf("\t%d",&opc);
	switch (opc){
		case 1:
			verde_limpar();
			relatorios_caixa();
			break;
		case 2:
			verde_limpar();
			relatorios_maisvendidos();
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
					menu_relatorios();
					break;
			}
		default:
			verde_limpar();
			logo();
			printf("\t##########################################################\n\n");
			printf("\t\t\tOPÇÃO INVALIDA!!\n");
			printf("\t\t\tVESCOLHA UMA DAS 4 OPÇÕES ACIMA!\n\n");
			printf("\t##########################################################\n");
			sleep(1);
			menu_relatorios();
			break;
	}
	
}

relatorios_caixa(){
	int opc;
	
	verde_limpar();
	logo();
	printf("\n");
	printf("\t>MENUPRINCIPAL\\RELATÓRIOS\\CAIXA\n");
	printf("\t#################################################################\n\n");
	printf("\t\tCAIXA\n\n");
	printf("\t#################################################################\n\n");
	printf("\t[1] DINHEIRO | [2] CARTÃO | [3] TOTAL | [4] VOLTAR  \n\n");
	printf("\t#################################################################\n");
	printf("\n");
	printf("\t->");
	scanf("\t%d",&opc);
	switch (opc){
		case 1:
			caixa_dinheiro();		
			break;
		case 2:
			caixa_dinheiro();
			break;
		case 3:
			caixa_total();
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
					menu_relatorios();
					break;		
				case 2:
					verde_limpar();
					relatorios_caixa();
					break;
			}
		default:
			verde_limpar();
			logo();
			printf("\t##########################################################\n\n");
			printf("\t\t\tOPÇÃO INVALIDA!!\n");
			printf("\t\t\tVESCOLHA UMA DAS 4 OPÇÕES ACIMA!\n\n");
			printf("\t##########################################################\n");
			sleep(1);
			relatorios_caixa();
			break;
	}
	
	
	
	
}
struct lista_fechamento // tipo de dado
{
	char data[40];
	char horas[40];
	float valor;
	float total;

}fechamento; // variavel usando o tipo de dado da struct global 

	struct lista_fechamento vetordinheiro [100];
	
caixa_dinheiro(){
	
	int tam, opc, opc2, cod, i, cont, linha = 0, esc, baixa;
	char data[40], horas[10], valor[10], dateStr[9], timeStr[9];
	float vfinal;
	
	verde_limpar();
	logo();
	
	FILE *arq1 = fopen("relatorio/totaldinheiro.txt", "r");  
	if(arq1 == NULL){
		printf("O ARQUIVO NAO PODE SER ABERTO!");
		getchar();
  		exit(1);
   	}
   	while(!feof(arq1)){
		
		fgets(data, 40, arq1);
		data[strcspn(data, "\n")] = '\0';
		
		fgets(horas, 40, arq1);
		horas[strcspn(horas, "\n")] = '\0';
		
		fgets(valor, sizeof(valor), arq1);

		strcpy(vetordinheiro[i].data, data);
		strcpy(vetordinheiro[i].horas, horas);
		vetordinheiro[i].valor = atof(valor);
		i++;
	}
	fclose(arq1);
	printf("\n");
	printf("\t>MENUPRINCIPAL\\RELATÓRIOS\\CAIXA\\DINHEIRO\n");
	printf("###############################################################################\n\n");
	printf("\t| DATA         | HORAS     | VALOR \n\n");
	printf("###############################################################################\n\n");

	for(cont =0; cont <(i-1); cont++){
		printf("\t %s     %s    %.2f\n", vetordinheiro[cont].data, vetordinheiro[cont].horas, vetordinheiro[cont].valor);

	}
		printf("###############################################################################\n\n");
		for(i =0; i < cont ; i++){
        vfinal = vfinal + vetordinheiro[i].valor;
    }
	printf("###############################################################################\n\n");
    printf("\t\tVALOR TOTAL DE DINEHIRO: R$%.2f\n", vfinal);
    printf("\n");
	printf("\tDESEJA REALMENTE SAIR?\n \t[1] SIM\n \t[2] NAO\n");
	printf("\t->");
	scanf("\t%d",&opc);
	
	time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    _strtime( timeStr );
	arq1 = fopen("relatorio/totalempresa.txt", "a");
	fprintf(arq1, "%d/%d/%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	fprintf(arq1, "%s\n", timeStr);
	fprintf(arq1, "%.2f\n", vfinal);
	fclose(arq1);
		
	switch (opc){
		case 1:
			verde_limpar();
			relatorios_caixa();
			break;		
		case 2:
			verde_limpar();
			caixa_dinheiro();
			break;
	}
}

caixa_cartao(){
	
	int tam, opc, opc2, cod, i, cont, linha = 0, esc, baixa;
	char data[40], horas[10], valor[10], dateStr[9], timeStr[9];
	float vfinal;
	
	verde_limpar();
	logo();
	
	FILE *arq1 = fopen("relatorio/totalcartao.txt", "r");  
	if(arq1 == NULL){
		printf("O ARQUIVO NAO PODE SER ABERTO!");
		getchar();
  		exit(1);
   	}
   	while(!feof(arq1)){
		
		fgets(data, 40, arq1);
		data[strcspn(data, "\n")] = '\0';
		
		fgets(horas, 40, arq1);
		horas[strcspn(horas, "\n")] = '\0';
		
		fgets(valor, sizeof(valor), arq1);

		strcpy(vetordinheiro[i].data, data);
		strcpy(vetordinheiro[i].horas, horas);
		vetordinheiro[i].valor = atof(valor);
		i++;
	}
	fclose(arq1);
	printf("\n");
	printf("\t>MENUPRINCIPAL\\RELATÓRIOS\\CAIXA\\CARTÃO\n");
	printf("###############################################################################\n\n");
	printf("\t| DATA         | HORAS     | VALOR \n\n");
	printf("###############################################################################\n\n");

	for(cont =0; cont <(i); cont++){
		printf("\t %s     %s    %.2f\n", vetordinheiro[cont].data, vetordinheiro[cont].horas, vetordinheiro[cont].valor);

	}
		printf("###############################################################################\n\n");
		for(i =0; i < cont ; i++){
        vfinal = vfinal + vetordinheiro[i].valor;
    }
    printf("\t\tVALOR TOTAL DE CARTÃO: R$%.2f\n", vfinal);
	printf("###############################################################################\n\n");
    printf("\n");
	printf("\tDESEJA REALMENTE SAIR?\n \t[1] SIM\n \t[2] NAO\n");
	printf("\t->");
	scanf("\t%d",&opc);
	
	time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    _strtime( timeStr );
	arq1 = fopen("relatorio/totalempresa.txt", "a");
	fprintf(arq1, "%d/%d/%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	fprintf(arq1, "%s\n", timeStr);
	fprintf(arq1, "%.2f\n", vfinal);
	fclose(arq1);
	
	switch (opc){
		case 1:
			verde_limpar();
			relatorios_caixa();
			break;		
		case 2:
			verde_limpar();
			caixa_cartao();
			break;
	}
	
}

caixa_total(){
	int tam, opc, opc2, cod, i, cont, linha = 0, esc, baixa;
	char data[40], horas[10], valor[10], dateStr[9], timeStr[9];
	float vfinal;
	
	verde_limpar();
	logo();
	
	FILE *arq1 = fopen("relatorio/totalempresa.txt", "r");  
	if(arq1 == NULL){
		printf("O ARQUIVO NAO PODE SER ABERTO!");
		getchar();
  		exit(1);
   	}
   	while(!feof(arq1)){
		
		fgets(data, 40, arq1);
		data[strcspn(data, "\n")] = '\0';
		
		fgets(horas, 40, arq1);
		horas[strcspn(horas, "\n")] = '\0';
		
		fgets(valor, sizeof(valor), arq1);

		strcpy(vetordinheiro[i].data, data);
		strcpy(vetordinheiro[i].horas, horas);
		vetordinheiro[i].valor = atof(valor);
		i++;
	}
	fclose(arq1);
	printf("\n");
	printf("\t>MENUPRINCIPAL\\RELATÓRIOS\\CAIXA\\TOTAL\n");
	printf("###############################################################################\n\n");
	printf("\t| DATA         | HORAS     | VALOR \n\n");
	printf("###############################################################################\n\n");

	for(cont =0; cont <(i-1); cont++){
		printf("\t %s     %s    %.2f\n", vetordinheiro[cont].data, vetordinheiro[cont].horas, vetordinheiro[cont].valor);

	}
		printf("###############################################################################\n\n");
		for(i =0; i < cont ; i++){
        vfinal = vfinal + vetordinheiro[i].valor;
    }
    printf("\t\tVALOR TOTAL: R$%.2f\n", vfinal);
	printf("###############################################################################\n\n");
    printf("\t\tVALOR TOTAL DE DINEHIRO: R$%.2f\n", vfinal);
    printf("\n");
	printf("\tDESEJA REALMENTE SAIR?\n \t[1] SIM\n \t[2] NAO\n");
	printf("\t->");
	scanf("\t%d",&opc);
	
	time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    _strtime( timeStr );
	arq1 = fopen("relatorio/valortotal.txt", "a");
	fprintf(arq1, "%d/%d/%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	fprintf(arq1, "%s\n", timeStr);
	fprintf(arq1, "%.2f\n", vfinal);
	fclose(arq1);
	
	switch (opc){
		case 1:
			verde_limpar();
			relatorios_caixa();
			break;		
		case 2:
			verde_limpar();
			caixa_total();
			break;
	}
	
}

relatorios_maisvendidos(){

	int opc, maisnum, i, v[10];
   	char maischar[1000];
   	
	verde_limpar();
	logo();
	printf("\n");
	printf("\t>MENUPRINCIPAL\\RELATÓRIOS\\MAIS VENDIDOS\n");
	printf("#################################################################\n\n");
	printf("\t\tCAIXA\n\n");
	printf("#################################################################\n\n");
	printf("\tSABOR 		 | CODIGO | QUANTIDADE DE VEZES VENDIDA  \n\n");
	printf("#################################################################\n");
	
	for(i=0;i<11;i++){
       v[i]=0;
  	}
  	
	FILE *arq1 = fopen("relatorio/maisvendidos.txt", "r");  
	while(!feof(arq1)){
		fgets(maischar, sizeof(maischar), arq1);
		maisnum = atoi(maischar);
    	v[maisnum]++;
  	}
  	
   	for(i=1;i<11;i++){
   		if(i == 1){
       		printf("\tPIZZA: CMD          COD:%d    FOI VENDIDA %d VEZ(ES)\n", i, v[i]);
		}
	   	if(i == 2){
       		printf("\tPIZZA: C            COD:%d    FOI VENDIDA %d VEZ(ES)\n", i, v[i]);
		}
	   if(i == 3){
       		printf("\tPIZZA: INTEL        COD:%d    FOI VENDIDA %d VEZ(ES)\n", i, v[i]);
		}
	   if(i == 4){
       		printf("\tPIZZA: LINUX        COD:%d    FOI VENDIDA %d VEZ(ES)\n", i, v[i]);
		}
		if(i == 5){
       		printf("\tPIZZA: PYTHON       COD:%d    FOI VENDIDA %d VEZ(ES)\n", i, v[i]);
		}
		if(i == 6){
       		printf("\tPIZZA: AMD          COD:%d    FOI VENDIDA %d VEZ(ES)\n", i, v[i]);
		}
		if(i == 7){
       		printf("\tPIZZA: JAVA         COD:%d    FOI VENDIDA %d VEZ(ES)\n", i, v[i]);
		}
		if(i == 8){
       		printf("\tPIZZA: HTML         COD:%d    FOI VENDIDA %d VEZ(ES)\n", i, v[i]);
		}
		if(i == 9){
       		printf("\tPIZZA: CSS          COD:%d    FOI VENDIDA %d VEZ(ES)\n", i, v[i]);
		}
		if(i == 10){
       		printf("\tPIZZA: TELA AZUL    COD:%d   FOI VENDIDA %d VEZ(ES)\n", i, v[i]);
		}
	}
	printf("#################################################################\n");
	printf("\n");
	printf("\tDESEJA REALMENTE SAIR?\n \t[1] SIM\n \t[2] NAO\n");
	printf("\t->");
	scanf("\t%d",&opc);
	
	switch (opc){
		case 1:
			verde_limpar();
			relatorios_caixa();
			break;		
		case 2:
			verde_limpar();
			relatorios_maisvendidos();
			break;
	}


}



