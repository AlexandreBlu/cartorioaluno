#include <stdio.h> //biblioteca de comunica��es com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios do sistema
{
	//inicio cria��o de vari�veis
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Final da cria��o de vari�veis/string
    
    printf("Digite o CPF a ser cadastrado: "); //Coletando informa��es do usu�rio
    scanf("%s", cpf); //$s refere-se a string
    
    strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
    
    FILE *file; // cria o arquivo
    file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); // salvo o valor da variavel
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); //Pausa o programa
	 
}

int consultar() //Fun��o respons�vel por consultar os dados do usu�rio
{
	setlocale(LC_ALL,"portuguese"); //Definindo a linguagem
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o cpf a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf,"r"); //Cria o arquivo e o "r" significa ler
    
    if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizada!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");

	
}

int deletar() //Fun��o respons�vel por deletar os dados do usu�rio
{
    char cpf [40];
    
    printf("digite o CPF do usu�rio que deseja deletar: ");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE* file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
	{
	    printf("O usu�rio n�o foi encontrado no sistema!.\n");
		system("pause");	
	}
	

}





int main()
    {
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

        system("cls"); //Respons�vel por limpar a tela
	
    	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    	printf("## Cart�rio da Asus##\n\n"); // Inicio do menu
    	printf("Escolha a op��o desejada do menu\n\n");
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n\n");
    	printf("Op��o: "); // Fim do menu
	
    	scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
    	system("cls");
    	
    	
    	switch(opcao)
		{
			case 1:
			registro(); //chamada de fun��es
 		    break;
 		    
 		    case 2:
 		    consultar();
 	        break;
 	        
 	        case 3:
 	        deletar();
		    break;
		    
		    default:
		    printf("Esta op��o n�o est� dispon�vel\n");
  		    system("pause");
		}
	
 
    }
}
