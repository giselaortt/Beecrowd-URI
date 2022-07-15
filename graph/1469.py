"""
URL of the problem:
https://www.beecrowd.com.br/judge/en/problems/view/1469

Result to this aproach: Time Limit Exceeded
"""

class LKS():

    def __init__( self, numberOfEmployees ):
        self.employeeAtPosition = { i : i for i in range( 1, numberOfEmployees+1 ) }
        self.positionOfEmployee = { i : i for i in range( 1, numberOfEmployees+1 ) }
        self.managersGraph = { i : set() for i in range( 1, numberOfEmployees+1 ) }
        self.ages = {}
        self.numberOfEmployees = numberOfEmployees


    def __str__( self ):
        
        return "ages = " + self.ages.__str__() +"\n" + "positions of employees ="+self.positionOfEmployee.__str__()+"\nemployee at position x = "+self.employeeAtPosition.__str__() + "\ngraph = "+self.managersGraph.__str__() 


    def readAges( self ):
        self.ages = input().rstrip().split()
        self.ages = { i : int(age) for i, age in  enumerate( self.ages, start = 1 ) }


    def _getManagers( self, employeeIndex ):
        position = self._getPositionPerEmployee( employeeIndex )
        return self.managersGraph[ position ]

    def _getManagersPerPosition( self, position ):
        return self.managersGraph[ position ]


    def _getPositionPerEmployee( self, employeeIndex ):
        return self.positionOfEmployee[ employeeIndex ]


    def _getEmployeePerPosition( self, position ):
        return self.employeeAtPosition[ position ]


    def addManager( self, employeeIndex, managerIndex ):
        self.managersGraph[ employeeIndex ].add( managerIndex )


    def swap( self, employeeFirst, employeeSecond ):
        firstPosition = self._getPositionPerEmployee( employeeFirst )
        secondPosition = self._getPositionPerEmployee( employeeSecond )
        self.employeeAtPosition[firstPosition], self.employeeAtPosition[secondPosition]=self.employeeAtPosition[ secondPosition ], self.employeeAtPosition[ firstPosition ] 
        self.positionOfEmployee[employeeFirst], self.positionOfEmployee[employeeSecond]=self.positionOfEmployee[ employeeSecond ], self.positionOfEmployee[ employeeFirst ]


    def findYoungestManager( self, employeeIndex ):
        managers = self._getManagers( employeeIndex )
        #print(employeeIndex)
        if( len( managers ) == 0 ):
            print("*")
            return
        youngest = 101
        for manager in managers:
            youngest = min( youngest, self._graphRecursion( manager ) )
        print( youngest )
        return


    def _graphRecursion( self, employeePosition ):
        employeeNumber = self.employeeAtPosition[ employeePosition ]
        age = self.ages[ employeeNumber ]
        managers = self._getManagers( employeeNumber )

        if( len(managers) == 0 ):
            return age

        for manager in managers:
            age = min( age, self._graphRecursion( manager ) )

        return age


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
                graph.findYoungestManager( int( inputs[1] ) )
            
            if( inputs[0] == 'T' ):
                firstIndex = int(inputs[1]) 
                secondIndex = int(inputs[2])
                graph.swap( firstIndex, secondIndex )
