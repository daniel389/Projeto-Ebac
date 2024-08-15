#include <stdio.h>//biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de aloação de espaço em memoria
#include <locale.h>//biblioteca de alocações de texto por região
#include <string.h>//bibliota responsável por cuidar das sting
int registro()//cadastrar usuários no sistema
{
	setlocale(LC_ALL,"Portuguese");//definindo linguagem
	//criação de variáveiss/string
    char arquivo[40];
	char cpf[40];
    char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveiss/string
	
	
	printf("Digite o CPF a ser cadastrado\n");//pegando informações
	
	printf(":");
	
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf);//Responsável por copiar os valores das string
	
	FILE *file;//Criandoo o arquivo
	file = fopen(arquivo,"w");//cria o arquivo ''w'' significa escrever
	fprintf(file, cpf);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file=fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado\n");
	printf(":");
	scanf("%s", nome);
	
	file=fopen(arquivo,"a");
	fprintf(file, nome);
	fclose(file);
	

	file=fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sosbrenome a ser cadastrado\n");
	printf(":");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:\n");
	printf(":");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");

	

}

int consulta()
{
	setlocale(LC_ALL,"Portuguese");//definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado!\n");
	printf(":");
	scanf("%s",cpf);
	
	FILE *file;
	file=fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel localizar o arquivo!\n");
	}
	
	while(fgets(conteudo,200,file)!=NULL)
	{
		printf("Essas são as informações do usuário!.\n");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	setlocale(LC_ALL,"Portuguese");//definindo linguagem
	
	char cpf[40];
	
	printf("Digite o CPF a deletar\n");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file=fopen(cpf,"r");
	
	if(file ==NULL)
	{
		printf("O usuário não foi encontrado!\n");
		system("pause");
		return 0;
	}
	
	else
	{
		remove(cpf);
		printf("CPF removido com sucesso!!\n");
		system("pause");
		return 0;
		fclose(file);
	}
}

int main ()
    {
	int opcao=0;//definindo variáveís
	int laco=1;
	
	for (laco=1;laco=1;)
	{
	     system("cls");
	    setlocale(LC_ALL,"Portuguese");//definindo linguagem
	 
	    printf(   "Cartório da EBAC   \n");//início do menu
	    printf("Escolha a opção desejada no menu\n");
	    printf("\t1 -Registrar Nomes \n");
	    printf("\t2 - Consultar Nomes\n");
	    printf("\t3 - Deletar Nomes\n");
	    printf("\t4 - Sair do Sistema\n");
	    printf("Opção: ");//fim do menu
    
    
        scanf("%d", &opcao);//armazenando a escolha do usuário
        system("cls");
        
        switch(opcao)
        {
        	 case 1:
			 registro();//chamada de funções
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
	 	   
	 	   default:printf("Essa opção não está disponível!\n");
    	   system("pause");
    	   break;
		}
     //fim da seleção

    }
}
