#URL: https://www.beecrowd.com.br/judge/en/problems/view/1940

#include <bits/stdc++.h>

#define MAX 502

using namespace std;

int e, r;
int v[MAX];

void print() {
        for(int i = 0; i< e; i++)
                cout << v[i] << ' ';

}


int main() {
        cin >> e >> r;
        int x;
        for(int i = 0; i < r; i++) {
                for( int j=0; j<e; j++){
                        cin >> x;
                        v[j] += x;
                }
        }

        int max = 0;
        int flag = 0;
        for(int i = 0; i < e; i++) {
                if(v[i] >= max){ flag = i; max = v[i];}
        }
        //print();
        cout << flag + 1 << endl;

        return 0;
}
