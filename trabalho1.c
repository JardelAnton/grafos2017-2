/*
	Aluno: Jardel Anton
	Matricula: 1311100022
	Disciplina: Grafos
	Professor: Douglas André Finco
	Semestre: 2017/2
	Trabalho 1: Matrizes de Adjacencia e Incidência e Algoritmo Guloso
*/

#include <stdlib.h>
#include <stdio.h>

int menu(){
	int a;
		printf("|############################################################\n");
		printf("|\tMENU\n");
		printf("|\t1 - Matriz de Adjacência\n");
		printf("|\t2 - Matriz de Incidência\n");		
		printf("|\tDefault - Sair.\n");
		printf("|############################################################\n");
		scanf("%d",&a);
		if(a <= 2 && a >= 0) 
			return a;
		else return 0;
}
void programa(){
    int ordem, qtd_vertices, total_custo = 0, vertice_atual = -1, aux1 = 0, custo_menor, x, aux2, a, b;
	while(a = menu()){
		system("clear");
		printf("Escolha o Exercicio: \n1 - Exercicio 1;\n2 - Exercicio 2;\n 0 - Voltar ao menu Anterior.\n");
		scanf("%d",&b);
		switch(a){
			case(1):{
				if(b==1){
					printf("\n\t1 - Exercicio 1.\n");
					ordem = 5; total_custo = 0; aux1 = 0;
			        int matriz_adjacencia[5][5] = {{0, 30, -15, 0, 20},{-30, 0, -10, 50, 0},{-15, 10, 0, 5, -10},{0, 50, -5, 0, -30},{-20, 0, 10, 30, 0}};
			        int vertices_visitados[5] = {0, 0, 0, 0, 0};
			        char vertices_nomes[5][20] = {{'1'},{'2'},{'3'},{'4'},{'5'}};
			        printf("Caminho de Vertices:");	
			        while(vertices_visitados[aux1] != 1){
			            printf(" %s", vertices_nomes[aux1]);
			            vertices_visitados[aux1] = 1;
			            vertice_atual = 0;
			            custo_menor = 2147483647;
			            for(x = 0; x < ordem; x++){
			                if(matriz_adjacencia[aux1][x] < custo_menor && matriz_adjacencia[aux1][x] > 0){
			                    vertice_atual = x;
			                    custo_menor = matriz_adjacencia[aux1][x];
			                }
			            }
			            aux1 = vertice_atual;
			            if(vertices_visitados[aux1] == 0) 
			            	total_custo += custo_menor;
			        }
			        printf("\nSoma = %d\n", total_custo);
				}else{
			        ordem = 7; total_custo = 0; aux1 = 0;
					printf("\n\t2 - Exercicio 2.\n");
					char vertices_nomes[7][20] = {{"Inicio"},{'2'},{'3'},{'4'},{'5'},{'6'},{"Objetivo"}};
			        int matriz_adjacencia[7][7] = {{0, 2,	0,	6,	12,	 0, 0}, {-2, 0,	1,	0,	0,	5,	0}, {0,	-1,	0,	0,	0,	0,	40}, {-6, 0,	0,	0,	0,	4,	0}, {-12, 0, 0,	0,	0,	0,	30}, {0,	-5,	 0,	-4,	 0, 0,	8}, {0, 0,-40, -30, -8, 0}};
			        int vertices_visitados[7] = {0, 0, 0, 0, 0, 0, 0};
			        printf("Caminho de Vertices:");	
			        while(vertices_visitados[aux1] != 1){
			            printf(" %s", vertices_nomes[aux1]);
			            vertices_visitados[aux1] = 1;
			            vertice_atual = 0;
			            custo_menor = 2147483647;
			            for(x = 0; x < ordem; x++){
			                if(matriz_adjacencia[aux1][x] < custo_menor && matriz_adjacencia[aux1][x] > 0){
			                    vertice_atual = x;
			                    custo_menor = matriz_adjacencia[aux1][x];
			                }
			            }
			            aux1 = vertice_atual;
			            if(vertices_visitados[aux1] == 0) 
			            	total_custo += custo_menor;
			        }
			        printf("\nSoma = %d\n", total_custo);
				}
			}
			break;
			case(2):{
			    if(b ==1 ){
                    ordem = 8; qtd_vertices = 5; total_custo = 0; vertice_atual = -1; custo_menor = 0;
                    char vertices_nomes[5][20] = {{'1'},{'2'},{'3'},{'4'},{'5'}};
                    int matriz_incidencia[5][8] = {{30, 0, 0, 20, 0, 0, 0, -15}, {-30, 50, 0, 0, 0, 0, -10, 0},{0, 0, 0, 0, -10, 5, 10, 15},{0, 50, -30, 0, 0, -5, 0, 0},{0, 0, 30, -20, 10, 0, 0, 0}};
					printf("\n\t1 - Exercicio 1.\n");
			        int vertices_visitados[5] = {0, 0, 0, 0, 0};
			        int aux1 = 0;
			        printf("MATRIZ INCIDENCIA\n");
					printf("Caminho de Vertices:");	
			        while(vertices_visitados[aux1] != 1){
			        	printf(" %s", vertices_nomes[aux1]);
			            vertices_visitados[aux1] = 1;
			            vertice_atual = 0;
			            custo_menor = 2147483647;
			            for(x = 0; x < ordem; x++){
			                if(matriz_incidencia[aux1][x] < custo_menor && matriz_incidencia[aux1][x] > 0){
		                    	vertice_atual = x;
			                    custo_menor = matriz_incidencia[aux1][x];
			                }
			            }
			            if(vertices_visitados[aux1] == 0) total_custo += custo_menor;
			            int aux2 = 0;
			            while(aux2 <= qtd_vertices){
			                if(matriz_incidencia[aux2][vertice_atual] == (custo_menor - (2 * custo_menor)) || (matriz_incidencia[aux2][vertice_atual] == custo_menor && vertices_visitados[aux2] == 0))
			                    aux1 = aux2;			                
			                aux2++;
			            }
			            total_custo += custo_menor;
			        }
			        printf("\nSoma = %d\n", total_custo - custo_menor);
				}else{
				    ordem = 9; qtd_vertices = 7; total_custo = 0; vertice_atual = -1; custo_menor = 0, aux1 = 0;
					printf("\n\t2 - Exercicio 2.\n");
					char vertices_nomes[7][20] = {{"Inicio"},{'2'},{'3'},{'4'},{'5'},{'6'},{"Objetivo"}};
			        int matriz_incidencia[7][9] ={{2, 6, 12, 0, 0, 0, 0, 0, 0}, {-2, 0, 0, 1, 5, 0, 0, 0, 0},{0, 0, 0, -1, 0, 40, 0, 0, 0},{0, -6, 0, 0, 0, 0, 4, 0, 0},{0, 0, -12, 0, 0, 0, 0, 0, 30},{0, 0, 0, 0, -5, 0, -4, 8, 0},{0, 0, 0, 0, 0, -40, 0, -8, -30}};                              
			        int vertices_visitados[7] = {0, 0, 0, 0, 0, 0, 0};			        
			        printf("MATRIZ INCIDENCIA\n");
		            printf("Caminho de Vertices:");	
			        while(vertices_visitados[aux1] != 1){
			            printf(" %s", vertices_nomes[aux1]);
                        vertices_visitados[aux1] = 1;
                        vertice_atual = 0;
                        custo_menor = 2147483647;
                        for( x = 0; x < ordem; x++){
                            if(matriz_incidencia[aux1][x] < custo_menor && matriz_incidencia[aux1][x] > 0){
			                    vertice_atual = x;
                                custo_menor = matriz_incidencia[aux1][x];
                            }
                        }           
                        if(vertices_visitados[aux1] == 0) total_custo += custo_menor;
            			aux2 = 0;
                        while(aux2 <= qtd_vertices){
                            if(matriz_incidencia[aux2][vertice_atual] == (custo_menor - (2 * custo_menor)) || (matriz_incidencia[aux2][vertice_atual] == custo_menor && vertices_visitados[aux2] == 0))
                                aux1 = aux2;
                            aux2++;
                        }
                        total_custo += custo_menor;
                    }
		        	printf("\nSoma = %d\n", total_custo - custo_menor);
				}
				break;	
			}
			default:{		
				return ;		
				break;
			}
		}
		printf("\n\n\n");
	}
}
int main(){
	programa();
	return 0;
}