#https://www.beecrowd.com.br/judge/en/problems/view/1469

import numpy as np
import queue

'''
def query( graph, numberOfEmployee, ages ):
    youngestAge = 101
    myqueue = queue.Queue()

    for i in range( graph.shape[0] ):
        if( graph[i][numberOfEmployee] == 1 ):
            myqueue.put(i)

    while( myqueue.empty() == False ):
        nextManager = myqueue.get()
        for i in range( graph.shape[0] ):
            if( graph[i][nextManager] == 1 ):
                myqueue.put(i)
                if( ages[i-1] <= youngestAge ):
                    youngestAge = ages[i-1]

    return youngestAge
'''




def query( graph, employeeNumber, ages ):
    youngest = 101

    for i in range(  len(graph)  ):
        if( graph[i][ employeeNumber ] == 1 ):
            youngest = min( youngest, ages[i-1], query( graph, i, ages ) )

    return youngest


def swap( graph, firstEmployee, secondEmployee ):
    for i in range( len(graph) ):
        if( i != firstEmployee and i != secondEmployee ):
            graph[i][ firstEmployee ], graph[i][ secondEmployee ] = graph[i][ secondEmployee ], graph[i][ firstEmployee ]
            graph[ firstEmployee ][i], graph[ secondEmployee ][i] = graph[ secondEmployee ][i], graph[firstEmployee][i]

    graph[ firstEmployee ][ secondEmployee ] = graph[ secondEmployee ][ firstEmployee ]

    return graph


if __name__ == '__main__':

    inputs = input().rstrip().split()

    totalOfEmployee = int(inputs[0])
    totalOfRelationships = int(inputs[1])
    totalOfQuestions = int(inputs[2])

    graph = [ [0]*(totalOfEmployee+1) for i in range(totalOfEmployee+1) ]
    #graph = np.zeros(( totalOfEmployee+1, totalOfEmployee+1 ))

    ages = [int(element) for element in input().rstrip().split()]


    for i in range(totalOfRelationships):
        inputs = input().rstrip().split()
        x = int(inputs[0])
        y = int(inputs[1])

        graph[x][y] = 1

    for i in range(totalOfQuestions):
        inputs = input().rstrip().split()

        if( inputs[0] == 'P' ):
           answer = query( graph, int(inputs[1]), ages )
           if( answer == 101 ):
               print("*")
           else:
                print(answer)
        
        if( inputs[0] == 'T' ):
            swap( graph, int(inputs[1]), int(inputs[2]) )
