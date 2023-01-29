#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cudar das string

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%S refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //criar arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" SIGNIFICA ESCREVER
	fprintf(file,cpf); //salvar o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //abrir arquivo
	fprintf(file, ",");
	fclose(file);//fechar arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coletando informação do usuário
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");//abrir arquivo
	fprintf(file,nome);
	fclose(file);//fechar arquivo
	
	file = fopen(arquivo, "a");//abrir arquivo
	fprintf(file, ",");
	fclose(file);//fechar arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando informação do usuário
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");//abrir arquivo
	fprintf(file,sobrenome);
	fclose(file);//fechar arquivo
	
	file = fopen(arquivo,"a");//abrir arquivo
	fprintf(file, ",");
	fclose(file); //fechar arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coletando informação do usuário
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);//fechar arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file, ",");
	fclose(file);//fechar arquivo
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //Consultar banco de dados
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informaçãoes do usuário: \n");//Consultar banco de dados
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: "); //deletar usuários
	scanf("%s,cpf");
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema! . \n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{ 
	    system("cls");

	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
        printf("### cartório da EBAC ###\n\n"); //inicio do menu
	    printf("Escolha a opção desejada do menu: \n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomens\n");
    	printf("\t4 - Sair do sistema \n\n ") ;
    	printf("opção: ");//fim do menu
	
    	scanf("%d", &opcao); //armazenando a escolha do usuário
	
    	system("cls"); //RESPONSAVEL POR LIMPAR A TELA
    	
    	
    	switch(opcao)
    	{
    		case 1:
    		registro(); //chamada de função
		    break;
		    
		    case 2:
		    consulta();//chamada de função
	        break;
	        
	        case 3:
	        deletar();//chamada de função
	        break;
	        
	        case 4:
	        printf("Obrigado por utilizar o sistema! \n");
	        return 0;
	        break;
			
			default:
			printf("Essa opção não está disponivel!\n");
	 	    system("pause");
			break;	
		}
	}
}
