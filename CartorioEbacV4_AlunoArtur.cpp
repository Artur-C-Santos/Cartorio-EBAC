#include <stdio.h> //biblioteca de comunica��o com usu�rios
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respos�vel por cuidar das string

int registro() //fun��o de registrar informa��es do usu�rio
{
	//inicio cria��o de vari�veis/string
	char arquivo[40]; //vari�vel de caracteres para armazenar o nome do arquivo
	char cpf[40]; //vari�vel para armazenar o CPF
    char nome[40]; //vari�vel para armazenar o nome
	char sobrenome[40]; //vari�vel para armazenar o sobrenome
	char cargo[40]; //vari�vel para armazenar o cargo
	//final da cia��o de vari�veis/string
	
	printf("Digita o CPF a ser cadastrado: "); //mensagem para o usu�rio
	scanf("%s", cpf); //%s refere-se a string (l� o CPF digitado pelo ussu�rio)
	
	strcpy(arquivo, cpf); //Responsavel por copiar o valor do 'CPF' para o 'ARQUIVO'
	
	FILE *file; //identificando o arquivo
 	file = fopen(arquivo, "w"); //cria ou sobrescreve um arquivo com o nome do CPF, "w" significa escrever
	
	file = fopen(arquivo, "a"); //abre o arquivo para acrescentar mais dados
	fprintf(file, "cpf: %s\n", cpf); // gravar variavel CPF no arquivo criado
	fclose(file); //fechar o arquivo que foi aberto
	
	printf("Digite o nome a ser cadastrado: "); //mensagem para o usu�rio
	scanf("%s", nome); //%s refere-se a string (l� o nome digitado pelo ussu�rio)
	
	file = fopen(arquivo, "a"); //abre o arquivo para acresenta mais dados
	fprintf(file, "nome: %s\n", nome); // gravar variavel nome no arquivo criado
	fclose(file); //fechar o arquivo que foi aberto

	printf("Digite o sobrenome a ser cadasstrado: "); //mensagem para o usu�rio
	scanf("%s",sobrenome); //%s refere-se a string (l� o sobrenome digitado pelo ussu�rio)
	
	file = fopen(arquivo, "a"); //abre o arquivo para acresenta mais dados
	fprintf(file, "sobrenome: %s\n", sobrenome);  // gravar variavel sobrenome no arquivo criado
	fclose(file); //fecha o arquivo que foi aberto
	
	printf("Digite o cargo a ser cadastrado: "); //mensagem para o usu�rio
	scanf("%s", cargo); //%s refere-se a string (l� o cargo digitado pelo ussu�rio)
	
	file = fopen(arquivo, "a"); //abre o arquivo para acresenta mais dados
	fprintf(file, "cargo: %s\n", cargo);  // gravar variavel cargo no arquivo criado
	fclose(file); //fecha o arquivo que foi aberto
		
	
	system("pause"); //pausa a execu��o do sistema
}

int consulta() //fun��o para consultar ass informa��es de um usu�rio pelo CPF
{
	setlocale(LC_ALL, "Portuguese"); //define a localidade para portuqu�s
	
	//inicio cria��o de vari�veis/string
	char cpf[40]; //vari�vel para armazenar o CPF
	char conteudo[200]; //vari�vel para armazenar o conte�do do arquivo
	//final da cia��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); //mensagem para o usu�rio
	scanf("%s", cpf);  //%s refere-se a string (l� o CPF digitado pelo ussu�rio)
	
	FILE *file; //identificando o arquivo
	file = fopen(cpf, "r"); //abre o arquivo correspondente ao CPF para ler
	
	if (file == NULL) //verifica se o arquivo existe
	{
		printf("Arquivo n�o pode ser emcontado!.\n"); //mensagem de errose o arquivo n�o for encontrado
	}
	
	printf("\nEssa s�o as informa�oes do usu�rio: \n"); //mensagem para o usu�rio
	printf("\n"); //mensagem para pular linha
	
	while(fgets(conteudo, 200, file) != NULL) //l� p contte�do do arquivo lina por linha
	{
		printf("%s", conteudo); //%s refere-se a string (mostra o conte�dp lido)
	}
	
	system("pause"); //pausa a execu��o do sistema
	
}

int deleta() //fun��o para deletar um arquivo baseado no CPF do usu�rio
{
	//inicio cria��o de vari�veis/string
	char cpf[40]; //vari�vel para armazenar o CPF
	//final da cia��o de vari�veis/string
	
	printf("Digite o CPF do usu�rio que deseja delartar: "); //mensagem para o usu�rio
	scanf("%s", cpf); //%s refere-se a string (l� o CPF digitado pelo ussu�rio)
	
	remove(cpf); //remove o arquivo correspondente ao CPF
	
	FILE *file; //identificando o arquivo
	file = fopen(cpf,"r"); //abre o arquivo correspondente ao CPF para ler

	if(file == NULL) //se o arquivo n�o esistir mais
	{
		printf("CPF n�o encontrado no sistema.\n"); //informa que o CPF n�o foi encontrado
	}
		system("pause"); //paua a execu��o do sistema
}

int main() //fun��o principal do programa
{
	int opcao = 0; //vari�vel para armazenar a op��o ecolhida pelo usu�rio
	int laco = 1; //vari�vel de controle para lo�o do menu
	
	for (laco = 1; laco = 1;) //la�o de repeti��o infinita (enquanto la�o for 1)
	{

    	system("cls"); //Limpa a tela
		
		setlocale(LC_ALL, "Portuguese"); //define a localidade para portugu�s
 	
    	//exibe o menu de op��es
		printf("---------------------------------\n");
		printf("###      Cart�rio da EBAC     ###\n"); 
		printf("---------------------------------\n");
    	printf("Escolha a op��o desejada do menu:\n\n");
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deleta nome\n");
    	printf("Op��o: ");

	
    	scanf("%d", &opcao); //%d refere-sse a armazenar a variavel (l� a op��o escolha pelo usu�rio)
	
    	system("cls"); //limpar a tela 
    	
    	switch(opcao) //estrutura switcch para camar a fun��o correpondente a op��o escolhida
    	{
    		case 1: //opi��o 01
    		registro(); //chama a fun��o de regggistro
    		break; //intterromper a execu��o
    			
    		case 2: //opi��o 02
    		consulta(); //chama a fun��o de consulta
    		break; //intterromper a execu��o
    		
    		case 3: //opi��o 03
    		deleta(); //chama a fun��o de deleta
    		break; //intterromper a execu��o
    		
    		default: //qulaquer outra opi��o que n�o esteja listada
    		printf("Essa op��o n�o est� disponivel!\n"); //mensagem para op��o inv�lida
    		system("pause"); //pausssa a execu��o de sistema
    		break; //intterromper a execu��o
    			
		}
		    	
    }
}
