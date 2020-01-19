//
// Created by eth3rial on 1/18/20.
//

#ifndef KURS_CLASSES_H
#define KURS_CLASSES_H

#include <string>
#include <vector>
#include "TextTable.h"
#include <fstream>
using namespace std;

class Date {
private:
    int day, month, year;
public:
    Date() {day = 01; month = 01; year = 2000;};
    Date (int day, int month, int year) {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    void setDate(Date date) {
        this->day = date.day;
        this->month = date.month;
        this->year = date.year;
    }
    int getDay() {
        return day;
    }
    int getMonth() {
        return month;
    }
    int getYear() {
        return year;
    }
    void setDate(int day, int month, int year) {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    string getDate() {
        return (to_string(day).length()<2?("0"+to_string(day)):(to_string(day))) + "-" + (to_string(month).length()<2?("0"+to_string(month)):(to_string(month))) + "-" + to_string(year);
    }
    operator string() {
        return getDate();
    }
};

class Person {
private:
    string name, surname;
    Date birthDate;
public:
    void setName(string name) {
        this->name = name;
    }
    void setSurname(string surname) {
        this->surname = surname;
    }
    void setBirthDate(Date birthDate) {
        this->birthDate.setDate(birthDate);
    }

    string getPerson() {
        return name + " " + surname + " " + birthDate.getDate();
    }
    string getName() {
        return name;
    }
    string getSurname() {
        return surname;
    }
    Date getBirthDate() {
        return birthDate;
    }

    Person() {
        name = "Sam";
        surname = "Sepiol";
        birthDate.setDate(9,5,2015);
    }
    Person(string name, string surname, Date birthDate) {
        this->name = name;
        this->surname = surname;
        this->birthDate.setDate(birthDate);
    }
    Person(string name, string surname) {
        this->name = name;
        this->surname = surname;
    }
    operator string() {
        return getPerson();
    }
};

class PositionNames {
private:
    int posIndex;
    vector<string> posNames;
public:
    void savePosNamesToFile() {
        ofstream file;
        file.open("posNames.txt");
        for (int i = 0; i < posNames.size(); i++) {
            file << posNames[i] << "\n";
        }
        file.close();
    }
    static void loadPosNamesFromFile() {
        string line;
        ifstream file ("posNames.txt");
        if (file.is_open())
        {
            while ( getline (file, line) )
            {
                cout << line << '\n';
            }
            file.close();
        }
    }
    void printPosNames() {
        TextTable t( '-', '|', '+' );
        t.add( "index" );
        t.add( "Pos name" );
        t.endOfRow();
        for (int i = 0; i < posNames.size(); i++) {
            t.add(std::to_string(i));
            t.add(posNames[i]);
            t.endOfRow();
        }
        t.setAlignment( 2, TextTable::Alignment::RIGHT );
        std::cout << t;
    }
    vector<string> getPosNames() {
        return posNames;
    }
    string getPos() {
        return posNames[posIndex];
    }
    void setPos(int posIndex) {
        this->posIndex = posIndex;
    }
    PositionNames() {
        posIndex = 0;
        posNames.emplace_back("����࠭�");
        posNames.emplace_back("���訩 ����࠭�");
        posNames.emplace_back("i������");
        posNames.emplace_back("c��訩 i������");
        posNames.emplace_back("�����訩 ��㪮��� �i�஡i⭨�");
        posNames.emplace_back("c��訩 ��㪮��� �i�஡i⭨�");
        posNames.emplace_back("��砫쭨�");
    }
    string& operator[] (int index) {
        return posNames[index];
    }
};

struct InvalidSalary : public exception {
    const char * msg () const throw () {
        return "Invalid employee salary exception (below zero).";
    }
};

class Position : public PositionNames {
private:
    int salary;
public:
    int getSalary() {
        return salary;
    }
    void setSalary(int salary) {
        if(salary < 0) throw InvalidSalary();
        this->salary = salary;
    }
    Position() {
        setPos(0);
        salary = 100;
    }
    Position(int salary, int posIndex) {
        this->salary = salary;
        setPos(posIndex);
    }
};

class Employee : public Person , public Position , public Date {
public:
    explicit Employee(Person person) {
        setName(person.getName());
        setSurname(person.getSurname());
        setBirthDate(person.getBirthDate());
    }
};

class Laboratory {
private:
    string name;
    Person zavLaboratory;
    vector<Employee> Employees;
public:
    void setName(string name) {
        this->name = name;
    }
    string getName() {
        return name;
    }
    void setZav(Person zav) {
        zavLaboratory = zav;
    }
    Person getZav() {
        return zavLaboratory;
    }
    vector<Person> getEmployees;
    void addEmployee(const Employee& employee) {
        Employees.emplace_back(employee);
    }
    int avgSalary() {
        int sumSalaries = 0;
        for (auto i : Employees) {
            sumSalaries += i.getSalary();
        }
        return sumSalaries / Employees.size();
    }
    int counEmployees() {
        return Employees.size();
    }
    operator string() {
        return name;
    };
    operator Person() {
        return zavLaboratory;
    }
    Laboratory() {
        name = "Lab name";
    }
};

class Department {
private:
    string name;
    Person manager;
    vector<Laboratory> labs;
public:
    void setName(string name) {
        this->name = name;
    }
    string getName() {
        return name;
    }
    Person getManager() {
        return manager;
    }
    void setManager(Person manager) {
        this->manager = manager;
    }
    vector<Laboratory> getLabs() {
        return labs;
    }
    void addLab(Laboratory lab) {
        labs.emplace_back(lab);
    }
    Department() {
        name = "Dep name";
    }
};

#endif //KURS_CLASSES_H
