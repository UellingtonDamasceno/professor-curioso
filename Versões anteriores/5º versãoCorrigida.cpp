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
Sem bugs
ideia: por que n�o colocar um break na linha 78 junto com um comando para sair do loop do nivel de escolaridade
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
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
//DECLARA��O DE FUN��ES
	void menuSobre();
//CORPO DO CODIGO
	setlocale(LC_ALL, "");
	do{
	repetirMenu = false;// foi necessario por esse codigo aki para impedir que o la�o mais interno retorne para esse caso utilize a op��o de voltar
		printf("MENU PRINCIPAL (TELA 1)\n\n");
		printf("Novo cadastro_______(01)\n");
		printf("Exibir relatorio____(02)\n");
		printf("Configura��es_______(03)\n");
		printf("Sobre_______________(04)\n");
		printf("Sair________________(05)\n");
		scanf("%d", &resposta);
		
		switch (resposta){
			case 1:{
				do{
				repetirCadastro = false; // foi necessario por esse codigo aki para impedir que o la�o mais interno retorne para esse caso utilize a op��o de voltar
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
					repetirEscolaridade = false;// foi necessario por esse codigo aki para impedir que o la�o mais interno retorne para esse caso utilize a op��o de voltar
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
				printf("Configuracoes\n");
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
	printf("| VERSAO: 1.4                �| @  @|    |\n");
	printf("| NIVEL: Variavel             |   > |    |\n");
	printf("| Orientador: Danillo         |_---_|    |\n");
	printf("| Ultima altercao 31/03/2017 as 23:02 PM |\n");
	printf("'+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n");
	getch();
	system("cls");
}
