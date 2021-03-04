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
*/
#include <stdio.h>

void barraSup(int largura){
	int i;
	printf("\xC9");
	for(i = 0; i<largura; i++){
		printf("\xCD");
	}
	printf("\xBB\n");
}
void barraInf(int largura){
	int i;
	printf("\xC8");
	for(i = 0; i<largura; i++){
		printf("\xCD");
}
	printf("\xBC\n");
}
int main(){
//CAMPO DE VARIAVEIS 
	int resposta = 0;//usada para confirmações, escolhas em menus e resposta não valiosas ou que não serão utilizadas para nenhum porcessamento 
	int idadeAtual, sexo, mulherCurso = 0,mulherEgressa = 0;
	int escolaridade, grauEscolaridade;
	float mediaIdadeP3, idadeTotalP3, resP2;//serve para calcular a media de idade dos entrevistados que não concordam com a questão 3
	float idadeConV = 0, idadeConE = 0, iConclusaoM = 0, idadeTotal = 0;//utilizadas para fazer o calculo de media de idade dos estudadantes no ano de conclusão.
	
// Variaves referentes a perguntas perguntas
	int concordoTotal = 0, nConcordoTotal = 0, neutroTotal = 0;//serve para contar o numero total de concordo, não concordo e naõ tem opinião.
	int concordoP1 = 0,concordoP4 = 0, concordoP5 = 0; // usado para armazenar valores de concordancia que será utilizado no relatorio
	int nConcordoP2 = 0, nConcordoP5 = 0;//responsavel por armazenar valores de pessoas que não concordam com determinada questão
	int neutroP2 = 0, neutroP5 = 0;// responsavel por armazenar valores que será usado nos relatorio 
	int anoFormatura, pesquisa = 1;
//variaveis de controles de laço. necessarias para fazer a interação entre os menus.
	int repetirMenu = 0, repetirCadastro = 0;
	int repetirIdade = 0, repetirSexo = 0;
	int repetirEscolaridade = 0;
	int repetirFormatura = 0;

	do{//laço resposavel por repetir o menu principal quando necessario
		system("cls");
		resposta = 0;
		repetirMenu = 0;// serve para impedir que o laço entre em loop infinito. pois durante a execução das instruçoes que ficam dentro do laço a variavel sofre uma alterção para ver
					//dadeiro. por isso é necessario que exista uma nova alteração para o valor falso. 
		barraSup(26);
		printf("\xBA\tMENU PRINCIPAL\t   \xBA\n\xBA\t\t\t   \xBA\n");
		printf("\xBA Nova pesquisa_______(01) \xBA\n");
		printf("\xBA Exibir relatorio____(02) \xBA\n");
		printf("\xBA Sobre_______________(03) \xBA\n");
		printf("\xBA Sair________________(04) \xBA\n");
		printf("\xBA                          \xBA\n");
		barraInf(26);
		scanf("%d", &resposta);// pega a escolha do usario
		fflush(stdin);
		switch (resposta){//começa a decidir o que fazer com a escolha do usario
			case 1:{
				do{//laço usado para repetir todo o cadastro caaso o usario queira fazer outro cadastro
					repetirCadastro = 0; // usado para impedir que o laço entre em loop infinito
					do{//responsavel por repetir do menu sexo para o menu idade.
						do{//resposavel por repetir todo o trecho de idade caso o usario digite uma idade invalida ou não tenha certeza
							system("cls");
							idadeAtual = 0;
							repetirIdade = 0;//impedir loop infinito.
							printf("Qual sua idade?\n");//pergunta
							scanf("%d", &idadeAtual);//leitrua da escolha do usario
							fflush(stdin);
							if (idadeAtual < 10 || idadeAtual > 100){//verifica se a idade digitada esta dentro dos criterios 
								printf("\nAlgo esta errado\nTente novamente!\nDigite um numero entre 10 e 100\n\n");//mensagem de erro que aparece quando o usario não digita uma idade valida
								repetirIdade = 1;//controle do laço repetirIdade
								system("pause");
							}//fim do if que imprime a mensagem de erro
							else{//caso o usario tenha digitado uma idade dentro dos criterio entrá nessa condição.
								do{//repetir a confirmação se o usario digitar um valor invalido
									system("cls");
									resposta = 0; //serve para impedir que o continue com o valor 1, pois sairia do loop caso o usario digite uma letra.
									barraSup(30);
									printf("\xBA    Confirmacao da idade      \xBA\n");//
									printf("\xBA Voce realmente tem: %d Anos  \xBA\n", idadeAtual);
									printf("\xBA Sim_(01)           Nao_(02)  \xBA\n");
									barraInf(30);
									scanf("%d", &resposta);//leitura da escolha de confirmação de idade
									fflush(stdin);
									if (resposta < 1 || resposta > 2){
										printf("Escolha invalida\n\n");
										system("pause");
									}
									else if(resposta == 2)
										repetirIdade = 1;
								}while(resposta < 1 || resposta > 2);// fim do laço de controle. repetir confirmação do usario.
							}//fim do else do menu idade.
						}while(repetirIdade == 1);
						do{//serve para fazer com que o usario possa voltar do menu escolaridade para sexo
							do{//serve para repetir o menu sexo caso o usario digite um valor invalido
								system("cls");
								sexo = 0;
								repetirSexo = 0;
								barraSup(29);
								printf("\xBA\t Qual seu sexo?       \xBA\n");
								printf("\xBA\t\t\t      \xBA\n");
								printf("\xBA Masculino_(1)  Femenino_(2) \xBA\n");
								printf("\xBA Voltar__________________(3) \xBA\n");
								barraInf(29);
								scanf("%d", &sexo);//leitura da escolha do sexo do usario
								fflush(stdin);
								if (sexo == 3)//verifica se o usario deseja voltar para o menu idade.
									repetirIdade = 1;//controle do lação de repetição de idade
								else if(sexo > 3 || sexo < 1){// responsavel por verificar e imprimir a mensagem de erro se for necessario
									printf("Escolha invalidada\nTente novamente!\n");//mensagem de erro
									system("pause");
								}
							}while(sexo > 3 || sexo < 1);
							if(repetirIdade != 1){ // serve para impedir que o programa continue execultadno caso ele tenha pedido para repetir a idade.
								do{//responsavel por voltar do menu grau de escolaridade para o menu escolaridade
									do{// responsavel por repetir o menu de escolaridade se o usario digitar um valor invalido
										system("cls");
										repetirEscolaridade = 0;//necessario para impedir que entre em loop infinito caso o usario digite para voltar.
										escolaridade = 0;
										barraSup(24);
										printf("\xBA  Veterano ou egresso   \xBA\n\xBA\t\t\t \xBA\n");
										printf("\xBA   Veterano______(01)   \xBA\n");
										printf("\xBA   Egresso_______(02)   \xBA\n\xBA\t\t\t \xBA\n");
										printf("\xBA   Voltar________(03)   \xBA\n");
										barraInf(24);
										scanf("%d", &escolaridade);//leitura da escolaridade do usario 
										fflush(stdin);
										if (escolaridade < 1 || escolaridade > 3){//verifica e mostra a mensagem de erros se necessario
											printf("Escolha invalida\nTente novamente!\n");
											system("pause");
										}
										else if(escolaridade == 2 ){//caso o usario digite que é egresso.
											do{//responsavel por repetir o menu grau de esolaridade caso o usario digite um valor invalido
												repetirEscolaridade = 0;// foi necessario por esse codigo aki para impedir que o laço mais interno retorne para esse caso utilize a opção de voltar
												grauEscolaridade = 0;
												system("cls");
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
												fflush(stdin);
												if(grauEscolaridade < 1 || grauEscolaridade > 5){//mensagem de erro caso o usario digite um valor invalido
													printf("Escolha invalida\nTente novamente!\n");
													system("pause");
												}
												else if (grauEscolaridade == 5)
												repetirEscolaridade = 1;
											}while(grauEscolaridade < 1 || grauEscolaridade > 5);
										}//fim menu escolaridade
										else if(escolaridade == 3)
										repetirSexo = 1;
									}while(escolaridade < 1 || escolaridade > 3);
									if(repetirEscolaridade != 1 && repetirSexo != 1){//impedir que o programa continue se o usario pedir para voltar para o menu de sexo
										do{//serve para repetir o ano de formatura do usario caso digite algum ano invalido.
											anoFormatura = 0;
											repetirFormatura = 0;//impedir que entre em loop infinito
											system("cls");
											if (escolaridade == 1)
												printf("Em que ano vai se formar?\n");
											else if (escolaridade == 2)
												printf("Em que ano se formou?\n");
												scanf("%d", &anoFormatura);//leitura da escolha do usario com relação ao ano de formatura
												fflush(stdin);
												if (escolaridade == 1 && anoFormatura < 2017 || escolaridade == 1 && anoFormatura > 2050){//verifica e mostra a mensagem de erro caso necessario
													printf("Algo esta errado!\nVerifique os dados e tente novamente\n");//mensagem de erro que aparecerá para o usario caso a escolha tenha sido indevida
													do{	
														resposta = 0;
														system("cls");
														barraSup(35);
														printf("\xBA Tem certeza que voce er veterano? \xBA\n");
														printf("\xBA \t\t\t\t    \xBA\n");
														printf("\xBA SOU veterano________________(01)  \xBA\n");
														printf("\xBA NAO sou veterano____________(02)  \xBA\n");
														barraInf(35);
														scanf("%d", &resposta);
														fflush(stdin);
														if(resposta < 1 || resposta > 2){
															printf("Escolha invalida\nTente novamente!\n\n");
															system("pause");
														}
														else if(resposta == 1){
															printf("Entao digite um ano de formatura maior que 2017 e menor que 2050\n\n");
															repetirFormatura = 1;
															system("pause");
														}
														else{
															printf("Tudo bem escolha seu grau de escolaridade\n\n");
															repetirEscolaridade = 1;
														}	
													}while(resposta < 1 || resposta > 2);
												}
											else if(escolaridade == 2 && anoFormatura < 1900 || escolaridade == 2 && anoFormatura > 2017){
												printf("Algo esta errado!\nVerifique os dados e tente novamente\n");//mensagem de erro que aparecerá para o usario caso a escolha tenha sido indevida
												system("pause");
												do{
													resposta = 0;
													system("cls");
													barraSup(35);
													printf("\xBA Tem certeza que voce er egresso?  \xBA\n");
													printf("\xBA \t\t\t\t    \xBA\n");
													printf("\xBA SOU egresso________________(01)   \xBA\n");
													printf("\xBA NAO sou egresso____________(02)   \xBA\n");
													barraInf(35);
													scanf("%d", &resposta);
													fflush(stdin);
													if(resposta < 1 || resposta > 2)
														printf("Escolha invalida\nTente novamente!\n\n");
													else if(resposta == 1){
														printf("Entao digite um ano de formatura menor que 2017 e maior que 1900\n\n");
														repetirFormatura = 1;
														system("pause");
													}
													else{
														printf("Tudo bem escolha seu grau de escolaridade\n\n");
														repetirEscolaridade = 1;
														system("pause");
													}
												}while(resposta < 1 || resposta > 2);
											}
											else{
												do{//laço de repetição usado para impedir que o usario digite um valor invalido
													resposta = 0;
													barraSup(34);
													printf("\xBA Confirmacao do ano de formatura  \xBA\n");
													printf("\xBA\t\t\t\t   \xBA\n");
													printf("\xBA SIM_(01)               NAO_(02)  \xBA\n");
													barraInf(34);
													scanf("%d", &resposta);//recebe a escolha do usario
													fflush(stdin);
													if (resposta < 1 || resposta > 2){//verifica e mostra uma mensagem de erro caso necessario
														printf("Escolha invalida\nDigite novamente\n\n");//mensagem de erro"
														system("pause");
													}
													else if(resposta == 1){//nesse momento o software faz a verificação se o usario tem certeza do ano de formatura e em seguida começa o porcessamento de informaçoes
														if (escolaridade == 1){// verifica se o entrevistado é veterano
															if(sexo == 2)//veriifica se é do sexo femenino
																mulherCurso++;  //responsavel por contabilizar quantas mulheres ainda estão fazendo o curso ou seja veteranas
															idadeConV = idadeConV + (idadeAtual + (anoFormatura - 2017));//serve para descobir com quantos quantos anos os veteranos irá se formar
														}
														else{//verifica se o entrevistado é egresso
															if(sexo == 2)//verifica se e do sexo femenino
																mulherEgressa++;//responsavel por contabilizar quantas mulheres ja terminaram o curso
															idadeConE = idadeConE + (idadeAtual - (2017 - anoFormatura));// serve para descobrir com quantos anos o egresso se formou 
														}
														iConclusaoM = (idadeConV + idadeConE) / pesquisa;//faz a media de idade de conclusão do curso
													}
													else if(resposta == 2)//verifica e repete e o ano de formatura do usario se necessario.
														repetirFormatura = 1;//alteração na variavel de controle}
												}while(resposta < 1 || resposta > 2);
											}
										}while(repetirFormatura == 1);
										if(repetirEscolaridade != 1){//necessario para impedir que o programa execulte esse trecho caso o usario queria voltar
											do{//PERGUNTA 01 // serve para repetir a pergunta caso o usuario tenha digitado um valor invalido
												system("cls");
												resposta = -1;
												barraSup(61);
												printf("\xBA\t\t\tPERGUNTA (1/5) \t\t\t      \xBA\n\xBA\t\t\t\t\t\t\t      \xBA\n");
												printf("\xBA Voce concorda que o PBL ajuda na execucao de seus trabalhos?\xBA\n");
												printf("\xBA\t\t\t\t\t\t\t      \xBA\n");
												printf("\xBA NAO CONCORDO_(00)\t CONCORDO_(01)\t NAO TEM OPINIAO_(02) \xBA\n");
												barraInf(61);
												scanf("%d", &resposta);
												fflush(stdin);
												switch(resposta){
													case 0:{
														nConcordoTotal++;
														break;
													}
													case 1:{
														concordoTotal++;
														concordoP1++;//responsavel por contabilizar quantas pessoas concordam com essa pergunta
														break;
													}
													case 2:{
														neutroTotal++;
														break;
													}
													default:
														printf("Escolha invalida\nTente novamente!");
														system("pause");
												}//fim do switch de respostas
											}while(resposta < 0 || resposta > 2);
											do{
												system("cls");
												resposta = -1;
												barraSup(61);
												printf("\xBA\t\t\tPERGUNTA (2/5)\t\t\t      \xBA\n\xBA\t\t\t\t\t\t\t      \xBA\n");
												printf("\xBA Voce concorda que o PBL er melhor que o metodo tradicional? \xBA\n");
												printf("\xBA\t\t\t\t\t\t\t      \xBA\n");
												printf("\xBA NAO CONCORDO_(00)\t CONCORDO_(01)\t NAO TEM OPINIAO_(02) \xBA\n");
												barraInf(61);
												scanf("%d", &resposta);
												fflush(stdin);
												switch(resposta){
													case 0:{
														nConcordoTotal++;
														nConcordoP2++;//responsavel por contabilizar quantas pessoas não concordam com a questão 2
														break;
													}
													case 1:{
														concordoTotal++;
														break;
													}
													case 2:{
														neutroTotal++;
														neutroP2++;//responsavel por contabilizar quantas pessoas não tem opinião
														break;
													}
													default:
														printf("Escolha invalida\nTente novamente!");
														system("pause");
												}
												resP2 = (100 / pesquisa) * (nConcordoP2 + neutroP2);//cauculo do percentual dos que não concordam ou não possuem opinião
											}while(resposta < 0 || resposta > 2);
											do{//PERGUNTA 03
												system("cls");
												resposta = -1;
												barraSup(63);
												printf("\xBA\t\t\tPERGUNTA (3/5)\t\t\t        \xBA\n\xBA\t\t\t\t\t\t\t\t\xBA\n");
												printf("\xBA O mercado de trabalho local e capaz de reter os prifissionais \xBA\n");
												printf("\xBA formados nas areas de informatica e engenharia?\t\t\xBA\n");
												printf("\xBA\t\t\t\t\t\t\t\t\xBA\n");
												printf("\xBA  NAO CONCORDO_(00)\t CONCORDO_(01)\t NAO TEM OPINIAO_(02)   \xBA\n");
												barraInf(63);
												scanf("%d", &resposta);
												fflush(stdin);
												switch(resposta){
													case 0:{
													nConcordoTotal++;
														idadeTotalP3 = idadeTotalP3 + idadeAtual;
														mediaIdadeP3 = idadeTotalP3 / pesquisa; //pesquisa é o node da varivael que contabiliza quantas pessoas foram entrevostados
														break;
													}
													case 1:{
														concordoTotal++;
														break;
													}
													case 2:{
														neutroTotal++;
														break;
													}
													default:
														printf("Escolha invalida\nTente novamente!");
														system("pause");
												}
											}while (resposta < 0 || resposta > 2);
											do{//PERGUNTA 04
											system("cls");
											resposta = -1;
											barraSup(61);
											printf("\xBA\t\t\tPERGUNTA (4/5)\t\t\t      \xBA\n\xBA\t\t\t\t\t\t\t      \xBA\n");
											printf("\xBA Voce concorda que os novos alunos desconhecem o PBL\t      \xBA\n");
											printf("\xBA quando entram no curso?\t\t\t\t      \xBA\n\xBA\t\t\t\t\t\t\t      \xBA\n");
											printf("\xBA NAO CONCORDO_(00)\t CONCORDO_(01)\t NAO TEM OPINIAO_(02) \xBA\n");
											barraInf(61);
											scanf("%d", &resposta);
											fflush(stdin);
											switch(resposta){
												case 0:{
													nConcordoTotal++;
													break;
												}
												case 1:{
													concordoTotal++;
													concordoP4++;//responsavel por contabilizar quantas pessoas concordam com a quesão 4	
													break;
												}
												case 2:{
													neutroTotal++;
													break;
												}
												default:
													printf("Escolha invalida\nTente novamente!");
													system("pause");
												}
											}while (resposta < 0 || resposta > 2);
											do{//PERGUNTA 05
												system("cls");
												resposta = -1;
												barraSup(61);
												printf("\xBA \t\t\t PERGUNTA (5/5)\t\t\t      \xBA\n");
												printf("\xBA\t\t\t\t\t\t\t      \xBA\n");
												printf("\xBA Concorda que um aluno so consegue se adaptar\t\t      \xBA\n");
												printf("\xBA com o PBL somente apartir do semestre 4?\t\t      \xBA\n");
												printf("\xBA\t\t\t\t\t\t\t      \xBA\n");
												printf("\xBA NAO CONCORDO_(00)\t CONCORDO_(01)\t NAO TEM OPINIAO_(02) \xBA\n");
												barraInf(61);
												scanf("%d", &resposta);
												fflush(stdin);
												switch(resposta){
													case 0:{
														nConcordoTotal++;
														break;
													}
													case 1:{
														concordoTotal++;
														if(escolaridade == 1){//verifica se o entrevistado que concordou com essa pergunta é veterano 
															concordoP5++; //se o entrevistado for veterano do curso serpa contabilizado mais um.
														}
														break;
													}
													case 2:{
														neutroTotal++;
														if(escolaridade == 1){// verifica se o entrevistado que não se manifestou é veterano
															neutroP5++;// se o entrevistado for veterano do curso será contabilizado mais um
														}		
														break;
													}
													default:
														printf("Escolha invalida\nTente novamente!");
														system("pause");
												}
											}while (resposta < 0 || resposta > 2);
										}
									}//fim da verificação que impede que continue se o usario pedir para repetir o sexo
								}while(repetirEscolaridade == 1);
							}//fim da verificação que impede que continue se o usario peça para repetir a idade	
						}while(repetirSexo == 1);
					}while(repetirIdade == 1);
					do{
						system("cls");
						resposta = 0;
						barraSup(31);
						printf("\xBA OBRIGADO PELA SUA OPINIAO\t\xBA\n\xBA\t\t\t\t\xBA\n");
						printf("\xBA NOVO CADASTRO____________(01) \xBA\n");
						printf("\xBA EXIBIR RELATORIO_________(02) \xBA\n");
						printf("\xBA VOLTAR PARA MENU_________(03) \xBA\n");
						barraInf(31);
						scanf("%d", &resposta);
						fflush(stdin);
						switch(resposta){
							case 1:{
								repetirCadastro = 1;
								pesquisa++;
								break;
							}
							case 2:{
								pesquisa ++;
								break;
							}
							case 3:{
								repetirMenu = 1;
								pesquisa++;
								break;
							}
							default:
								printf("Escolha invalida\nTente novamente!\n");
							}
					}while(resposta < 1 || resposta > 3);
				}while(repetirCadastro == 1);
			}//fim do case 1 do switch resposta do menu principal
			case 2:{
				if (resposta != 2)//verificação que impede que o software mostre o relatorio em momentos indesejados
					break;
				if (pesquisa <= 1){//verifica se existe uma quantidade minima de pesquisas cadastradas
					printf("DADOS INSUFICIENTE!\nSEM PESQUISA CADASTRADA!\n");
					repetirMenu = 1;
				}
				else{
					system("cls");
					printf("\t\t");
					barraSup(50);
					printf("\t\t\xBA  RELATORIO FINAL - PESQUISA IMPORTANCIA DO PBL   \xBA\n\t\t");
					barraInf(50);
					
					barraSup(80);
					printf("\xBA  %d pessoas concordaram com a primeira pergunta \t\t\t\t \xBA\n", concordoP1);
					barraInf(80);
					barraSup(80);
					printf("\xBA  %.0f%% pessoas nao concordam ou nao possue opiniao definida na pergunta 2\t \xBA\n", resP2);
					barraInf(80);
					barraSup(80);
					printf("\xBA A media de idade dos que nao concorda com a questao 3 er : %.1f Anos\t\t \xBA\n", mediaIdadeP3);
					barraInf(80);
					barraSup(80);
					printf("\xBA  %d Veteranos concordaram ou nao tem opiniao com relacao a ultima pergunta\t \xBA\n", concordoP5 + nConcordoP5);
					barraInf(80);
					barraSup(80);
					printf("\xBA  %d Mulheres foram entrevistadas\t\t\t\t\t\t \xBA\n", mulherCurso + mulherEgressa);
					barraInf(80);
					barraSup(80);
					printf("\xBA  %d mulheres esta fazendo o curso\t\t\t\t\t\t \xBA\n", mulherCurso);
					barraInf(80);
					barraSup(80);
					printf("\xBA  %d mulheres ja concluiram o curso\t\t\t\t\t\t \xBA\n", mulherEgressa);
					barraInf(80);
					barraSup(80);
					printf("\xBA  %d pessoas concordaram com a quarta pergunta\t\t\t\t\t \xBA\n", concordoP4);
					barraInf(80);
					barraSup(80);
					printf("\xBA  A media de idade dos estudantes no momento da conclusao do curso er de: %.1f  \xBA\n", iConclusaoM);
					barraInf(80);
					getch();
					repetirMenu = 1;
				}
				break;
			}//fim do caso 2
			case 3:{
				printf("'+=+=+=+=+=+=+= #Sobre# =+=+=+=+=+=+=+=+=+\n");
				printf("| DESENVOLVEDOR: Uellington Damasceno    |\n");
				printf("| DATA DO INICIO: 31/03/2017  |||||||    |\n");
				printf("| VERSAO: 1.4                ª| @  @|    |\n");
				printf("| NIVEL: Variavel             |   > |    |\n");
				printf("| Orientador: Danillo         |_---_|    |\n");
				printf("| Ultima altercao 23/04/2017 as 20:46 PM |\n");
				printf("'+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n");
				system("pause");
				system("cls");
				repetirMenu = 1;
				break;
			}
			case 4:{
				do{
					barraSup(30);
					printf("\xBA Tem certeza que deseja sair? \xBA\n");
					printf("\xBA SIM_(01)            NAO_(02) \xBA\n");
					barraInf(30);
					scanf("%d", &resposta);
					fflush(stdin);
					switch(resposta){
						case 1:{
							system("cls");
							printf("Ate a proxima\n");
							break;
						}
					case 2:{
						repetirMenu = 1;//serve para voltar para o menu caso o usario não deseje sair
						break;
					}
					default:
						printf("Escolha invalida\nTente Novamente!\n");	
					}
				}while(resposta < 1 || resposta > 2);
				break;
			}//fim do caso 5
			default:{
				printf("Escolha invalida\nTente Novamente!\n\n");
				repetirMenu = 1;
			}
		}//fim do switch responsavel por receber a resposta do usario no menu principal.
	}while(repetirMenu == 1);
	return 0;
}
