//algoritmo de coloração simples.
#include <stdio.h>
#include <stdlib.h>
void coloracao_simples(){
    int matriz_adjacencia[11][11] = {
    //   0 1 2 3 4 5 6 7 8 9  -- Exemplo presente no material do moodle.
        {0,1,0,0,1,0,0,0,1,0}, //0            
        {1,0,1,0,0,0,1,0,0,0}, //1
        {0,1,0,1,0,0,0,0,0,1}, //2
        {0,0,1,0,1,0,0,1,0,0}, //3
        {1,0,0,1,0,1,0,0,0,0}, //4
        {0,0,0,0,1,0,1,0,0,1}, //5
        {0,1,0,0,0,1,0,1,0,0}, //6
        {0,0,0,1,0,0,1,0,1,0}, //7
        {1,0,0,0,0,0,0,1,0,1}, //8
        {0,0,1,0,0,1,0,0,1,0}  //9
    };
    int a, b, c;
    int m_coloracao_simples[11] = {1,0,0,0,0,0,0,0,0,0};
    int cor=0, cor_m=0;
    for (a = 0, c = 0; a < 11; a++, c++){
        cor_m = 1;
        for(b = 0; b < 11; b++){
            if(matriz_adjacencia[a][b]!=0){
                printf("%d - %d", a, b);
                if(m_coloracao_simples[b] == cor_m){
                    cor_m++;
                    b=0;
                }
                
                    printf(" = cor %d ",cor_m);
                printf("\n");
            } 
            
        }
            //printf("a = %d\nb = %d\ncor = %d\n",a,b,cor_m);
        m_coloracao_simples[a] = cor_m;
    }
    for(b = 0; b < 10; b++){
          printf("%d ", b);
        }
    printf("\n");
    for(b = 0; b < 10; b++){
          printf("%d ",m_coloracao_simples[b]);
        }
    printf("\n");
    FILE *file;
	file=fopen("coloracao.dot","w");
	fprintf(file,"graph G {label=\"Árvore Geradora mínima Prim\";\n");
	
    for(a = 0; a < 10; a++){
        for(b = 0; b < 10; b++){
            if(matriz_adjacencia[a][b]!=0){
                fprintf(file,"%d--%d[label= \"\" ];\n", a, b);            
                //fprintf(file,"[label=\"%d\"][color=RED];\n",);
            }
        }
    }
    fprintf(file,"\n}\n");
	fclose(file);
	system("dot -Tpng coloracao.dot -o coloracao.png");
	system("open roloracao.png ");
	
}

void coloracao_simples1(){
    int matriz_adjacencia[6][6] = {
    //   0 1 2 3 4 5 6 7 8 9  -- Exemplo presente no material do moodle.
        {0,1,0,0,0,1},//0
        {1,0,1,1,0,0},//1
        {0,1,0,1,1,0},//2
        {0,1,1,0,1,1},//3
        {0,0,1,1,0,1},//4
        {1,0,0,1,1,0},//5
    };
    int a, b, c;
    int m_coloracao_simples[6] = {0,0,0,0,0,0};
    int cor=0, cor_m=0;
    for (a = 0, c = 0; a < 6; a++, c++){
        cor_m = 1;
        for(b = 0; b < 6; b++){
            if(matriz_adjacencia[a][b]!=0){
                printf("%d - %d", a, b);
                if(m_coloracao_simples[b] == cor_m){
                    cor_m++;
                    b=0;
                }
                
                    printf(" = cor %d ",cor_m);
                printf("\n");
            } 
            
        }
            //printf("a = %d\nb = %d\ncor = %d\n",a,b,cor_m);
        m_coloracao_simples[a] = cor_m;
    }
    for(b = 0; b < 6; b++){
          printf("%d ", b);
        }
    printf("\n");
    for(b = 0; b < 6; b++){
          printf("%d ",m_coloracao_simples[b]);
        }
    printf("\n");
    FILE *file;
	file=fopen("coloracao.dot","w");
	fprintf(file,"graph G {label=\"Árvore Geradora mínima Prim\";\n");
	
    for(a = 0; a < 10; a++){
        for(b = 0; b < 10; b++){
            if(matriz_adjacencia[a][b]!=0){
                fprintf(file,"%d--%d[label= \"\" ];\n", a, b);            
                //fprintf(file,"[label=\"%d\"][color=RED];\n",);
            }
        }
    }
    fprintf(file,"\n}\n");
	fclose(file);
	system("dot -Tpng coloracao.dot -o coloracao.png");
	system("open roloracao.png ");
	
}
void welsh_powell();

int main(){
    //coloracao_simples();
    //coloracao_simples1();
    welsh_powell();
    return 0;
}

void welsh_powell(){
    int matriz_adjacencia[11][11]={
    //   a b c d e f g h i j k
        {0,1,0,0,0,0,0,1,0,0,0},//a
        {1,0,0,1,0,0,0,0,0,0,0},//b
        {0,0,0,1,0,0,0,0,0,0,0},//c
        {0,0,1,0,0,0,0,0,1,0,1},//d
        {0,0,0,0,0,1,0,0,0,0,1},//e
        {0,0,0,0,1,0,1,0,0,0,0},//f
        {0,0,0,0,0,1,0,1,0,0,1},//g
        {1,0,0,0,0,0,1,0,1,1,1},//h
        {0,0,0,1,0,0,0,1,0,1,0},//i
        {0,0,0,0,0,0,0,1,1,0,1},//j
        {0,0,0,1,1,0,1,1,0,1,0} //k
    };
    int mat_welsh_powell[3][11]={
        {7,10,3,6,8,9,0,1,4,5,2},//vertice
        {5, 5,4,3,3,3,2,2,2,2,1},//qtd
        {0,0,0,0,0,0,0,0,0,0,0}//cor
    };
    int sem_cor[11] = {7,10,3,6,8,9,0,1,4,5,2};//vertice
    
    int a, b,c, cor = 1, f, x, y;
    for(a = 0, cor=0; a < 11; a++){
        if(mat_welsh_powell[2][a] == 0){
            cor++;
            mat_welsh_powell[2][a]=cor;
        }
        for(b = a+1; b < 11; b++){
            f =1;
            if(matriz_adjacencia[mat_welsh_powell[0][a]][mat_welsh_powell[0][b]]==0 && mat_welsh_powell[2][b]==0){
                for(c = b-1 ; c >=0; c--){
                    if(matriz_adjacencia[mat_welsh_powell[0][b]][mat_welsh_powell[0][c]]!=0 && mat_welsh_powell[2][c]==cor){
                    f = 0;
                    break;
                    }
                }
                if(f){
                    mat_welsh_powell[2][b]=cor;
                }
                    
            }
        }
    }
    
    for(x = 0; x < 11; x++){    
            printf("%c\t",mat_welsh_powell[0][x]+65);
        }
        printf("\n");
    for(x = 0; x < 3; x++){
        for(y = 0; y < 11; y++){    
            printf("%d\t",mat_welsh_powell[x][y]);
        }
        printf("\n");
    }
    printf("\n\n\n");
    
}