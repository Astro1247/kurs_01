//
// Created by eth3rial on 1/18/20.
//

#ifndef KURS_CLASSES_H
#define KURS_CLASSES_H

#include <string>
#include <vector>
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
        return to_string(day) + "-" + to_string(month) + "-" + to_string(year);
    }
    operator string() {
        return to_string(day) + "-" + to_string(month) + "-" + to_string(year);
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
};

class PositionNames {
private:
    int posIndex;
    vector<string> posNames;
public:
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
        posNames.emplace_back("Лаборант");
        posNames.emplace_back("старший лаборант");
        posNames.emplace_back("інженер");
        posNames.emplace_back("cтарший інженер");
        posNames.emplace_back("молодший науковий співробітник");
        posNames.emplace_back("cтарший науковий співробітник");
        posNames.emplace_back("начальник");
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
    void addEmployee(const Person& employee) {
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
