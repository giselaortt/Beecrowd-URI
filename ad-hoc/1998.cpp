#URL: https://www.beecrowd.com.br/judge/en/problems/view/1998

#include <bits/stdc++.h>
#define M 501
#define REP(a, b, c) for(int a=b; a<c; a++)

using namespace std;

// AWARI

int vetor[M];

int main(){
	int num, point;
	bool good;
	scanf("%d", &num);
	while( num != -1 ){
		num++;
		REP(i, 1, num ) scanf("%d", &vetor[i]);
		do{
			point = 1;
			good = true;
			while( vetor[point] != point && point != num ){
				if( vetor[point] ) good = false;
				point++;
			}
			if( point != num ){
				vetor[point] = 0;
				while( point-- ) vetor[point] += 1;
			}
		}while( point != num );
		if( good ) printf("S\n");
		else printf("N\n");
		scanf("%d", &num);
	}

return 0;
}
