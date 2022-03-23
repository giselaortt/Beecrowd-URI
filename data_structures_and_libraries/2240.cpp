#URL: https://www.beecrowd.com.br/judge/en/problems/view/2240

#include <bits/stdc++.h>
#define tam 10001

using namespace std;

int canhota[tam][2];
int destra[tam][2];

int dfsc( int vert, int ctd ){
	if( vert == 0 ) return ctd;
	ctd++;
	if( canhota[vert][0] == 0 && canhota[vert][1] == 0 ) return ctd;
	return max( dfsc( canhota[vert][0], 0 ), dfsc( canhota[vert][1], ctd ) );
}

int dfsd( int vert, int ctd ){
	if( vert == 0 ) return ctd;
	ctd++;
	if( destra[vert][0] == 0 && destra[vert][1] == 0 ) return ctd;
	return max( dfsd( destra[vert][1], 0 ), dfsd( destra[vert][0], ctd ) );
}

int frontc(){
	int q = 1, vert = 1;
	while( canhota[vert][1] != 0 ){
		vert = canhota[vert][1];
		q++;
	}
return q;
}

int frontd(){
	int r = 1, vert =1;
	while( destra[vert][0] != 0 ){
		vert = destra[vert][0];
		r++;
	}
	return r;
}

int main(){
	int n, m, a,b ,c;
	cin >> n;
	for( int i=1; i<=n; i++ ){
		cin >> a >> b >> c;
		canhota[a][0] = b;
		canhota[a][1] = c;
	}
	cin >> m;
	for( int i=1; i<=m; i++ ){
		cin >> a >> b >> c;
		destra[a][0] = b;
		destra[a][1] = c;
	}

	int o, p, q, r;
	o = frontd();
	p = frontc();
	q = dfsc( 1, 0 );
	r = dfsd( 1, 0 );

	int ans = m + n - max( min(o, q), min(p, r) );
	printf("%d\n", ans );

return 0;
}
