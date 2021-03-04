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
APÓS RESOLVER O BUG VPF O DESENVOLVEDOR ENCONTROU O BUG PQNE.
O QUE ERA O BUG?
	Mal funcionamento das funções do menu principal logo depois de ter voltado do "menu cadastro".
	
COMO ESTAVA A ESTUTURA DO CODIGO?
	else if(escolaridade == 3){
		repetirCadastro = false;
		repetirMenu = true;
		break;
	}

COMO FOI ENCONTRADO O BUG?
	Falando de forma não formal/técnica o bug foi encontrado quando o usario retornava do menu cadastro para o menu 
principal. pois, sempre que o usario digitava alguma coisa no menu principal (após ter retronado) as funções eram inutilizadas
fazendo com que o menu principal entrasse em um loop infinito e consequentemente fazendo com que a função "system ("exit");" 
não fosse executada(quando selecionada).

COMO FOI RESOLVIDO O BUG
	puts to me sentido um idiota... 
	O bug era algo consideravélmente simples. Pois, o bug surgiu quando o valor da laço de repetição maior "repetirMenu" foi alterado 
para "true" (logo depois de resolver o VPF) e não era alterado em momento algum, fazendo com que o laço ficasse em loop infinito.
para resolver o problema so foi necessario que o valor do repetirMenu fosse alterado de forma individal em cada função do menu.
	
QUAL É O NOVO PROBLEMA?

EXTRA
	enquanto fuçava o cogido descobirir que era necessario impedir que o laço maior responsavel por repetir o menu
principal fosse neutralizado toda vez que o usario entrasse em outro menu... para evitar..
sessão para teste? alterar o valor de qualquer uma das linhas(72,82 e 88);
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
