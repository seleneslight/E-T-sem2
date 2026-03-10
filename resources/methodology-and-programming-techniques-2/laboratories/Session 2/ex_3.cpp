#include <iostream>
#include <string>
using namespace std;

class Course
{
public:
    string name;
    double scores[];
    Course() {};
};

class Student
{
public:
    string name;
    Course courses[4];
    Student() {};
};

class Program
{
public:
    string name;
    Student students[10];
    Program() {};
    void print_average_for_each_subject();
};

void Program::print_average_for_each_subject() {

}

int main()
{
    
    return 0;
}
