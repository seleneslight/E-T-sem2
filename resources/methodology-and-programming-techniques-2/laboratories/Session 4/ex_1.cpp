#include <fstream>
#include <iostream>

using namespace std;

string str;
float sum;
int counter = 0;

int main()
{
    ifstream input("data_in.csv");
    if (!input)
    {
        cerr << "Unable to open file" << endl;
    }
    while (getline(input, str))
    {
        counter++;
        sum += stof(str);
    }
    ofstream output{"data_out.csv"};
    if (!output)
    {
        cerr << "Unable to open file" << endl;
    }

    output << sum << endl << (sum/(float)counter) << endl;
    return 0;
}
