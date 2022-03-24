#URL: https://www.beecrowd.com.br/judge/en/problems/view/1140

#include <bits/stdc++.h>
#define M 1000002
#define min(a, b) a < b ? a : b
#define max(a, b) a > b ? a : b
#define REP(a, b, c) for(int a=b; a<c; a++)

using namespace std;

// flowers

int main(){
	bool good;
	char f;
	string strin;
	int i;

	do {
		good = true;
		getline( cin, strin );
		if( strin[0] == '*' ) break;
		if( strin[0] >= 'a' && strin[0] <= 'z' ) f = strin[0];
		else f = strin[0] - 'A' + 'a';
		for( i=1; i<strin.size(); i++ )
			if( strin[i] == ' ' &&  strin[i+1] != f && strin[i+1] != f + 'A' - 'a' )
				good = false;

		if( good ) printf("Y\n");
		else printf("N\n");
	} while( 1 );

return 0;
}
