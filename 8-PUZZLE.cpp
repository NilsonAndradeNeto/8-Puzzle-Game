#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

//-------------------------------------------------------------------------------------------------------------------------------
// IMPRIMIR A MATRIZ
void imprimir_matriz(int matriz[3][3]){
    cout <<"" <<endl;
    cout <<"" <<endl;

    cout << "                                               Utilize para se movimentar "<<endl;
    cout << "" <<endl;
    cout <<"                                                           w"<<endl;
    cout <<"                                                        a "<<" s "<<" d "<<endl;
    cout <<"" <<endl;
    cout <<"" <<endl;
    cout <<"" <<endl;                                  // somente para deixar a impressao do codigo mais agradavel
    cout <<"" <<endl;
    cout <<"" <<endl;
    cout <<"" <<endl;


    for(int l=0;l<3;l++){
        for(int c=0;c<3;c++){

            cout <<"                          "<<matriz[l][c]<<"\t";
        }
        cout<<endl;
    }
}

//-------------------------------------------------------------------------------------------------------------------------------
// MATRIZ MISTURADA
void imprimir_matrizebaralhada(int matriz[3][3]){
    srand(time(NULL));
    int aux;
    int linha,coluna;
    linha=rand  ()%  2+1;                          // utilizei o rand na linha e coluna para gerar posicoes aleatorias
    coluna=rand ()%  2+1;

    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 3; c++) {             //loop normal para pegar todas a posicao e a cada volta pela os numero aleatorio
                                                  //formado pelo rand()%2+1;

            aux = matriz[l][c];
            matriz[l][c] = matriz[linha][coluna]; //utilizei uma aux para armazenar o valor da matriz[l][c]
            matriz[linha][coluna] = aux;          //depois a posicao aleatoria matriz[linha][coluna] para trocar com a posicao aux
        }
    }
}
//---------------------------------------------------------------------------------------------------------------------------------
// Para confirmar se a matriz esta correta
bool sao_iguais(int matriz[3][3], int matriz2[3][3]) {


    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(matriz[i][j] != matriz2[i][j]) {// se alguma posicao for diferente return false e para o loop
                return false;

                break;
            }
        }
    }
    // cout <<"  funciona " <<endl;
    return true;                         // se o loop rodar tudo e todas a posicao for igual retorna true
}

void movimento_A(int matriz[3][3], int linha, int coluna) {

    int aux;

    if (coluna < 2) {// if para nao sair dos parametros da matriz
        aux = matriz[linha][coluna];
        matriz[linha][coluna] = matriz[linha][coluna+1];//trocas
        matriz[linha][coluna+1] = aux;

    }
}
void movimento_W(int matriz[3][3], int linha, int coluna) {

    int aux;

    if (linha < 2 ) {// if para nao sair dos parametros da matriz
        aux = matriz[linha][coluna];
        matriz[linha][coluna] = matriz[linha+1][coluna];// trocas de valores
        matriz[linha+1][coluna] = aux;
    }
}
void movimento_S(int matriz[3][3], int linha, int coluna) {

    int aux;

    if (linha > 0  ) {// if para nao sair dos parametros da matriz

        aux = matriz[linha][coluna];
        matriz[linha][coluna] = matriz[linha-1][coluna];//trocas de valores
        matriz[linha-1][coluna] = aux;

    }
}
void movimento_D(int matriz[3][3], int linha, int coluna) {

    int aux;

    if (coluna > 0 ) {// if para nao sair dos parametros da matriz
        aux = matriz[linha][coluna];
        matriz[linha][coluna] = matriz[linha][coluna-1];//troca de valores
        matriz[linha][coluna-1] = aux;

    }
}


int main()
{
    srand(time(NULL));
    int linha,coluna;
    char direcao;
    int movimento_w=0,movimento_a=0,movimento_s=0,movimento_d=0;
    int matriz[3][3]{{1,2,3},
                     {4,5,6},// matriz que vai ser embaralhada
                     {7,8,0}};

    int matriz2[3][3]{{1,2,3},
                      {4,5,6},// matriz correta
                      {7,8,0}};

    srand(time(NULL));
    imprimir_matrizebaralhada(matriz);


    do{

        imprimir_matriz(matriz);

        cout <<"\n";
        cout<< "\n";

        cout<<">>";cin>>direcao;



        for (int i = 0; i < 3; i++) {//fiz 1 for para coluna e outro para linha ele vai rodando linha por linha e coluna por coluna ate achar
            for (int j = 0; j < 3; j++) {// o numero 0 quando ele encontra da uma break e para o loop  e
                if (matriz[i][j] == 0) {
                    linha = i;
                    coluna = j;
                    break;
                    cout << " teste 1 2 3 " <<endl;// apenas para verificar se o loop estava parando
                }
            }

        }




        // SWITCH PARA FAZER A TROCA DE VALORES PARA MOVIMENTAR OS NUMEROS SOMENTE A ONDE TEM O 0
        switch (direcao) {

        case 's': // para baixo
            movimento_S(matriz,linha,coluna);

            movimento_s=(movimento_w+1);

            break;

        case 'd': // para a direita

            movimento_D(matriz,linha,coluna);

            movimento_d=(movimento_a+1);

            break;

        case 'w': // para cima

            movimento_W(matriz, linha, coluna);

            movimento_w=(movimento_s + 1);

            break;

        case 'a': // para a esquerda

            movimento_A(matriz, linha, coluna);

            movimento_a=(movimento_d + 1);

            break;

        }

        system("cls");


    }while(!sao_iguais(matriz,matriz2));//sofri por causa do !

    cout << "                                                 PARABENS VOCE GANHOU" <<endl;
    cout<<  "------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<""<<endl;
    cout << " quantidade de movimento para cima     |"<< movimento_w  <<"|"<<endl;
    cout << " quantidade de movimento para esquerda |"<< movimento_a  <<"|"<<endl;
    cout << " quantidade de movimento para baixo    |"<< movimento_s  <<"|"<<endl;
    cout << " quantidade de movimento para direita  |"<< movimento_d  <<"|"<<endl;
    return 0;
}

