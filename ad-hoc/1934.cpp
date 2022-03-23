#URL: https://www.beecrowd.com.br/judge/en/problems/view/1934

#include <bits/stdc++.h>
#define max 101
#define flag INT_MAX

using namespace std;

map< string, int > mymap;
map< string, int > ans;
map< int, string > mymap2;
int matriz[max][max];
int vetor[max];
int vetor2[max];

int main(){
	string name; int good, cool;
	bool check, check2;
	int ctd, ctd2, k = 0, linha, col, sum, sum2, next = 1;
	scanf("%d %d", &linha, &col);
	for( int i=0; i<linha; i++){
		for(int j=0; j<col; j++){
			cin >> name;
			if( !mymap.count( name ) ){ mymap[name] = next; mymap2[next] = name; matriz[i][j] = next; next++; }
			else matriz[i][j] = mymap[name];
		}
		scanf("%d", &vetor[i]);
	}
	for( int i=0; i< col; i++) scanf("%d", &vetor2[i] );

	bool check3 = true;
	while( check3 ){
	check3 = false;
		for(int i=0; i<linha; i++){
			good = flag; check = true; sum = 0; ctd = 1;
			for(int j=0; j<col; j++){
				if( good == matriz[i][j] ) ctd++;
				if( good == flag && !ans.count( mymap2[ matriz[i][j] ] ) ) good = matriz[i][j]; 
				if( good != flag && good != matriz[i][j] && !ans.count( mymap2[ matriz[i][j]]) ){ check = false; break; }
				if( ans.count( mymap2[ matriz[i][j]] ) ) sum += ans[ mymap2[ matriz[i][j]] ];

			}
			if( check && good != flag ) ans[ mymap2[good] ] = ((vetor[i] - sum)/ctd);
			if( check == false ) check3 = true;
		}

		for( int i=0; i<col; i++){
			cool = flag;  check2 = true;  sum2 = 0;  ctd2 = 1;
			for( int j=0; j<linha; j++ ){
				if( cool == matriz[j][i] ) ctd2++;
				if( cool == flag && !ans.count( mymap2[ matriz[j][i] ] ) ) cool = matriz[j][i];
				if( cool != flag && cool != matriz[j][i] && !ans.count( mymap2[matriz[j][i]]) ) {check2 = false; break;}
				if( ans.count( mymap2[ matriz[j][i]] ) ) sum2 += ans[ mymap2[ matriz[j][i]] ];
			}
			if( check2 && cool != flag ) ans[ mymap2[cool] ] = ((vetor2[i] - sum2)/ctd2);
			if( check2 == false ) check3 = true;
		}
		
		
	}
	map< string, int > :: iterator it;
	for( it = ans.begin(); it != ans.end(); it++){
		cout << it->first << ' ' << it->second << endl;
	}

return 0;
}
