#URL do problema:
#https://www.beecrowd.com.br/judge/en/runs/code/5316443

#include <bits/stdc++.h>
#define TAM 1000000
#define TAM2 100000

using namespace std;

int dist[TAM+5];
//set< int > myset;
queue<int>myq;

int main(){
	int org, dest, num, a;
	int top, atual;
	while( scanf("%d %d %d", &org, &dest, &num) && org + dest + num != 0 ){
		//myset.clear();
		//fill(vis, vis+TAM, 1); 
		memset( dist, -1, sizeof(dist) );
		for( int i=0; i<num; i++){
			scanf("%d", &a );
			dist[a] = -3;
		}
		while ( !myq.empty() ) myq.pop();
		myq.push( org );
		dist[org] = 0;
		while( !myq.empty() && dist[ dest ] == -1 ){
			atual = myq.front();
			myq.pop();
			if( atual && !(atual%2) && dist[atual/2] == -1 ){
				dist[atual/2] = dist[atual] + 1;
				myq.push( atual/2 );
			} 
			if( atual*2 <= TAM2 && dist[ atual*2 ] == -1 ){
				dist[atual*2] = dist[atual] + 1;
				myq.push( atual*2 );
			}
			if( atual*3 <= TAM2 && dist[atual*3] == -1 ){
				dist[atual*3] = dist[atual] + 1;
				myq.push( atual*3 );
			}
			if( atual + 1 <= TAM2 && dist[atual+1] == -1 ){
				dist[atual+1] = dist[atual] + 1;
				myq.push( atual+1 );
			}
			if( atual - 1 > 0 && dist[atual-1] == -1 ){
                dist[atual-1] = dist[atual] + 1;
                myq.push( atual-1 );
            }
		}
		printf("%d\n", dist[dest]);
	}
return 0;
}
