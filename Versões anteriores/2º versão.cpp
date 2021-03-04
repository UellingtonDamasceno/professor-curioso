/******************************************************************************
Autor: Uellington da Conceição Damasceno
Componente Curricular: Algoritimos I
Concluido em: 
Declaro que este código foi elaborado por mim de forma individual e não contem nenhum
trecho de código de outro colega ou de outro autor, tais como porvindos de livros e 
apostilas, e páginas ou documentos eletrônicos da internet. Qualquer trecho de código
de outra autoria que não a minha está destacado com uma citação para o autor e a fonte
do código, e estou ciente que estes trechos não serão considerados para fins de avaliação.
*******************************************************************************/
/*
....................................BUG ENCONTRADO.................................
QUESTÃO INICIAL E MOTIVADORA
COMO FAZER OS MENUS INTERAGIREM ENTRE SI ?
	Em outras palavras a pergunta era "ERA COMO VOLTAR DE QUALQUER MENU PARA O MENU PRINCIPAL?"
O QUE ERA O BUG?
	Loop infinito no "MENU DE SEGUNDO NIVEL" (menu cadastro) idependente da escolha do usario.
	
COMO ESTAVA A ESTUTURA DO CODIGO?
	Bom, a estrutura utilizada para fazer o menu proncipal foi um "switch" onde o desenvolvedor
não tem o completo dominio... sendo assim surgiu o bug "Volta por favor" OU (VPF).
	Sabendo da necessidade de criar uma interação entre os menus foi implementado um laço de repetição maior
de tipo "bool"(boolano), BATIZADO DE "repetirMenu" e sendo incializado com "false"
esse laço tem como função voltar para o menu principal dependendo da escolha do usario no "MENU DE SEGUNDO NIVEL".

COMO FOI ENCONTRADO O BUG?
	O bug foi encontrado quando um "laço menor" chamdado de "repetirCadastro" (com as mesmas caracteristicas do "laço maior")
responsavel por impedir que o usario faça uma escolha indevida entrava em loop infinito logo após o úsario escolher a opção
"voltar". O que até então não fazia sentido por que teroricamente falando o codigo estava correto... 

COMO FOI RESOLVIDO O BUG
	Após algumas tentativas (quase sempre aleatorias) foi descoberto que a maneira de quebrar o loop era colocando 
o comando "break" do "case 1" do laço menor e alterando o valor do "laço maior" OU "repetirMenu" para "true" fazendo
tornado veradeira a opção de repetir o menu principal enquanto seu valor for igual a true.

QUAL É O NOVO PROBLEMA?
	Solucionando o bug o desenvolvedor estava completamente empolgado desejando loucamente um como de suco...
logo depois de uma ida a geladeira o desenvolvedor testando o codigo novamente encontrou algo muito triste 
que ele batizou de "por que não entra" (PQNE).
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(){
	int resposta;
	int concordo, nConcordo, neutro;
	bool repetirMenu = false;
	
	do{
		printf("MENU PRINCIPAL\n");
		printf("Novo cadastro_______(01)\n");
		printf("Exibir relatorio____(02)\n");
		printf("Configuracoes_______(03)\n");
		printf("Sobre_______________(04)\n");
		printf("Sair________________(05)\n");
		scanf("%d", &resposta);
		
		switch (resposta){
			case 1:{
				int escolaridade;
				bool repetirCadastro = true;
				while(repetirCadastro = true){
					printf("Novo cadastro\n");
					printf("Veterano______(01)\n");
					printf("Egresso_______(02)\n");
					printf("Voltar________(03)\n");
					scanf("%d", &escolaridade);
//CODIGO FUNCIONAL 
					if (escolaridade == 1){
						printf("veterano");
					}
					else if(escolaridade == 2){
						printf("Egresso");
					}
					else if(escolaridade == 3){
						repetirCadastro = false;
						repetirMenu = true;
					break;//--------------------->SOLUÇÃO DO BUG | esse break tem como função quebrar a repetição do "laço menor"<--------------------------------
					}
					else
						printf("Desculpe escolha invalida\nTente novamente!");
/*CODIGO DESEJADO QUE APRESENTAVA O BUG
					switch(escolaridade){
						case 1:
							printf("veterano");
							break;
						case 2:
							printf("Egresso");
							break;
						case 3:{
							printf("Voltando");
							repetirCadastro = false;
							repetirMenu = true;
						break;
						}
						default:{
							system("cls");
							printf("Desculpe escolha invalida\nTente novamente!");
							repetirCadastro = true;	
						}
					}*/
				}
				break;
			}
			case 2:
				printf("Relatorio");
				break;
			case 3:
				printf("Configuracoes\n");
				break;
			case 4:
				printf("Sobre");
				break;
			case 5:{
				printf("Foi um prazer ajuda-lo!");
				system("exit");
				getch();
			break;
			}
			default:
				system("cls");
				printf("Desculpe escolha invalida\nTente novamente!");
				repetirMenu = true;
		}
	}while (repetirMenu == true);
	
	return 0;
}
