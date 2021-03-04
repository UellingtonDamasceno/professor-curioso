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
quando vai e volta. e peço para vltar no do menu sexo para o menu idade o programa entra em loopo infito

...................................ATUALIZAÇÃO DA VERSÃO..........................
CODIGO FUNCIONAL FALTA APENAS IPLEMENTAR A ULTIMA FUNÇÃO QUE É DE CAUCULAR A MEDIA DE IDADE DAS PESSOAS
NOS ANOS DE CONCLUSÃO DO CURSO.
	
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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
	float mediaIdadeP3, idadeTotalP3;//serve para calcular a media de idade dos entrevistados que não concordam com a questão 3
	int resposta;
	int idadeAtual, sexo, mulherCurso = 0,mulherEgressa = 0;
	int escolaridade, grauEscolaridade;
	//perguntas
	int concordoTotal = 0, nConcordoTotal = 0, neutroTotal = 0;//serve para contar o numero total de concordo, não concordo e naõ tem opinião.
	int concordoP1 = 0,concordoP4 = 0, concordoP5 = 0; // usado para armazenat valores de concordancia que será utilizado no relatorio
	int nConcordoP2 = 0, nConcordoP5 = 0;//responsavel por armazenar valores de pessoas que não concordam com determinada questão
	int neutroP2 = 0, neutroP5 = 0;// responsavel por armazenar valores que será usado nos relatorio 
	int anoFormatura, pesquisa = 1;
//variaveis de controles de laço. necessarias para fazer a interação entre os menus.
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
									barraSup(30);
									printf("\xBA    Confirmacao da idade      \xBA\n");//
									printf("\xBA Voce realmente tem: %d Anos  \xBA\n", idadeAtual);
									printf("\xBA Sim_(01)           Nao_(02)  \xBA\n");
									barraInf(30);
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
							repetirSexo = 0;
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
						if(repetirIdade != 1){ // serve para impedir que o programa continue execultadno caso ele tenha pedido para repetir a idade.
						do{//responsavel por voltar do menu grau de escolaridade para o menu escolaridade
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
								repetirSexo = 1;
								}
							}while(escolaridade < 1 || escolaridade > 3);
						if(repetirEscolaridade != 1 && repetirSexo != 1){//impedir que o programa continue se o usario pedir para voltar para o menu de sexo
						do{//serve para repetir o ano de formatura do usario caso digite algum ano invalido.
							repetirFormatura = 0;//impedir que entre em loop infinito
							if (escolaridade == 1){
								printf("Em que ano vai se formar?\n");
							}
							else if (escolaridade == 2){
								printf("Em que ano se formou?\n");
							}
							scanf("%d", &anoFormatura);//leitura da escolha do usario com relação ao ano de formatura
							if (escolaridade == 1 && anoFormatura < 2017){//verifica e mostra a mensagem de erro caso necessario
								printf("Algo esta errado!\nVerifique os dados e tente novamente\n");//mensagem de erro que aparecerá para o usario caso a escolha tenha sido indevida
								do{
									barraSup(35);
									printf("\xBA Tem certeza que voce er veterano? \xBA\n");
									printf("\xBA \t\t\t\t    \xBA\n");
									printf("\xBA SOU veterano________________(01)  \xBA\n");
									printf("\xBA NAO sou veterano____________(02)  \xBA\n");
									barraInf(35);
									scanf("%d", &resposta);
									if(resposta < 1 || resposta > 2){
										printf("Escolha invalida\nTente novamente!\n\n");
									}
									else if(resposta == 1){
										printf("Entao digite um ano de formatura maior ou igual a 2017\n\n");
										repetirFormatura = 1;
									}
									if (resposta == 2){
										printf("Redirecionando para o menu de escolaridade\n\n");
										repetirEscolaridade = 1;
									}	
								}while(resposta < 1 || resposta > 2);
							}
							else if(escolaridade == 2 && anoFormatura < 1900 || escolaridade == 2 && anoFormatura > 2017){
								printf("Algo esta errado!\nVerifique os dados e tente novamente\n");//mensagem de erro que aparecerá para o usario caso a escolha tenha sido indevida
								do{
									barraSup(35);
									printf("\xBA Tem certeza que voce er egresso?  \xBA\n");
									printf("\xBA \t\t\t\t    \xBA\n");
									printf("\xBA SOU egresso________________(01)   \xBA\n");
									printf("\xBA NAO sou egresso____________(02)   \xBA\n");
									barraInf(35);
									scanf("%d", &resposta);
									if(resposta < 1 || resposta > 2){
										printf("Escolha invalida\nTente novamente!\n\n");
									}
									else if(resposta == 1){
										printf("Entao digite um ano de formatura menor ou igual a 2017\n\n");
										repetirFormatura = 1;
									}
									else{
										printf("Redirecionando para o menu de escolaridade\n\n");
										repetirEscolaridade = 1;
									}
								}while(resposta < 1 || resposta > 2);
							}
							else{
								do{//laço de repetição usado para impedir que o usario digite um valor invalido
									barraSup(34);
									printf("\xBA Confirmacao do ano de formatura  \xBA\n");
									printf("\xBA\t\t\t\t   \xBA\n");
									printf("\xBA SIM_(01)               NAO_(02)  \xBA\n");
									barraInf(34);
									scanf("%d", &resposta);//recebe a escolha do usario
									if (resposta < 1 || resposta > 2){//verifica e mostra uma mensagem de erro caso necessario
										printf("Escolha invalida\nDigite novamente\n\n");//mensagem de erro
									}
									else if(resposta == 1 && sexo == 2){//nesse momento o software faz a verificação se o entrevistado er mulher e se ela esta fazendo o curso ou se ja terminou
										if (escolaridade == 1) // se ela for veterana
										mulherCurso++;  //responsavel por contabilizar quantas mulheres estão fazendo o curso
										else if(escolaridade == 2)
										mulherEgressa++;//responsavel por contabilizar quantas mulheres ja terminaram o curso
									}
									else if(resposta == 2){//verifica e repete e o ano de formatura do usario se necessario.
										repetirFormatura = 1;//alteração na variavel de controle
									}
							}while(resposta < 1 || resposta > 2);
							}
						}while(repetirFormatura == 1);
					if(repetirEscolaridade != 1){
					do{//PERGUNTA 01 // serve para repetir a pergunta caso o usuario tenha digitado um valor invalido
						repetirPergunta = 0;//serve para impedir que o laço entre em loop infinito
						printf("PERGUNTAS (1/5)\n");
						printf("Voce concorda que o PBL ajuda na execucao de seus trabalhos?\n");
						printf("NAO CONCORDO_(00)\t CONCORDO_(01)\t NAO TEM OPINIAO_(02)\n");
						scanf("%d", &resposta);
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
						printf("NAO CONCORDO_(00)\t CONCORDO_(01)\t NAO TEM OPINIAO_(02)\n");
						scanf("%d", &resposta);
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
						printf("NAO CONCORDO_(00)\t CONCORDO_(01)\t NAO TEM OPINIAO_(02)\n");
						scanf("%d", &resposta);
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
						printf("NAO CONCORDO_(00)\t CONCORDO_(01)\t NAO TEM OPINIAO_(02)\n");
						scanf("%d", &resposta);
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
						printf("NAO CONCORDO_(00)\t CONCORDO_(01)\t NAO TEM OPINIAO_(02)\n");
						scanf("%d", &resposta);
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
							default:{
								printf("Escolha invalida\nTente novamente!");
								repetirPergunta = 1;
								break;
							}
						}
					}while (repetirPergunta == 1);
					}
				}//fim da verificação que impede que continue se o usario pedir para repetir o sexo
					}while(repetirEscolaridade == 1);
				}//fim da verificação que impede que continue se o usario peça para repetir a idade	
					}while(repetirSexo == 1);
					}while(repetirIdade == 1);
					do{
					repetirConfirmacao = 0;
					barraSup(31);
					printf("\xBA OBRIGADO PELA SUA OPINIAO\t\xBA\n\xBA\t\t\t\t\xBA\n");
					printf("\xBA NOVO CADASTRO____________(01) \xBA\n");
					printf("\xBA EXIBIR RELATORIO_________(02) \xBA\n");
					printf("\xBA VOLTAR PARA MENU_________(03) \xBA\n");
					barraInf(31);
					scanf("%d", &resposta);
					if (resposta == 1){
						repetirCadastro = 1;
						pesquisa++;//se o usario quiser fazer um novo cadastro o numero de pesquisas feitas devem aumentar
					}
					else if(resposta == 2){
						pesquisa++;//se exibir o relatorio o usario voltará para o menu principal então poderá fazer uma nova pesquisa
					}
					else if(resposta == 3){
						repetirMenu = 1;
						pesquisa++;//se voltar par o menu principal ele poderá fazer outra pesquisa sem porblemas.
					}
					else if(resposta < 1 || resposta > 3){
							printf("Escolha invalida\nTente novamente!\n");
							repetirConfirmacao = 1;
						}
					}while(repetirConfirmacao == 1);
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
				printf("\t\t");
				barraSup(50);
				printf("\t\t\xBA  RELATORIO FINAL - PESQUISA IMPORTANCIA DO PBL   \xBA\n\t\t");
				barraInf(50);
				
				barraSup(80);
				printf("\xBA  %d pessoas concordaram com a primeira pergunta \t\t\t\t \xBA\n", concordoP1);
				barraInf(80);
				barraSup(80);
				printf("\xBA  %.1f pessoas nao concordam ou nao possue opiniao definida na pergunta 2\t \xBA\n", ((nConcordoP2 + neutroP2)*100 / pesquisa));
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
				printf("\xBA  A media de idade dos estudantes no momento da conclusao do curso er de: %.1f   \xBA\n");
				barraInf(80);
				repetirMenu = 1;
			}
			break;
		}
		case 3:{
			printf("Em desenvolvimento\n");
			repetirMenu = 1;
			break;
		}
		case 4:{
			printf("'+=+=+=+=+=+=+= #Sobre# =+=+=+=+=+=+=+=+=+\n");
			printf("| DESENVOLVEDOR: Uellington Damasceno    |\n");
			printf("| DATA DO INICIO: 31/03/2017  |||||||    |\n");
			printf("| VERSAO: 1.4                ª| @  @|    |\n");
			printf("| NIVEL: Variavel             |   > |    |\n");
			printf("| Orientador: Danillo         |_---_|    |\n");
			printf("| Ultima altercao 02/04/2017 as 23:02 PM |\n");
			printf("'+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n");
			getch();
			system("cls");
			repetirMenu = 1;
			break;
		}
		case 5:{
			do{
			barraSup(30);
			printf("\xBA Tem certeza que deseja sair? \xBA\n");
			printf("\xBA SIM_(01)            NAO_(02) \xBA\n");
			barraInf(30);
			scanf("%d", &resposta);
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
					default:{
					printf("Escolha invalida\nTente Novamente!\n");	
					}
				}
		}while(resposta < 1 || resposta > 2);
			break;
		}
		default:{
			printf("Escolha invalida\nTente Novamente!\n\n");
			repetirMenu = 1;
			}
		}//fim do switch responsavel por receber a resposta do usario no menu principal.
	}while(repetirMenu == 1);
}
