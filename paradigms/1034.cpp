#URL: https://www.beecrowd.com.br/judge/en/problems/view/1034


#include <stdio.h>
#include <string.h>
#define REP(a, b, c) for( int a = b; a < c; a++ )
#define min( a, b ) a < b ? a : b
#define inf 100000000

using namespace std;

int sizes[26];
int table[1000005];
int cases, blocks, size;

void bottomup( int value ){
        table[0] = 0;
        table[1] = 1;
        REP(i, 2, value+1 ){
                table[i] = inf;
                for( int j=0; j < blocks && sizes[j] <= i; j++ ){
                        table[i] = min( table[i], table[i - sizes[j] ] + 1);
                }
        }
}

int main(){
        scanf("%d", &cases);
        REP(i, 0, cases){
                memset( table, -1, sizeof(table) );
                scanf("%d %d", &blocks, &size);
                REP( j, 0, blocks ) scanf("%d", &sizes[j]);
                bottomup( size );
                printf("%d\n", table[ size ] );
        }
return 0;
}

