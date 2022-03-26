#URL: https://www.beecrowd.com.br/judge/en/problems/view/1583


#include <bits/stdc++.h>

using namespace std;

char matriz[51][51];
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

void dfs(int x, int y, int maxx, int maxy  ){
    if(x < 0 || y < 0 || x > maxx || y > maxy || matriz[x][y] == 'T' ||  matriz[x][y] == 'X') return;
    matriz[x][y] = 'T';
    for(int i = 0; i<4; i++){
        dfs( x + dir[i][0], y + dir[i][1], maxx, maxy );
    }
}

int ts[51][2];

int main() {
    int n, m; int siz=0;
    scanf("%d %d", &n, &m);

    while( n != 0 && m != 0 ){
        int x, y;
        for( int i=0; i<n; i++)
            for( int j=0; j<m; j++ )
                scanf(" %c", &matriz[i][j]);


        for( int i=0; i<n; i++)
            for( int j=0; j<m; j++ )
                if( matriz[i][j] == 'T' )
                    matriz[i][j] = 'A',
                    dfs( i, j, n-1, m-1 );

        for( int i=0; i<n; i++){
            for( int j=0; j<m; j++ ){
                printf("%c", matriz[i][j]);
            }
            printf("\n");
        }

        printf("\n");
    scanf("%d %d", &n, &m);
    }

return 0;
}

