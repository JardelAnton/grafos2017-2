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

// 	Protótipos das Funções
tp_vetor*  mostra_caminho_adjacencia(tp_vertices * vetor, int qtd_vertices);
tp_vetor*  mostra_caminho_incidencia(tp_vertices * vetor, int qtd_vertices);
tp_vertices * recebe_valores(tp_vertices * vetor, int qtd_vertices);
tp_vertices * recebe_valoresi(tp_vertices * vetor, int qtd_vertices);
int acha_menor(tp_vertices* vetor, int vertice, int qtd_vertices, tp_vetor* custo);
int menu();
void imprimir(tp_vetor * vetor,int controle, FILE *file);

tp_vertices * recebe_valores(tp_vertices * vetor, int qtd_vertices){
	vetor = (tp_vertices*)malloc(qtd_vertices*sizeof(tp_vertices));
	int matriz[qtd_vertices][qtd_vertices];
	int a, b, conta = 0;
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
			if(strcmp(vetor[a].nome,nome) == 0)
				controle = a;
		}
	}
	return controle;
}
tp_vetor* mostra_caminho_adjacencia(tp_vertices * vetor, int qtd_vertices){
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
	return vetor_caminho;
}
tp_vertices * recebe_valoresi(tp_vertices * vetor, int qtd_vertices){
	vetor = (tp_vertices*)malloc(qtd_vertices*sizeof(tp_vertices));
	int arestas;
	printf("Número de arestas:\n");
	scanf("%d",&arestas);
	int matriz[qtd_vertices][arestas];
	int a, b, conta=0;
	printf("Nome dos vértices: \n");
	for(a=0; a < qtd_vertices; a++){
		printf("vértice: %d ", a );
		scanf("%s",vetor[a].nome);
	}	
	printf("Insira a matriz de incidência: \n");
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
				int x;// é preciso encontrar o outro valor na coluna que seja diferente de 0
				for(x = 0; x < qtd_vertices; x++){
					if(x != a && matriz[x][b] != 0)
						vetor[a].apontados[conta].vizinho= &vetor[x];
				}				
				vetor[a].apontados[conta].custos= matriz[a][b];
				vetor[a].visitato = 0;	
				conta++;				
			}
		}
	}
	vetor[a].qt_vizinhos = conta;
	return vetor;	
}
tp_vetor* mostra_caminho_incidencia(tp_vertices * vetor, int qtd_vertices){
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

	
	return vetor_caminho;
}
int menu(){
	printf("|############################################################\n");
	printf("|\tMENU\n");
	printf("|\t1 - Matriz de Adjacência\n");
	printf("|\t2 - Matriz de Incidência\n");
	printf("|\t3 - Plot Way\n");
	printf("|\tDefault - Sair.\n");
	printf("|############################################################\n");
	int a;
	scanf("%d",&a);
	return a;
}
int main(){ 
	tp_vertices * vetor = NULL;
	tp_vetor * vetor1 = NULL;
	int qtd_vertices;
	while(1){
		switch(menu()){
			case(1):{
				system("clear");
				printf("\tInsira a quantidade de vértices: ");
				scanf("%d",&qtd_vertices);
				vetor1 = mostra_caminho_adjacencia(recebe_valores(vetor, qtd_vertices), qtd_vertices); // matriz de adjacencia
				break;
			}
			case(2):{
				printf("\tInsira a quantidade de vértices: ");
				scanf("%d",&qtd_vertices);
				vetor1 = mostra_caminho_incidencia(recebe_valoresi(vetor, qtd_vertices), qtd_vertices); // matriz de adjacencia
				break;
			}
			case(3):{	
				// plotagem do grafo usando o graphviz, ainda a ser implementado.

				printf("Desenha\n"); 
					FILE *file;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             

					file=fopen("grafo.dot","w");
					fprintf(file,"graph G {\n");
	        		imprimir(vetor1,qtd_vertices,file);
	        		fprintf(file,"}\n"); 
	        		fclose(file);
	        		system("dot -Tpng grafo.dot -o visualiza_caminho.png");
				break;
			}
			default:{		
				return 0;		
				break;
			}
		}
	}
	return 0;
}

void imprimir(tp_vetor * vetor,int controle, FILE *file){
	int a=0;
	while(a < controle-1){
		fprintf(file,"%s -- %s",vetor[a].nome, vetor[a+1].nome);
		fprintf(file,"[label=\"%d\"];\n",vetor[a+1].custos);
		a++;
	}
}
