// lab2_e1.cpp
#include <iostream>
#include <string>
using namespace std;

class Machine
{
private:
    string name = "general machine";

public:
    void print_description();
    Machine() {};
    Machine(string);
    string description = "An instance of Machine class";
};

Machine::Machine(string name)
{
    this->name = name;
    cout << "Creating an object of the class "
            "Machine, with name: "
         << endl
         << " " << this->name << endl
         << "Description: " << endl
         << " " << description << endl
         << "In the Machine constructor" << endl;
}

void Machine::print_description()
{
    cout << "description: " << this->description << endl;
}

class CNC : public Machine
{
private:
    string name = "CNC machine";

public:
    CNC() {};
    CNC(string);
    void print_description();
    string description = "A computerized numerical control (CNC) machine";
};

CNC::CNC(string name) : Machine()
{
    this->name = name;
    cout << "Creating an object of the class "
            "CNC, with name: "
         << endl
         << " " << this->name << endl
         << "Description: " << endl
         << " " << description << endl
         << "In the CNC constructor" << endl;
}
void CNC::print_description()
{
    cout << "description: " << this->description << endl;
}
int main()
{
    CNC mill("CNC machine");
    mill.print_description(); // prints: description: A computerized numerical control (CNC) machine
  
    mill.Machine::print_description(); // prints: description: An instance of Machine class
    // Machine hammer("super hammer");
    // hammer.print_description();
    return EXIT_SUCCESS;
}