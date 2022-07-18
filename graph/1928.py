# -*- coding: utf-8 -*-
#url of the problem:
#https://www.beecrowd.com.br/judge/en/problems/view/1928
#Result of this approach: Time Limit Exceeded
#In my opinion this problem was not thought to be solved in python on the given time,
#I believe there is not a more efficient way to solve it, in terms of Big O complexity, after a lot of thinking on this problem.
#If you do know an aceptable solution in python please contact me!
#My suggestion is to implement this approach on cpp, wich I decided not to do because I am working towards my python skills.
from collections import deque, Counter
import copy


wasVisited = set()
numberOfCards  = int(input().rstrip())
cardValues = {}
pairsOfPositions = {}
graph = { index : list() for index in range( 1, numberOfCards+1 ) }
totalSum = 0
distances =  Counter()


def getPositionPair( position ):
    value = cardValues[ position ]
    pair = pairsOfPositions[ value ]
    if( position == pair[0] ):
        return pair[1]
    return pair[0]


def calculateSum(  ):
    stack = deque()
    stack.append( 1 )
    totalSum = 0

    while( len(stack) > 0 ):
        currentNode = stack.pop()
        if( currentNode in wasVisited ):
            continue
        wasVisited.add( currentNode )
        valueOfCurrentNode = cardValues[ currentNode ]
        matchPosition = getPositionPair( currentNode )
        if( matchPosition in wasVisited ):
            totalSum = totalSum + distances[ matchPosition ]
            distances.pop( matchPosition )
        else:
            distances[ currentNode ] = 0

        for vertex in graph[ currentNode ]:
            if( vertex not in wasVisited ):
                stack.append( vertex )
                #wasVisited.add(vertex)

       #add one to every element that is still on the distances counter 
        distances.update( distances.keys() )

    return  totalSum


if __name__ == '__main__':

    for i, value in zip( range( 1,numberOfCards+1 ), input().rstrip().split() ):
        value = int( value )
        cardValues[ i ] = int(value)
        if( value not in pairsOfPositions ):
            pairsOfPositions[value] = i
        else:
            pairsOfPositions[value] = ( i, pairsOfPositions[value] )

    for i in range(numberOfCards-1):
        firstNode, secondNode = map( int, input().strip().split() )
        graph[ firstNode ].append( secondNode )
        graph[ secondNode ].append( firstNode )

    totalSum = totalSum + calculateSum(  )

    print( totalSum )

