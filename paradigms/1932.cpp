#URL: https://www.beecrowd.com.br/judge/en/problems/view/1932

#include <bits/stdc++.h>
#define min(a, b) a < b ? a : b
#define max(a, b) a > b ? a : b
#define mod( a ) a >= 0 ? a : -a
#define N 200005

using namespace std;

int vetor[N];

int main(){
	int price, size;
	scanf("%d %d", &size, &price);
	for( int i=0; i<size; i++){
		scanf("%d", &vetor[i]);
	}
	
	int j=0, k=0, l, sum = 0, proft=0, a;
	while( k < size - 1 ){

		while( vetor[j+1] < vetor[j] && j < size - 1 ) j++;
		k = j;
		while( vetor[k+1] > vetor[k] && k < size - 1 ) k++;

		if( vetor[k+1] + price < vetor[k] || vetor[k+1] < vetor[j] || k == size ){
			a = vetor[k] - vetor[j] - price;
			if( a > 0 ) proft += a;
			k++; j = k;
		} else {
			l = k;
			while( l < size - 1 &&( ( vetor[k] <= price + vetor[l] || vetor[l] >= vetor[k] ) && vetor[l] >= vetor[j] ) ){
				l++;
				if( vetor[l] > vetor[k] ) k = l;
			}
			a = vetor[k] - vetor[j] - price;
			//printf("%d %d %d   ", j, k, l);
			if( a > 0 ) proft += a;
			k = l; j = l;
		}

	}
	printf("%d\n", proft);

return 0;
}
