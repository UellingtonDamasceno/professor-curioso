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
Desinger do relatorio e de alguns outros detalhes.
	
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void barraSup(int x,bool espaco, int vezes){//necessario para desenhar as barras superirores.
	if (espaco == true){
		for(int i = 0; i < vezes; i++)
			printf("\t");
	}
	printf("\xC9");
	for(int i = 0; i<x; i++)
		printf("\xCD");
	printf("\xBB\n");
}
void barraInf(int x,bool espaco, int vezes){
	if (espaco == true){
		for(int i = 0; i < vezes; i++)
			printf("\t");
	}
	printf("\xC8");
	for(int i = 0; i<x; i++)
		printf("\xCD");
	printf("\xBC\n");
}
int relatorio(int cP1, int cP4, int cP5, int nP5, int mCurso,int mEgressa, float mIdade, float iCM){
	int largBarra = 80;
	barraSup(50, true, 4);
	printf("\t\t\t\t\xBA  RELATORIO FINAL - PESQUISA IMPORTANCIA DO PBL   \xBA\n");
	barraInf(50, true, 4);
	
	barraSup(largBarra, true, 2);
	printf("\t\t\xBA  %d pessoas concordaram com a primeira pergunta\t\t\t\t \xBA\n", cP1);
	barraInf(largBarra, true, 2);
	printf("\t\t\xBA  %d pessoas concordaram com a quarta pergunta\t\t\t\t\t \xBA\n", cP4);
	barraSup(largBarra, true, 2);
	printf("\t\t\xBA  %d pessoas concordaram ou nao tem opiniao com relacao a ultima pergunta\t \xBA\n", cP5 + nP5);
	barraInf(largBarra, true, 2);
	printf("\t\t\xBA  %d mulheres esta fazendo o curso\t\t\t\t\t\t \xBA\n", mCurso);
	barraSup(largBarra, true, 2);
	printf("\t\t\xBA  %d mulheres ja concluiram o curso\t\t\t\t\t\t \xBA\n", mEgressa);
	barraInf(largBarra, true, 2);
	printf("\t\t\xBA  A media de idade das pessoas que discordam com a quarta questao er de: %.1f    \xBA\n", mIdade);
	barraSup(largBarra, true, 2);
	printf("\t\t\xBA  A media de idade dos estudantes no momento da conclusao do curso er de: %.1f   \xBA\n", iCM);
	barraInf(largBarra, true, 2);
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
	bool espaco = false;
	bool repetirMenu = false, repetirCadastro = false;
	bool repetirIdade = false, repetirEscolaridade = false;
	bool repetirFormatura = false, repetirSexo = false;
	bool repetirPergunta = false, repetirConfirmacao = false;
//DECLARAÇÃO DE FUNÇÕES
	void escolhaCor();
//CORPO DO CODIGO
	do{
		system("cls");
		repetirMenu = false;// foi necessario por esse codigo aki para impedir que o laço mais interno retorne para esse caso utilize a opção de voltar
		barraSup(26, true, 5);
		printf("\t\t\t\t\t\xBA\tMENU PRINCIPAL\t   \xBA");
		printf("\n\t\t\t\t\t\xBA\t\t\t   \xBA\n");
		printf("\t\t\t\t\t\xBA Nova pesquisa_______(01) \xBA\n");
		printf("\t\t\t\t\t\xBA Exibir relatorio____(02) \xBA\n");
		printf("\t\t\t\t\t\xBA Configuracoes_______(03) \xBA\n");
		printf("\t\t\t\t\t\xBA Sobre_______________(04) \xBA\n");
		printf("\t\t\t\t\t\xBA Sair________________(05) \xBA\n");
		printf("\t\t\t\t\t\xBA                          \xBA\n");
		barraInf(26, true, 5);
		printf("\t\t\t\t\t>>>>");
			scanf("%d", &resposta);// pega a escolha do usario
			switch (resposta){//começa a decidir o que fazer com a escolha do usario
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@...primeiro caso...@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
				case 1:{
					do{
						repetirCadastro = false; // foi necessario por esse codigo aki para impedir que o laço mais interno retorne para esse caso utilize a opção de voltar
						system("cls");		
						do{//SE O USARIO DIGITAR UMA IDADE INVALIDA IRA REPEITIR
							repetirIdade = false;// impedir loops infinitos.
							printf("Qual sua idade?\n");
								scanf("%d", &idadeAtual);
								fflush(stdin);
								if (idadeAtual < 10 || idadeAtual > 100){
									printf("Imporvavel\nTente novamente!\n");
									repetirIdade = true;
								}
							}while(repetirIdade == true);
						do{//SE O USARIO DIGITAR UM SEXO INVALIDO 
							repetirSexo = false; //caso o laço repita o valor será reniciado para evitar loops infinitos.
							system ("cls");
							barraSup(29, true, 5);
							printf("\t\t\t\t\t\xBA\t Qual seu sexo?       \xBA\n\t\t\t\t\t\xBA\t\t\t      \xBA\n");
							printf("\t\t\t\t\t\xBA Masculino_(1)  Femenino_(2) \xBA\n\t\t\t\t\t\xBA Voltar__________________(3) \xBA\n");
							barraInf(29, true, 5);
							printf("\t\t\t\t\t>>>>");
								scanf("%d", &sexo);
								if (sexo == 3){
									repetirCadastro = true;
									repetirMenu = true;
								}
								else if(sexo > 3 || sexo < 1){
									printf("Escolha invalidada\nTente novamente!\n");
									repetirSexo = true;
								}
							}while(repetirSexo == true);
						while(repetirMenu == false){//laço que serve para impedir que faça a proxima pergunta caso o usario tenha digitado voltar na pergunta anterior
						repetirEscolaridade = false;
						system("cls");
						barraSup(20, true, 5);
						printf("\t\t\t\t\t\xBA   Novo cadastro    \xBA\n");
						printf("\t\t\t\t\t\xBA\t\t     \xBA\n");
						printf("\t\t\t\t\t\xBA Veterano______(01) \xBA\n");
						printf("\t\t\t\t\t\xBA Egresso_______(02) \xBA\n");
						printf("\t\t\t\t\t\xBA\t\t     \xBA\n");
						printf("\t\t\t\t\t\xBA Voltar________(03) \xBA\n");
						barraInf(20, true, 5);
						printf("\t\t\t\t\t>>>>");
							scanf("%d", &escolaridade);
							if (escolaridade == 1 && sexo == 2){
									mulherCurso++;
								//break;
							}
							else if(escolaridade == 2){
								contadorIdade++;
								if(sexo == 2){
									mulherEgressa++;
								}
								do{
									repetirFormatura = false;
									printf("Ano da formatura?");
									scanf("%d", &anoFormatura);
										if (anoFormatura < 1900 || anoFormatura > 2017){
											printf("Escolha invalida\n tente novamete\n");
											repetirFormatura = true;
										}						
										else{
											idadeConclusao = idadeAtual - (2017 - anoFormatura);// aki eu sei com quantos anos o usario se formou...
											iConclusaoM = idadeConclusao / contadorIdade;//conta para descobrir a idade media de conclusão dos usarios
										break; // se de merda so olhar isso aki
										}
								}while(repetirFormatura == true);
							do{
								repetirEscolaridade = false;// foi necessario por esse codigo aki para impedir que o laço mais interno retorne para esse caso utilize a opção de voltar
								system("cls");
								barraSup(30, true, 4);
								printf("\t\t\t\t\xBA   Qual grau de escolaridade? \xBA\n\t\t\t\t\xBA\t\t\t       \xBA\n");
								printf("\t\t\t\t\xBA    Graduado__________(01)    \xBA\n");
								printf("\t\t\t\t\xBA    Mestrado__________(02)    \xBA\n");
								printf("\t\t\t\t\xBA    Doutorado_________(03)    \xBA\n\t\t\t\t\xBA\t\t\t       \xBA\n");
								printf("\t\t\t\t\xBA    Voltar____________(04)    \xBA\n");
								barraInf(30, true, 4);
								printf("\t\t\t\t>>>>");	
								scanf("%d", &grauEscolaridade);
									if (grauEscolaridade == 4){
										contadorIdade--; //caso o usario volte para o menu anterior o contador de idade será decrementado.
										idadeTotal = idadeTotal - idadeAtual;//serve para decrementar o valor da idade total caso o usario queira voltar.
										repetirMenu = true;
										if (escolaridade ==  1) 
												mulherCurso--; 
										else if(escolaridade == 2) 
												mulherEgressa--;
											repetirCadastro = true;
									}
									else if(grauEscolaridade < 1 || grauEscolaridade > 4){
										printf("Escolha invalida\nTente novamente!\n");
										repetirEscolaridade = true;
									}
							}while(repetirEscolaridade == true);
						break; //descobirir o que esse break faz... SAPORRA ER DUAS CARAS TOMA CUIDADO ELE ERA UM PESO TODO O PROGRAMA AGR NÃO ER MAIS...
						}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@...CASO O USARIO QUEIRA VOLTAR....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
							else if(escolaridade == 3){
								if (sexo == 2 && escolaridade == 1)
									mulherCurso--;
								else if(sexo == 2 && escolaridade == 2)
									mulherEgressa--;
								repetirMenu = true;
							break;
							}
							else
								printf("Desculpe escolha invalida\nTente novamente!\n");
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@......AKI COMEÇA A EXECUÇÃO DO CODIGO DEPOIS DE ESOCLHER O NIVEL DE ESCOLARIDADE@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
						}//laço do while que impede de entrar nessa parte...
					while(repetirMenu == false){
					do{//PERGUNTA 01
						repetirPergunta = false;
					system ("cls");
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
								repetirPergunta = true;
							}
						}
					}while (repetirPergunta == true);
					do{//PERGUNTA 02
					system("cls");
						repetirPergunta = false;
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
								repetirPergunta = true;
								break;
							}
						}
						}while (repetirPergunta == true);
					do{//PERGUNTA 03
					system("cls");
						repetirPergunta = false;
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
								repetirPergunta = true;
								break;
							}
						}
					}while (repetirPergunta == true);
					do{//PERGUNTA 04
					system("cls");
						repetirPergunta = false;
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
								repetirPergunta = true;
								break;
							}
						}
					}while (repetirPergunta == true);
					do{//PERGUNTA 05
					system("cls");
						repetirPergunta = false;
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
								repetirPergunta = true;
								break;
							}
						}
					}while (repetirPergunta == true);
					do{//CONFIRMAÇÃO
						repetirConfirmacao = false;
						printf("OBRIGADO PELA SUA OPINIAO\nELA SERA MUITO PRECIOSA\n\n");
						printf("NOVO CADASTRO____________(01)\n");
						printf("EXIBIR RELATORIO_________(02)\n");
						printf("VOLTAR PARA MENU_________(03)\n");
						scanf("%d", &resposta);
							switch(resposta){
								case 1:{
									repetirCadastro = true;
									pesquisa++;
									break;
								}
								case 2:{
									repetirConfirmacao = true;
									relatorio(concordoP1, concordoP4, concordoP5, neutroP5, mulherCurso, mulherEgressa, mediaIdade, iConclusaoM);
									break;
								}
								case 3: {
									repetirMenu = true;
									pesquisa++; 
									break;
								}
								default:{
									printf("Escolha invalida\nTente novamente!\n");
									repetirConfirmacao = true;
									break;
								}
							}
						}while(repetirConfirmacao == true);
						}
					}while(repetirCadastro == true);
				break;
			}// do case
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@....fim do primeiro caso...@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			case 2:
				if (pesquisa == 1){
					printf("DADOS INSUFICIENTES\nTENTE NOVAMENTE MAIS TARDE!\n\n");
					repetirMenu = true;
				}
				else{
					relatorio(concordoP1, concordoP4, concordoP5, neutroP5, mulherCurso, mulherEgressa, mediaIdade, iConclusaoM);
					repetirMenu = true;
					getch();
				}
				break;
			case 3:
				escolhaCor();
				repetirMenu = true;
				break;
			case 4:{
					barraSup(40, true, 4);
					printf("\t\t\t\t\xBA DESENVOLVEDOR: Uellington Damasceno    \xBA\n");
					printf("\t\t\t\t\xBA DATA DO INICIO: 31/03/2017  |||||||    \xBA\n");
					printf("\t\t\t\t\xBA VERSAO: 1.4                ª| @  @|    \xBA\n");
					printf("\t\t\t\t\xBA NIVEL: Variavel             |   > |    \xBA\n");
					printf("\t\t\t\t\xBA Orientador: Danillo         |_---_|    \xBA\n");
					printf("\t\t\t\t\xBA Ultima altercao 04/04/2017 as 04:02 PM \xBA\n");
					barraInf(40, true, 4);
					getch();
					system("cls");
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
void escolhaCor(){
	int cor;
	int certeza;
	bool repetirTudo = false;
	bool repetirCor = false;
do{
	do{
		repetirTudo = false; // necessario para fazer o valor do laço de repetição para evitar entrar em loop infinito.
		barraSup(70, true, 3);
		printf("\t\t\t\xBA\t\t    ESCOLHA UMA COR DE SUA PREFERENCIA\t\t       \xBA\n");
		printf("\t\t\t\xBA \t\t\t\t\t\t\t\t       \xBA\n");
		printf("\t\t\t\xBA (01) Branco & Preto\t (02) Branco & Verde\t (03) Branco & Vermelho\xBA\n");
		printf("\t\t\t\xBA (04) Preto & Branco\t (05) Preto e Verde\t (06) Preto & Vermelho \xBA\n");
		printf("\t\t\t\xBA (07) Azul & Branco\t (08) Azul & Verde\t (09) Azul & Amarelo   \xBA\n");
		printf("\t\t\t\xBA (10) Cinza & Preto\t (11) Cinza & Verde\t (12) Cor padrao       \xBA\n");
		printf("\t\t\t\xBA \t\t\t\t\t\t\t\t       \xBA\n");
		printf("\t\t\t\xBA >A primeira cor equivale ao fundo ja a segunda cor equivale a letra< \xBA\n");
		barraInf(70, true, 3);
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
	repetirCor == false;
	barraSup(55, false, 0);
	printf("\xBA  Voce realmente deseja utilizar essa cor no terminal? \xBA\n");
	printf("\xBA        (01) Sim\t\t\t(02) Nao        \xBA\n");	
	barraInf(55, false, 0);
	scanf("%d", &certeza);
		if(certeza == 1){
			printf("Otima escolha!\n");
			break;
		}
		else if (certeza == 2){
			system("cls");
			printf("Hum... tambem nao gostei dessa cor\n");
			printf("tentar novamente!\n\n\n");
			repetirTudo = true;
		break;
		}
		else{
			printf("Escolha invalida\nTente novamente!\n\n");
			repetirCor = true;
		}
	}while(repetirCor == true);
}while(repetirTudo == true);
}
