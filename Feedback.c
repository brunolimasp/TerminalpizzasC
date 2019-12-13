#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>




int feedback(){
	system("cls");	
	logo();
 	int opcao;
	FILE *file;
	file = fopen("banco/FeedBackRelatorio.txt","r");
    system("color 17");
    printf("\n");
	printf("\t>MENUPRINCIPAL\\FEEDBACK\n");
	printf("\t#################################################################\n\n");
	printf("\t\t[1]REGISTRAR RECLAMACÕES OU ELOGIOS\n");
	printf("\t\t[2]RELATÓRIO\n");
	printf("\t\t[3]VOLTAR\n");
	printf("\t#################################################################\n\n");
    scanf ("%d", &opcao);
    if (opcao == 1){
    void registro();
	registro();
	}

	if (opcao == 2){
	void relatorio();
	relatorio();
	}
	if (opcao == 3){
	menu_principal();
	}
    else {

    }
    system ("pause");
    return 0;
}

void registro(){
	system("cls");	
	logo();
	char text[200];
	char opcao;
	FILE *file;
	file = fopen("banco/FeedBackRelatorio.txt","a");



	char dateStr[9];
	char timeStr[9];

	// pega a data atual
	_strdate( dateStr);
//	printf_s( "The current date is %s \n", dateStr);

	// pega a hora atual
	_strtime( timeStr );
	//printf_s( "The current time is %s \n", timeStr);
// vai incluir DATA E HR DO TXT COM TABULACAO
	fputs(dateStr,file);
	fputs(" - ",file);
	fputs(timeStr,file);
	fputs(" - ",file);

	
	printf("\nINSIRA O FEEDBACK DO CLIENTE : ");
	getchar();
	fgets(text, 200, stdin);
	fputs(text,file);
	fclose(file);
	
	
	printf("\n\n\n\t\tPRESSIONE QUALQUER TECLA PARA VOLTAR\n\n");
	scanf ("%s", &opcao);
	
	if (opcao == 1){
	feedback();
	}
    else {
    	feedback();
    }
    fclose(file);
    
}




void relatorio(){
	system("cls");
	logo();
	char opcao;
	FILE *file;
	file = fopen("banco/FeedBackRelatorio.txt","r");
	char relatorio[500];
	
	while(fgets(relatorio, 500,file)!= NULL){
		printf("\n %s",relatorio);
	}
	fclose(file);
	printf("\n\n\n\t\tPRESSIONE QUALQUER TECLA PARA VOLTAR\n\n");
	scanf ("%s", &opcao);
	
	if (opcao == 1){
	feedback();
	}
    else {
    	feedback();
    }

}


