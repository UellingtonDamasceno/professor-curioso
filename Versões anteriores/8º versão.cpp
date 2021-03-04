/******************************************************************************
Autor: Uellington da Conceição Damasceno
Componente Curricular: Algoritimos I
Concluido em: 
Declaro que este código foi elaborado por mim de forma individual e não contem nenhum
trecho de código de outro colega ou de outro autor, tais como porvindos de livros e 
apostilas, e páginas ou documentos eletrônicos da internet. Qualquer trecho de código
de outra autoria que não a minha está destacado com uma citação para o autor e a fonte
do código, e estou ciente que estes trechos não serão considerados para fins de avaliação.
*******************************************************************************

....................................BUG ENCONTRADO.................................
O QUE É O BUG?
	O bug consiste em um mal funcionamento do menu "grau de escolaridade". 
o bug faz com que o menu anterior (veterano ou egresso) aparece ao inves de finalizar 
o software. pois não existe nenhuma outra instrução além de um incrementador...

nome do bug: "Volto mesmo" ou VMS.
...................................ATUALIZAÇÃO DA VERSÃO..........................

*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void barraSup(int x){
	printf("\xC9");
	for(int i = 0; i<x; i++)
		printf("\xCD");
	printf("\xBB\n");
}
void barraInf(int x){
	printf("\xC8");
	for(int i = 0; i<x; i++)
		printf("\xCD");
	printf("\xBC\n");
}
int main(){
//CAMPO DE VARIAVEIS 
	int resposta;
	int idade, sexo, homem, mulher;
	int escolaridade;
	int grauEscolaridade;
	int concordo, nConcordo, neutro;
	int veterano = 0, egresso = 0, graduado = 0, mestrado = 0, doutorado = 0;
	bool repetirMenu = false;
	bool repetirCadastro = false;
	bool repetirIdade = false;
	bool repetirSexo = false;
	bool repetirEscolaridade = false;
//DECLARAÇÃO DE FUNÇÕES
	void escolhaCor();
	void menuSobre();
//CORPO DO CODIGO
	do{
	repetirMenu = false;// foi necessario por esse codigo aki para impedir que o laço mais interno retorne para esse caso utilize a opção de voltar
		//system("cls");
	barraSup(25);
		printf("\xBA\tMENU PRINCIPAL\t  \xBA\n\xBA\t\t\t  \xBA\n");
		printf("\xBA Novo cadastro_______(01)\xBA\n");
		printf("\xBA Exibir relatorio____(02)\xBA\n");
		printf("\xBA Configuracoes_______(03)\xBA\n");
		printf("\xBA Sobre_______________(04)\xBA\n");
		printf("\xBA Sair________________(05)\xBA\n");
	barraInf(25);
		scanf("%d", &resposta);
		
		switch (resposta){
			case 1:{
				do{
				repetirCadastro = false; // foi necessario por esse codigo aki para impedir que o laço mais interno retorne para esse caso utilize a opção de voltar
					//system("cls");
					do{
					repetirIdade = false;// impedir loops infinitos.
					printf("Qual sua idade?\n");
					scanf("%d", &idade);
						if (idade < 15 || idade > 100){
							printf("Imporvavel\nTente novamente!\n");
							repetirIdade = true;
						}
					}while(repetirIdade == true);
					do{
						repetirSexo = false; //caso o laço repita o valor será reniciado para evitar loops infinitos.
					printf("Qual seu sexo?\n");
					printf("(1)_Masculino (2)_Femenino\n Voltar_________(3)\n");
						scanf("%d", &sexo);
					if (sexo == 1)
						homem ++;
					else if(sexo == 2)
						mulher++;
					else if (sexo == 3)
						repetirMenu = true;
					else{
						printf("Escolha invalidada\nTente novamente!\n");
						repetirSexo = true;
					}
					}while(repetirSexo == true);
					while(repetirMenu == false){//laço que serve para impedir que faça a proxima pergunta caso o usario tenha digitado voltar na pergunta anterior
					barraSup(20);
					printf("\xBA   Novo cadastro    \xBA\n\xBA\t\t     \xBA\n");
					printf("\xBA Veterano______(01) \xBA\n");
					printf("\xBA Egresso_______(02) \xBA\n\xBA\t\t     \xBA\n");
					printf("\xBA Voltar________(03) \xBA\n");
					barraInf(20);
					scanf("%d", &escolaridade);
					if (escolaridade == 1){
						veterano ++;
					}
					else if(escolaridade == 2){
						egresso++; // contador de egressos.
					do{
					repetirEscolaridade = false;// foi necessario por esse codigo aki para impedir que o laço mais interno retorne para esse caso utilize a opção de voltar
						//system("cls");
						barraSup(30);
						printf("\xBA   Qual grau de escolaridade? \xBA\n\xBA\t\t\t       \xBA\n");
						printf("\xBA    Graduado__________(01)    \xBA\n");
						printf("\xBA    Mestrado__________(02)    \xBA\n");
						printf("\xBA    Doutorado_________(03)    \xBA\n\xBA\t\t\t       \xBA\n");
						printf("\xBA    Voltar____________(04)    \xBA\n");
						barraInf(30);
						
						scanf("%d", &grauEscolaridade);
						switch(grauEscolaridade){
							case 1:{
								graduado ++;
							break;
							}
							case 2:{
								mestrado ++;
							break;
							}
							case 3:{
								doutorado ++;
							break;
							}
							case 4:{
								if (escolaridade ==  1) 
									veterano--; //se o usario não tiver terminado o cadastro e voltar irá decrentar do contador a ultima escolha valida 
								else if(escolaridade == 2)// no caso essa escolha seria os veteranos ou egressos. pois se o usario digitar um numero 
									egresso--;//entre 1 a 3 vai aumentar o grau de esoclaridade. em outras palavras para derementar o doutorado ou qq outro grau é necessario
									//inplmentar a função para voltar no menu de idade.
								repetirCadastro = true;
								break;
							}
							default:
								printf("Escolha invalida\nTente novamente!\n");
						}
					}while(repetirEscolaridade == true);
						//break; descobirir o que esse break faz...
					}
					else if(escolaridade == 3){
						if (sexo == 1)
							homem--;
						else if(sexo == 2)
							mulher--;
						repetirMenu = true;
						break;
					}
					else
						printf("Desculpe escolha invalida\nTente novamente!\n");
			}
				}while(repetirCadastro == true);
			}
				break;
			case 2:
				printf("Relatorio\n");
				break;
			case 3:
				escolhaCor();
				repetirMenu = true;
				break;
			case 4:{
				menuSobre();
				repetirMenu = true;
				break;
			}
			case 5:{
				printf("Foi um prazer ajuda-lo!\n");
				system("exit");
				break;
			}
			default:
				system("cls");
				printf("Desculpe escolha invalida\nTente novamente!\n");
				repetirMenu = true;
		}
	}while (repetirMenu == true);
	return 0;
}
void menuSobre(){
	printf("'+=+=+=+=+=+=+= #Sobre# =+=+=+=+=+=+=+=+=+\n");
	printf("| DESENVOLVEDOR: Uellington Damasceno    |\n");
	printf("| DATA DO INICIO: 31/03/2017  |||||||    |\n");
	printf("| VERSAO: 1.4                ª| @  @|    |\n");
	printf("| NIVEL: Variavel             |   > |    |\n");
	printf("| Orientador: Danillo         |_---_|    |\n");
	printf("| Ultima altercao 31/03/2017 as 23:02 PM |\n");
	printf("'+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n");
	getch();
	system("cls");
}
void escolhaCor(){
	int cor;
	int certeza;
	bool repetirTudo = false;
	bool repetirCor = false;
do{
	do{
		repetirTudo = false; // necessario para fazer o valor do laço de repetição para evitar entrar em loop infinito.
		barraSup(70);
		printf("\xBA\t\t    ESCOLHA UMA COR DE SUA PREFERENCIA\t\t       \xBA\n");
		printf("\xBA \t\t\t\t\t\t\t\t       \xBA\n");
		printf("\xBA (01) Branco & Preto\t (02) Branco & Verde\t (03) Branco & Vermelho\xBA\n");
		printf("\xBA (04) Preto & Branco\t (05) Preto e Verde\t (06) Preto & Vermelho \xBA\n");
		printf("\xBA (07) Azul & Branco\t (08) Azul & Verde\t (09) Azul & Amarelo   \xBA\n");
		printf("\xBA (10) Cinza & Preto\t (11) Cinza & Verde\t (12) Cor padrao       \xBA\n");
		printf("\xBA \t\t\t\t\t\t\t\t       \xBA\n");
		printf("\xBA >A primeira cor equivale ao fundo ja a segunda cor equivale a letra< \xBA\n");
		barraInf(70);
		scanf("%d", &cor);
			switch(cor){
				case 1:
					system("color f0");
					break;
				case 2:
					system("color f2");
					break;
				case 3:
					system("color fc");
					break;
				case 4:
					system("color 0f");
					break;
				case 5:
					system("color 0a");
					break;
				case 6:
					system("color 0c");
					break;
				case 7:
					system("color 1f");
					break;
				case 8:
					system("color 1a");
					break;
				case 9:
					system("color 16");
					break;
				case 10:
					system("color 80");
					break;
				case 11:
					system ("color 8a");
					break;
				case 12:
					system("color 07");
					break;
				default:{
					system("cls");
					printf("Escolha invalida\nTente novamente!\n\n");
				}
			}
		}while(cor < 1 || cor > 12);
		system("cls");
		do{
		repetirCor == false;
		printf("Voce realmente deseja utilizar essa cor no terminal?\n");
		printf("      (01) Sim\t\t\t(02) Nao\n");	scanf("%d", &certeza);
			if(certeza == 1){
				printf("Otima escolha!\n");
				break;
			}
			else if (certeza == 2){
				system("cls");
				printf("Hum... tambem nao gostei dessa cor\n");
				printf("tentar novamente!\n\n\n");
				repetirTudo = true;
				break;
			}
			else{
				printf("Escolha invalida\nTente novamente!\n\n");
				repetirCor = true;
			}
		}while(repetirCor == true);
}while(repetirTudo == true);
}
