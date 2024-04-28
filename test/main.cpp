#include <iostream>
#include <fstream>
#include <string>
#include "lcs.h" 

using namespace std;

int main() {
    ifstream input_file("./input/input4.txt"); // Open the input file
    if (!input_file.is_open()) {
        cout << "File does not exist" << endl;
        return 1;
    }

    string X, Y;
    getline(input_file, X); // Read the first string from the file
    getline(input_file, Y); // Read the second string from the file
    input_file.close(); // Close the input file

    const int m = X.length();
    const int n = Y.length();
    char B[51][51];
    int C[51][51];
    char lcs[max(m, n) + 1];

    cout << "String 1: " << X << endl;
    cout << "String 2: " << Y << endl;

    LCS_Length(X.c_str(), Y.c_str(), m, n, B, C);
    cout << "Length of LCS: " << C[m][n] << endl;
    cout << endl;

    cout << "C matrix:" << endl;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "B matrix:" << endl;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    ExtractLCS(X.c_str(), B, m, n, lcs);
    cout << "LCS: " << lcs << endl;

    return 0;
}