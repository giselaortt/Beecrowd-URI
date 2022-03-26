#URL: https://www.beecrowd.com.br/judge/en/problems/view/1799


#include <bits/stdc++.h>
#define M 4000 

using namespace std;

map< string, int> mymap;
int vis[M];
queue<int>myq;
vector<int>myvec[M];
//map<int, int> vis;

int bfs(int start, int target){
        memset(vis, -1, sizeof(vis));
//      vis.clear();
        while( !myq.empty() ) myq.pop();
        myq.push( start );
        vis[start] = 0;
        int atual;
        while( !myq.empty() && vis[target] == -1){
                atual = myq.front();
                myq.pop();
                for(int i=0; i<myvec[atual].size(); i++){
                        if( vis[ myvec[atual][i] ]  == -1 ) {
                                vis[myvec[atual][i]] = vis[atual] + 1;
                                myq.push( myvec[atual][i] );
                        }
                }
        }
return vis[target];
}

int main(){
        int name = 1;
        int target, resp;
        string first, sec;
        int a, b;
        int edge, vert;
        scanf("%d %d", &vert, &edge);

        for(int i=0; i<edge; i++){
                cin >> first >> sec;
                if( !mymap.count(first) ){ mymap[first] = name; name++; }
                if( !mymap.count( sec ) ) { mymap[sec] = name; name++; }

                myvec[ mymap[first] ].push_back( mymap[sec] );
                myvec[ mymap[sec] ].push_back( mymap[first] );
        }

        resp = bfs( mymap["Entrada"], mymap["*"]) + bfs( mymap["*"], mymap["Saida"]);
        cout << resp << endl;
return 0;
}
