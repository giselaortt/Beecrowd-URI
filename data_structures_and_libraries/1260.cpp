#URL: https://www.beecrowd.com.br/judge/en/problems/view/1260


#include <bits/stdc++.h>


using namespace std;

void readline(){}

int main(){
        map<string, double> mymap;
        int cases, total;
        string name;
        map<string, double>  :: iterator it;
        double percent;
        char temp, temp2;
        scanf("%d", &cases);
        scanf("%c%c", &temp, &temp2);
        for(int i=0; i<cases; i++){
                mymap.clear();
                total = 0;
                percent = 0;
                getline(cin, name);
                while( name.size() > 0 )
                        mymap[name]++,
                        total++,
                        getline(cin, name);
                for( it = mymap.begin(); it != mymap.end(); it++)
                        cout << it->first << ' ' << setprecision(4)<< fixed << (it->second*100.0)/total << endl;
                if( i != cases - 1)printf("\n");
        }


return 0;
}
