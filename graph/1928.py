#url of the problem:
#https://www.beecrowd.com.br/judge/en/problems/view/1928
# -*- coding: utf-8 -*-

from collections import deque
import copy


def calculateDistances( graph ):
    queue = deque()
    wasVisited = set()
    startingPoint = 1 # it makes no diference where we start this calculation so i will simply start at zero.
    queue.append( startingPoint )
    numberOfNodes = len(graph)
    distances = { index : dict() for index in range( 1, numberOfNodes+1 ) }

    for index in distances.keys():
        distances[ index ][ index ] = 0

    while( len( queue ) > 0 ):
        currentNode = queue.popleft()
        if( currentNode in wasVisited ):
            continue
        wasVisited.add( currentNode )
        for nextNode in graph[ currentNode ]:
            if( nextNode not in wasVisited ):
                queue.append( nextNode )
                distances[ nextNode ][ currentNode ] = 1
                distances[ currentNode ][ nextNode ] = 1
                for node, distance in distances[ currentNode ].items() :
                    if( node not in distances[ nextNode ] ):
                        distances[ nextNode ][ node ] = distances[ node ][ nextNode ] = distnce + 1

    return distances


if __name__ == '__main__':
    numberOfCards  = int(input().rstrip())
    cardValues = {}
    pairsOfPositions = {}
    graph = { index : list() for index in range( 1, numberOfCards+1 ) }
    totalSum = 0

    for i, value in zip( range( 1,numberOfCards+1 ), input().rstrip().split() ):
        value = int( value )
        cardValues[ i ] = int(value)
        if( value not in pairsOfPositions ):
            pairsOfPositions[value] = [ i, -1 ]
        else:
            pairsOfPositions[value][1] = i

    for i in range(numberOfCards-1):
        inputs = input().strip().split()
        firstNode = int( inputs[0] )
        secondNode = int( inputs[1] )
        graph[ firstNode ].append( secondNode )
        graph[ secondNode ].append( firstNode )

    distances = calculateDistances( graph )
    #print( distances )

    for pair in pairsOfPositions.values() :
        totalSum = totalSum + distances[ pair[0] ][ pair[1] ]

    print( totalSum )

