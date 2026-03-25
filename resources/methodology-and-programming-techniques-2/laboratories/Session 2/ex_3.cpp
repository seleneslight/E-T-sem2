#include <iostream>
#include <string>
using namespace std;

#define SCORES_PER_COURSE 4
#define COURSES_PER_STUDENT 4
#define STUDENTS_IN_COURSE 10

class Course
{
public:
    string name;
    double scores[SCORES_PER_COURSE]; // without the use of some kind of dynamic list or vectors the size of an array must be predetermined
};

class Student
{
public:
    string name;
    Course courses[COURSES_PER_STUDENT];
};

class Program
{
public:
    string name;
    Student students[STUDENTS_IN_COURSE];
    void print_average_for_each_subject();
};

void Program::print_average_for_each_subject() {
    for (unsigned char courseIndex = 0; courseIndex < COURSES_PER_STUDENT; courseIndex++)
    {
        double course_average = 0;
        int counter = 0;
        for (auto &student : students)
        {
            counter++;
            double average_of_student = 0;
            for(auto &score : student.courses[courseIndex].scores) {
                average_of_student += score;
            }
            average_of_student /= (double)SCORES_PER_COURSE;
            // cout << counter << ". average of student: " << average_of_student <<endl; /* debug helper*/
            course_average += average_of_student;
        }
        // cout << course_average << endl;
        course_average /= (double)STUDENTS_IN_COURSE;
        cout << course_average << endl;
    }  
}

int main()
{
    // Initialization
    Program Electronics_and_Telecommunications{
        "Electronics & Telecommunications", 
        {
            {
                "Alice",
                {
                    {"Math",        {5.0, 4.5, 4.0, 5.0}},
                    {"Physics",     {4.5, 4.0, 3.5, 4.0}},
                    {"Chemistry",   {3.5, 4.0, 3.0, 3.5}},
                    {"Programming", {5.0, 5.0, 4.5, 4.5}}
                }
            },
            {
                "Bob",
                {
                    {"Math",        {3.0, 3.5, 4.0, 3.5}},
                    {"Physics",     {2.5, 3.0, 3.5, 3.0}},
                    {"Chemistry",   {3.5, 3.5, 4.0, 3.5}},
                    {"Programming", {4.0, 4.5, 4.0, 4.5}}
                }
            },
            {
                "Charlie",
                {
                    {"Math",        {4.0, 4.0, 4.5, 4.0}},
                    {"Physics",     {3.5, 3.5, 4.0, 3.5}},
                    {"Chemistry",   {3.0, 3.0, 3.5, 3.0}},
                    {"Programming", {4.5, 5.0, 4.5, 5.0}}
                }
            },
            {
                "Diana",
                {
                    {"Math",        {5.0, 4.5, 5.0, 4.5}},
                    {"Physics",     {4.0, 4.5, 4.0, 4.5}},
                    {"Chemistry",   {3.5, 4.0, 3.5, 4.0}},
                    {"Programming", {5.0, 5.0, 4.5, 5.0}}
                }
            },
            {
                "Ethan",
                {
                    {"Math",        {2.5, 3.0, 3.0, 2.5}},
                    {"Physics",     {3.0, 3.5, 3.0, 3.5}},
                    {"Chemistry",   {3.5, 3.5, 3.0, 3.5}},
                    {"Programming", {4.0, 4.0, 4.5, 4.0}}
                }
            },
            {
                "Fiona",
                {
                    {"Math",        {4.5, 4.0, 4.5, 4.0}},
                    {"Physics",     {4.0, 4.0, 3.5, 4.0}},
                    {"Chemistry",   {3.5, 3.5, 4.0, 3.5}},
                    {"Programming", {5.0, 4.5, 5.0, 4.5}}
                }
            },
            {
                "George",
                {
                    {"Math",        {3.5, 3.5, 4.0, 3.5}},
                    {"Physics",     {3.0, 3.0, 3.5, 3.0}},
                    {"Chemistry",   {2.5, 3.0, 3.0, 2.5}},
                    {"Programming", {4.0, 4.0, 4.5, 4.0}}
                }
            },
            {
                "Hannah",
                {
                    {"Math",        {5.0, 4.5, 5.0, 4.5}},
                    {"Physics",     {4.5, 4.5, 4.0, 4.5}},
                    {"Chemistry",   {4.0, 4.0, 3.5, 4.0}},
                    {"Programming", {5.0, 5.0, 5.0, 5.0}}
                }
            },
            {
                "Ian",
                {
                    {"Math",        {3.0, 3.5, 3.0, 3.5}},
                    {"Physics",     {3.5, 3.5, 3.0, 3.5}},
                    {"Chemistry",   {3.0, 2.5, 3.0, 2.5}},
                    {"Programming", {4.0, 4.5, 4.0, 4.5}}
                }
            },
            {
                "Julia",
                {
                    {"Math",        {4.0, 4.5, 4.0, 4.5}},
                    {"Physics",     {3.5, 4.0, 3.5, 4.0}},
                    {"Chemistry",   {3.5, 3.0, 3.5, 3.0}},
                    {"Programming", {4.5, 5.0, 4.5, 5.0}}
                }
            }
        }
    };

    Electronics_and_Telecommunications.print_average_for_each_subject();
    return 0;
}
