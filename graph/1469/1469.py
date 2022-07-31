"""
URL of the problem:
https://www.beecrowd.com.br/judge/en/problems/view/1469
Result to this aproach: Time Limit Exceeded
"""
import queue
import heapq
from collections import deque


class LKS():

    def __init__( self, numberOfEmployees ):
        self.employeeAtPosition =   { i : i         for i in range( 1, numberOfEmployees+1 ) }
        self.positionOfEmployee =   { i : i         for i in range( 1, numberOfEmployees+1 ) }
        self.graph =                { i : set()     for i in range( 1, numberOfEmployees+1 ) }
        self.ages =                 {}
        self.managerChain =         {}
        self.numberOfEmployees = numberOfEmployees


    def __str__( self ):
        return "ages = " + self.ages.__str__() +"\n" + "positions of employees ="+self.positionOfEmployee.__str__()+"\nemployee at position x = "+self.employeeAtPosition.__str__() + "\ngraph = "+self.graph.__str__()


    def readAges( self ):
        self.ages = input().rstrip().split()
        self.ages = { i : int(age) for i, age in  enumerate( self.ages, start = 1 ) }


    def _getManagers( self, employeePosition ):
        return self.graph[ employeePosition ]


    def _getPositionPerEmployee( self, employeeIndex ):
        return self.positionOfEmployee[ employeeIndex ]
    def addManager( self, employeeIndex, managerIndex ):
        self.graph[ employeeIndex ].add( managerIndex )


    def _getAgeByPosition( self, position ):
        index = self.employeeAtPosition[ position ]
        age = self.ages[ index ]

        return age


    def swap( self, employeeFirst, employeeSecond ):
        firstPosition = self._getPositionPerEmployee( employeeFirst )
        secondPosition = self._getPositionPerEmployee( employeeSecond )
        self.employeeAtPosition[firstPosition], self.employeeAtPosition[secondPosition]=self.employeeAtPosition[ secondPosition ], self.employeeAtPosition[ firstPosition ]
        self.positionOfEmployee[employeeFirst], self.positionOfEmployee[employeeSecond]=self.positionOfEmployee[ employeeSecond ], self.positionOfEmployee[ employeeFirst ]


    def queryYoungestManager( self, employeeIndex ):
        position = self.positionOfEmployee[ employeeIndex ]

        if( position not in self.managerChain ):
            self.findManagersChain( position )

        youngest = 101
        #print( self.managerChain[position] )
        for manager in self.managerChain[ position ]:
            #print(manager)
            managerAge = self._getAgeByPosition( manager  )
            youngest = min( youngest, managerAge )

        if( youngest == 101 ):
            youngest = "*"

        return youngest


    def findManagersChain( self, employeePosition ):
        managers = self._getManagers( employeePosition )
        managerChain = []

        for manager in managers:
            managerChain.extend( self._findManagersChainRecursion( manager ) )

        self.managerChain[ employeePosition ] =  managerChain


    def _findManagersChainRecursion( self, employeePosition ):
        if( employeePosition in self.managerChain ):

            return list( self.managerChain[ employeePosition ] )

        managers = self._getManagers( employeePosition )
        ans = [ employeePosition ]

        for manager in managers:
            ans.extend( self._findManagersChainRecursion( manager ) )

        return ans

if __name__ ==  "__main__":

    while True:

        try:
            inputs = input().rstrip().split()
        except EOFError:
            break

        totalOfEmployee = int(inputs[0])
        totalOfRelationships = int(inputs[1])
        totalOfQuestions = int(inputs[2])
        graph = LKS( totalOfEmployee )
        graph.readAges()

        for i in range(totalOfRelationships):
            inputs = input().rstrip().split()
            graph.addManager( int(inputs[1]), int(inputs[0]) )

        for i in range(totalOfQuestions):
            inputs = input().rstrip().split()

            if( inputs[0] == 'P' ):
                print( graph.queryYoungestManager( int( inputs[1] ) ) )

            if( inputs[0] == 'T' ):
                firstIndex, secondIndex = map( int, inputs[1:] )
                graph.swap( firstIndex, secondIndex )
