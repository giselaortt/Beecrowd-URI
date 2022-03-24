#URL: https://www.beecrowd.com.br/judge/en/problems/view/1553


#include <bits/stdc++.h>
#define REP( a, b, c ) for(int a=b; a<c; a++)
#define inf INT_MAX
#define MAX 200001
#define mod(a) a > 0 ? a : -a
#define min(a, b) a < b ? a : b

using namespace std;

map<int, int> mymap;
map<int, int>  :: iterator it;

int main(){
	int ctd, quest, num, a;
	scanf("%d %d", &quest, &num);
	while( num != 0 && quest != 0 ){
		ctd = 0;
		mymap.clear();
		REP(i, 0, quest)
			scanf("%d", &a),
			mymap[a]++;
		for(it = mymap.begin(); it!=mymap.end(); it++)
			//cout << it->first << ' ' << it->second << "  ";
			if( it->second >= num ) ctd++;
		printf("%d\n", ctd);
		scanf("%d %d", &quest, &num);
	}
	
return 0;
}
