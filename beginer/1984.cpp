#URL:
#https://www.beecrowd.com.br/judge/en/problems/view/1984

#include <bits/stdc++.h>

using namespace std;

int main(){
        long long int a, b = 0;
        int ctd;
        cin >> a;
        int i;
        for( i=0; a%10 == 0 ; i++) a = a/10;
        while( a > 0 ){
                b*=10;
                b += a%10;
                a = a/10;
        }
        while( i-- ) printf("0");
        cout << b << endl;

return 0;
}
