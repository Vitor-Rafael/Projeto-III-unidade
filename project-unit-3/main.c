#include <stdio.h>
#include <stdlib.h>

/* A funcao interface quando solicitada mostra o menu de acoes que o usuario
 * pode escolher dentre as 16 definidas.
*/
void interface(){
    printf("PROGRAMA DE MANIPULACAO DE MATRIZES\n"
           "(1) Definir o tamanho da matriz A\n"
           "(2) Definir o tamanho da matriz B\n"
           "(3) Preencher a matriz A com valores aleatorios\n"
           "(4) Preencher a matriz B com valores aleatorios\n"
           "(5) Atribuir valores manualmente para os elementos da matriz A\n"
           "(6) Atribuir valores manualmente para os elementos da matriz B\n"
           "(7) Calcular A+B\n"
           "(8) Calcular A-B\n"
           "(9) Calcular A*B\n"
           "(10) Imprimir matriz A\n"
           "(11) Imprimir matriz B\n"
           "(12) Imprimir matriz C\n"
           "(13) Ler a matriz A de um arquivo\n"
           "(14) Ler a matriz B de um arquivo\n"
           "(15) Escrever a matriz C em um arquivo\n"
           "(16) Sair\n"
           "digite sua operacao: ");
}
/* A funcao randA corresponde a acao 3, a qual ira preencher
 * a matriz A com valores aleatorios de um intervalo
 * escolhido pelo usuario.
*/
void randA(int i,int j, float A[100][100]){

    int a, b, primeiro, ultimo;
    printf("primeiro numero do intervalo dos aleatorios: ");
    scanf("%d",&primeiro);
    printf("ultimo numero do intervalo dos aleatorios: ");
    scanf("%d",&ultimo);

    for(a=0; a<i; a++){
        for(b=0; b<j; b++){
            A[a][b]=(primeiro + rand()%ultimo);
        }
    }

}
/* A randB faz igual a randA, mas com a matriz B, alem de que
 * correspondem a opcao 4 do menu.
*/
void randB(int i,int j, float B[100][100]){

    int a, b, primeiro, ultimo;
    printf("primeiro numero do intervalo dos aleatorios: ");
    scanf("%d",&primeiro);
    printf("ultimo numero do intervalo dos aleatorios: ");
    scanf("%d",&ultimo);
    for(a=0; a<i; a++){
        for(b=0; b<j; b++){
            B[a][b]=(primeiro + rand()%ultimo);
        }
    }

}
/* atribuirA e a funcao condizente com a acao 5, nesse
 * caso o usuario ira atribuir manualmente a cada laco
 * de repeticao um valor para a matriz A.
*/
void atribuirA(int i,int j, float A[100][100]){
    int x, y;

    for(x=0; x<i; x++){
        for(y=0; y<j; y++){
            printf("Matriz A valor da posicao [%d][%d]: ", x,y);
            scanf("%f", &A[x][y]);
        }
    }

}
/* atribuirB ea funcao da opcao 6, ela realiza o mesmo
 * trabalho da funcao atribuirA, porem com a matriz B.
*/
void atribuirB(int i,int j, float B[100][100]){

    int x, y;
    for(x=0; x<i; x++){
        for(y=0; y<j; y++){
            printf("Matriz B valor da posicao [%d][%d]: ", x,y);
            scanf("%f", &B[x][y]);

        }
    }

}
/* a funcao somaAB realiza a soma dos valores das posicoes
 * correspondentes das duas matrizes e coloca na matriz C.
 * a soma so pode ocorrer se as matrizes forem de tamanhos iguais,
 * alem disso corresponde ao item 7 do menu.
*/
void somaAB(int ia, int ja, int ib, int jb, float A[100][100], float B[100][100], float C[100][100]){

    if((ia==ib) && (ja==jb)){
        for(int x=0;x<ia;x++){
            for(int y=0; y<ja; y++){
                C[x][y]=(A[x][y]+B[x][y]);
            }
        }
    }else{
        printf("NAO E POSSIVEL, MATRIZES DE TAMANHOS DIFERENTES\n");
    }
}
/* subtracaoAB realiza passos identicos a da funcao somaAB, mas
 * dessa vez com a operacao matematica de subtrair, alem disso
 * ela atende aos mesmo requisitos de somaAB. Por fim e o item 8 do menu.
*/
void subtracaoAB(int ia, int ja, int ib, int jb, float A[100][100], float B[100][100], float C[100][100]){

    if((ia==ib) && (ja==jb)){
        for(int x=0;x<ia;x++){
            for(int y=0; y<ja; y++){
                C[x][y]=(A[x][y]-B[x][y]);
            }
        }
    }else{
        printf("NAO E POSSIVEL, MATRIZES DE TAMANHOS DIFERENTES\n");
    }
}
/* multiplicacaoAB e o item 9 do menu, a funcao realiza a operacao
 * matematica de multiplicacao de matrizes, para que isso possa ocorrer
 * o tamanho da coluna de A deve ser igual ao de linhas de B e o tamanho
 * de linhas de A igual ao de colunas de B.
*/
void multiplicacaoAB(int ia, int ja, int ib, int jb, float A[100][100], float B[100][100], float C[100][100]){

    float valorvariado, valorfinal=0;
    int a, b, linha=0, coluna=0, contador=0, colunaB=0,linhaA=0;

    if((ia==jb) && (ib==ja)){
        for(a=0; a<(ia*jb); a++){
            for(b=0; b<ja; b++){
                valorvariado=(A[linhaA][b]*B[b][colunaB]);//valorvariado guarda o valor de cada multiplicacao.
                valorfinal=valorfinal+valorvariado;//valor final soma os valores variados para por na posicao da matriz C.
                if(b==(ja-1)){//verifica se ja ocorreu todas as multiplicacoes para por o valor na posicao.
                    C[linha][coluna]=valorfinal;//preenche a posicao com os valore somados das multiplicacoes.
                    coluna++;//vai para a proxima coluna da linha para preencher com o outro valor.
                    valorfinal=0;//reinicia valor final
                    if(coluna==(ia)){//verifica se ja preencheu todas as colunas da linha.
                        linha++;//caso ja tenha preenchido, pula para a outra linha.
                        coluna=0;//reinicia a coluna para preencher uma de cada vez da outra linha.
                    }
                }
            }
            contador++;//contador para analisar se ja foi completada uma das operacoes repetitiveis da multiplicacao.
            if(contador<ia){//verifica se o contador e menor que o tamanho de linhas da matriz A.
                colunaB++;//aumenta o valor da coluna da matriz B para a proxima multiplicacao.
            }else{
                colunaB=0;//coluna B volta para a primeira.
                contador=0;//como o contador foi maior, reinicia ele para repetir a operacao de multiplicacao seguinte.
                linhaA++;//vai para a proxima linha da matriz A.
            }
            // coluna=0;
        }
    }else{
        printf("NAO E POSSIVEL, MATRIZES IMCOMPATIVEIS\n");
    }
}
/* A funcao imprimeA realiza a acao do item 10 do menu.
 * atraves de lacos de repeticao sao imprimidos os valores
 * da posicao da matriz A.
*/
void imprimeA(int i, int j, float A[100][100]){

    int x, y;
    for(x=0; x<i; x++){
        for(y=0; y<j; y++){
            printf("%.2f ", A[x][y]);
        }
        printf("\n");
    }
}
/* imprimeB faz a mesma operacao do imprimeA, mas com a matriz B.
 * item 11 do menu.
*/
void imprimeB(int i, int j, float B[100][100]){

    int x, y;
    for(x=0; x<i; x++){
        for(y=0; y<j; y++){
            printf("%.1f ", B[x][y]);
        }
        printf("\n");
    }
}
/* imprimeC e o mesmo caso das duas anteriores, mas
 * com a matriz C. item 12 do menu.
*/
void imprimeC(int i, int j, float C[100][100]){

    int x, y;
    for(x=0; x<i; x++){
        for(y=0; y<j; y++){
            printf("%.1f ", C[x][y]);
        }
        printf("\n");
    }
}
/* leraquivoA e uma funcao que realiza a operacao do item 13.
 * Ela conssite em mostrar os valores dentro de um arquivo da
 * matriz A.
*/
void lerarquivoA(float matrizA[100][100], int linhaA, int colunaA){

    //operacao a seguir manda a matriz A para o arquivo.
    FILE *file;
    file = fopen("E:/Qt-Creator/arquivo/matrizA.txt","w");
    for(int i=0; i<linhaA; i++){
        for(int j=0; j<colunaA; j++){
            fprintf(file,"%.2f ",matrizA[i][j]);
        }
        fprintf(file,"\n");
    }
    fclose(file);
    //fim da operacao.

    //a proxima operacao ler o que tem no arquivo.
    file = fopen("E:/Qt-Creator/arquivo/matrizA.txt","r");
    for(int i=0; i<linhaA; i++){
        for(int j=0; j<colunaA; j++){
            fscanf(file,"%.2f ",&matrizA[i][j]);
        }
    }

    for(int i=0; i<linhaA; i++){
        for(int j=0; j<colunaA; j++){
            printf("%.2f ",matrizA[i][j]);
        }
        printf("\n");
    }
    fclose(file);
    //fim da operacao.
}
/* leraquivoB realiza a mesma funcao do lerarquivoA, mas dessa
 * vez ira mostrar os valores da matriz B. E o item 14 do menu.
*/
void lerarquivoB(float matrizB[100][100], int linhaB, int colunaB){

    FILE *file;
    // a operacao seguinte manda o arquivo B para o arquivo.
    file = fopen("E:/Qt-Creator/arquivo/matrizB.txt","w");
    for(int i=0; i<linhaB; i++){
        for(int j=0; j<colunaB; j++){
            fprintf(file,"%.2f ",matrizB[i][j]);
        }
        fprintf(file,"\n");
    }
    fclose(file);
    //fim da operacao.

    //a operacao seguinte ler o arquivo com os valores da matriz B.
    file = fopen("E:/Qt-Creator/arquivo/matrizB.txt","r");
    for(int i=0; i<linhaB; i++){
        for(int j=0; j<colunaB; j++){
            fscanf(file,"%.2f ",&matrizB[i][j]);
        }
    }

    for(int i=0; i<linhaB; i++){
        for(int j=0; j<colunaB; j++){
            printf("%.2f ",matrizB[i][j]);
        }
        printf("\n");
    }
    fclose(file);
    //fim da operacao.
}

/* escreverC e diferente das funcoes ler arquivo, pois ela tem
 * como execucao enviar os valores das posicoes da matriz C para
 * o arquivo em questao. E o item 15 do menu.
*/
void escreverC(float matrizC[100][100], int linhaA, int colunaB){

    FILE *file;
    file = fopen("E:/Qt-Creator/arquivo/matrizC.txt","w");
    for(int i=0; i<linhaA; i++){
        for(int j=0; j<colunaB; j++){
            fprintf(file,"%.2f ",matrizC[i][j]);
        }
        fprintf(file,"\n");
    }
    fclose(file);
}

int main()
{
    float A[100][100], B[100][100], C[100][100];//matrizes.
    int linhaA=100, colunaA=100, linhaB=100, colunaB=100;//tamanhos de linhas e colunas.
    int operacao=0;//escolha da operacao.

    do{
        interface(); //chama a funcao interface.
        scanf("%d", &operacao); //usuario digite a opcao da sua escolha

        switch(operacao){ //analisa a opcao.
        case 1:
            printf("QUANTIDADE DE LINHAS DE A: ");
            scanf("%d", &linhaA); //define o tamanho de linhas da matriz A.
            printf("QUANTIDADE DE COLUNAS DE A: ");
            scanf("%d", &colunaA); //define o tamanho de colunas de A.
            break;
        case 2:
            printf("QUANTIDADE DE LINHAS DE B: ");
            scanf("%d", &linhaB); //define o tamanho de linhas da matriz B.
            printf("QUANTIDADE DE COLUNAS DE B: ");
            scanf("%d", &colunaB); //define o tamanho de colunas de B.
            break;
        case 3:
            randA(linhaA, colunaA, A); //chama a funcao randA e envia linha, coluna e a propria matriz A.
            break;
        case 4:
            randB(linhaB, colunaB, B); //chama a funcao randB e envia linha, coluna e a propria matriz B.
            break;
        case 5:
            atribuirA(linhaA, colunaA, A); //chama a funcao atribuirA e envia linha, coluna e a propria matriz A.
            break;
        case 6:
            atribuirB(linhaB, colunaB, B); //chama a funcao atribuirB e envia linha, coluna e a propria matriz B.
            break;
        case 7:
            somaAB(linhaA,colunaA,linhaB,colunaB,A,B,C); //chama a funcao somaAB e envia os valores de linha e coluna
            //das matrizes A e B, alem das matrizes A, B e C.
            break;
        case 8:
            subtracaoAB(linhaA,colunaA,linhaB,colunaB,A,B,C); //chama a funcao subtracaoAB e envia os valores de linha e coluna
            //das matrizes A e B, alem das matrizes A, B e C.
            break;
        case 9:
            multiplicacaoAB(linhaA,colunaA,linhaB,colunaB,A,B,C); //chama a funcao multiplicacaoAB e envia os valores de linha e coluna
            //das matrizes A e B, alem das matrizes A, B e C.
            break;
        case 10:
            imprimeA(linhaA,colunaA,A); //chama a funcao imprimeA e envia linha, coluna e a propria matriz A.
            break;
        case 11:
            imprimeB(linhaB,colunaB,B); //chama a funcao imprimeB e envia linha, coluna e a propria matriz B.
            break;
        case 12:
            imprimeC(linhaA,colunaB,C); //chama a funcao imprimeC e envia o tamanho da linha de A, coluna de B,
            //alem da matriz C.
            break;
        case 13:
            lerarquivoA(A, linhaA, colunaA); //chama a funcao lerarquivoA e envia linha, coluna e a propria matriz A.
            break;
        case 14:
            lerarquivoB(B, linhaB, colunaB); //chama a funcao lerarquivoB e envia linha, coluna e a propria matriz B.
            break;
        case 15:
            escreverC(C, linhaA, colunaB); //chama a funcao escreverC e envia os valores de linha da matriz A,
            //coluna da matriz B e a propria matriz C.
            break;
        }

        printf("\n");
    }while(operacao!=16); //repete enquanto o valor de operacao for diferente de 16.


    return 0;
}
