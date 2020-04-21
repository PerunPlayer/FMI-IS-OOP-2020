#include <iostream>
#include <cstring>
#include <fstream>


class Person {
private:
    char* name;
    size_t age;
public:

    Person():name(nullptr),age(0){}
    Person(char* name = nullptr, int age = 0){

        this->name = new char[strlen(name + 1)];
        strcpy(this->name, name);
        this->age = age;
    }

    Person(const Person& other){

        this->name = new char [strlen(other.name) + 1];
        strcpy(this->name, other.name);
        age = other.age;
    }

    Person& operator=(const Person& other){

        if(this != &other){
            delete[] name;

            this->name = new char [strlen(other.name) + 1];
            strcpy(this->name, other.name);
            this->age = other.age;
        }
        return *this;
    }

    ~Person(){
        delete[] name;
    }

    //Move constructor
    Person(Person&& other){

        this->name = other.name;
        age = other.age;


        other.name = nullptr;

    }

    //Move assigment operator
    Person& operator=(Person&& other){

        if(this != &other){

            delete[] name;

            this->name = other.name;
            age = other.age;

            other.name = nullptr;
        }

        return *this;
    }
};




// 1 -> 2 -> 3 -> ... -> 7


int main() {


    Person p1("Pesho", 25);
}