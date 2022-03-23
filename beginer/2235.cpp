#URL: https://www.beecrowd.com.br/judge/en/problems/view/2235


#include <bits/stdc++.h>

using namespace std;

int main(){
        int a, b, c;
        cin >> a >> b >> c;
        if( a == b || b == c || a == c ){
                printf("S\n"); return 0;
        }
        if( a == 0 || b == 0 || c == 0 ){
                printf("S\n"); return 0;
        }
        if( a == b + c || b == c + a || c == a + b ){
                printf("S\n"); return 0;
        }
        printf("N\n");

return 0;
}

