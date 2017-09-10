#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct adjacentes{
	struct vertices* vizinho;
	int custos;	
}tp_adjacentes;

typedef struct vertices{
	char nome[20];
	int visitato;
	int qt_vizinhos;
	tp_adjacentes * apontados;
}tp_vertices;

typedef struct vetor{
    char nome[20];
    int custos;
}tp_vetor;
void mostra_caminho_adjacencia(tp_vertices * vetor, int qtd_vertices);
tp_vertices * recebe_valores(tp_vertices * vetor, int qtd_vertices);
int acha_menor(tp_vertices* vetor, int vertice, int qtd_vertices, tp_vetor* custo);


tp_vertices * recebe_valores(tp_vertices * vetor, int qtd_vertices){
	vetor = (tp_vertices*)malloc(qtd_vertices*sizeof(tp_vertices));
	int matriz[qtd_vertices][qtd_vertices];
	int a, b, conta=0, rep = 0;
	printf("Nome dos vértices: \n");
	for(a=0; a < qtd_vertices; a++){
		printf("vértice: %d ", a );
		scanf("%s",vetor[a].nome);
	}	
	printf("matriz de adjacencia: \n");
	for(a=0; a < qtd_vertices; a++){	
		for(b = 0; b < qtd_vertices; b++)
			scanf("%d",&matriz[a][b]);
	}
	for(a=0; a < qtd_vertices; a++){	
		for(b = 0; b < qtd_vertices; b++){
			if(matriz[a][b] > 0)
				conta++;
		}
		vetor[a].apontados = (tp_adjacentes*)malloc(sizeof(tp_adjacentes)*conta);
	}
	for(a=0; a < qtd_vertices; a++){	
		conta = 0;
		for(b = 0; b < qtd_vertices; b++){
			if(matriz[a][b] > 0){
				vetor[a].apontados[conta].vizinho= &vetor[b];
				vetor[a].apontados[conta].custos= matriz[a][b];
				vetor[a].visitato = 0;	
				conta++;
			}
		}
		vetor[a].qt_vizinhos = conta;
	}
	return vetor;	
}

int acha_menor(tp_vertices* vetor, int vertice, int qtd_vertices, tp_vetor* caminho){
	int menor = 0, a = vertice, b, controle = -1;
	char nome[20];
	for(b = 0; b < vetor[a].qt_vizinhos; b++){
		if((menor == 0 || menor > vetor[a].apontados[b].custos) && vetor[a].visitato == 0 ){		
		 	menor = vetor[a].apontados[b].custos;
		 	strcpy(nome, vetor[a].apontados[b].vizinho->nome);
		 	controle = b;
		}
	}
	if(menor != 0){
		a=1;
		while(caminho[a].custos!=0)
			a++;
		caminho[a].custos = menor;

		for(a = 0; a < qtd_vertices; a++){
			printf("%d =  %d\n", a, caminho[a].custos);
			if(strcmp(vetor[a].nome,nome) == 0)
				controle = a;
		}
	}
	return controle;
}


void mostra_caminho_adjacencia(tp_vertices * vetor, int qtd_vertices){
	tp_vetor * vetor_caminho = (tp_vetor*)malloc(sizeof(tp_vetor)*qtd_vertices);
	int x, a=0, controle = 0, custo = 0;
	for(x = 0; x < qtd_vertices; x++)
		vetor_caminho[x].custos = 0;
	
	while (vetor[a].qt_vizinhos != 0){
		x = a;		
		strcpy(vetor_caminho[controle].nome,vetor[a].nome);
		controle++;
		a = acha_menor(vetor, a,qtd_vertices, vetor_caminho); // retorna o indice do vetor que tem menor custo	
		vetor[x].visitato = 1;
	}
	custo = 0;
	printf("Caminho do Grafo\n");
		for(x=0;x < controle-1;x++){
			custo = custo+ vetor_caminho[x].custos;
			printf("%s ", vetor_caminho[x].nome);
		}
	printf("\nCom custo total de: %d u.m\n\n",custo);

	
	return;
}
tp_vertices * recebe_valoresi(tp_vertices * vetor, int qtd_vertices){
	vetor = (tp_vertices*)malloc(qtd_vertices*sizeof(tp_vertices));
	int arestas;
	printf("Numero de arestas:\n");
	scanf("%d",&arestas);
	int matriz[qtd_vertices][arestas];
	int a, b, conta=0, rep = 0;
	printf("Nome dos vértices: \n");
	for(a=0; a < qtd_vertices; a++){
		printf("vértice: %d ", a );
		scanf("%s",vetor[a].nome);
	}	
	printf("matriz de incidencia: \n");
	for(a=0; a < qtd_vertices; a++){	
		for(b = 0; b < arestas; b++)
			scanf("%d",&matriz[a][b]);
	}
	for(a=0; a < qtd_vertices; a++){	
		for(b = 0; b < arestas; b++){
			if(matriz[a][b] > 0)
				conta++;
		}
		vetor[a].apontados = (tp_adjacentes*)malloc(sizeof(tp_adjacentes)*conta);
	}
	for(a=0; a < qtd_vertices; a++){	
		conta = 0;
		for(b = 0; b < arestas; b++){
			if(matriz[a][b] > 0){
				//preciso encontrar o outro valor na coluna que seja diferente de 0
				int x;
				for(x = 0; x < qtd_vertices; x++){
					if(x != a && matriz[x][b] != 0){
						vetor[a].apontados[conta].vizinho= &vetor[x];
					}
				}
				
				vetor[a].apontados[conta].custos= matriz[a][b];
				vetor[a].visitato = 0;	
				conta++;
				
			}
		}
		vetor[a].qt_vizinhos = conta;
	}/*
	printf("Matriz\n");
	for(a=0; a < qtd_vertices; a++){	
		printf("vertice: %s\n", vetor[a].nome);
		for(b = 0; b < vetor[a].qt_vizinhos; b++){
			printf("%s->%d\t",vetor[a].apontados[b].vizinho->nome,vetor[a].apontados[b].custos);	
		}
		printf("\n");
	}//*/
	return vetor;	
}


void mostra_caminho_incidencia(tp_vertices * vetor, int qtd_vertices){
	tp_vetor * vetor_caminho = (tp_vetor*)malloc(sizeof(tp_vetor)*qtd_vertices);
	int x, a=0, controle = 0, custo = 0;
	for(x = 0; x < qtd_vertices; x++)
		vetor_caminho[x].custos = 0;
	
	while (vetor[a].qt_vizinhos != 0){
		x = a;		
		strcpy(vetor_caminho[controle].nome,vetor[a].nome);
		controle++;
		a = acha_menor(vetor, a,qtd_vertices, vetor_caminho); // retorna o indice do vetor que tem menor custo	
		vetor[x].visitato = 1;
	}
	custo = 0;
	printf("Caminho do Grafo\n");
		for(x = 0;x < controle-1;x++){
			custo = custo+ vetor_caminho[x].custos;
			printf("%s ", vetor_caminho[x].nome);
		}
	printf("\nCom custo total de: %d u.m\n\n",custo);

	
	return;
}
int menu(){
	printf("|############################################################\n");
	printf("|\tMENU\n");
	printf("|\t1 - Matriz de Adjacencia\n");
	printf("|\t2 - Matriz de Incidencia\n");
	printf("|\t3 - Plot Way\n");
	printf("|\tDefault - Sair.\n");
	printf("|############################################################\n");
	int a;
	scanf("%d",&a);
	return a;
}

int main(int argc, char *argv[]){ // função main recebe como parâmetro a quantidade de vértices do Grafo
	int argv1 = 0;
	tp_vertices * vetor;
	if(argv[1])
		argv1 = atoi(argv[1]);
	if(argv1 > 0){ 					// Se parâmetro contem um número que possa ser o número de vértices, o programa continua.
		switch(menu()){
			case(1):{
				mostra_caminho_adjacencia(recebe_valores(vetor, argv1), argv1); // matriz de adjacencia
				break;
			}
			case(2):{
				mostra_caminho_incidencia(recebe_valoresi(vetor, argv1), argv1); // matriz de adjacencia
				break;
			}
			case(3):{
				printf("Desenha\n");
				break;
			}
			default:{
				return 0;
				break;
			}
		}
	}else // senão o programa é encerrado com mensagem de erro.
		printf("\tInforme o numero de vertices junto com a chamada do programa.\n");

	return 0;
}




/*
8
1
2
3
4
5
0 	0 	0 	-15	20	30	0	0
0	0	-10	0	0	-30	0	50
5	-10	10	15	0	0	0	0
-5	0	0	0	0	0	-30	50
0	10	0	0	-20	0	30	0

1
2
3
4
5
0	30	0	0	20
0	0	0	50	0
15	10	0	5	0
0	50	0	0	0
0	0	10	30	0

inicio
2
3
4
5
6
fim
0 2 0 6 12 0 0
-2 0 10 0 0 5 0
0 -1 0 0 0 0 40
-6 0 0 0 0 6 0
-12 0 0 0 0 0 30
0 -5 0 -6 0 0 8
0 0 -40 0 -30 -8 0

1
A
B
C
D
0 	5 	0 	2 
-5 	0 	4 	-9 
0 	-4 	0 	-10 
-2	9 	10 	0


*/
