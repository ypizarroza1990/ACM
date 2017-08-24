#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <time.h>
using namespace std;
#define ull unsigned long long

const ull base = 1000000000 + 7;

ull hash(int arr[20]){
    ull ans = 0;
    for(int i=0;i<20;i++)
        ans = ans * base + arr[i];
    return ans;
}

struct node{
    int arr[20];

    node(int x[20]){
        for(int i=0;i<20;i++) arr[i] = x[i];
    }
};

char mat[10][10];
int inicio[20];
int especial;
int marcas[20];
bool tipo[20];
int len[20];
queue<node> cola;
map<ull,bool> mapa;
int MAT[6][6],n;
int solve(){
    int aux[20];
    ull num;
    int cant = 1, hijos = 0,f,c,cnt,tiempo = 0;
    while(cant){
        hijos = 0;
        for(int p=0;p<cant;p++){
            node kaka = cola.front(); cola.pop();

            memset(MAT,-1,sizeof(MAT));
            for(int i=0;i<n;i++){
                cnt = len[i];
                if (tipo[i]){ // ----
                    f = inicio[i], c = kaka.arr[i];
                    while(cnt--){
                        MAT[f][c] = i;
                        c++;
                    }
                }
                else{
                    f = kaka.arr[i], c = inicio[i];
                    while(cnt--){
                        MAT[f][c] = i;
                        f++;
                    }
                }
            }

            for(int i=0;i<n;i++)
                if (tipo[i]){ 
                    //izq
                    int x = kaka.arr[i];
                    int c = x - 1;
                    while(c >= 0 && MAT[inicio[i]][c] == -1){
                        memcpy(aux,kaka.arr,sizeof(kaka.arr));
                        aux[i] = c;
                        num = hash(aux);
                        if (mapa.find(num) == mapa.end()){
                            mapa[num] = true;
                            cola.push(node(aux));
                            hijos++;
                        }
                        c--;
                    }

                    c = x + len[i];
                    while(c < 6 && MAT[inicio[i]][c] == -1){
                        memcpy(aux,kaka.arr,sizeof(kaka.arr));
                        aux[i] = c - len[i] + 1;
                        num = hash(aux);
                        if (mapa.find(num) == mapa.end()){
                            mapa[num] = true;
                            cola.push(node(aux));
                            hijos++;
                        }
                        c++;
                    }
                    if (especial == i && c == 6)
                        return tiempo + 1;
                }
                else{

                    //arriba
                    int x = kaka.arr[i];
                    int f = x - 1;
                    while(f >= 0 && MAT[f][inicio[i]] == -1){
                        memcpy(aux,kaka.arr,sizeof(kaka.arr));
                        aux[i] = f;
                        num = hash(aux);
                        if (mapa.find(num) == mapa.end()){
                            mapa[num] = true;
                            cola.push(node(aux));
                            hijos++;
                        }
                        f--;
                    }

                    //arriba
                    x = kaka.arr[i];
                    f = x + len[i];
                    while(f < 6 && MAT[f][inicio[i]] == -1){
                        memcpy(aux,kaka.arr,sizeof(kaka.arr));
                        aux[i] = f - len[i] + 1;
                        num = hash(aux);
                        if (mapa.find(num) == mapa.end()){
                            mapa[num] = true;
                            cola.push(node(aux));
                            hijos++;
                        }
                        f++;
                    }
                }
        }
        tiempo++;
        cant = hijos;
    }


    return -1;
}


int main(){
    char cad[100];
    while(scanf("%s",cad), cad[0] != '*'){

        for(int i=0;i<6;i++) scanf("%s",mat[i]);

        memset(marcas,0,sizeof(marcas));
        n = 0;
        for(int i=0;i<6;i++)
            for(int j=0;j<6;j++)
                if (mat[i][j] != '.'){
                    char aux = mat[i][j];
                    if (aux == cad[0])
                        especial = n;
                    mat[i][j] = '.';
                    len[n] = 2;
                    if (j+1 < 6 && mat[i][j+1] == aux){
                        inicio[n] = i;
                        marcas[n] = j;
                        tipo[n] = true;
                        mat[i][j+1] = '.';
                        if (j+2 < 6 && mat[i][j+2] == aux)
                            mat[i][j+2] = '.', len[n]++;
                    }
                    else{
                        marcas[n] = i;
                        inicio[n] = j;
                        tipo[n] = false;
                        mat[i+1][j] = '.';
                        if (i+2 < 6 && mat[i+2][j] == aux)
                            mat[i+2][j] = '.', len[n]++;
                    }
                    n++;
                }
        while(!cola.empty()) cola.pop();
        mapa.clear();
        mapa[hash(marcas)] = true;
        cola.push(node(marcas));

        printf("%d\n",solve());
    }

    return 0;
}
 
