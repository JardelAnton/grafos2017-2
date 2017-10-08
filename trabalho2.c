/*
	Aluno: Jardel Anton
	Matricula: 1311100022
	Disciplina: Grafos
	Professor: Douglas André Finco
	Semestre: 2017/2
	Trabalho 2: Matrizes de Adjacencia ou Incidência e Algoritmos BFS e Dijkstra
*/

#include <stdlib.h>
#include <stdio.h>

void largura(){
	char vertices_nomes[21][20] = {{'A'},{'B'},{'C'},{'D'},{'E'},{'F'},{'G'},{'H'},{'I'},{'J'},{'K'},{'L'},{'M'},{'N'},{'O'},{'P'},{'Q'},{'R'},{'S'},{'T'},{'Z'}};
	int matriz_adjacencia[25][25] = {//	 a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  z									
										{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//a
										{1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//b
										{0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//c
										{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//d
										{0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//e
										{0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//f
										{0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//g
										{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//h
										{0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//i
										{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},	//j
										{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},	//k
										{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},	//l
										{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},	//m
										{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},	//n
										{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},	//o
										{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0},	//p
										{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0},	//q
										{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0},	//r
										{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1},	//s
										{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},	//t
										{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0}		//z
									};	
	int a, b, qtd_black = 0, matriz_bfs[4][21] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};
	for(b = 0; b < 4; b++)
		for (a = 1; a < 21; a++)
			matriz_bfs[b][a] = 0;
	for (a = 1; a < 21; a++)
			matriz_bfs[0][a] = 8888888;	
	a = b = 0;
	int control = 0;
	while(qtd_black < 21-1){
		for(b = 0; b < 21; b++){
			if(matriz_adjacencia[a][b] != 0 && matriz_bfs[2][b] == 0){
				matriz_bfs[0][b] = (matriz_bfs[0][a]) +1;
				matriz_bfs[3][control] = b+1;
				control++;
				matriz_bfs[2][b] = 1;
				matriz_bfs[1][b] = a+1;
			}
		}
		for(a = 0; a <= control; a++){
			if(matriz_bfs[3][a]!=0){
				b = a;
				a = matriz_bfs[3][a]-1;
				qtd_black++;
				matriz_bfs[2][a] = 2;
				matriz_bfs[3][b] = 0;
				break;
			}
		}
	}
	printf("Matriz resultado após concluir a busca\n");
	for(a = 0; a < 4; a++){
		for(b = 0; b < 21; b++){
			printf("\t%d ",matriz_bfs[a][b]);
		}
		printf("\n");
	}
	a = 21-1;
	printf("\nCaminho\n");
	control = 0;
	while(b != 0){
		b = a;
		control++;
		matriz_bfs[3][control] = a; 
		a = matriz_bfs[1][a]-1;
	}
	while(control > 0){
		b = matriz_bfs[3][control--]; 
		printf(" %s ", vertices_nomes[b]);
	}
	printf("\n");
}


int verifica(int * vetor, int valor){     
 	int a;
	for(a = 0; a < 7; a++)        
	if(vetor[a]== valor)
	      return 1;         
	return 0;
}
void remove_vetor(int * vetor, int valor){
	int a;
	for(a = 0; a < 7; a++)
		if(vetor[a] == valor)
			vetor[a] = 0;
}
int acha_menor(int * vetor, int * vertices_abertos){
	int a
	, menor = 1000, b=0;
	for(a = 0; a < 7; a++)
		if(vetor[a]!=0  && vetor[a] < menor && verifica(vertices_abertos, a)){
			menor = vetor[a];
			b = a;
		}
	return b;
}
void dijkstra(){
	char vertices_nomes[21][20] = {{'A'},{'B'},{'C'},{'D'},{'E'},{'F'},{'G'}};
	int matriz_adjacencia[7][7] = {
		{0, 7, 0, 5, 0, 0, 0},
		{7, 0, 8, 9, 7, 0, 0},	
		{0, 8, 0, 0, 5, 0, 0},
		{5, 9, 0, 0,15, 6, 0}, // exemplo alterando (d,f) de 6 para 8
		{0, 7, 5,15, 0, 8, 9},
		{0, 0, 0, 6, 8, 0,11}, // exemplo alterando (f,d) de 6 para 8
		{0, 0, 0, 0, 9,11, 0}
	};
	int matriz_dijkstra[3][7] = {
		{0, 1, 2, 3, 4, 5, 6},
		{0, 1000, 1000, 1000, 1000, 1000, 1000},
		{0, 0, 0, 0, 0, 0, 0}	
	};
	int vertices_abertos[7] = {0, 1, 2, 3, 4, 5, 6};
	int v_atual = 0, control = 7;
	int b, a = 0;
	while(control >= 0){
		for(b = 0; b < 7; b++){
			if(matriz_adjacencia[a][b]!=0 && verifica(vertices_abertos,b) && (matriz_dijkstra[1][b] > (matriz_adjacencia[a][b]+matriz_dijkstra[1][a]))){
				matriz_dijkstra[1][b] = matriz_adjacencia[a][b] +matriz_dijkstra[1][a];
				matriz_dijkstra[2][b] = a;
			}
		}
		remove_vetor(vertices_abertos, a);
		control--;		
		a = acha_menor(matriz_dijkstra[1], vertices_abertos);
	}
	print("Matriz após a aplicação do algoritimo\n");
	for(a = 0; a < 3; a++){
		for(b = 0; b < 7; b++){
			printf("\t%d",matriz_dijkstra[a][b]);
		}
		printf("\n");
	}

	//####################################
	a = b = 6; 
	int x = 0;
	int vetor_auxiliar[7];
	while(b != 0){
		b = a;
		vetor_auxiliar[x] = b;
		x++;
		a = matriz_dijkstra[2][b];
	}
	printf("\nCaminho: ");
	for(a = x-1; a >=0 ; a--){
		printf("%s ",vertices_nomes[vetor_auxiliar[a]] );
	}
	printf("\n");
}

void menu(){
	int a = 1;
	while(a){
		printf("|############################################################\n");
		printf("|\tMENU\n");
		printf("|\t1 - Algoritmo de Busca em Largura (BFS)\n");
		printf("|\t2 - Algoritmo de Dijkstra\n");		
		printf("|\tDefault - Sair.\n");
		printf("|############################################################\n");
		scanf("%d",&a);
		switch(a){
			case(1):{
				largura();
				break;			
			}
			case(2):{
				dijkstra();
				break;			
			}
			default:{
				return;
			}
		}
	}
}


int main(){
	menu();
	return 0;
}