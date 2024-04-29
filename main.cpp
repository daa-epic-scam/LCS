#include <iostream>
#include <fstream>
#include <string>
#include "lcs.h"
#include "lcs.cpp"

using namespace std;

int main()
{
    ifstream input_file("./input/final.txt"); // Open the input file
    if (!input_file.is_open())
    {
        cout << "File does not exist" << endl;
        return 1;
    }

    string X, Y;
    getline(input_file, X); // Read the first string from the file
    getline(input_file, Y); // Read the second string from the file
    input_file.close();     // Close the input file

    const int m = X.length();
    const int n = Y.length();
    char **B = new char *[m + 1];
    int **C = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        B[i] = new char[n + 1];
        C[i] = new int[n + 1];
    }

    string lcs;

    cout << "String 1: " << X << endl;
    cout << "String 2: " << Y << endl;

    LCS_Length(X, Y, m, n, B, C);
    cout << "Length of LCS: " << C[m][n] << endl;
    cout << endl;

    cout << "C matrix:" << endl;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%4d", C[i][j]);
        }
        cout << endl;
    }

    cout << "B matrix:" << endl;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%4c", B[i][j]);
        }
        cout << endl;
    }

    lcs = ExtractLCS(X, B, m, n);
    cout << "LCS: " << lcs << endl;

    // Free the dynamically allocated memory for B and C
    for (int i = 0; i <= m; i++)
    {
        delete[] B[i];
        delete[] C[i];
    }
    delete[] B;
    delete[] C;

    return 0;
}
