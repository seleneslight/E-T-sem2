#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ofstream outFile("bird_up.txt");

    if (outFile) {
        outFile << "              __" << endl;
        outFile << "             /'{>" << endl;
        outFile << "         ____) (____" << endl;
        outFile << "       //'--;   ;--'\\\\" << endl;
        outFile << "      ///////\\_/\\\\\\\\\\\\\\" << endl;
        outFile << "             m m" << endl;
        
        outFile.close();
        cout << "Successfully wrote to bird_up.txt" << endl;
    } else {
        cout << "Error: Could not open bird_up.txt for writing." << endl;
        return 1;
    }

    ifstream inFile("bird_up.txt");
    vector<string> lines;
    string currentLine;

    if (inFile) {
        while (getline(inFile, currentLine)) {
            lines.push_back(currentLine);
        }
        inFile.close();
    } else {
        cout << "Error: Could not open bird_up.txt for reading." << endl;
        return 1;
    }

    ofstream outDown("bird_usdown.txt");

    if (outDown) {
        reverse(lines.begin(), lines.end());

        for (const string& line : lines) {
            string expandedLine = "";
            for (char c : line) {
                expandedLine += c;
                expandedLine += ' '; 
            }
            outDown << expandedLine << endl;
        }
        
        outDown.close();
        cout << "Successfully created bird_usdown.txt (Upside down & 2X)" << endl;
    } else {
        cout << "Error: Could not open bird_usdown.txt for writing." << endl;
        return 1;
    }

    return 0;
}