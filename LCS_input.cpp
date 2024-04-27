#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// C is the LCS number matrix and B is direction matrix, he used arrows, im using D,U,L
void LCS_Length(const char *X, const char *Y, int m, int n, char B[51][51], int C[51][51])
{
    for (int i = 0; i <= m; i++)
    {
        C[i][0] = 0;
    }
    for (int j = 0; j <= n; j++)
    {
        C[0][j] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                C[i][j] = C[i - 1][j - 1] + 1;
                B[i][j] = 'D'; // move diagonally
            }
            else if (C[i - 1][j] >= C[i][j - 1])
            {
                C[i][j] = C[i - 1][j];
                B[i][j] = 'U'; // move up
            }
            else
            {
                C[i][j] = C[i][j - 1];
                B[i][j] = 'L'; // move left
            }
        }
    }
}

void Reverse_String(char *str, int length)
{
    int start = 0;
    int end = length - 1;
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void ExtractLCS(const char *X, char B[51][51], int m, int n, char *lcs)
{
    int i = m, j = n; // building bottom up, starting peeche se
    int index = 0;

    while (i > 0 && j > 0)
    {
        if (B[i][j] == 'D')
        {
            lcs[index++] = X[i - 1];
            i--;
            j--;
        }
        else if (B[i][j] == 'U')
        {
            i--;
        }
        else if (B[i][j] == 'L')
        {
            j--;
        }
    }

    lcs[index] = '\0';

    // reverse the string because it was constructed backwards
    Reverse_String(lcs, index);
}

int main()
{
    ifstream input_file("input.txt"); // Open the input file
    if (!input_file.is_open())
    {
        cout << "Failed to open input file" << endl;
        return 1;
    }

    string X, Y;
    getline(input_file, X); // Read the first string from the file
    getline(input_file, Y); // Read the second string from the file
    input_file.close();     // Close the input file

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
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "B matrix:" << endl;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    ExtractLCS(X.c_str(), B, m, n, lcs);
    cout << "LCS: " << lcs << endl;

    return 0;
}