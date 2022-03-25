#URL: https://www.beecrowd.com.br/judge/en/problems/view/1261


#include <bits/stdc++.h>

using namespace std;

int main(){
        map<string, int> mymap;
        map<string, int> :: iterator it;
        int total, words, cases, points;
        string word;
        scanf("%d %d", &words, &cases);
        for( int i=0; i<words; i++)
                cin >> word >> points,
                mymap[word] = points;
        for(int i=0; i<cases; i++){
                total = 0;
                do
                        cin >> word,
                        total += mymap[word];
                while( word != "." );
                cout << total << endl;
        }

return 0;
}
