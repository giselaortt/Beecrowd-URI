#url of the problem:
#https://www.beecrowd.com.br/judge/en/problems/view/1928


# -*- coding: utf-8 -*-


import numpy as np


def getMatchingPositions():
    pass


def calculatePath( graph ):
    pass


if __name__ == '__main__':
    

    numberOfCards  = int(input().rstrip())

    cardValues = [ int(value) for value in input().rstrip().split() ]

    graph = np.zeros((numberOfCards, numberOfCards), type=int)

    for i in range(numberOfCards - 1):
        inputs = input().strip().split()
        graph[int(inputs[0])][int(inputs[1])] = 1
        graph[int(inputs[1])][int(inputs[0])] = 1


