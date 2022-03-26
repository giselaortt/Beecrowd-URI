#URL: https://www.beecrowd.com.br/judge/en/problems/view/1082


#include <bits/stdc++.h>

using namespace std;

bool vis[27];

vector< char > ans;

vector< char > lista[26];

bool order( char a, char b ){ return (a < b); }

void dfs( int n, int maxi ){
    if( vis[n] ) return;
    vis[n] = 1;
    ans.push_back( n + 'a' );
    for( int it=0; it<lista[n].size(); it++ ){
        dfs( lista[n][it] - 'a', maxi );
    }
}

int main() {
    int edge, vert, ctd;
    bool good;
    char a, b;

    int num; scanf("%d", &num);

    for( int k=0; k<num; k++ ){

        scanf("%d %d", &vert, &edge); /// 3 e 1
        
        good = true;

        for( int i=0; i<vert; i++ ) vis[i] = 0;
        for( int i=0; i<26; i++ ) lista[i].clear();

        for( int i=0; i<edge; i++ ){
            scanf(" %c %c", &a, &b);
            lista[a - 'a'].push_back( b );
            lista[b - 'a'].push_back( a );
        }

        ctd = 0;
        printf("Case #%d:\n", k + 1);
        while( good ){
            good = false;
            for( int i=0; i<vert; i++ ){
                if( vis[i] == 0 ){
                    dfs( i, vert );
                    good = true;
                    ctd++;
                    break;
                }
            }
            if( good == false ) break;
            sort( ans.begin(), ans.end(), order );
            for( int it=0; it<ans.size(); it++ ){
                printf("%c,", ans[it]);
            }
            printf("\n");
            ans.clear();
        }
        printf("%d connected components\n\n", ctd);

    }

return 0;
}
