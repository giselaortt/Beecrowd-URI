#include <unordered_map>
#include <queue>
#include <stack>
#include <iostream>
#include <queue>
#include <utility>
#include <bits/stdc++.h>
#define N_MAX 500


using namespace std;


int query( int employee_number ){

return 0;
}


void swap( int employee, int other_employee ){

return;
}


int main(){

    int n, m, instructions;
    int ages[N_MAX];
    vector<vector<int>> grafo;
    vector< pair<int,int> > employees_ages;


    while( cin >> n >> m >> instructions ){

        grafo.clear();
        employees_ages.clear();

        for(int i=0; i<n; i++)
            grafo.push_back( vector<int>() );

        for( int i=0; i<n; i++ )
            cin >> ages[i],
            employees_ages.push_back( make_pair( ages[i], i ) );

        sort( employees_ages.begin(), employees_ages.end(), greater<pair<int,int>>() );

        int x, y;
        for( int i=0; i<m; i++ )
            cin >> x >> y,
            grafo[x].push_back( y ),
            grafo[y].push_back( x );

        char type_of_instruction;
        int employee, other_employee;
        for( int i=0; i<instructions; i++ ){
            cin >> type_of_instruction;
            if( type_of_instruction == 'p' )
                cin >> employee,
                cout << query(employee);
            else 
                cin >> employee >> other_employee,
                swap( employee, other_employee );
        }
    }

    for( auto it = employees_ages.begin(); it!= employees_ages.end(); it++ )
        cout << it->first<<endl;

return 0;
}
