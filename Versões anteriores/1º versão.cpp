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

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(){
	int resposta;
	int concordo, nConcordo, neutro;
	bool reptirMenu = false;
	
	do{
		printf("MENU PRINCIPAL\n");
		printf("Novo cadastro_______(01)\n");
		printf("Exibir relatorio____(02)\n");
		printf("Configuracoes_______(03)\n");
		printf("Sobre_______________(04)\n");
		printf("Sair________________(05)\n");
		scanf("%d", &resposta);
		
		switch (resposta){
			case 1:
				int escolaridade;
				
				printf("Novo cadastro\n");
				printf("Veterano______(01)\n");
				printf("Egresso_______(02)\n");
				scanf("%d", &escolaridade);
				getch();
				break;
			case 2:
				printf("Relatorio");
				break;
			case 3:
				printf("Configuracoes\n");
				break;
			case 4:
				printf("Sobre");
				break;
			case 5:
				printf("Foi um prazer ajuda-lo!");
				system("exit");
				getch();
			break;
			default:
				system("cls");
				printf("Desculpe escolha invalida\nTente novamente!");
				reptirMenu = true;
		}
	}while (reptirMenu == true);
	
	return 0;
}
