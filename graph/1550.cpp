#URL: https://www.beecrowd.com.br/judge/en/problems/view/1550



#include <bits/stdc++.h>

using namespace std;
map<int, int> mym;
int invert( int a ){
    int resp = 0;
    while( a > 0 ){
        resp *= 10;
        resp += a%10;
        a = a/10;
    }
    return resp;
}

int main(){
   int atual, next;
    queue<int> myq;
    int a, b, c;
    cin >> c;
    for( int i=0; i<c; i++ ){
        while( !myq.empty() ) myq.pop();
        mym.clear();
        cin >> a >> b;
        mym[a] = 0;
        myq.push( a );
        while( !myq.empty() && !mym.count( b ) ){
            atual = myq.front();
            myq.pop();
            if( !mym.count( atual + 1 ) ){
                mym[ atual + 1] = mym[atual] + 1;
                myq.push( atual + 1 );
            }
            next = invert( atual );
            if( !mym.count( next ) ){
                mym[next] = mym[atual] + 1;
                myq.push( next );
        } }
        cout << mym[b] << endl;
    }

return 0;
}

