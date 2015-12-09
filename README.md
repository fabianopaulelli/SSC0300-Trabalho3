# SSC0300 – LINGUAGENS DE PROGRAMAÇÃO E APLICAÇÕES #
# TRABALHO 3 – MATRIZES ESPARSAS

### PARTICIPANTES DO GRUPO
- RENAN STRANO DE OLIVEIRA – 8530980
- FABIANO CAVALHEIRO PAULELLI - 8670013

### AMBIENTE DE DESENVOLVIMENTO
- PLATAFORMA: WINDOWS 8
- COMPILADOR: GCC/CPP ( IDE – Code::Blocks v12.11 )


####Introdução

	O trabalho 3 consiste na implementação dinâmica de uma Matriz Esparsa. A maior característica de uma 
	matriz esparsa é que ela possui muitos zeros, fazendo com que uma matriz estática ocupe muito espaço 
	não utilizado. A solução é criar uma estrutura dinâmica por onde são alocados na memória apenas os 
	elementos utilizados, ou seja, que não tem valor zero. Para isso, utiliza-se mais memória para 
	matrizes pequenas, por conta das estruturas e alocações, mas as vantagens aumentam quanto maior o 
	tamanho da matriz.
	Também foram implementadas algumas operações básicas sobre a matriz esparsa, tais como inserir e 
	deletar elementos em posições específicas, recuperar elementos na matriz (caso existam), calcular a
	soma de elementos em uma determinada linha ou coluna e liberar a matriz da memória.

####Descrição do Projeto

	A implementação foi feita em sistema operacional Windows 8, arquitetura x64, 
	IDE Code::Blocks versão 12.11, compilador gcc.
	Foram criados 5 arquivos de código-fonte:

	main.c Este é o arquivo do menu principal onde o usuário coloca as informações do menu 
	principal e modifica a matriz esparsa criada dinamicamente no início do programa.

	matEsp.c Arquivo das funções de manipulação direta da matriz esparsa.

	funcMenu.c Arquivo das funções do menu principal do programa.

	matEsp.h Declarações das funções do arquivo matEsp.c.

	funcManu.h Declarações das funções do arquivo funcMenu.c.

	O programa se inicia pedindo dois valores para o tamanho da matriz e sem seguida cria uma matriz esparsa vazia.
	Após isso, o usuário encontra um menu com todas as possíveis operações sobre a matriz, podendo  alterá-la como 
	quiser e também sair do programa principal.


 

####Descrição da Matriz

	O programa faz o uso de duas estruturas para criação da matriz. Uma delas é a estrutura Celula, que é 
	cada célula de posição (X,Y) e valor da matriz, todos do tipo int. Cada Celula também possui um ponteiro 
	para o próximo elemento da linha (direita) e outro ponteiro para o próximo elemento da coluna (baixo). 
	Ambos os ponteiros são do tipo Celula.
	A outra estrutura chamamos de MatrizEsparsa, que é a matriz em si. Nela, guardamos os valores do tamanho 
	máximo de X e Y e também um ponteiro para o elemento (-1,-1) do tipo Celula, chamado ini.
	Ao ser criada, a matriz cria X+Y+1 Celulas ligadas, onde temos X celulas se ligando à direita em fila, 
	sendo todas com o valor Y = -1 e o valor X crescente de -1 até o tamanho máximo de X. Analogamente, temos
	uma fila na posição X = -1 com o valor crescente de Y de -1 até o tamanho máximo.

####Descrição das Funções

	MatrizEsparsa* criaMatrizEsparsa(int tam_x, int tam_y);
		Aloca uma variável do tipo MatrizEsparsa, coloca os parâmetros na variável, seta o ponteiro para nulo e 
		retorna a variável criada.

	Celula *verificaPosicaoNaMatrizEsparsa(MatrizEsparsa *m, int x, int y);
		Verifica se existe alguma celula na posição (x,y) dada nos parâmetros.

	int inserirValorMatrizEsparsa(MatrizEsparsa *m, int x, int y, int valor);
		Insere uma célula na posição (x,y) especificada, se puder ser inserida. Utiliza a função acima para isso.
		Esta função não só apenas adiciona uma célula como uma lista encadeada, mas também coloca na posição 
		(X,Y) correta, já que se trata de uma matriz.

	void printaMatrizEsparsa(MatrizEsparsa *m);
		Utiliza um ponteiro para passar por toda a matriz, imprimindo na tela cada célula, com valores que 
		representam (Posição X, Posição Y, Valor da Célula), nessa ordem.

	int deletarCelula(MatrizEsparsa *m, int x, int y);
		Busca uma determinada célula na posição (X,Y) e a libera da memória, caso exista, acertando todos os 
		ponteiros necessários.

	void destroiMatrizEsparsa(MatrizEsparsa *m);
		Destrói toda a matriz, deletando todas as suas células antes.

	int consultaValorCelulaMatrizEsparsa(MatrizEsparsa *m, int x, int y);
		Procura uma determinada célula na posição (X,Y) e retorna seu valor, caso a mesma exista.

	int somaLinha(MatrizEsparsa *m, int linha);
		Utiliza um ponteiro para somar todos os valores de uma determinada linha.

	int somaColuna(MatrizEsparsa *m, int coluna);
		Utiliza um ponteiro para somar todos os valores de uma determinada coluna.

	void menuInserir(MatrizEsparsa *m);
	void menuDeletar(MatrizEsparsa *m);
	void menuConsultar(MatrizEsparsa *m);
	void menuMostrarMatriz(MatrizEsparsa *m);
	void menuCalcularLinha(MatrizEsparsa *m);
	void menuCalcularColuna(MatrizEsparsa *m);
	void menuLiberarSair(MatrizEsparsa *m);
		Funções de auxílio do menu principal. Servem para chamar as funções correspondentes à escolha do 
		usuário no menu.




####Tutorial de Uso

	Ao iniciar, o programa pergunta o tamanho X e Y para já alocar uma matriz. Se tudo der certo, a matriz é 
	alocada e o usuário é recebido com um menu principal, onde poderá manipular a matriz de diversas formas.
	O menu dá-se por um texto e uma leitura do teclado ao final, onde cada opção do menu é uma operação 
	diferente sobre a matriz.
	Ao escolher uma das opções, o usuário deverá colocar alguns parâmetros, quando necessário, para manipular 
	a matriz. Depois, o programa tentará computar o que foi pedido, exibindo uma mensagem de sucesso ou não.
	O programa terminará se o usuário escolher a opção 7, onde a matriz é completamente desalocada e o programa, 
	enfim, é finalizado.

####Outras Informações

		Uma limitação da matriz implementada neste trabalho é o fato de que não é possível adicionar uma 
	célula em uma posição se já existe célula nesta mesma posição, ou seja, se já temos uma célula na posição (2,2), 
	o programa não permite que se adicione uma outra célula nessa posição. Uma das coisas que poderia ser feita é 
	simplesmente alterar a variável valor da célula em questão. Melhor ainda, poderíamos ter uma lista encadeada de 
	vários valores para uma mesma posição, mas não achamos necessário para o escopo do trabalho. Enfim, optamos por 
	não permitir que o usuário insera uma célula naquela posição. Para isso, deve-se utilizar o menu para deletar a 
	célula em questão e depois inserir nova célula.
		O programa preocupa-se sempre em não deixar com que o usuário coloque valores impossíveis, como 
	por exemplo, alocar uma matriz com um número negativo de espaço ou buscar por posições inexistentes na matriz.
	Porém, alguns bugs estão propensos a acontecer visto a complexidade da implementação.
