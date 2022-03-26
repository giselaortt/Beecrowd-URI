#URL: https://www.beecrowd.com.br/judge/en/problems/view/1907



#include <bits/stdc++.h> 
#define MAX 1024 
 
using namespace std; 
 
char mat[MAX][MAX]; 
 
int moves[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}}; 
int lin, col, ctd; 
 
void dfs(int x, int y){ 
        if( x < 0 || y < 0 || x >= lin || y >= col || mat[x][y] == 'o') return; 
        mat[x][y] = 'o'; 
        for(int i=0; i<4; i++) 
                dfs(x + moves[i][0], y + moves[i][1] ); 
} 
 
int main(){ 
        scanf("%d %d", &lin, &col); 
        for(int i=0; i<lin; i++){ 
                for(int j=0; j<col; j++){ 
                        scanf(" %c", &mat[i][j] ); 
        }       } 
 
        for(int i=0; i<lin; i++){ 
                for(int j=0; j<col; j++){ 
                        if(mat[i][j] == '.' ){ 
                                ctd++; 
                                dfs(i, j); 
        }       }       } 
        cout << ctd << endl; 
 
return 0; 
} 

