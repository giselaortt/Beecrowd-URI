#URL: https://www.beecrowd.com.br/judge/en/problems/view/1081


#include <bits/stdc++.h>

using namespace std;

const int N = 21;

bool vis[N];

vector<int> grafo[N];

void dfs ( int pos, int ctd ){
    if( vis[pos] ) return;
    vis[pos] = 1;
    ctd++;
    for( int i=0; i<grafo[pos].size(); i++ ){
        for( int j=0; j<ctd; j++ ) printf("  ");
        if( !vis[ grafo[pos][i] ] ) printf("%d-%d pathR(G,%d)\n", pos, grafo[pos][i], grafo[pos][i] );
        else  printf("%d-%d\n", pos, grafo[pos][i] );
        dfs( grafo[pos][i], ctd );
    }
return;
}

int main(){
   int vert, edge;
   int a, b;
   int num;
   cin >> num;
   for( int k=0; k<num; k++ ){
        for( int i=0; i<N; i++ ){
            grafo[i].clear();
            vis[i] = 0;
        }
       scanf("%d %d", &vert, &edge);
       for( int i=0; i<edge; i++ ){
            cin >> a >> b;
            grafo[a].push_back( b );
       }
       for( int i=0; i<vert; i++ )
            sort( grafo[i].begin(), grafo[i].end() );

       printf("Caso %d:\n", k+1);

       for( int i=0; i<vert; i++ ){
            if( !vis[i] && !grafo[i].empty() ){
                dfs( i, 0 );
                printf("\n");
            }
       }

   }

return 0;
}
