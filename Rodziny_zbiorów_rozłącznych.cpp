#include <string>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <sstream>
#include <stdio.h>

#define MAX 1000

using namespace std;

typedef struct Node{
        char key;
        struct Node *p;
        int rank;
}* node;

node makeSet(char k){
    node x = new Node;
    x->key = k;
    x->p = x;
    x->rank = 0;
    return x;
}

node findSet(node x){
    if (x != x->p)
        x->p = findSet(x->p);
    return x->p;
}

node node_union(node x, node y){
        if (x->rank > y->rank){
                y->p = x;
        }
        else{
                x->p = y;
                if (x->rank == y->rank)
                        y->rank = y->rank+1;
        }
}

void drukuj(char x,char y, int rank){
        printf("%c  +  %c rank: %d\n",x,y,rank);
}

int main(int argc, char *argv[]){
        fstream fs("dane.txt",fstream::in);
        char key_tab[MAX][2];
        int rank_tab[MAX]={0};
        int i=0,j;
        node tab[MAX*2];
        while (fs >> key_tab[i][0] && fs >> key_tab[i][1] && fs >> rank_tab[i])
        {
                tab[key_tab[i][0]] = makeSet(key_tab[i][0]);
                tab[key_tab[i][1]] = makeSet(key_tab[i][1]);
                drukuj(key_tab[i][0],key_tab[i][1],rank_tab[i]);
                i++;
        }
        fs.close();
return 0;
}

