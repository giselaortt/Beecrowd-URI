#URL: https://www.beecrowd.com.br/judge/en/problems/view/1310


#include <bits/stdc++.h>
#define maxi 51
using namespace std;

int vetor[maxi];

int main(){
        int price, days;
        while(  scanf("%d %d", &days, &price) != EOF ){
                for( int i=0; i<days; i++) scanf("%d", &vetor[i]);
                for(int i=0; i<days; i++) vetor[i] -= price;
                int sum = 0, max = 0;
                for( int i=0; i<days; i++){
                        sum += vetor[i];
                        if( sum > max )  max = sum;
                        if( sum < 0 ) sum = 0;
                }
                printf("%d\n", max);
        }
return 0;
}
