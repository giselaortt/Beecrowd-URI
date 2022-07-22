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

#define infinity 100000000

using namespace std;


int main(){

    int numberOfCards;
    cin >> numberOfCards;
    int values[numberOfCards];
    int first, second;
    int graph[ numberOfCards ][ numberOfCards ];
    int positionOfValue[ numberOfCards ];
    vector< pair< int, int > > pairsOfPositions;

    for( int i=0; i<numberOfCards;i++ ){
        positionOfValue[ i ] = -1;
    }

    for( int i=0; i<numberOfCards; i++ ){
        cin >> values[ i ];
        if( positionOfValue[ values[i] ] == -1 )
            positionOfValue[ values[i] ] = i;
        else{
            pairsOfPositions.push_back( make_pair( positionOfValue[ values[i] ], i ) );
        }
    } 

    for( int i=0; i<numberOfCards;i++ ){
        for( int j=0; j<numberOfCards; j++ ){
            graph[i][j] = infinity;   
        }
    }

    for( int i=0; i<numberOfCards;i++ ){
        cin >> first >> second;
        graph[ first-1 ][ second-1 ] = 1;
        graph[ second-1 ][ first-1 ] = 1;
    }

    for( int i=0; i<numberOfCards; i++ ){
        for( int j=0; j<numberOfCards; j++ ){
            for( int k=0; k<numberOfCards; k++ ){
                if( graph[i][k] > graph[i][j] + (graph[j][k]) ){
                    graph[i][k] = graph[i][j] + (graph[j][k]);
                    graph[k][i] = graph[i][j] + (graph[j][k]);
                }
            }
        }
    }

    int total = 0;
    for( int i=0; i<pairsOfPositions.size(); i++ ){ 
        int first =  pairsOfPositions[i].first;
        int sec = pairsOfPositions[i].second;
        total += graph[ first ][ sec ];
        //cout << first <<  "  " << sec << "  " << graph[first][sec] << endl;
    }
    cout << total << endl;

return 0;
}
