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
Sem bugs

...................................ATUALIZAÇÃO DA VERSÃO..........................
O QUE HÁ DE NOVO NESSA VERSÃO?
	Nessa versão será implementada uma função para alterar as cores do teminal de controle do windows
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(){
//CAMPO DE VARIAVEIS 
	int resposta;
	int escolaridade;
	int grauEscolaridade;
	int concordo, nConcordo, neutro;
	int graduado = 0, mestrado = 0, doutorado = 0;
	bool repetirMenu = false;
	bool repetirCadastro = false;
	bool repetirEscolaridade = false;
//DECLARAÇÃO DE FUNÇÕES
	void escolhaCor();
	void menuSobre();
//CORPO DO CODIGO
	do{
	repetirMenu = false;// foi necessario por esse codigo aki para impedir que o laço mais interno retorne para esse caso utilize a opção de voltar
		system("cls");
		printf("MENU PRINCIPAL (TELA 1)\n\n");
		printf("Novo cadastro_______(01)\n");
		printf("Exibir relatorio____(02)\n");
		printf("Configuracoes_______(03)\n");
		printf("Sobre_______________(04)\n");
		printf("Sair________________(05)\n");
		scanf("%d", &resposta);
		
		switch (resposta){
			case 1:{
				do{
				repetirCadastro = false; // foi necessario por esse codigo aki para impedir que o laço mais interno retorne para esse caso utilize a opção de voltar
					system("cls");
					printf("Novo cadastro (TELA 2)\n\n");
					printf("Veterano______(01)\n");
					printf("Egresso_______(02)\n\n");
					printf("Voltar________(03)\n");
					scanf("%d", &escolaridade);
					
					if (escolaridade == 1){
						printf("Veterano");
						break;
					}
					else if(escolaridade == 2){
					do{
					repetirEscolaridade = false;// foi necessario por esse codigo aki para impedir que o laço mais interno retorne para esse caso utilize a opção de voltar
						system("cls");
						printf("Qual seu grau de escolaridade? (TELA 3)\n\n");
						printf("Graduado__________(01)\n");
						printf("Mestrado__________(02)\n");
						printf("Doutorado_________(03)\n\n");
						printf("Voltar____________(04)\n");
						scanf("%d", &grauEscolaridade);
						switch(grauEscolaridade){
							case 1:{
								printf("Graduado\n");
								break;
							}
							case 2:{
								printf("Mestrado\n");
								break;
							}
							case 3:{
								printf("Doutorado\n");
								break;
							}
							case 4:{
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
						repetirMenu = true;
						break;
					}
					else
						printf("Desculpe escolha invalida\nTente novamente!\n");
				}while(repetirCadastro == true);
				break;
			}
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
do{
	do{
		system("cls");
		repetirTudo = false; // necessario para fazer o valor do laço de repetição para evitar entrar em loop infinito.
		printf("\xBA ESCOLHA UMA COR DE SUA PREFERENCIA\t\t\t\t       \xBA\n");
		printf("\xBA \t\t\t\t\t\t\t\t       \xBA\n");
		printf("\xBA (01) Branco & Preto\t (02) Branco & Verde\t (03) Branco & Vermelho\xBA\n");
		printf("\xBA (04) Preto & Branco\t (05) Preto e Verde\t (06) Preto & Vermelho \xBA\n");
		printf("\xBA (07) Azul & Branco\t (08) Azul & Verde\t (09) Azul & Amarelo   \xBA\n");
		printf("\xBA (10) Cinza & Preto\t (11) Cinza & Verde\t (12) Cor padrao       \xBA\n");
		printf("\xBA \t\t\t\t\t\t\t\t       \xBA\n");
		printf("\xBA >A primeira cor equivale ao fundo ja a segunda cor equivale a letra< \xBA\n");
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
				default:
					printf("Escolha invalida\nTente novamente!");
			}
		system("cls");
		printf("Você realmente deseja utilizar essa cor no terminal?\n");
		printf("      (01) Sim\t\t\t(02) Nao\n");
		scanf("%d", &certeza);
			if(certeza == 1)
				printf("Otima escolha!\n");
				
			else if (certeza == 2){
				printf("Hum... tambem nao gostei dessa cor\n");
				printf("tentar novamente!\n");
				repetirTudo = true;
			}
			else
				printf("Escolha invalida\n tente novamente!\n");
	}while(cor < 1 || cor > 12);
}while(repetirTudo == true);
}
