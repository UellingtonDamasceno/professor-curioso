/******************************************************************************
Autor: Uellington da Concei��o Damasceno
Componente Curricular: Algoritimos I
Concluido em: 
Declaro que este c�digo foi elaborado por mim de forma individual e n�o contem nenhum
trecho de c�digo de outro colega ou de outro autor, tais como porvindos de livros e 
apostilas, e p�ginas ou documentos eletr�nicos da internet. Qualquer trecho de c�digo
de outra autoria que n�o a minha est� destacado com uma cita��o para o autor e a fonte
do c�digo, e estou ciente que estes trechos n�o ser�o considerados para fins de avalia��o.
*******************************************************************************

....................................BUG ENCONTRADO.................................
AP�S RESOLVER O BUG VPF O DESENVOLVEDOR ENCONTROU O BUG PQNE.
O QUE ERA O BUG?
	Mal funcionamento das fun��es do menu principal logo depois de ter voltado do "menu cadastro".
	
COMO ESTAVA A ESTUTURA DO CODIGO?
	else if(escolaridade == 3){
		repetirCadastro = false;
		repetirMenu = true;
		break;
	}

COMO FOI ENCONTRADO O BUG?
	Falando de forma n�o formal/t�cnica o bug foi encontrado quando o usario retornava do menu cadastro para o menu 
principal. pois, sempre que o usario digitava alguma coisa no menu principal (ap�s ter retronado) as fun��es eram inutilizadas
fazendo com que o menu principal entrasse em um loop infinito e consequentemente fazendo com que a fun��o "system ("exit");" 
n�o fosse executada(quando selecionada).

COMO FOI RESOLVIDO O BUG
	puts to me sentido um idiota... 
	O bug era algo considerav�lmente simples. Pois, o bug surgiu quando o valor da la�o de repeti��o maior "repetirMenu" foi alterado 
para "true" (logo depois de resolver o VPF) e n�o era alterado em momento algum, fazendo com que o la�o ficasse em loop infinito.
para resolver o problema so foi necessario que o valor do repetirMenu fosse alterado de forma individal em cada fun��o do menu.
	
QUAL � O NOVO PROBLEMA?

EXTRA
	enquanto fu�ava o cogido descobirir que era necessario impedir que o la�o maior responsavel por repetir o menu
principal fosse neutralizado toda vez que o usario entrasse em outro menu... para evitar..
sess�o para teste? alterar o valor de qualquer uma das linhas(72,82 e 88);
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
					
					if (escolaridade == 1){
						printf("Veterano");
						repetirMenu = false;
						break;
					}
					else if(escolaridade == 2){
						printf("Egresso");
						repetirMenu = false;
						break;
					}
					else if(escolaridade == 3){
						repetirMenu = true;
						break;
					}
					else
						printf("Desculpe escolha invalida\nTente novamente!");
				}
				break;
			}
			case 2:
				printf("Relatorio\n");
				repetirMenu = false;
				break;
			case 3:
				printf("Configuracoes\n");
				repetirMenu = false;
				break;
			case 4:
				printf("Sobre\n");
				repetirMenu = false;
				break;
			case 5:{
				printf("Foi um prazer ajuda-lo!\n");
				repetirMenu = false;
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
