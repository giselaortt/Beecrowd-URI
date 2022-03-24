#URL: https://www.beecrowd.com.br/judge/en/problems/view/1068

#include <bits/stdc++.h>
#define REP(a, b, c, d) for(int a = b, a < c; a += d)
#define min(a, b) a < b ? a : b
#define max(a, b) a > b ? a : b
#define N 10000
#define inf INT_MAX
#define ii pair< int, int >
#define vii vector< ii >
#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)

using namespace std;

// Parentese

int main(){
	char c; int num; bool good;

	while( scanf("%c", &c ) != EOF ){
		good = true;
		num = 0;
		while( c != '\n' ){
			if( c == '(' ) num++;
			if( c == ')' ){
				if(num == 0) good = false;
				else num--;
			}
			scanf("%c", &c );
		}
		if( good && !num ) printf("correct\n");
		else printf("incorrect\n");
	}

return 0;
}
