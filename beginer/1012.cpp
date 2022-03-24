#URL: https://www.beecrowd.com.br/judge/en/problems/view/1012

#include <bits/stdc++.h>
#define pi 3.14159

using namespace std;


int main(){
	double a, b, c;
	cin >> a >> b >> c;
	cout << "TRIANGULO: " << setprecision(3) << fixed << a*c/2.0 << endl;
	cout << "CIRCULO: " << setprecision(3) << fixed << pi*c*c << endl;
	cout << "TRAPEZIO: " << setprecision(3) << fixed << ( a + b )*c/2.0 << endl;
	cout << "QUADRADO: " << setprecision(3) << fixed << b*b << endl;
	cout << "RETANGULO: " << setprecision(3) << fixed << a*b << endl;

return 0;
}
