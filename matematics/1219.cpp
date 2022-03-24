#URL: https://www.beecrowd.com.br/judge/en/problems/view/1219

#include <bits/stdc++.h>
#define pi 3.1415926535897

using namespace std;

int main(){
	double lado1, lado2, lado3;
	double At, Acc, Aci;
	while( scanf("%lf %lf %lf", &lado1, &lado2, &lado3) != EOF ){
		double p = (lado1+lado2+lado3)/2;
		At = sqrt( p*(p-lado1)*(p-lado2)*(p-lado3) );
		Acc = pi*pow( lado1*lado2*lado3/4.0/At , 2 );
		Aci = pi*pow( At/p , 2 );
		printf("%.4f %.4f %.4f\n", Acc - At, At - Aci, Aci);
	}

return 0;
}
