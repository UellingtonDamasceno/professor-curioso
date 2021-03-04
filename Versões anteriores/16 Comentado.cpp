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
SEM BUG'S
...................................ATUALIZAÇÃO DA VERSÃO..........................
CODIGO FUNCIONAL FALTA APENAS IPLEMENTAR A ULTIMA FUNÇÃO QUE É DE CAUCULAR A MEDIA DE IDADE DAS PESSOAS
NOS ANOS DE CONCLUSÃO DO CURSO.
	
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void barraSup(int x){//necessario para desenhar as barras superirores.
	int i;
	printf("\xC9");
	for(i = 0; i<x; i++){
		printf("\xCD");
	}
	printf("\xBB\n");
}
void barraInf(int x){
	int j;
	printf("\xC8");
	for(j = 0; j<x; j++){
		printf("\xCD");
	}
	printf("\xBC\n");
}
int main(){
//CAMPO DE VARIAVEIS 
	float mediaIdade, idadeConclusao, iConclusaoM;
	int resposta, contadorIdade = 0;
	int idadeTotal, idade, idadeAtual, sexo, homem, mulherCurso = 0,mulherEgressa = 0;
	int escolaridade, grauEscolaridade;
	int concordoTotal = 0, nConcordoTotal = 0, neutroTotal = 0;
	int concordoP1 = 0,concordoP4 = 0, concordoP5 = 0;
	int nConcordoP2 = 0 , nConcordoP3 = 0, nConcordoP5 = 0;
	int neutroP2 = 0, neutroP5 = 0;
	int anoFormatura, pesquisa = 1;
//variaveis de controles de laço. necessarias para fazer a opção de voltar entre os menus.
	int repetirMenu = 0, repetirCadastro = 0;
	int repetirIdade = 0, repetirSexo = 0;
	int repetirEscolaridade = 0;
	int repetirFormatura = 0;
	int repetirPergunta = 0, repetirConfirmacao = 0;
	
	do{//laço resposavel por repetir o menu principal quando necessario
		repetirMenu = 0;// serve para impedir que o laço entre em loop infinito. pois durante a execução das instruçoes que ficam dentro do laço a variavel sofre uma alterção para ver
						//dadeiro. por isso é necessario que exista uma nova alteração para o valor falso. 
		barraSup(26);
		printf("\xBA\tMENU PRINCIPAL\t   \xBA\n\xBA\t\t\t   \xBA\n");
		printf("\xBA Nova pesquisa_______(01) \xBA\n");
		printf("\xBA Exibir relatorio____(02) \xBA\n");
		printf("\xBA Configuracoes_______(03) \xBA\n");
		printf("\xBA Sobre_______________(04) \xBA\n");
		printf("\xBA Sair________________(05) \xBA\n");
		printf("\xBA                          \xBA\n");
		barraInf(26);
		scanf("%d", &resposta);// pega a escolha do usario
		switch (resposta){//começa a decidir o que fazer com a escolha do usario
			case 1:{
				do{//laço usado para repetir todo o cadastro caaso o usario queira fazer outro cadastro
					repetirCadastro = 0; // usado para impedir que o laço entre em loop infinito
					do{//responsavel por repetir do menu sexo para o menu idade.
						do{//resposavel por repetir todo o trecho de idade caso o usario digite uma idade invalida ou não tenha certeza
							repetirIdade = 0;//impedir loop infinito.
							printf("Qual sua idade?\n");//pergunta
							scanf("%d", &idadeAtual);//leitrua da escolha do usario
							if (idadeAtual < 10 || idadeAtual > 100){//verifica se a idade digitada esta dentro dos criterios 
								printf("Imporvavel\nTente novamente!\n");//mensagem de erro que aparece quando o usario não digita uma idade valida
								repetirIdade = 1;//controle do laço repetirIdade
							}//fim do if que imprime a mensagem de erro
							else{//caso o usario tenha digitado uma idade dentro dos criterio entrá nessa condição.
								do{//repetir a confirmação se o usario digitar um valor invalido
									printf("Confirmacao da idade\n");//
									printf("Voce realmente tem: %d Anos\n", idadeAtual);
									printf("Sim_(01)           Nao_(02)\n");
									scanf("%d", &resposta);//leitura da escolha de confirmação de idade
									if (resposta < 1 || resposta > 2)
										printf("Escolha invalida\n\n");
									else if(resposta == 2)
											repetirIdade = 1;
								}while(resposta < 1 || resposta > 2);// fim do laço de controle. repetir confirmação do usario.
							}//fim do else do menu idade.
						}while(repetirIdade == 1);
					do{//serve para fazer com que o usario possa voltar do menu escolaridade para sexo
						do{//serve para repetir o menu sexo caso o usario digite um valor invalido
							barraSup(29);
							printf("\xBA\t Qual seu sexo?       \xBA\n");
							printf("\xBA\t\t\t      \xBA\n");
							printf("\xBA Masculino_(1)  Femenino_(2) \xBA\n");
							printf("\xBA Voltar__________________(3) \xBA\n");
							barraInf(29);
							scanf("%d", &sexo);//leitura da escolha do sexo do usario
							if (sexo == 3){//verifica se o usario deseja voltar para o menu idade.
								repetirIdade = 1;//controle do lação de repetição de idade
								//break; testar para ver se funciona sem ele
							}
							else if(sexo > 3 || sexo < 1)// responsavel por verificar e imprimir a mensagem de erro se for necessario
								printf("Escolha invalidada\nTente novamente!\n");//mensagem de erro
						}while(sexo > 3 || sexo < 1);
						while(repetirIdade != 1){ // serve para impedir que o programa continue execultadno caso ele tenha pedido para repetir a idade.
						do{
						do{// responsavel por repetir o menu de escolaridade se o usario digitar um valor invalido
							repetirEscolaridade = 0;
							barraSup(20);
							printf("\xBA   Novo cadastro    \xBA\n\xBA\t\t     \xBA\n");
							printf("\xBA Veterano______(01) \xBA\n");
							printf("\xBA Egresso_______(02) \xBA\n\xBA\t\t     \xBA\n");
							printf("\xBA Voltar________(03) \xBA\n");
							barraInf(20);
								scanf("%d", &escolaridade);//leitura da escolaridade do usario 
								if (escolaridade < 1 || escolaridade > 3){//verifica e mostra a mensagem de erros se necessario
									printf("Escolha invalida\nTente novamente!\n");
									repetirEscolaridade = 1;
								}
								else if(escolaridade == 2 ){//caso o usario digite que é egresso.
									do{//responsavel por repetir o menu grau de esolaridade caso o usario digite um valor invalido
										repetirEscolaridade = 0;// foi necessario por esse codigo aki para impedir que o laço mais interno retorne para esse caso utilize a opção de voltar
										//system("cls");
										barraSup(30);
										printf("\xBA   Qual grau de escolaridade? \xBA\n");
										printf("\xBA\t\t\t       \xBA\n");
										printf("\xBA    Especializacao____(01)    \xBA\n");
										printf("\xBA    Graduado__________(02)    \xBA\n");
										printf("\xBA    Mestrado__________(03)    \xBA\n");
										printf("\xBA    Doutorado_________(04)    \xBA\n");
										printf("\xBA\t\t\t       \xBA\n");
										printf("\xBA    Voltar____________(05)    \xBA\n");
										barraInf(30);		
										scanf("%d", &grauEscolaridade);// faz a leitura da escolha do usario com relação ao grau de escolaridade
										if(grauEscolaridade < 1 || grauEscolaridade > 5){//mensagem de erro caso o usario digite um valor invalido
											printf("Escolha invalida\nTente novamente!\n");
											repetirEscolaridade = 1;
										}//fim do else de mensagem de erro
										else if (grauEscolaridade == 5){
											repetirEscolaridade = 1;
										}
									}while(grauEscolaridade < 1 || grauEscolaridade > 5);
								}//fim menu escolaridade
								else if(escolaridade == 3){
								printf("esta aki\n");
								repetirSexo = 1;
								break;
								}
							}while(escolaridade < 1 || escolaridade > 3);
						}while(repetirEscolaridade == 1);
//====================================================pergunta formaura================================================================
						while(repetirSexo != 1){//impedir que o programa continue se o usario pedir para voltar para o menu de sexo
						do{//serve para repetir o ano de formatura do usario caso digite algum ano invalido.
							repetirFormatura = 0;//impedir que entre em loop infinito
							printf("Ano da formatura?\n");
							scanf("%d", &anoFormatura);//leitura da escolha do usario com relação ao ano de formatura
							if (anoFormatura < 1900 || anoFormatura > 2017){//verifica e mostra a mensagem de erro caso necessario
								printf("Escolha invalida\n tente novamete\n");//mensagem de erro que aparecerá para o usario caso a escolha tenha sido indevida
								repetirFormatura = 1;
							}
							do{//laço de repetição usado para impedir que o usario digite um valor invalido
								printf("Confirmacao do ano de formatura\n");
								printf("SIM_(01)               NAO_(02)\n");
								scanf("%d", &resposta);//recebe a escolha do usario
								if (resposta < 1 || resposta > 2){//verifica e mostra uma mensagem de erro caso necessario
									printf("Escolha invalida\nDigite novamente\n\n");//mensagem de erro
								}
								else if(resposta == 2)//verifica e repete e o ano de formatura do usario se necessario.
									repetirFormatura = 1;//alteração na variavel de controle
							}while(resposta < 1 || resposta > 2);
						}while(repetirFormatura == 1);
					do{//PERGUNTA 01 // serve para repetir a pergunta caso o usuario tenha digitado um valor invalido
						repetirPergunta = 0;//serve para impedir que o laço entre em loop infinito
						printf("PERGUNTAS (1/5)\n");
						printf("Voce concorda que o PBL ajuda na execucao de seus trabalhos?\n");
						printf("CONCORDO (00)\t NAO CONCORDO (01)\t NAO TEM OPINIAO (02)\n");
						scanf("%d", &resposta);
						switch(resposta){
							case 0:{
								concordoTotal++;
								concordoP1++;
								break;
							}
							case 1:{
								nConcordoTotal++;
								break;
							}
							case 2:{
								neutroTotal++;
								break;
							}
							default:{
								printf("Escolha invalida\nTente novamente!");
								repetirPergunta = 1;
							}
						}//fim do switch de respostas
					}while (repetirPergunta == 1);
					do{
						repetirPergunta = 0;
						printf("PERGUNTA (2/5)\n");
						printf("Voce concorda que o PBL é melhor que o metodo tradicional?\n");
						printf("CONCORDO (00)\t NAO CONCORDO (01)\t NAO TEM OPINIAO (02)\n");
						scanf("%d", &resposta);
						switch(resposta){
							case 0:{
								concordoTotal++;
								break;
							}
							case 1:{
								nConcordoTotal++;
								nConcordoP2++;
								break;
							}
							case 2:{
								neutroTotal++;
								neutroP2;
								break;
							}
							default:{
								printf("Escolha invalida\nTente novamente!");
								repetirPergunta = 1;
								break;
							}
						}
					}while(repetirPergunta == 1);
					do{//PERGUNTA 03
						repetirPergunta = 0;
						printf("PERGUNTA (3/5)\n");
						printf("O mercado de trabalho local e capaz de reter os prifissionais\nformados nas areas de informatica e engenharia?\n");
						printf("CONCORDO (00)\t NAO CONCORDO (01)\t NAO TEM OPINIAO (02)\n");
						scanf("%d", &resposta);
						switch(resposta){
							case 0:{
								concordoTotal++;
								break;
							}
							case 1:{
								nConcordoTotal++;
								idadeTotal = idadeTotal + idadeAtual;
								if(pesquisa != 0){ // usado para evitar que o softwares trave se por acaso a conta for feita com o divisor = 0.
								mediaIdade = idadeTotal / pesquisa; //pesquisa é o node da varivael que contabiliza quantas pessoas foram intrevistadas.
								}
								break;
							}
							case 2:{
								neutroTotal++;
								break;
							}
							default:{
								printf("Escolha invalida\nTente novamente!");
								repetirPergunta = 1;
								break;
							}
						}
					}while (repetirPergunta == 1);
					do{//PERGUNTA 04
						repetirPergunta = 0;
						printf("PERGUNTA (4/5)\n");
						printf("Voce concorda que os novos alunos desconhecem o PBL quando entram no curso?\n");
						printf("CONCORDO (00)\t NAO CONCORDO (01)\t NAO TEM OPINIAO (02)\n");
						scanf("%d", &resposta);
						switch(resposta){
							case 0:{
								concordoTotal++;
								concordoP4++;
								break;
							}
							case 1:{
								nConcordoTotal++;
								break;
							}
							case 2:{
								neutroTotal++;
								break;
							}
							default:{
								printf("Escolha invalida\nTente novamente!");
								repetirPergunta = 1;
								break;
							}
						}
					}while (repetirPergunta == 1);
					do{//PERGUNTA 05
						repetirPergunta = 0;
						printf("PERGUNTA (5/5)\n");
						printf("Concorda que um aluno so consegue se adaptar com o PBL somente apartir do 4º semestre?\n");
						printf("CONCORDO (00)\t NAO CONCORDO (01)\t NAO TEM OPINIAO (02)\n");
						scanf("%d", &resposta);
						switch(resposta){
							case 0:{
								concordoTotal++;
								if(escolaridade == 1){
									concordoP5++;
								}	
								break;
							}
							case 1:{
								nConcordoTotal++;
								break;
							}
							case 2:{
								neutroTotal++;
								if(escolaridade == 1){
									neutroP5++;
								}		
								break;
							}
							default:{
								printf("Escolha invalida\nTente novamente!");
								repetirPergunta = 1;
								break;
							}
						}
					}while (repetirPergunta == 1);
				}
				}//fim do laço que impede que continue se o usario peça para repetir a idade
					}while(repetirSexo == 1);
					}while(repetirIdade == 1);
				}while(repetirCadastro == 1);
				break;
			}//fim do case 1 do switch resposta do menu principal
		}//fim do switch responsavel por receber a resposta do usario no menu principal.
	}while(repetirMenu == 1);
}
