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
	void menuSobre(void);
	bool novoCadastro();
	bool repetirMenu = false;
	int resposta;
	setlocale(LC_ALL,"");
	do{
		printf("MENU PRINCIPAL\n");
		printf("Novo cadastro_______(01)\n");
		printf("Exibir relatorio____(02)\n");
		printf("Configura��es_______(03)\n");
		printf("Sobre_______________(04)\n");
		printf("Sair________________(05)\n");
		scanf("%d", &resposta);
		
		switch (resposta){
			case 1:{
				novoCadastro();
				break;
			}
			case 2:
				printf("Relatorio\n");
				repetirMenu = true;
				break;
			case 3:
				printf("Configuracoes\n");
				repetirMenu = true;
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
void menuSobre(void){
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
int novoCadastro(void){
	int escolaridade;
	int grauEscolaridade;
	int graduado = 0, mestrado = 0, doutorado = 0;
	bool repetirCadastro = false;
	bool repetirEscolaridade = false;
	
	do{
		printf("Novo cadastro\n");
		printf("Veterano______(01)\n");
		printf("Egresso_______(02)\n");
		printf("Voltar________(03)\n");
		scanf("%d", &escolaridade);
			switch(escolaridade){
				case 1:{
					printf("Veterano\n");
					break;
				}
				case 2:{
					do{
					printf("Qual seu grau de escolaridade?\n");
					printf("Graduado__________(01)\n");
					printf("Mestrado__________(02)\n");
					printf("Doutorado_________(03)\n");
					printf("Voltar____________(04)\n");
					scanf("%d", &grauEscolaridade);
					switch(grauEscolaridade){
						case 1:{
							printf("Graduado\n");
							repetirCadastro = false;
							repetirEscolaridade = false;
							//break;
						}
						case 2:{
							printf("Mestrado\n");
							//break;
						}
						case 3:{
							printf("Doutorado\n");
							//break;
						}
						case 4:{
							repetirCadastro = true;
							//break;
						}
						default:
							printf("Escolha invalida\nTente novamente!\n");
					}
				}while(repetirEscolaridade == true); 
					break;
				}
				case 3:{
					printf("Voltando\n");
					break;
				}
				default:
					printf("Escolha invalida\nTente novamente\n");
			}
		}while(repetirCadastro == true);
}
