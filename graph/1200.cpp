#URL: https://www.beecrowd.com.br/judge/en/problems/view/1200

#include <bits/stdc++.h>

using namespace std;

char min( char a, char b){ if(a > b) return b; return a; }

class node{
public:
        char ch;
        node *left, *right, *dad;
        node(){}
        node( char ch, node *d = NULL){
                this->ch = ch;
                dad = d;
                right = NULL;
                left = NULL;
        }
};

void pre( node *n ){
        if( n == NULL ) return;
        if( n->dad != NULL ) printf(" ");
        printf("%c", n->ch);
        pre( n->left );
        pre( n->right );
}

void in( node *n, char menor ){
        if(n == NULL) return;
        in( n->left, menor );
        if( n->ch != menor ) printf(" ");
        printf("%c", n->ch);
        in( n->right, menor );
}

void pos( node *n ){
        if(n == NULL) return;
        pos( n->left );
        pos( n->right );
        printf("%c", n->ch);
        if( n->dad != NULL ) printf(" ");
}void insert(node *n, char ch ){
        if( n->ch == ch ) return;
        if( n->ch > ch ){
            if(n->left == NULL){
                n->left = new node(ch, n);
                return;
            }
            insert(n->left, ch);
            return;
        }
        if(n->right == NULL){
            n->right = new node(ch, n);
            return;
        }
        insert(n->right, ch);
        return;
}

bool busca( node *n, char ch){
        if( n == NULL ) return 0;
        if( n->ch == ch ) return 1;
        return ( busca(n->left, ch)||busca(n->right, ch) );
}

void wrapbusca( node *first, char ch ){
        if( busca(first, ch) ) printf("%c existe\n", ch);
        else printf("%c nao existe\n", ch);
}
int main() {
        string A;
        char c, d, menor;
        node *first = NULL;
        first = (node*)malloc( sizeof(node) );
        scanf("%c %c", &c, &d);
        first->ch = d;
        first->left = NULL;
        first->right = NULL;
        menor = d;
        while( cin >> A ){
                if( A.size() == 1 ){
                        scanf(" %c", &c);
                        if( A[0] == 'I' ) insert( first, c ), menor = min( menor, c );
                        else wrapbusca( first, c );
                } else {
                        if( A[0] == 'I' ) in( first, menor ), printf("\n");
                        if( A[1] == 'R' ) pre( first ), printf("\n");
                        if( A[1] == 'O' ) pos( first ), printf("\n");
                }
        }

return 0;
}
