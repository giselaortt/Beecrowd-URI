#UR:https://www.beecrowd.com.br/judge/en/problems/view/1869

#include <bits/stdc++.h>
#define M 100000000

using namespace std;

/// base 32

int resp[M];

void convert( unsigned long long int num ){
	int ctd = 0;
	while( num ){
		resp[ctd] = num%32;
		num /= 32;
		ctd++;
	}
	for( int i=ctd - 1; i>= 0; i-- )
		if( resp[i] <= 9 ) printf("%d", resp[i]);
		else printf("%c", 'A' + resp[i] - 10 );
	printf("\n");
}

int main(){
	unsigned long long int num;
	do{
		cin >> num;
		if( !num ){ printf("0\n"); return 0; }
		convert(num);
	}while( 1 );

return 0;
}
