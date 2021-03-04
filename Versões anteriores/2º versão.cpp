/******************************************************************************
Autor: Uellington da Concei��o Damasceno
Componente Curricular: Algoritimos I
Concluido em: 
Declaro que este c�digo foi elaborado por mim de forma individual e n�o contem nenhum
trecho de c�digo de outro colega ou de outro autor, tais como porvindos de livros e 
apostilas, e p�ginas ou documentos eletr�nicos da internet. Qualquer trecho de c�digo
de outra autoria que n�o a minha est� destacado com uma cita��o para o autor e a fonte
do c�digo, e estou ciente que estes trechos n�o ser�o considerados para fins de avalia��o.
*******************************************************************************/
/*
....................................BUG ENCONTRADO.................................
QUEST�O INICIAL E MOTIVADORA
COMO FAZER OS MENUS INTERAGIREM ENTRE SI ?
	Em outras palavras a pergunta era "ERA COMO VOLTAR DE QUALQUER MENU PARA O MENU PRINCIPAL?"
O QUE ERA O BUG?
	Loop infinito no "MENU DE SEGUNDO NIVEL" (menu cadastro) idependente da escolha do usario.
	
COMO ESTAVA A ESTUTURA DO CODIGO?
	Bom, a estrutura utilizada para fazer o menu proncipal foi um "switch" onde o desenvolvedor
n�o tem o completo dominio... sendo assim surgiu o bug "Volta por favor" OU (VPF).
	Sabendo da necessidade de criar uma intera��o entre os menus foi implementado um la�o de repeti��o maior
de tipo "bool"(boolano), BATIZADO DE "repetirMenu" e sendo incializado com "false"
esse la�o tem como fun��o voltar para o menu principal dependendo da escolha do usario no "MENU DE SEGUNDO NIVEL".

COMO FOI ENCONTRADO O BUG?
	O bug foi encontrado quando um "la�o menor" chamdado de "repetirCadastro" (com as mesmas caracteristicas do "la�o maior")
responsavel por impedir que o usario fa�a uma escolha indevida entrava em loop infinito logo ap�s o �sario escolher a op��o
"voltar". O que at� ent�o n�o fazia sentido por que teroricamente falando o codigo estava correto... 

COMO FOI RESOLVIDO O BUG
	Ap�s algumas tentativas (quase sempre aleatorias) foi descoberto que a maneira de quebrar o loop era colocando 
o comando "break" do "case 1" do la�o menor e alterando o valor do "la�o maior" OU "repetirMenu" para "true" fazendo
tornado veradeira a op��o de repetir o menu principal enquanto seu valor for igual a true.

QUAL � O NOVO PROBLEMA?
	Solucionando o bug o desenvolvedor estava completamente empolgado desejando loucamente um como de suco...
logo depois de uma ida a geladeira o desenvolvedor testando o codigo novamente encontrou algo muito triste 
que ele batizou de "por que n�o entra" (PQNE).
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
					break;//--------------------->SOLU��O DO BUG | esse break tem como fun��o quebrar a repeti��o do "la�o menor"<--------------------------------
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
