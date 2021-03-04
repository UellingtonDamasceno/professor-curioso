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
ideia: por que não colocar um break na linha 78 junto com um comando para sair do loop do nivel de escolaridade
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
menuSobre(){
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
int main(){
	int resposta;
	int concordo, nConcordo, neutro;
	int grauEscolaridade;
	int graduado = 0, mestrado = 0, doutorado = 0;
	bool repetirMenu = false;
	bool repetirEscolaridade = false;
						
	do{
		printf("MENU PRINCIPAL (TELA 1)\n");
		printf("Novo cadastro_______(01)\n");
		printf("Exibir relatorio____(02)\n");
		printf("Configuracoes_______(03)\n");
		printf("Sobre_______________(04)\n");
		printf("Sair________________(05)\n");
		scanf("%d", &resposta);
		
		switch (resposta){
			case 1:{
				int escolaridade;
				bool repetirCadastro = false;
				do{
					printf("Novo cadastro (TELA 2)\n");
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
					do{
						printf("Qual seu grau de escolaridade? (TELA 3)\n");
						printf("Graduado__________(01)\n");
						printf("Mestrado__________(02)\n");
						printf("Doutorado_________(03)\n");
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
						printf("Desculpe escolha invalida\nTente novamente!");
				}while(repetirCadastro == true);
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
				menuSobre();
				repetirMenu = true;
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
