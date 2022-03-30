#URL: https://www.beecrowd.com.br/judge/en/problems/view/1905


#include <bits/stdc++.h>

using namespace std;

int matriz[5][5];
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

void dfs(int x, int y, int maxi  ){
    if(x < 0 || y < 0 || x > maxi || y > maxi || matriz[x][y] != 0) return;
    matriz[x][y] = 2;
    for(int i = 0; i<4; i++){
        dfs( x + dir[i][0], y + dir[i][1], maxi );
    }
}

int main() {
    int n; cin >> n;
    int c;

    for(int k=0; k<n; k++){

        for( int i=0; i<5; i++){
            for( int j=0; j<5; j++ ){
                scanf("%d", &matriz[i][j]);
            }
        }

        if(matriz[0][0] == 0 && matriz[4][4] == 0) dfs(0, 0, 4);
        if( matriz[4][4] == 2 )  printf("COPS\n");
        else printf("ROBBERS\n");

    }

return 0;
}
