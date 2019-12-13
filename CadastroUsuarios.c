#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


 
  FILE *fileDB, *fileDBTemp;
  char *fileNameUsers = "banco/comum.txt";
  char *fileNameUsersTemp = "Usuario_BDTemp.txt";
  char *modeInsert = "a";
  char *modeReader = "r";
  char *modeOverride = "w";
  const int  maxCharByLine = 200;

struct Usuario
{
        
            char login[50];
            char password[50];
            char email[50];
       
     
};


 void closeDB(char *fileNameDB){
    if(strcmp(fileNameDB,fileNameUsers)==0){    
      fclose(fileDB);     
    }

    if(strcmp(fileNameDB,fileNameUsersTemp)==0){  
        fclose(fileDBTemp); 
    }
 }

//Simula atualização em em banco criando um novo arquivo e substituindo o mesmo 
void updateBD(){
  closeDB(fileNameUsers);//Força o fechamento do arquivo caso ainda nao tenha ocorrido
  closeDB(fileNameUsersTemp);//Força o fechamento do arquivo caso ainda nao tenha ocorrido

   if(remove(fileNameUsers)==0){//Se conseguir Remover o arquivo Original
        if(rename(fileNameUsersTemp,fileNameUsers)==0){//Renomeia o arquivo temporario para ter o mesmo nome do arquivo original
            remove(fileNameUsersTemp);//remove o arquivo temporario
        }else{
          printf("nao foi possivel remover o arquivo %s\n",fileNameUsersTemp);
        }
      }else{
        printf("nao foi possivel remover o arquivo %s\n",fileNameUsers);
      }
}


//Abre conexao com o Arquivo 
bool openBD(char *fileNameDB,char *mode){
   if(strcmp(fileNameUsers,fileNameDB)==0){
        fileDB = fopen(fileNameDB, mode);      
        if(fileDB != NULL)    
            return true;
    }else{
        if(strcmp(fileNameUsersTemp,fileNameDB)==0){
            fileDBTemp = fopen(fileNameDB, mode);      
            if(fileDBTemp != NULL)    
                return true;
            }
    }
    return false;
}



//Escreve no Arquivo
void writeInDB(char *fileNameDB,char *mode,struct Usuario user){ 
   
      openBD(fileNameDB,mode);
      FILE *db; 
      if(strcmp(fileNameDB,fileNameUsers)==0){
          db = fileDB;           
      } 
      if(strcmp(fileNameDB,fileNameUsersTemp)==0){
         db = fileDBTemp;           
      }
      fprintf(db, "%s\n%s\n%s\n\n", strlwr(user.login),strlwr(user.password),strlwr(user.email));
      closeDB(fileNameDB);   
}  

bool isLoginExists(char login[50]){
     bool isExists = false; 
    if(openBD(fileNameUsers,modeReader)){
     char *word; 
    char line[maxCharByLine];
    
    /**
     * while -> Enquanto ouver o valor nao for igual a NULL
     * fgets -> 1º Parametro variavel que ira armazenar a linha;   2
     * fgets -> 2º Parametro numero maximo de caracters a ser lido; 
     * fgets -> 3º Parametro Ponteiro para arquivo; 
     * */   
    while(fgets(line, maxCharByLine, fileDB) != NULL){
          //Insere o primeiro texto da linha atualseparando por tabulação (\t) na variavel palavra.(POR ISSO PRIMEIRO ARGUMENTO É A LINHA ATUAL)
          word = strtok(line,"\t");
          if(strcmp(word,login)==0){
            isExists = true;
            break;
          }
          
    }
    closeDB(fileNameUsers);
  }else{
    printf("\nNao foi possivel Abrir/Encontrar o arquivo de usuarios.");
  }
     
    
  return isExists;
}



//Insere um novo usuario
void insertNewUser(){
      system("cls");
		logo();	
      struct Usuario usuario;
       
      printf("\n\nO arquivo aberto com sucesso!\n");
      printf("\n\nDigite o nome de usuario!\n");   
      scanf("%s",usuario.login);   

      if(isLoginExists(usuario.login)){  
         printf("\nEste usuario ja existe!!!!\n");
         system("pause"); 
      
      }else{
        printf("\n\nDigite a senha do usuario!\n");    
        scanf("%s",usuario.password);   
          
        printf("\n\nDigite o email para o usuario!\n");    
        scanf("%s",usuario.email);   
        writeInDB(fileNameUsers,modeInsert,usuario);
      }
     
            
}      

//Insere os valores de um array em outro
void setUserValues(char insert[50],char value[50]){    
    int i;
    for ( i=0; i < 50; i++)
    {
        insert[i]=value[i];
    }
}

//deleta Usuario escrito no terminal
void deleteSelectedUser(){
  if(openBD(fileNameUsers,modeReader)){     
      system("cls");
      system("color 9");      
      char selectedUser[50];
      char *word; 
      char line[200]; 
      bool isExist = false;
      printf("Digite o nome do usuario que deseja deletar...\n");
      scanf("%s",selectedUser);   
      while(fgets(line, maxCharByLine, fileDB) != NULL){
          
          word = strtok(line,"\t");
         
          
          if(strcmp(word,selectedUser)!=0){  
           
            struct Usuario usuario;
            
            setUserValues(usuario.login,word);        
            setUserValues(usuario.password,strtok(NULL,"\t"));
            setUserValues(usuario.email,strtok(NULL,"\n"));     
                
            writeInDB(fileNameUsersTemp,modeInsert,usuario);           
          }else{
            isExist = true;
          }

      }
     
      
     updateBD();
     if(isExist){
       printf("\n%s excluido com sucesso!\n",selectedUser);
     }else{
        printf("\n%s não foi encontrado!\n",selectedUser);
     }
      
  }
   system("pause");
}

void findAllUsuarios(){
 	system("cls");
	logo();
	char opcao;
	FILE *file;
	file = fopen("banco/comum.txt","r");
	char relatorio[500];
	
	while(fgets(relatorio, 500,file)!= NULL){
		printf("\t\t\t %s",relatorio);
	}
	fclose(file);
	printf("\n\n\n\t\tPRESSIONE QUALQUER TECLA PARA VOLTAR\n\n");
	scanf ("%s", &opcao);
	
	if (opcao == 1){
	mainCadastroUsuario();
	}
    else {
    	mainCadastroUsuario();
    }
}


int mainCadastroUsuario()
{   
  

    system("cls"); 
	logo();
	printf("\t##########################################################\n");
	printf("\t\t\t [0] CADASTRAR NOVO USUARIO ADMINISTRADOR	\n");
	printf("\t\t\t [1] CADASTRAR NOVO USUARIO COMUM	 	\n");
	printf("\t\t\t [2] LISTA DE USUARIO	 	\n");
	printf("\t\t\t [3] VOLTAR AO MENU ANTERIOR	\n");
	printf("\t##########################################################\n");
    int opcao;
    scanf("%i",&opcao); 
    
    if(opcao==0){
    	inseriadm();
	}
	 if(opcao==1){
    	insertNewUser();
	}
	 if(opcao==2){
    	findAllUsuarios();  
	}
	 if(opcao==3){
    	menu_principal();
	}
	 if(opcao==4){
    	menu_principal();
	}

    /*switch(opcao){      
            case 0:{
                menu_principal();
            }break;  
            case 1:{         
                insertNewUser();
            }break;
            case 2:{        
                findAllUsuarios();  
            }break;
            case 3:{
                deleteSelectedUser();
            }break;
            default:{
                system("cls");
                printf("\n\nOpção Invalida!!!\n\n");
            }break;
    }
  
    }while(true);
  
  */
}
