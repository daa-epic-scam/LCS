#include <iostream>

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

// Mukku, can you make another input for this and have test cases? Idk what these test cases will be.
int main()
{
    const int m = 7;
    const int n = 10;
    char X[m + 1] = "ABCBABD"; // +1 for \0
    char Y[n + 1] = "BDCABADASC";
    int C[51][51]; // both are 50 characters long, idk if its enough, just increase or handle differetly
    char B[51][51];
    char lcs[max(m, n) + 1];

    // print the strings
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
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    // can print B from 1 onwards also instead of 0
    cout << "B matrix:" << endl;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    ExtractLCS(X, B, m, n, lcs);
    cout << "LCS: " << lcs << endl;

    return 0;
}
