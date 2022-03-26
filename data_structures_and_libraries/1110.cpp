#URL: https://www.beecrowd.com.br/judge/en/problems/view/1110


#include <bits/stdc++.h>

using namespace std;

int main(){
        int N, next;
        queue<int>myq;
        scanf("%d", &N);
        while( N != 0 ){
                for( int i=1; i<=N; i++) myq.push( i );
                printf("Discarded cards: ");
                while( myq.size() > 2){
                        printf("%d, ", myq.front() );
                        myq.pop();
                        next = myq.front();
                        myq.pop();
                        myq.push( next );
                }
                printf("%d\n", myq.front());
                myq.pop();
                printf("Remaining card: %d\n", myq.front() );
                myq.pop();
                scanf("%d", &N);
        }
return 0;
}
