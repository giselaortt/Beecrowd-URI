#URL: https://www.beecrowd.com.br/judge/en/problems/view/1835


#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

bool vis[MAX];
vector<int> myvec[MAX];
int ctd, edges, vert;

void dfs( int pos ){
        if( pos < 1 || pos > vert || vis[pos] ) return;
        vis[pos] = 1;
        for(int i=0; i<myvec[pos].size(); i++)
                dfs( myvec[pos][i] );
}

int main(){
        int cases, x, y;
        scanf("%d", &cases);
        for(int i=0; i<cases; i++){
                ctd = 0;
                memset( vis, 0, sizeof(vis) );
                for(int j=1; j<=vert; j++) myvec[j].clear();
                scanf("%d %d", &vert, &edges);
                for(int j=0; j<edges; j++)
                        scanf("%d %d", &x, &y),
                        myvec[x].push_back( y ),
                        myvec[y].push_back( x );
                dfs(1);
                for(int j=1; j<=vert; j++)
                        if( !vis[j] )
                                dfs( j ),
                                ctd++;
                printf("Caso #%d: ", i+1);
                if( ctd ) printf("ainda falta(m) %d estrada(s)\n", ctd);
                else printf("a promessa foi cumprida\n");
        }


return 0;
}
