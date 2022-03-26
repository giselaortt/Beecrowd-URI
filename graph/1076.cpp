#URL: https://www.beecrowd.com.br/judge/en/problems/view/1076


#include <bits/stdc++.h>

using namespace std;

const int N = 200;

int vis[N];

int ctd;

vector<int>myvec[N];

int dfs( int pos ){
    vis[pos] = 1;
    int resp = 0;
    for( int i=0; i<myvec[pos].size(); i++ ){
        if( vis[ myvec[pos][i] ] == 0 )
            resp += dfs( myvec[pos][i] );
    }
return resp + 2;
}

int main(){
    int vert, edge, start;
    int a, b;
    int cases;
    cin >> cases;

    for( int i=0; i<cases; i++ ){
        cin >> start >> vert >> edge;

        for( int i=0; i<vert; i++ ){
            myvec[i].clear();
            vis[i] = 0;
        }

        for( int i=0; i<edge; i++ ){
            cin >> a >> b;
            myvec[a].push_back( b );
            myvec[b].push_back( a );
        }
        int resp = dfs( start );
        printf("%d\n", resp - 2);
    }

return 0;
}

