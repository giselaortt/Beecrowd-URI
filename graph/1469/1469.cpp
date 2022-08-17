#include <unordered_map>
#include <queue>
#include <stack>
#include <iostream>
#include <queue>
#include <utility>
#include <bits/stdc++.h>
#include <set>
#define N_MAX 500


using namespace std;


int n, m, instructions;
int ages[N_MAX];
int position_of_employee[ N_MAX ];
int employee_at_position[ N_MAX ];
vector<vector<int>> graph;
set< int > managars_chain[N_MAX];
vector< pair<int,int> > employees_ages;
bool visited[ N_MAX ];


void dfs( int position ){
    visited[ position ] = true;
    for( auto it = graph[ position ].begin(); it!= graph[ position ].end(); it++ ){
        if( !visited[ *it ] ){ 
            dfs( *it );
            managars_chain[ position ].insert( *it );
        }
        managars_chain[ position ].insert( managars_chain[ *it ].begin(), managars_chain[ *it ].end() );
    }
}


int query( int employee_index ){
    int employee_position = position_of_employee[ employee_index ];
//    cout << "position" <<   employee_position << endl;
    if( graph[ employee_position ].empty() )
        return -1;
    if( managars_chain[ employee_position ].empty() )
        dfs( employee_position );
    for( auto it = employees_ages.begin(); it != employees_ages.end(); it++ )
        if( managars_chain[ employee_position ].count(  position_of_employee[ it->second ]  ) )
            return it->first;

return 0;
}


void swap( int employee, int other_employee ){

    //swap its index
    int temp;
    temp = position_of_employee[ employee ];
    position_of_employee[ employee ] = position_of_employee[ other_employee ];
    position_of_employee[ other_employee ] = temp;
    
    //swap its positions
    temp = employee_at_position[ employee ];
    employee_at_position[ employee ] = employee_at_position[ other_employee ];
    employee_at_position[ other_employee ] = temp;

}


int main(){

    while( cin >> n >> m >> instructions ){

        graph.clear();
        employees_ages.clear();

        for(int i=0; i<n+1; i++)
            managars_chain[i].clear(),
            employee_at_position[i] = i,
            position_of_employee[i] = i,
            graph.push_back( vector<int>() );

        for( int i=0; i<n; i++ )
            cin >> ages[i],
            employees_ages.push_back( make_pair( ages[i], i+1 ) );

        sort( employees_ages.begin(), employees_ages.end() );

        int x, y;
        for( int i=0; i<m; i++ )
            cin >> x >> y,
            graph[y].push_back( x );

        char type_of_instruction;
        int employee, other_employee;
        for( int i=0; i<instructions; i++ ){
            cin >> type_of_instruction;
            if( type_of_instruction == 'P' ){ 
                cin >> employee;
                int ans = query(employee);
                if( ans == -1 )
                    cout <<  "*" << endl; 
                else
                    cout << ans << endl;
            }
            else 
                cin >> employee >> other_employee,
                swap( employee, other_employee );
        }
    }


return 0;
}




