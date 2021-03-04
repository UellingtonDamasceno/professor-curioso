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
	int repetirMenu = 0, repetirCadastro = 0;
	int repetirIdade = 0, repetirSexo = 0;
	int repetirEscolaridade = 0;
	int repetirFormatura = 0;
	int repetirPergunta = 0, repetirConfirmacao = 0;
//DECLARAÇÃO DE FUNÇÕES
	void escolhaCor();
	void menuSobre();
//CORPO DO CODIGO
	do{//serve para repetir o menu se for necessario
		repetirMenu = 0;// foi necessario por esse codigo aki para impedir que o laço mais interno retorne para esse caso utilize a opção de voltar
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
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@...primeiro caso...@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
				case 1:{
					do{
						repetirCadastro = 0; // foi necessario por esse codigo aki para impedir que o laço mais interno retorne para esse caso utilize a opção de voltar
						//system("cls");		
						do{//serve para voltar do menu sexo para o menu idade
							do{//SE O USARIO DIGITAR UMA IDADE INVALIDA IRA REPEITIR
								repetirIdade = 0;
									printf("Qual sua idade?\n");
									scanf("%d", &idadeAtual);
									if (idadeAtual < 10 || idadeAtual > 100){
										printf("Imporvavel\nTente novamente!\n");
										repetirIdade = 1;
									}
									else{
										do{//repetir a confirmação se o usario digitar um valor invalido
											printf("Confirmacao da idade\n");
											printf("Voce realmente tem: %d Anos\n", idadeAtual);
											printf("Sim_(01)           Nao_(02)\n");
											scanf("%d", &resposta);
											if (resposta < 1 || resposta > 2)
												printf("Escolha invalida\n\n");
											else if(resposta == 2)
												repetirIdade = 1;
										}while(resposta < 1 || resposta > 2);
								}//fecha else linhda 90	
							}while(repetirIdade == 1);//serve para repetir a idade caso exista uma escolha invalida
							do{//serve para voltar do menu escolaridade para o menu sexo
								do{//serve para repetir o menu sexo se o usario digitar alguma alternativa invalida
								barraSup(29);
								printf("\xBA\t Qual seu sexo?       \xBA\n");
								printf("\xBA\t\t\t      \xBA\n");
								printf("\xBA Masculino_(1)  Femenino_(2) \xBA\n");
								printf("\xBA Voltar__________________(3) \xBA\n");
								barraInf(29);
									scanf("%d", &sexo);
									if (sexo == 3){
										repetirIdade = 1;
										break;
									}
									else if(sexo > 3 || sexo < 1)
										printf("Escolha invalidada\nTente novamente!\n");
								}while(sexo > 3 || sexo < 1);
						while(repetirIdade == 0){//laço que serve para impedir que faça a proxima pergunta caso o usario tenha digitado voltar na pergunta anterior
						repetirEscolaridade = 0;
						do{
						barraSup(20);
						printf("\xBA   Novo cadastro    \xBA\n\xBA\t\t     \xBA\n");
						printf("\xBA Veterano______(01) \xBA\n");
						printf("\xBA Egresso_______(02) \xBA\n\xBA\t\t     \xBA\n");
						printf("\xBA Voltar________(03) \xBA\n");
						barraInf(20);
							scanf("%d", &escolaridade);
							if (escolaridade < 1 || escolaridade > 3)
								printf("Escolha invalida\nTente novamente!\n");
						}while(escolaridade < 1 || escolaridade > 3);
							if (escolaridade == 1 && sexo == 2){
									mulherCurso++;
								break;
							}
							else if(escolaridade == 2){
								contadorIdade++;
								if(sexo == 2)
									mulherEgressa++;
								do{//serve para repetir o ano de formatura do usario caso digite algum ano invalido.
									repetirFormatura = 0;//impedir que entre em loop infinito
									printf("Ano da formatura?\n");
									scanf("%d", &anoFormatura);
										if (anoFormatura < 1900 || anoFormatura > 2017){
											printf("Escolha invalida\n tente novamete\n");
											repetirFormatura = 1;
										}						
										else{
											idadeConclusao = idadeAtual - (2017 - anoFormatura);// aki eu sei com quantos anos o usario se formou...
											iConclusaoM = idadeConclusao / contadorIdade;//conta para descobrir a idade media de conclusão dos usarios
										break; // se de merda so olhar isso aki
										}
								}while(repetirFormatura == 1);
							do{
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
								scanf("%d", &grauEscolaridade);
									if (grauEscolaridade == 5){
										contadorIdade--; //caso o usario volte para o menu anterior o contador de idade será decrementado.
										idadeTotal = idadeTotal - idadeAtual;//serve para decrementar o valor da idade total caso o usario queira voltar.
										if (escolaridade ==  1) 
												mulherCurso--; 
										else if(escolaridade == 2) 
												mulherEgressa--;
											repetirSexo = 1;
									}
									else if(grauEscolaridade < 1 || grauEscolaridade > 5){
										printf("Escolha invalida\nTente novamente!\n");
										repetirSexo = 1;
									}
							}while(repetirEscolaridade == 1);
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@...INICIO DAS PERGUNTAS...@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
						break; //descobirir o que esse break faz... SAPORRA ER DUAS CARAS TOMA CUIDADO ELE ERA UM PESO TODO O PROGRAMA AGR NÃO ER MAIS...
						}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@...CASO O USARIO QUEIRA VOLTAR....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
							else if(escolaridade == 3){
								if (sexo == 2 && escolaridade == 1)
									mulherCurso--;
								else if(sexo == 2 && escolaridade == 2)
									mulherEgressa--;
								repetirMenu = 1;
							break;
							}
							else
								printf("Desculpe escolha invalida\nTente novamente!\n");
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@......AKI COMEÇA A EXECUÇÃO DO CODIGO DEPOIS DE ESOCLHER O NIVEL DE ESCOLARIDADE@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
						while(repetirSexo == 0){
							do{//PERGUNTA 01
						repetirPergunta = 0;
					printf("PERGUNTAS (1/5)\n");
					printf("Voce concorda que o PBL ajuda na execucao de seus trabalhos?\n");
					printf("CONCORDO (01)\t NAO CONCORDO (02)\t NAO TEM OPINIAO (03)\n");
						scanf("%d", &resposta);
						switch(resposta){
							case 1:{
								concordoTotal++;
								concordoP1++;
								break;
							}
							case 2:{
								nConcordoTotal++;
								break;
							}
							case 3:{
								neutroTotal++;
								break;
							}
							default:{
								printf("Escolha invalida\nTente novamente!");
								repetirPergunta = 1;
							}
						}
					}while (repetirPergunta == 1);
					do{//PERGUNTA 02
						repetirPergunta = 0;
					printf("PERGUNTA (2/5)\n");
					printf("Voce concorda que o PBL é melhor que o metodo tradicional?\n");
					printf("CONCORDO (01)\t NAO CONCORDO (02)\t NAO TEM OPINIAO (03)\n");
					scanf("%d", &resposta);
						switch(resposta){
							case 1:{
								concordoTotal++;
								break;
							}
							case 2:{
								nConcordoTotal++;
								nConcordoP2++;
								break;
							}
							case 3:{
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
						}while (repetirPergunta == 1);
					do{//PERGUNTA 03
						repetirPergunta = 0;
					printf("PERGUNTA (3/5)\n");
					printf("O mercado de trabalho local e capaz de reter os prifissionais\nformados nas areas de informatica e engenharia?\n");
					printf("CONCORDO (01)\t NAO CONCORDO (02)\t NAO TEM OPINIAO (03)\n");
					scanf("%d", &resposta);
						switch(resposta){
							case 1:{
								concordoTotal++;
								break;
							}
							case 2:{
								nConcordoTotal++;
								idadeTotal = idadeTotal + idadeAtual;
								if(pesquisa != 0){ // usado para evitar que o softwares trave se por acaso a conta for feita com o divisor = 0.
								mediaIdade = idadeTotal / pesquisa; //pesquisa é o node da varivael que contabiliza quantas pessoas foram intrevistadas.
								}
								break;
							}
							case 3:{
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
					printf("CONCORDO (01)\t NAO CONCORDO (02)\t NAO TEM OPINIAO (03)\n");
					scanf("%d", &resposta);
						switch(resposta){
							case 1:{
								concordoTotal++;
								concordoP4++;
								break;
							}
							case 2:{
								nConcordoTotal++;
								break;
							}
							case 3:{
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
					printf("CONCORDO (01)\t NAO CONCORDO (02)\t NAO TEM OPINIAO (03)\n");
					scanf("%d", &resposta);
						switch(resposta){
							case 1:{
								concordoTotal++;
								if(escolaridade == 1){
									concordoP5++;
								}	
								break;
							}
							case 2:{
								nConcordoTotal++;
								break;
							}
							case 3:{
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
					do{//CONFIRMAÇÃO
						repetirConfirmacao = 0;
						printf("OBRIGADO PELA SUA OPINIAO\nELA SERA MUITO PRECIOSA\n");
						printf("NOVO CADASTRO____________(01)\n");
						printf("EXIBIR RELATORIO_________(02)\n");
						printf("VOLTAR PARA MENU_________(03)\n");
						scanf("%d", &resposta);
							switch(resposta){
								case 1:{
									repetirCadastro = 1;
									pesquisa++;
									break;
								}
								case 2:{
										printf("%d pessoas concordaram com a primeira pergunta\n", concordoP1);
										printf("%d pessoas concordaram com a quarta pergunta\n", concordoP4);
										printf("%d pessoas concordaram ou nao tem opiniao com relacao a ultima pergunta\n", concordoP5 + neutroP5);
										printf("%d mulheres esta fazendo o curso\n", mulherCurso);
										printf("%d mulheres ja concluiram o curso\n", mulherEgressa);
										printf("A media de idade das pessoas que discordam com a quarta questao e de: %.1f\n", mediaIdade);
										printf("A media de idade dos estudantes no momento da conclusao do curso é de: %.1f\n", iConclusaoM);
										repetirConfirmacao = 1;
									break;
								}
								case 3: {
									repetirMenu = 1;
									pesquisa++; 
									break;
								}
								default:{
									printf("Escolha invalida\nTente novamente!\n");
									repetirConfirmacao = 1;
									break;
								}
							}
						}while(repetirConfirmacao == 1);
						}
						}//laço que serve para garantir que a idade será repetida.
						}while(repetirSexo == 1);
						}while(repetirIdade == 1);
					}while(repetirCadastro == 1);
				break;
			}// do case
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@....fim do primeiro caso...@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			case 2:
				if (pesquisa == 1)
					printf("DADOS INSUFICIENTES\nTENTE NOVAMENTE MAIS TARDE!\n\n");
				else{
					printf("%d pessoas concordaram com a primeira pergunta\n", concordoP1);
					printf("%d pessoas concordaram com a quarta pergunta\n", concordoP4);
					printf("%d pessoas concordaram ou nao tem opiniao com relacao a ultima pergunta\n", concordoP5 + neutroP5);
					printf("%d mulheres esta fazendo o curso\n", mulherCurso);
					printf("%d mulheres ja concluiram o curso\n", mulherEgressa);
					printf("A media de idade das pessoas que discordam com a quarta questao e de: %.1f\n", mediaIdade);
					printf("A media de idade dos estudantes no momento da conclusao do curso é de: %.1f\n", iConclusaoM);
				}
				getch();
				repetirMenu = 1;
				break;
			case 3:
				escolhaCor();
				repetirMenu = 1;
				break;
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
				printf("Foi um prazer ajuda-lo!\n");
				system("exit");
				break;
			}
			default:
				system("cls");
				printf("Desculpe escolha invalida\nTente novamente!\n");
				repetirMenu = 1;
		}
	}while (repetirMenu == 1);
	return 0;
}
void escolhaCor(){
	int cor;
	int certeza;
	int repetirTudo = 0;
	int repetirCor = 0;
do{
	do{
		repetirTudo = 0; // necessario para fazer o valor do laço de repetição para evitar entrar em loop infinito.
		barraSup(70);
		printf("\xBA\t\t    ESCOLHA UMA COR DE SUA PREFERENCIA\t\t       \xBA\n");
		printf("\xBA \t\t\t\t\t\t\t\t       \xBA\n");
		printf("\xBA (01) Branco & Preto\t (02) Branco & Verde\t (03) Branco & Vermelho\xBA\n");
		printf("\xBA (04) Preto & Branco\t (05) Preto e Verde\t (06) Preto & Vermelho \xBA\n");
		printf("\xBA (07) Azul & Branco\t (08) Azul & Verde\t (09) Azul & Amarelo   \xBA\n");
		printf("\xBA (10) Cinza & Preto\t (11) Cinza & Verde\t (12) Cor padrao       \xBA\n");
		printf("\xBA \t\t\t\t\t\t\t\t       \xBA\n");
		printf("\xBA >A primeira cor equivale ao fundo ja a segunda cor equivale a letra< \xBA\n");
		barraInf(70);
			scanf("%d", &cor);
			switch(cor){
				case 1:
					system("color f0");
					break;
				case 2:
					system("color f2");
					break;
				case 3:
					system("color fc");
					break;
				case 4:
					system("color 0f");
					break;
				case 5:
					system("color 0a");
					break;
				case 6:
					system("color 0c");
					break;
				case 7:
					system("color 1f");
					break;
				case 8:
					system("color 1a");
					break;
				case 9:
					system("color 16");
					break;
				case 10:
					system("color 80");
					break;
				case 11:
					system ("color 8a");
					break;
				case 12:
					system("color 07");
					break;
				default:{
					system("cls");
					printf("Escolha invalida\nTente novamente!\n\n");
				}
			}
		}while(cor < 1 || cor > 12);
	system("cls");
	do{
	repetirCor == 0;
	barraSup(55);
	printf("\xBA  Voce realmente deseja utilizar essa cor no terminal? \xBA\n");
	printf("\xBA        (01) Sim\t\t\t(02) Nao        \xBA\n");	
	barraInf(55);
	scanf("%d", &certeza);
		if(certeza == 1){
			printf("Otima escolha!\n");
			break;
		}
		else if (certeza == 2){
			system("cls");
			printf("Hum... tambem nao gostei dessa cor\n");
			printf("tentar novamente!\n\n\n");
			repetirTudo = 1;
		break;
		}
		else{
			printf("Escolha invalida\nTente novamente!\n\n");
			repetirCor = 1;
		}
	}while(repetirCor == 1);
}while(repetirTudo == 1);
}
