#URL: https://www.beecrowd.com.br/judge/en/problems/view/1804

#include <bits/stdc++.h>
#define REP(i, a, b);for (int i = int(a); i < int(b); i++)
#define max 100004

using namespace std;

vector <int> segtree;

void init(int N) {
    int length = (int)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1)));
    segtree.resize(length, 0);
}

void build( int A[], int node, int b, int e) {
    if (b == e)    segtree[node] = A[b];
    else {
        int leftIdx = 2 * node, rightIdx = 2 * node + 1;
        build( A, leftIdx , b, (b + e) / 2);
        build( A, rightIdx, (b + e) / 2 + 1, e );
        int lContent = segtree[leftIdx]; int rContent = segtree[rightIdx];
        segtree[node] = lContent + rContent;
}}

int query( int A[], int node, int b, int e, int i, int j) {
    if (i > e || j < b) return 0;
    if (b >= i && e <= j) return segtree[node];
    int p1 = query( A, 2 * node , b , (b + e) / 2, i, j);
    int p2 = query( A, 2 * node + 1, (b + e) / 2 + 1, e , i, j);
    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    return p1 + p2;
}

void update( int dif, int pos, int node, int b, int e ){
        segtree[node] += dif;
        if( b == e ) return;
        if( pos <= (b + e)/2 ) update( dif, pos, 2*node, b, (b + e)/2 );
        else update( dif, pos, 2*node + 1, (b + e)/2 + 1, e );
}

int vetor[max];
int main() {
        int num;
        scanf("%d", &num);
        REP( i, 0, num) scanf("%d", &vetor[i]);
        init(num);
        build( vetor, 1, 0, num-1 );
        char c; int index;
        while( scanf(" %c %d", &c, &index ) != EOF ){
                if( c == 'a' ) update( -vetor[index -1 ], index-1, 1, 0, num-1 );
                else printf("%d\n", query( vetor, 1, 0, num-1, 0, index-2 ) );
        }

return 0;
}
