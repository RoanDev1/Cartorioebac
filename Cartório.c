#include <stdio.h> // biblioteca de comunica��o com o usu�rio                                                                                                                                     
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	// In�cio cria��o de vari�veis/strings; Strings = Conjunto de vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Fim da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando a informa��o do usu�rio
	scanf("%s", cpf); //Salvando na vari�vel, %s � para strings
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); // Cria o arquivo, "w" significa escrever
	fprintf(file,cpf); //Salvar o valor da var�avel
	fclose(file); //Fechar o arquivo
	
	file = fopen(arquivo, "a"); // O "a" � para atualizar o arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome); //String � conjunto de vari�veis
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // O "a" � para atualizar o arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r"); //Ler o arquivo
    
    if(file == NULL) //Dois iguais � compara��o
    {
    	printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}
    
    while(fgets(conteudo, 200, file) != NULL);
    {
    	printf("\nEssas s�o as informa��es do usu�rio: ");
    	printf("%s",conteudo);
    	printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
}

int main()
{
    int opcao=0; // Definindo as var�aveis 
    int laco=1;
   
    for(laco=1;laco=1;) 
    {
	
        system("cls"); // Respons�vel por LIMPAR a tela
	   
	    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

	    printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
   	    printf("Escolha a op��o desejada do menu: \n\n");
     	printf("\t1 - Registrar nomes\n");
 	    printf("\t2 - Consultar os nomes\n");
     	printf("\t3 - Deletar nomes\n\n");        
		printf("\t4 - Sair do sistema\n\n");                                           
	    printf("Opc�o: "); //Fim do menu
	
	    scanf("%d", &opcao); // Armazenando a escolha do usu�rio
	
     	system("cls"); // Respons�vel por LIMPAR a tela
	
	
	    switch(opcao) // In�cio da sele��o do menu
	    {
	    	case 1:
	    	registro(); // Chamadando a fun��o
	    	break;
			
			case 2:	
			consulta();
            break;
            
            case 3:
            deletar();
	        break;
	        
	        case 4:
	        printf("Obrigado por utilizar o sistema!\n");
	        return 0;
	        break;
	        
	        default:
	       	printf("Essa op��o n�o est� dispon�vel!\n");
            system("pause");
            break;
	        
		}
	
	
    	
      
    }
	
	
}


