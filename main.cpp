#include <iostream>
#include "Classes.h"
#include <fstream>

int main() {
    cout << "Initialising new Date class object 'date' 9/5/1975\n";
    Date date(9, 5,1975);
    cout << "Printing 'date'\n";
    cout << date.getDate() << endl;

    cout << "Init 'pers1' and 'pers2' of class Person, 'lab' of class Laboretory\n";
    Person pers1, pers2, pers3;
    Laboratory lab;
    cout << "Creatine 'emp1' and 'emp2' of class Employee with 'pers1' and 'pers2'\n";
    Employee emp1(pers1);
    Employee emp2(pers2);
    Employee emp3(pers3);
    cout << "Setting birth date for 'pers1' with 'date' object\n";
    pers1.setBirthDate(date);
    cout << "Printing 'pers1' executing a 'getPerson()' method of Person class\n";
    cout << pers1.getPerson() << endl;

    cout << "Trying to set salary '-150' for Employee 'emp1'\n";
    try {
        emp1.setSalary(-150);
        cout << "Successful salary setting for Employee object\n";
    } catch (InvalidSalary e) {
        cout << "Caught exception: " << e.msg() << endl;
    }
    cout << "Trying to set salary '1000' for Employee 'emp2'\n";
    try {
        emp2.setSalary(1000);
        cout << "Successful salary setting for Employee object\n";
    } catch (InvalidSalary e) {
        cout << "Caught exception: " << e.msg() << endl;
    }
    cout << "Trying to set salary '758' for Employee 'emp3'\n";
    try {
        emp3.setSalary(758);
        cout << "Successful salary setting for Employee object\n";
    } catch (InvalidSalary e) {
        cout << "Caught exception: " << e.msg() << endl;
    }
    cout << "Adding 'emp1', 'emp2' and 'emp3' to 'lab' object\n";
    lab.addEmployee(emp1);
    lab.addEmployee(emp2);
    lab.addEmployee(emp3);
    cout << "Get average salary for 'lab' with executing 'avgSalary()' method\n";
    cout << lab.avgSalary() << endl;
    cout << "Executing 'printPosNames()' for 'emp1' ti print a table-view for position names array\n";
    emp1.printPosNames();
    cout << "Executing 'savePosNamesToFile()' for 'emp1' to save position names to text file\n";
    try {
        emp1.savePosNamesToFile();
        cout << "Successful save data to text file\n";
    } catch (exception e) {
        cout << "Caught some exception during saving a file. Exception: " << e.what() << endl;
    }
    cout << "Executing 'loadPosNamesFromFile()' for 'emp1' to load position names from text file\n";
    emp1.loadPosNamesFromFile();

    return 0;
}
