#URL: https://www.beecrowd.com.br/judge/en/problems/view/1466

#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

class node{
public:
        int val;
        node *left, *right, *dad;
        node(){}
        node( int val, node *d = NULL ){
                this->val = val;
                dad = d;
                right = NULL;
                left = NULL;
        }
};
void insert(node *n, int val ){
        if( n->val >= val ){
            if(n->left == NULL){
                n->left = new node(val, n);
                return;
            }
            insert(n->left, val);
            return;
        }
        if(n->right == NULL){
            n->right = new node(val, n);
            return;
        }
        insert(n->right, val);
        return;
}

void clear( node *start ){
        if( start == NULL ) return;
        if( start->left != NULL) clear( start->left );
        if( start->right != NULL ) clear( start->right );
        free( start );
}
queue< node* > myq;

void bfs( node *start ){
        if( start == NULL ) return;
        printf("%d", start->val );
        if( start->left != NULL ) myq.push( start->left );
        if( start->right != NULL ) myq.push( start->right );
        while( !myq.empty() ){
                printf(" %d", myq.front()->val );
                if( myq.front()->left != NULL ) myq.push( myq.front()->left );
                if( myq.front()->right != NULL ) myq.push( myq.front()->right );
                myq.pop();
        }
}

int main(){
        int cases, nodes, val;
        scanf("%d", &cases);
        node *first = NULL;
        first = new node( 0 );
        for(int l=0; l<cases; l++){
                clear( first->left );
                clear( first->right );
                while( !myq.empty() ) myq.pop();
                scanf("%d", &nodes );
                scanf("%d", &first->val );
                first->left = NULL;
                first->right = NULL;
                for(int k=1; k<nodes; k++)
                        scanf("%d", &val),
                        insert( first, val );
                printf("Case %d:\n", l+1);
                bfs( first );
                printf("\n\n");
        }

return 0;
}
