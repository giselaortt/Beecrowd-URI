#include <unordered_map>
#include <queue>
#include <stack>
#include <iostream>
#include <queue>

#define N_MAX 500


using namespace std;


class Employee{
    public:
    int age;
    int index;

    Employee( int a, int i ){
        age = a;
        index = i;
    }

    bool operator < ( Employee other ){
        return age < other.age;
    }

    bool greater ( Employee other ){
        return age > other.age;
    }

    bool operator > ( Employee other ){
        return age > other.age;
    }
};


int query( int employee_number ){

return 0;
}


void swap( int employee, int other_employee ){

return;
}


int main(){

    int n, m, instructions;
    int ages[N_MAX];
//    priority_queue< Employee, vector<Employee>, Employee::greater > employees_ages;
//    question: how can i have 2 elements in my priority queue and keep them ordered by only one of them?
//    example, if i use pair< int , int > to represent the age and the index, how can i tell my pq how who is bigger ?
    vector<vector<int>> grafo;

    while( cin >> n >> m >> instructions ){

        grafo.clear();
//        employees_ages.clear();
        for(int i=0; i<n; i++)
            grafo.push_back( vector<int>() );

        for( int i=0; i<n; i++ )
            cin >> ages[i],
            employees_ages.push( Employee( ages[i], i ) );

        int x, y;
        for( int i=0; i<m; i++ )
            cin >> x >> y,
            grafo[x].push_back( y ),
            grafo[y].push_back( x );

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
