#URL: https://www.beecrowd.com.br/judge/en/problems/view/1897


include <bits/stdc++.h>

using namespace std;

map<int, int> vis;
queue<int> myq;

void add( int a, int val){
    if( !vis.count ( a ) ){
        vis[a] = val;
        myq.push( a );
    }
}

int main(){
   int a, b;
    cin >> a >> b;

   myq.push( a );
    int atual, next;

    while( !myq.empty() && !vis.count( b ) ){
        atual = myq.front();
        myq.pop();
        add( atual * 2, vis[atual]+1);
        add( atual * 3, vis[atual]+1);
        add( atual / 2, vis[atual]+1);
        add( atual / 3, vis[atual]+1);
        add( atual + 7, vis[atual]+1);
        add( atual - 7, vis[atual]+1);
    }
    cout << vis[b] << endl;

return 0;
}
