#URL: https://www.beecrowd.com.br/judge/en/problems/view/1195

#include <bits/stdc++.h>
#define N 1000

using namespace std;

class no {
public:
    int valor;
    no *dad, *child1, *child2;
    no () {}
    no (int V, no *D=NULL){
        valor = V;
        dad = D;
        child1 = NULL;
        child2 = NULL;
    }
};

    void pre (no *n){
        if(n == NULL) return;
        printf(" %d", n->valor);
        pre(n->child1);
        pre(n->child2);
    }
    void in(no *n){
        if(n == NULL) return;
        in(n->child1);
        printf(" %d", n->valor);
        in(n->child2);
    }
    void pos(no *n){
        if(n == NULL) return;
        pos(n->child1);
        pos(n->child2);
        printf(" %d", n->valor);
    }
void inserir(no *n, int val ){
        if( n->valor >= val ){
            if(n->child1 == NULL){
                n->child1 = new no(val, n);
                return;
            }
            inserir(n->child1, val);
            return;
        }
        if(n->child2 == NULL){
            n->child2 = new no(val, n);
            return;
        }
        inserir(n->child2, val);
        return;
    }

void limpa( no *n ){
    if(n == NULL) return;
    limpa( n->child1 );
    limpa( n->child2 );
    free(n);
}
int main (){
        int A, B, C;
        no *first = NULL;
        first = (no*)malloc(sizeof(no));
        scanf("%d", &A);
        for( int i=0; i<A;  i++ ){
                scanf("%d %d", &B, &C);
                first->valor = C;
                first->child1 = NULL;
                first->child2 = NULL;
                for(int j=1; j<B; j++){
                        scanf("%d", &C);
                        inserir( first, C );
                }
                printf("Case %d:\n", i + 1);
                printf("Pre.:");
                pre( first );
                printf("\n");
                printf("In..:");
                in( first );
                printf("\n");
                printf("Post:");
                pos( first );
                printf("\n\n");
                limpa( first->child1 );
                limpa( first->child2 );
        }
        free(first);
return 0;
}
