# professor-curioso

## Sumário
- [Problema](#problema)
- [Requisistos básicos](#requisitos-básicos)
- [Perguntas](#perguntas)
- [Relátorio de pesquisa](#relatório-de-pesquisa)
- [Produto](#produto)
- [Objetivo de aprendizagem](#objetivo-de-aprendizagem)
- [Melhorias](#melhorias)
- [Versões anteriores](#versões-anteriores)
- [Curiosidades](#curiosidades)

## Problema

"A disciplina Introdução a Engenhaira, do primeiro semestre do curso de Engenharia da 
Computação, trata de questões relacionadas à área de conhecimento, os desafios e as 
possibilidades para os egressos, assim como questões relacionadas à Aprendizagem Baseada
em Problemas (PBL). Diante da necessidade de aproximar os estudantes do curso e da área,
o professor da disciplina resolveu solicitar aos calouros uma pesquisa de opinião com
os estudantes do curso, assim como os egressos. Para agilizar a obtenção e a análise dos 
resultados, deseja-se qeu a pesquisa seja informatizada."

## Requisitos básicos

| Requisito nº | Descrição | Status |
| :----------: | --------- | :----: |
| 01 | As opiniões podem ser três: `0 - Não concordo`,  `1 - Concordo` e `2 - Não tenho opinião.` | :white_check_mark:| 
| 02 | Cada entrevistado deve informar seu sexo, sua idade e o ano de formatura. | :white_check_mark: |
| 03 | Caso o entrevistado seja egresso, deverá também informar seu grau de instrução ( superior completo, especialização, mestrado ou doutorado); | :white_check_mark: |
| 04 | Calcular e mostrar a quantidade dos que Concordam com a pergunta 05. | :white_check_mark: |
| 05 | Calcular o percentual dos que Não concordam ou Não possuem opinião definida com a afirmação da pergunta 06 | :white_check_mark: |
| 06 | Calcular a média de idade dos que Não Concordam com a pergunta 07. | :white_check_mark: |
| 07 | Calcular a média de idade dos estudantes no momento da conclução do curso. | :white_check_mark: |
| 08 | Computar o número de mulheres que pertencem ao curso e o número de egressas. | :white_check_mark: |
| 09 | Computar o número de entrevistados que Concordam com a pergunta 08. | :white_check_mark: |
| 10 | Calcular entre os estudantes em curso, aqueles que Concordam com a pergunta 09 ou Não tem Opinião. | :white_check_mark: |
| 11 | Ao final da pesquisa, o sistema deve exibir um relatório apresentando os resultados solicitados. | :white_check_mark: |

## Perguntas
<details>
<summary>:eyes: Listar perguntas </summary>
  
| Pergunta nº | Pergunta | Intervalo válido de respostas |
| :---------: | -------- | ----------------------------- |
| 01 | Qual a sua idade? | 10 e 100 |
| 02 | Qual seu sexo? | 1 - Masculino<br>2 - Femenino<br>3 - Voltar|
| 03 | Veterando ou egresso? | 1 - Veterano<br> 2 - Egresso<br> 3 - Voltar |
| 04 | Que ano irá se formar (Se veterano) | entre 2017 e 2050  |
| 4.1 |  Qual é seu grau de escolaridade? | 1 - Especialização<br>2 - Graduado<br>3 - Mestrado<br>4 - Doutorado<br>5 - Voltar |
| 4.2 | Em que ano se formo? (Para egressos) | entre 1900 e 2017 | 
| 05 | Você concorda que o PBL ajuda na execução de seus trabalhos? | 0 - Não Concordo<br>1 - Concordo<br>2 - Não Tenho Opinião |
| 06 | Você concorda que o PBL é melhor que o método tradicional de ensino? | 0 - Não Concordo<br>1 - Concordo<br>2 - Não Tenho Opinião |
| 07 | O mercado de trabalho local é capaz de reter os profissionais formados nas áres de informática e engenharia? | 0 - Não Concordo<br>1 - Concordo<br>2 - Não Tenho Opinião |
| 08 | Voce concorda que os novos alunos desconhecem o PBL quando entram no curso? | 0 - Não Concordo<br>1 - Concordo<br>2 - Não Tenho Opinião |
| 09 | Concorda com a afirmação de que um aluno só consegue se adaptar com o PBL somente a partir do 4º semestre? | 0 - Não Concordo<br>1 - Concordo<br>2 - Não Tenho Opinião |
</details>

Após o término de uma entrevista o sistema apresenta o menu abaixo que possiblita o entrevistador 
efetuar uma nova pesquisa ou ver o [relatório](#relatório-de-pesquisa) das ultimas pesquisa.

![Menu resultados da pesquisa](https://github.com/UellingtonDamasceno/professor-curioso/blob/main/res/imagens/menu-fim-pesquisa.png)

## Relatório de pesquisa

![Relátorio](https://github.com/UellingtonDamasceno/professor-curioso/blob/main/res/imagens/resultados-pesquisas.png)

## Produto
Como produto final foi necessário construir um algoritmo na representação de
[fluxograma](https://github.com/UellingtonDamasceno/professor-curioso/blob/main/res/Fluxograma.pdf)
e um [relatório técnico](https://github.com/UellingtonDamasceno/professor-curioso/blob/main/res/Relat%C3%B3rio.pdf).

    Dá um desconto para meu relatório. Ele foi o meu primeiro. 
    
## Objetivo de aprendizagem
- [Fluxograma.](https://github.com/UellingtonDamasceno/professor-curioso/blob/main/res/Fluxograma.pdf)
- Costrução de [relatório técnico.](https://github.com/UellingtonDamasceno/professor-curioso/blob/main/res/Relat%C3%B3rio.pdf) 
- Linguagem de programação C.
- Entrada e saída de dados.
- Estrutura condicionais.
- Estrutura de repetições.

Para o implementação desse sistema não era permitido o uso de funções, e
por esse motivo o código ficou com essa aparência de "Kamehameha" (ou
Hadouken se preferirem). Apesar dessa restrição foram utilizadas funções
sendo uma para imprimir uma barra superior e outra para barra inferior
(UX em primeiro lugar).
      
Por falar em UX, o sistema não é finalizado até que o usuário selecione 
a opção de "sair" no menu principal. Isso significa que todos os erros de
entradas inválidas foram tratadas, portanto é possível inserir caracteres
inválidos em questões onde era esperado um inteiro sem que o sistema seja
finalizado.

## Melhorias
Este sistema foi um primeiro contato real com a metodólogia PBL e por esse 
motivos há muitas melhorias para serem implementadas. Abaixo segue uma lista
de melhorias que poderiam ser implementadas sem fugir do objetivo de 
aprendizagem.

- Utilizar condicionais para verificar a quantidade de entrevistadas para evitar textos como: "0 Veteranos foram entrevistados."
- Utilizar caracteres ASCII para construir as bordas do menu.
- Utilização de funções para reduzir o efeito "Kamehameha".
- Refatorar condições para retirar redundâncias como por exemplo:
```c
  else if(escolaridade == 2 && anoFormatura < 1900 || escolaridade == 2 && anoFormatura > 2017) // Linha 207
  // Trocar por:
  else if(escolaridade == 2 && (anoFormatura < 1900 || anoFormatura > 2017))
```
- Utilizar pré-processadores para identificar qual é o S.O utilizado e definir quais funções auxiliares do sistema devem ser utilzados. 
- Inserir bibliotecas necessárias para o bom funcionamento do _software_ em sistemas operacionais baseado em Linux.

## Versões anteriores
Na época do desenvolvimento desse sistema não havia um repositório git para organizar as versões. 
Por esse motivo pensou-se em criar cópias do código a fim de salvar o estado do mesmo.
[Veja aqui as versões anteriores](https://github.com/UellingtonDamasceno/professor-curioso/tree/main/Vers%C3%B5es%20anteriores)

### Curiosidades
1. O motivo do github informar que há mais código `c++` do que `c` e  que na época do desenvolvimento desse sitema eu
não sabia que o tipo `bool` não estava presente na Linguagem C. Mas como estava utilizando o DEVC++ como ambiente de desenvolvimento
comecei a produzir códigos em `c++` (sem saber) por causa das variáveis boleanas presentes no código e da IDE que também entendia `c++`. 
2. A descrição que aparece ao selecionar a opção "sobre" no menu principal foi construida em `python` e reimplementado em c.
3. O [relatório técnico](https://github.com/UellingtonDamasceno/professor-curioso/blob/main/res/Relat%C3%B3rio.pdf) recebeu duas notas diferentes.
4. Apesar de não utilizar o git/github os códigos na pasta de versões anteriores possuem uma descição que lista as diferenças entre a versão atual e a anterior.
5. Em uma das versões anteriores há uma opção no menu principal na qual o usuário podia escolher entre 12 combinações de cores do terminal e fonte. Essa opção foi retirada para facilitar a construção do fluxograma.

