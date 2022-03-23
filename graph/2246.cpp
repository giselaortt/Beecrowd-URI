#URL: https://www.beecrowd.com.br/judge/en/problems/view/2246

#include <bits/stdc++.h>
#define tam 1000

using namespace std;

int moves[4][2] = { {0,1}, {1, 0}, {-1, 0}, {0, -1} };

int matriz[tam][tam];

int ctd;

void dfs( int x, int maxx, int y, int maxy, int p ){
        if( x < 0 || x >= maxx || y < 0 || y >= maxy ||  matriz[x][y] != p ) return;
        ctd++;
        matriz[x][y] = -1;
        for( int i=0; i<4; i++ ) {
                dfs( x + moves[i][0], maxx, y + moves[i][1], maxy, p );
        }
}

int main() {
        int alt, larg, min = INT_MAX;
        cin >> alt >> larg;
        for( int i=0; i<alt; i++ )
                for( int j=0; j<larg; j++ ) scanf("%d", &matriz[i][j] );

         for( int i=0; i<alt; i++ )
                for( int j=0; j<larg; j++ ) {
                        if( matriz[i][j] != -1 ){
                                ctd = 0;
                                dfs( i, alt, j, larg, matriz[i][j] );
                                if( ctd < min ) min = ctd;
                        }
                }

        printf("%d\n", min);

return 0;
}
