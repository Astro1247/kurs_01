#include <iostream>
#include "Classes.h"
#include <fstream>

int main() {
    //std::cout << "Hello, World!" << std::endl;
    Person pers1, pers2;
    Laboratory lab;
    Employee emp(pers1);
    Employee emp2(pers2);
    try {
        emp.setSalary(-150);
    } catch (InvalidSalary e) {
        cout << "Caught exception: " << e.msg() << endl;
    }
    emp2.setSalary(1000);
    lab.addEmployee(emp);
    lab.addEmployee(emp2);
    cout << lab.avgSalary() << endl;
    //emp.printPosNames();
    emp.savePosNamesToFile();
    emp.loadPosNamesFromFile();

    return 0;
}
