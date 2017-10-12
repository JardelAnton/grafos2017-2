/*
	Aluno: Jardel Anton
	Matricula: 1311100022
	Disciplina: Grafos
	Professor: Douglas André Finco
	Semestre: 2017/2
	Trabalho 3: Algoritmos de Kruskal e Prim
*/

#include <stdlib.h>
#include <stdio.h>
void prim();
void kruskal();
int encontra_menor(int * vetor_valores, int * vertices_abertos);
int main(){
    kruskal();
    prim();
    return 0;
}
void prim(){
    int custo =0;
    int matriz_adjacencia[8][8] = {   //exemplo dos slides
    //   0 1 2 3 4 5 6 7      
        {0,2,0,6,5,0,0,0},  //0
        {2,0,7,7,0,0,0,0},  //1
        {0,7,0,0,6,2,0,0},  //2
        {6,7,0,0,0,0,0,0},  //3
        {5,0,6,0,0,0,4,5},  //4
        {0,0,2,0,0,0,4,6},  //5
        {0,0,0,0,4,4,0,1},  //6
        {0,0,0,0,5,6,1,0},  //7
    };//*/
      /*int matriz_adjacencia[8][8] = { // exercício pg 29
    //   0 1 2 3 4 5 6 7      
        {0,5,0,5,2,0,0,0},  //0
        {5,0,0,9,0,1,0,0},  //1
        {0,0,0,0,0,0,8,0},  //2
        {5,9,0,0,0,0,0,1},  //3
        {2,0,0,0,0,0,4,6},  //4
        {0,1,0,0,0,0,0,0},  //5
        {0,0,8,0,4,0,0,0},  //6
        {0,0,0,1,6,0,0,0}   //7
    };  // */
    int matriz_prim[3][8] = {
        {0,1,2,3,4,5,6,7},
        {0,10,10,10,10,10,10,10},
        {-1,-1,-1,-1,-1,-1,-1,-1}
    };
    int vertices_abertos[8] = {0,1,2,3,4,5,6,7};
    int vertice_atual = 0;
    int numero_vertices_abertos = 8,x, y;   //inteiros auxiliares para loops
    while(-1 != (vertice_atual=encontra_menor(matriz_prim[1],vertices_abertos))){
        for(y = 0; y < 8; y++){
            if(matriz_adjacencia[vertice_atual][y] != 0){
                if(matriz_prim[1][y] > matriz_adjacencia[vertice_atual][y] && vertices_abertos[y] != -1){
                    matriz_prim[1][y] = matriz_adjacencia[vertice_atual][y];
                    matriz_prim[2][y] = vertice_atual;
                }
                vertices_abertos[vertice_atual] = -1;
            }
        }
    }
    printf("\nMatriz Prim após a execução do algoritmo:\n");
    for(x = 0; x < 3; x++){
        for(y = 0; y < 8; y++)
            printf("%d\t",matriz_prim[x][y]);
        printf("\n");
    }
    numero_vertices_abertos = 0;
    printf("\n");
    FILE *file;
	file=fopen("prim.dot","w");
	fprintf(file,"graph G {label=\"Árvore Geradora mínima Prim\";\n");
	while(numero_vertices_abertos < 8){
        for(y = 0; y < 8; y++){
            if(matriz_adjacencia[numero_vertices_abertos][y] != 0){
                if(numero_vertices_abertos == matriz_prim[2][y] && matriz_prim[2][y]!=-1){
                    fprintf(file,"%d--%d", numero_vertices_abertos, y);            
                    custo += matriz_prim[1][y];
    	            fprintf(file,"[label=\"%d\"][color=RED];\n",matriz_prim[1][y]);
                }else if(y > numero_vertices_abertos && matriz_prim[2][numero_vertices_abertos]!=y){ 
                    fprintf(file,"%d--%d", numero_vertices_abertos, y);            
                    //printf("\n%d\t%d",y, matriz_adjacencia[numero_vertices_abertos][y]);
                    fprintf(file,"[label=\"%d\"];\n",matriz_adjacencia[numero_vertices_abertos][y]);
                }
            }
        }
        numero_vertices_abertos++;
    }
    fprintf(file," 	Custo [label=\"Custo Total: %d\"];\n}\n",custo);
	fclose(file);
	system("dot -Tpng prim.dot -o imprime_prim.png");
	system("open imprime_prim.png ");
}

int encontra_menor(int * vetor_valores, int * vertices_abertos){
    int x, y = -1, valor = 10;
    for(x = 0; x < 8; x++)
        if(vetor_valores[x] < valor && vertices_abertos[x] != -1){
            y = x;
            valor = vetor_valores[x];
        }
    return y;
}

void kruskal(){
    int vetor_valores[8]={-1,-1,-1,-1,-1,-1,-1,-1};
    int matriz_kruskal[3][11] = {
        {2,3,3,4,4,7,7,7,8,8,8},
        {6,0,0,0,5,4,4,5,2,2,3},
        {7,1,3,2,6,6,7,7,4,5,5}
    };
    int y, y1=0, w, w1=0, x=0, x1, custo = 0;
    FILE *file;
	file=fopen("kruskal.dot","w");
	fprintf(file,"graph G {label=\"Árvore Geradora mínima Kruskal\";\n");
    for(x = 0; x < 11; x++){
        y=matriz_kruskal[1][x];
        w=matriz_kruskal[2][x];
        y1=y;
        w1=w;
        while((y1 = vetor_valores[y1])>0) y = y1;
        while((w1 = vetor_valores[w1])>0) w = w1;
        if(y1>=w1 && y!=w){
            fprintf(file,"%d--%d", matriz_kruskal[1][x],matriz_kruskal[2][x]); 
            fprintf(file,"[label=\"%d\"][color=RED];\n",matriz_kruskal[0][x]);
            vetor_valores[w] = vetor_valores[y] + vetor_valores[w];
            vetor_valores[y] = w;
            custo+=matriz_kruskal[0][x];
        }else if(y<w){
            fprintf(file,"%d--%d", matriz_kruskal[1][x],matriz_kruskal[2][x]); 
            fprintf(file,"[label=\"%d\"][color=RED];\n",matriz_kruskal[0][x]);
             vetor_valores[y] = vetor_valores[y] + vetor_valores[w];
            vetor_valores[w] = y;
            custo+=matriz_kruskal[0][x];
        }else{
             fprintf(file,"%d--%d", matriz_kruskal[1][x],matriz_kruskal[2][x]); 
             fprintf(file,"[label=\"%d\"];\n",matriz_kruskal[0][x]);
        }
    }
    fprintf(file," 	Custo [label=\"Custo Total: %d\"];\n}\n",custo);
	fclose(file);
	system("dot -Tpng kruskal.dot -o imprime_kruskal.png");
	printf("\nMatriz Kruskal após a execução do algoritmo:\n");
    for(x = 0; x < 8; x++)
        printf("%d  ", x);
    printf("\n");
    for(x = 0; x < 8; x++)
        printf("%d  ", vetor_valores[x]);
    printf("\n");
    
    system("open imprime_kruskal.png ");
}


/*
RECOMENDAÇÕES:
para execução desse algoritmo é necessário ter instalado em sua máquina o graphviz.
Gera e compila imagens
*/