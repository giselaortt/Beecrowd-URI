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
int positionOfEmployee[ N_MAX ];
int employeeAtPosition[ N_MAX ];
vector<vector<int>> graph;
vector< set< int > > managersChain;
vector< pair<int,int> > employees_ages;


int query( int employee_index ){
    int employee_position = positionOfEmployee[ employee_index ];
    if( managersChain[ employee_position ].empty() )
        return -1;
    for( auto it = employees_ages.begin(); it != employees_ages.end(); it++ )
        if( managersChain[ employee_position ].count( positionOfEmployee[ it->second ] ) )
            return it->first;

return 0;
}


void swap( int employee, int other_employee ){

    //swap its index
    int temp;
    temp = positionOfEmployee[ employee ];
    positionOfEmployee[ employee ] = positionOfEmployee[ other_employee ];
    positionOfEmployee[ other_employee ] = temp;
    
    //swao its positions
    temp = employeeAtPosition[ employee ];
    employeeAtPosition[ employee ] = employeeAtPosition[ other_employee ];
    employeeAtPosition[ other_employee ] = temp;

}


void dfs(){
    // todo: still did not figure it out how to add the manager to every single one of its employees. maybe the graph needs to change for a single directed one...
    stack<int> filo;
    filo.push( 0 );
    int visited[ N_MAX ];
    // todo: zero the whole visited vector...
    while( !filo.empty() ){
        int current = filo.top();
        filo.pop();
        //add to visited...
        visited[ current ] = 1;
        for( auto it = graph[ current ].begin(); it!= graph[current].end(); it++ ){
            if( !visited[ *it ] )
                filo.push( *it );
        }
        // é.........
    }

}


int main(){


    while( cin >> n >> m >> instructions ){

        graph.clear();
        employees_ages.clear();
        managersChain.clear();

        for(int i=0; i<n; i++)
            graph.push_back( vector<int>() );

        for( int i=0; i<n; i++ )
            cin >> ages[i],
            employees_ages.push_back( make_pair( ages[i], i ) );

        sort( employees_ages.begin(), employees_ages.end(), greater<pair<int,int>>() );

        int x, y;
        for( int i=0; i<m; i++ )
            cin >> x >> y,
            graph[x].push_back( y ),
            graph[y].push_back( x );

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


return 0;
}
