#URL: https://www.beecrowd.com.br/judge/en/problems/view/1100

#include <bits/stdc++.h>

using namespace std;

int moves[8][2] = { { 2, -1 },{2, 1}, {1, 2}, {-1, 2},{ -2, -1 },{-2, 1}, {1, -2}, {-1, -2} };

struct par{
    int first, second;
    par () {}
    par(int a,int b) { first = a; second = b; }
};

int vis[10][10];

int main() {
    char a[9];
    char c;
    int x, y, nextx, nexty;
    par next;
    par atual;

    queue < par >myq;

    while(scanf(" %[^\n]", a) != EOF){
        memset( vis, -1, sizeof(vis) );

	//a = readLine();
        x = a[0] - 'a';
        y = a[1] - 49;

        myq.push( par( x, y ) );
        vis[x][y] = 0;

        while( !myq.empty() ){
            x = (myq.front()).first;
            y = (myq.front()).second;

            myq.pop();

            for( int i=0; i<8; i++ ){
                nextx = x + moves[i][0];
                nexty = y + moves[i][1];

                if( nextx >= 0 && nextx < 8 && nexty >=0 && nexty < 8 && vis[nextx][nexty] == -1 ){
                    myq.push( par(nextx, nexty) );
                    vis[nextx][nexty] = vis[x][y] + 1;
                }
            }
        }
        printf("To get from %c%c to %c%c takes %d knight moves.\n", a[0], a[1], a[3], a[4], vis[ a[3] - 'a' ][ a[4] - 49 ] );
    }

return 0;
}
