#include <stdlib.h>
#include <stdio.h>

void prim();
int encontra_menor(int * vetor_valores, int * vertices_abertos);
int main(){
    prim();
    return 0;
}

void prim(){
   /* int matriz_adjacencia[8][8] = {   //exemplo dos slides
    //   0 1 2 3 4 5 6 7      
        {0,2,0,6,5,0,0,0},  //0
        {2,0,7,7,0,0,0,0},  //1
        {0,7,0,0,6,2,0,0},  //2
        {6,7,0,0,0,0,0,0},  //3
        {5,0,6,0,0,0,4,5},  //4
        {0,0,2,0,0,0,4,6},  //5
        {0,0,0,0,4,4,0,1},  //6
        {0,0,0,0,5,6,1,0},  //7
    };*/
    
      int matriz_adjacencia[8][8] = { // exercício pg 29
    //   0 1 2 3 4 5 6 7      
        {0,5,0,5,2,0,0,0},  //0
        {5,0,0,9,0,1,0,0},  //1
        {0,0,0,0,0,0,8,0},  //2
        {5,9,0,0,0,0,0,1},  //3
        {2,0,0,0,0,0,4,6},  //4
        {0,1,0,0,0,0,0,0},  //5
        {0,0,8,0,4,0,0,0},  //6
        {0,0,0,1,6,0,0,0}   //7
    };
   // */
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
        for(y = 0; y < 8; y++){
            printf("%d\t",matriz_prim[x][y]);
        }    
        printf("\n");
    }
    
    
    numero_vertices_abertos = -1;
    
    printf("\n");
    FILE *file;
	file=fopen("arvore.dot","w");
	fprintf(file,"graph G {\n");
	while(numero_vertices_abertos < 8){
        for(y = 0; y < 8; y++){
            if(numero_vertices_abertos == matriz_prim[2][y] && matriz_prim[2][y]!=-1){
                //printf("%d - %d ", matriz_prim[2][y],matriz_prim[0][y]);
                fprintf(file,"%d--%d",matriz_prim[2][y],matriz_prim[0][y]);            
	            fprintf(file,"[label=\"%d\"][color=RED];\n",matriz_prim[1][y]);
            }
        }
        numero_vertices_abertos++;
    }
	
	fprintf(file,"}\n"); 
	fclose(file);
	system("dot -Tpng arvore.dot -o impressao.png");
    
    return;
}
int encontra_menor(int * vetor_valores, int * vertices_abertos){
    int x, y = -1, valor = 10;
    for(x = 0; x < 8; x++){
        if(vetor_valores[x] < valor && vertices_abertos[x] != -1){
            y = x;
            valor = vetor_valores[x];
        }
    }
    return y;
}