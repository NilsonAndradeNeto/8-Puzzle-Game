# 8-Puzzle-Game

Introdução
Este projeto é um jogo de 8 puzzle desenvolvido como parte do curso de Ciência da Computação na UNIVALI, 2023. O objetivo do trabalho é detalhar o processo de desenvolvimento do código, incluindo as principais funções utilizadas para imprimir e embaralhar matrizes, bem como os movimentos dos números dentro do jogo.

Desenvolvimento
O desenvolvimento do projeto enfrentou desafios, especialmente na criação de movimentos e na geração de matrizes embaralhadas. Houve dificuldades com loops, como o do-while, que não parava corretamente quando as matrizes eram iguais.

Funções e Estruturas Utilizadas
Impressão da Matriz:

Função void imprimir_matriz: Utiliza dois loops for para imprimir a matriz.
Função void imprimir_matriz_embaralhada: Mistura a matriz de 0 a 8 (onde 0 representa o espaço vazio) e a imprime.
Movimentos:

Funções void movimento_A, void movimento_W, void movimento_S e void movimento_D: Permitem movimentar o espaço vazio na matriz (0) para esquerda, cima, baixo e direita, respectivamente.
Comparação de Matrizes:

Função bool sao_iguais: Compara duas matrizes para verificar se são iguais, retornando true se forem e false caso contrário.
Lógica Principal:

Dentro do int main, duas matrizes são declaradas: uma para ser embaralhada e outra para verificar a igualdade.
Um loop do-while é utilizado para solicitar movimentos do usuário até que as matrizes sejam iguais, utilizando um switch para capturar os comandos de movimento (W, A, S, D).

