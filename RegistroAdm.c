#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int inseriadm(){
	system("cls");	
	logo();
	char text[200];
	FILE *file;
	file = fopen("banco/adm.txt","a");
	printf("\nINSIRA O USERNAME: ");
	getchar();
	fgets(text, 200, stdin);
	fputs(text,file);
	fclose(file);
	
    senha();
    
}




int senha(){
	system("cls");	
	logo();
	char text[200];
	FILE *file;
	file = fopen("banco/adm.txt","a");

	


	printf("\nINSIRA UMA SENHA : ");
	getchar();
	fgets(text, 200, stdin);
	fputs(text,file);
	fclose(file);
	
	email();
    
    
}

int email(){
	system("cls");	
	logo();
	char text[200];
	char opcao;
	FILE *file;
	file = fopen("banco/adm.txt","a");



	printf("\nINSIRA O E-MAIL CORPORATIVO : ");
	getchar();
	fgets(text, 200, stdin);
	fputs(text,file);
	fclose(file);
	
	
	printf("\n\n\n\t\tSELECIONE QUALQUER TECLA PARA VOLTAR\n\n");
	scanf ("%s", &opcao);
	
	if (opcao == 1){
	mainCadastroUsuario();
	}
    else {
    	mainCadastroUsuario();
    }
    fclose(file);
    
    
}





/*O CODIGO TA FEIO MAS FUNCIONA 
TA SAFE.................

         ,
        /|      __
       / |   ,-~ /
      Y :|  //  /
      | jj /( .^
      >-"~"-v"
     /       Y
    jo  o    |
   ( ~T~     j
    >._-' _./
   /   "~"  |
  Y     _,  |
 /| ;-"~ _  l
/ l/ ,-"~    \
\//\/      .- \
 Y        /    Y    
 l       I     !
 ]\      _\    /"\
(" ~----( ~   Y.  )
follow the white rabbit 
*/

