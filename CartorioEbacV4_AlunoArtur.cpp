#include <stdio.h> //biblioteca de comunicação com usuários
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca resposável por cuidar das string

int registro() //função de registrar informações do usuário
{
	//inicio criação de variáveis/string
	char arquivo[40]; //variável de caracteres para armazenar o nome do arquivo
	char cpf[40]; //variável para armazenar o CPF
    char nome[40]; //variável para armazenar o nome
	char sobrenome[40]; //variável para armazenar o sobrenome
	char cargo[40]; //variável para armazenar o cargo
	//final da ciação de variáveis/string
	
	printf("Digita o CPF a ser cadastrado: "); //mensagem para o usuário
	scanf("%s", cpf); //%s refere-se a string (lê o CPF digitado pelo ussuário)
	
	strcpy(arquivo, cpf); //Responsavel por copiar o valor do 'CPF' para o 'ARQUIVO'
	
	FILE *file; //identificando o arquivo
 	file = fopen(arquivo, "w"); //cria ou sobrescreve um arquivo com o nome do CPF, "w" significa escrever
	
	file = fopen(arquivo, "a"); //abre o arquivo para acrescentar mais dados
	fprintf(file, "cpf: %s\n", cpf); // gravar variavel CPF no arquivo criado
	fclose(file); //fechar o arquivo que foi aberto
	
	printf("Digite o nome a ser cadastrado: "); //mensagem para o usuário
	scanf("%s", nome); //%s refere-se a string (lê o nome digitado pelo ussuário)
	
	file = fopen(arquivo, "a"); //abre o arquivo para acresenta mais dados
	fprintf(file, "nome: %s\n", nome); // gravar variavel nome no arquivo criado
	fclose(file); //fechar o arquivo que foi aberto

	printf("Digite o sobrenome a ser cadasstrado: "); //mensagem para o usuário
	scanf("%s",sobrenome); //%s refere-se a string (lê o sobrenome digitado pelo ussuário)
	
	file = fopen(arquivo, "a"); //abre o arquivo para acresenta mais dados
	fprintf(file, "sobrenome: %s\n", sobrenome);  // gravar variavel sobrenome no arquivo criado
	fclose(file); //fecha o arquivo que foi aberto
	
	printf("Digite o cargo a ser cadastrado: "); //mensagem para o usuário
	scanf("%s", cargo); //%s refere-se a string (lê o cargo digitado pelo ussuário)
	
	file = fopen(arquivo, "a"); //abre o arquivo para acresenta mais dados
	fprintf(file, "cargo: %s\n", cargo);  // gravar variavel cargo no arquivo criado
	fclose(file); //fecha o arquivo que foi aberto
		
	
	system("pause"); //pausa a execução do sistema
}

int consulta() //função para consultar ass informações de um usuário pelo CPF
{
	setlocale(LC_ALL, "Portuguese"); //define a localidade para portuquês
	
	//inicio criação de variáveis/string
	char cpf[40]; //variável para armazenar o CPF
	char conteudo[200]; //variável para armazenar o conteúdo do arquivo
	//final da ciação de variáveis/string
	
	printf("Digite o CPF a ser consultado: "); //mensagem para o usuário
	scanf("%s", cpf);  //%s refere-se a string (lê o CPF digitado pelo ussuário)
	
	FILE *file; //identificando o arquivo
	file = fopen(cpf, "r"); //abre o arquivo correspondente ao CPF para ler
	
	if (file == NULL) //verifica se o arquivo existe
	{
		printf("Arquivo não pode ser emcontado!.\n"); //mensagem de errose o arquivo não for encontrado
	}
	
	printf("\nEssa são as informaçoes do usuário: \n"); //mensagem para o usuário
	printf("\n"); //mensagem para pular linha
	
	while(fgets(conteudo, 200, file) != NULL) //lê p contteúdo do arquivo lina por linha
	{
		printf("%s", conteudo); //%s refere-se a string (mostra o conteúdp lido)
	}
	
	system("pause"); //pausa a execução do sistema
	
}

int deleta() //função para deletar um arquivo baseado no CPF do usuário
{
	//inicio criação de variáveis/string
	char cpf[40]; //variável para armazenar o CPF
	//final da ciação de variáveis/string
	
	printf("Digite o CPF do usuário que deseja delartar: "); //mensagem para o usuário
	scanf("%s", cpf); //%s refere-se a string (lê o CPF digitado pelo ussuário)
	
	remove(cpf); //remove o arquivo correspondente ao CPF
	
	FILE *file; //identificando o arquivo
	file = fopen(cpf,"r"); //abre o arquivo correspondente ao CPF para ler

	if(file == NULL) //se o arquivo não esistir mais
	{
		printf("CPF não encontrado no sistema.\n"); //informa que o CPF não foi encontrado
	}
		system("pause"); //paua a execução do sistema
}

int main() //função principal do programa
{
	int opcao = 0; //variável para armazenar a opção ecolhida pelo usuário
	int laco = 1; //variável de controle para loço do menu
	
	for (laco = 1; laco = 1;) //laço de repetição infinita (enquanto laço for 1)
	{

    	system("cls"); //Limpa a tela
		
		setlocale(LC_ALL, "Portuguese"); //define a localidade para português
 	
    	//exibe o menu de opções
		printf("---------------------------------\n");
		printf("###      Cartório da EBAC     ###\n"); 
		printf("---------------------------------\n");
    	printf("Escolha a opção desejada do menu:\n\n");
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deleta nome\n");
    	printf("Opção: ");

	
    	scanf("%d", &opcao); //%d refere-sse a armazenar a variavel (lê a opção escolha pelo usuário)
	
    	system("cls"); //limpar a tela 
    	
    	switch(opcao) //estrutura switcch para camar a função correpondente a opção escolhida
    	{
    		case 1: //opição 01
    		registro(); //chama a função de regggistro
    		break; //intterromper a execução
    			
    		case 2: //opição 02
    		consulta(); //chama a função de consulta
    		break; //intterromper a execução
    		
    		case 3: //opição 03
    		deleta(); //chama a função de deleta
    		break; //intterromper a execução
    		
    		default: //qulaquer outra opição que não esteja listada
    		printf("Essa opção não está disponivel!\n"); //mensagem para opção inválida
    		system("pause"); //pausssa a execução de sistema
    		break; //intterromper a execução
    			
		}
		    	
    }
}
