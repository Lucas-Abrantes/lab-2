#include <stdio.h>
#include <stdlib.h>
#include "cidade.cpp"
#include "lerArquivos.cpp"
#include <string.h>
#include <math.h>


dataItem* criarGrafo(char *arquivo_cidades, char *arquivo_coordenadas){

    cidade *todasCidades = getCidades(arquivo_cidades);
    gps *todoLocal = getGps(arquivo_coordenadas);
    dataItem* d = getItens(todasCidades, todoLocal);

    int k = 0;

    dataItem* cidadesDoRN = (dataItem*)malloc(167*sizeof(dataItem*));

    for(int i = 0; i<5570; i++){
        if(strcmp(d[i].city.estado, "RN" ) == 0){
            cidadesDoRN[k] = d[i];
            k++;
        }
    }

    return cidadesDoRN;

}

float distancia(dataItem local1, dataItem local2){

    float d = sqrt(pow((local1.GPS.la - local2.GPS.la), 2) + pow((local1.GPS.lo - local2.GPS.lo), 2));

    return d;

}

void Grafo(dataItem* grafo, float D){

    float G[167][167];
    float menorD = 0;
    float maiorD = 0;

    for (int i = 0; i < 167; i++)
    {

        for (int y = 166; y >= 0; y--)
        {
            float d = distancia(grafo[i], grafo[y]);

            if (d < D)
            {
                G[i][y] = d;
                G[y][i] = d;

            } else
            {
                G[i][y] = 0;
                G[y][i] = 0;
            }


            if (i != y)
            {
                if (i == 0 && y == 166)
                {
                    menorD = d;
                    maiorD = d;
                }
    
                if (d < menorD)
                {
                    menorD = d;
                }

                if (d > maiorD)
                {
                    maiorD = d;
                }

            }
        
        }
        
    }

    int cont = 0;
    int quantidadeMaisVizinhos = 0;
    int quantidadeMenosVizinhos = 0;
    int posicaoMaisVizinho = 0;
    int posicaoMenosVizinho = 0;

    for (int x = 0; x < 167; x++)
    {
        for (int z = 0; z < 167; z++)
        {
            
            if (G[x][z] > 0)
            {
                cont++;
            }
            
        }
        
        if (x == 0)
        {
            quantidadeMenosVizinhos = cont;
        }

        if (cont > quantidadeMaisVizinhos)
        {
            quantidadeMaisVizinhos = cont;
            posicaoMaisVizinho = x;
            cont = 0;
        }
        
        if (cont < quantidadeMenosVizinhos)
        {
            quantidadeMenosVizinhos = cont;
            posicaoMenosVizinho = x;
            cont = 0;
        }
        
    }

}