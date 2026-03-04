// ex_2.cpp
#include <iostream>
using namespace std;
// std::cout --> cout

class Coordinates
{
public:
    Coordinates(double);                 // constructor of the class
    Coordinates(double, double);         // constructor of the class
    Coordinates(double, double, double); // constructor of the class
    size_t dimension_;
    double data_[3];
};

Coordinates::Coordinates(double element1)
{
    dimension_ = 1;
    data_[0] = element1;
    cout << "Constructor method for " << dimension_ << "D coordinates is called." << endl;
}

Coordinates::Coordinates(double element1, double element2)
{
    dimension_ = 2;
    data_[0] = element1;
    data_[1] = element2;
    cout << "Constructor method for " << dimension_ << "D coordinates is called." << endl;
}

Coordinates::Coordinates(double element1, double element2, double element3)
{
    dimension_ = 3;
    data_[0] = element1;
    data_[1] = element2;
    data_[2] = element3;
    cout << "Constructor method for " << dimension_ << "D coordinates is called." << endl;
}

void show_coor(double coordinates)
{
    cout << coordinates << endl;
}

void show_coor(Coordinates coordinates)
{
    cout << "The coordinates of object " << coordinates.dimension_ << "D are: [";
    for (size_t i = 0; i < coordinates.dimension_; i++)
    {
        cout << coordinates.data_[i];
        if (i != coordinates.dimension_ - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main(void)
{
    Coordinates _1d(1.3);
    cout << "Expected dimension of the coordinates : 1 Actual dimension: " << _1d.dimension_ << "\n"
         << endl;
    Coordinates _2d(2.3, 4.3);
    cout << "Expected dimension of the coordinates : 2 Actual dimension: " << _2d.dimension_ << "\n"
         << endl;
    Coordinates _3d(1.5, 2.1, 3.3);
    cout << "Expected dimension of the coordinates : 3 Actual dimension: " << _3d.dimension_ << "\n"
         << endl;
    show_coor(1.3);
    show_coor(_1d);
    show_coor(_2d);
    show_coor(_3d);

    return EXIT_SUCCESS;
}