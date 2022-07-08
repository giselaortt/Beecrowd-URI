#url of the problem:
#https://www.beecrowd.com.br/judge/en/problems/view/1928


# -*- coding: utf-8 -*-


import numpy as np
import queue


def calculatePath( graph, startingPoint, values ):
    myqueue = queue.Queue()
    distances = [-1]*(len(graph)+1)
    distances[ startingPoint ] = 0
    myqueue.put( startingPoint )
    targetValue = values[ startingPoint-1 ]

    answer = -1

    while( not myqueue.empty() ):
        currentNode = myqueue.get()
        for i in range(len(graph)):
            if( graph[ currentNode ][ i ] == 1 and distances[ i ] == -1 ):
                distances[ i ] = distances[ currentNode ] + 1
                myqueue.put( i )
                if( values[i-1] == targetValue ):
                    answer = distances[ i ]
                    break
    return answer


if __name__ == '__main__':
    numberOfCards  = int(input().rstrip())
    cardValues = [ int(value) for value in input().rstrip().split() ]
    #graph = np.zeros((numberOfCards, numberOfCards), type=int)
    graph = [ [0]*(numberOfCards+1) for i in range( numberOfCards+1 ) ]

    for i in range(numberOfCards - 1):
        inputs = input().strip().split()
        graph[int(inputs[0])][int(inputs[1])] = 1
        graph[int(inputs[1])][int(inputs[0])] = 1

    totalSum = 0
    counted = [0]*(int(numberOfCards/2)+1)
    for i in range( 1, numberOfCards ):
        if( counted[ cardValues[i-1] ] == 0 ):
            totalSum = totalSum + calculatePath( graph, i, cardValues )
            counted[ cardValues[i-1] ] = 1

    print( totalSum )

