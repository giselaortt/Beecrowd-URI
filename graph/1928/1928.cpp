//url of the problem:
//https://www.beecrowd.com.br/judge/en/problems/view/1928
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <climits>
#include <list>
#include <limits>
#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <stack>


#define infinity 100000000
#define N 50000


using namespace std;


int values[ N ];
int positionOfValue[ N ];
vector< int > graph[ N ];
int visited[ N ];
unordered_map< int, int > pairOfPosition;
unordered_map< int, int > distances;


//using iterative dfs
int sumPoints(){
    stack<int> mstack; 
    mstack.push( 1 );
    int total = 0;

    while( mstack.size() ){
        int currentNode = mstack.top();
        mstack.pop();
        if( visited[ currentNode ] )
            continue;
        visited[ currentNode ] = 1;
        int match = pairOfPosition[ currentNode ];

        //sum 1 to every element in the hashmap...
        for( auto it = distances.begin(); it != distances.end(); it++ )
            it->second++;

        if( visited[ match ] ){
            total += distances[ match ];
            distances.erase( match );
        } else {
            distances[match] = 0;
        }

        //add every neighboor of this node to mystack...
        for( int i=0; i< graph[currentNode].size(); i++ ){
            mstack.push( graph[currentNode][i] );
        }
    
    }

    return total;
}


int main(){

    int numberOfCards;
    cin >> numberOfCards;
    int first, second;

    for( int i=0; i<numberOfCards;i++ ){
        positionOfValue[ i ] = -1;
        visited[ i ] = 0;
    }

    for( int i=0; i<numberOfCards; i++ ){
        cin >> values[ i ];
        if( positionOfValue[ values[i] ] == -1 )
            positionOfValue[ values[i] ] = i;
        else{
            pairOfPosition[ i ] = positionOfValue[ values[i] ];
            pairOfPosition[ positionOfValue[ values[i] ] ] = i;
        }
    } 

    for( int i=0; i<numberOfCards;i++ ){
        cin >> first >> second;
        graph[ first-1 ].push_back( second-1 );
        graph[ second-1 ].push_back( first-1 );
    }

    cout << sumPoints() <<endl;

return 0;
}
