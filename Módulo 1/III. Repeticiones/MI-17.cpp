#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    
    float salary = 1, a_employees = 0, b_employees = 0, c_employees = 0, d_employees = 0;
    
    while(salary != 0){
        cout << "Type the salary: ";
        cin >> salary;
        
        if(salary > 0 && salary < 1520) a_employees++;

        else if(salary >= 1520 && salary < 2780) b_employees++;

        else if(salary >= 2780 && salary < 5999) c_employees++;

        else if(salary >= 5999) d_employees++;
    }

    cout << "Empleados que ganan menos de $1520: " << a_employees << endl;
    cout << "Empleados que ganan $1520 o mas pero menos de $2780: " << b_employees << endl;
    cout << "Empleados que ganan $2780 o mas pero menos de $5999: " << c_employees << endl;
    cout << "Empleados que ganan $5999 o mas: " << d_employees << endl;


    return 0;
}