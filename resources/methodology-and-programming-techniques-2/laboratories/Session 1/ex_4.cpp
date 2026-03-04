// ex_3.cpp
#include <iostream>
using namespace std;
// std::cout --> cout

class Coordinates
{
public:
    Coordinates(double, bool verbose = true);                 // constructor of the class
    Coordinates(double, double, bool verbose = true);         // constructor of the class
    Coordinates(double, double, double, bool verbose = true); // constructor of the class
    size_t dimension_;
    double data_[3] = {0, 0, 0};
    Coordinates operator+(const Coordinates &c);
    static void show_coor(double);
    static void show_coor(const Coordinates &c);
    void show_coor();
};

Coordinates Coordinates::operator+(const Coordinates &c)
{
    if (this->dimension_ != c.dimension_)
        throw invalid_argument("The dimensions of the coordinates must be the same for addition.");

    Coordinates temp(0, false);
    switch (this->dimension_)
    {
    case 1:
        temp = Coordinates(this->data_[0], false);
        break;
    case 2:
        temp = Coordinates(this->data_[0], this->data_[1], false);
        break;
    default:
        temp = Coordinates(this->data_[0], this->data_[1], this->data_[2], false);
        break;
    }
    for (size_t i = 0; i < this->dimension_; i++)
    {
        temp.data_[i] = this->data_[i] + c.data_[i];
    }
    return temp;
}

Coordinates::Coordinates(double element1, bool verbose)
{
    dimension_ = 1;
    data_[0] = element1;
    if (verbose)

        cout << "Constructor method for " << dimension_ << "D coordinates is called." << endl;
}

Coordinates::Coordinates(double element1, double element2, bool verbose)
{
    dimension_ = 2;
    data_[0] = element1;
    data_[1] = element2;
    if (verbose)
        cout << "Constructor method for " << dimension_ << "D coordinates is called." << endl;
}

Coordinates::Coordinates(double element1, double element2, double element3, bool verbose)
{
    dimension_ = 3;
    data_[0] = element1;
    data_[1] = element2;
    data_[2] = element3;
    if (verbose)
        cout << "Constructor method for " << dimension_ << "D coordinates is called." << endl;
}

void Coordinates::show_coor(double coordinates)
{
    cout << "The coordinates are: [" << coordinates << "]" << endl;
}

void Coordinates::show_coor()
{
    cout << "The coordinates of " << this->dimension_ << "D object are: [";
    for (size_t i = 0; i < this->dimension_; i++)
    {
        cout << this->data_[i];
        if (i != this->dimension_ - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main(void)
{
    Coordinates _1d(1.3, false);
    Coordinates _2d(2.3, 4.3, false);
    Coordinates _3d(1.5, 2.1, 3.3, false);

    Coordinates _1d1(2.4, true);
    Coordinates _2d1(2.4, 6.5, true);
    Coordinates _3d1(2.4, 3.2, 4.5, true);

    _1d1.show_coor();
    Coordinates A = _1d1 + _1d;
    A.show_coor();
    (_2d1 + _2d).show_coor();
    (_3d1 + _3d).show_coor();
    (_1d1 + _2d).show_coor();

    Coordinates::show_coor(2.6);

    return EXIT_SUCCESS;
}