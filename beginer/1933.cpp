#URL: https://www.beecrowd.com.br/judge/en/problems/view/1933

#include <bits/stdc++.h>
//#define max(a, b) a > b ? a : b;

using namespace std;


int a, b, ans;

int main() {
        int a, b;
        cin >> a >> b;
        if( a == b ) cout << a << endl;
        else cout << max(a, b) << endl;

        return 0;
}
