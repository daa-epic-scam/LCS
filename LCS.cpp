#include <iostream>

using namespace std;
// C is the LCS number matrix and B is direction matrix, he used arrows, I'm using D,U,L
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
            if (X[i] == Y[j])
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

char *ExtractLCS(const char *X, char B[51][51], int m, int n)
{
    int i = m, j = n; // building bottom up, starting peeche se
    int index = 0;
    char *lcs = new char[min(m, n) + 1]; // dynamically allocation because length unknowun during compile
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
    Reverse_String(lcs, index); // reverse the string because it was constructed backwards
    return lcs;
}

int main()
{
    const int m = 22;
    const int n = 17;
    char X[m + 1] = "IDON'TWANTTOKILLMYSELF";
    char Y[n + 1] = "IWANTTOKILLMYSELF";
    int C[51][51] = {0};
    char B[51][51] = {0};
    char *lcs;

    cout << "String 1: " << X << endl;
    cout << "String 2: " << Y << endl;

    LCS_Length(X, Y, m, n, B, C);
    cout << "Length of LCS: " << C[m][n] << endl;

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
    for (int i = 1; i <= m; i++) // starting from 1 because 0th row and column are 0s
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%4c", B[i][j]);
        }
        cout << endl;
    }

    lcs = ExtractLCS(X, B, m, n);
    cout << "LCS: " << lcs << endl;

    delete[] lcs; // free allocated memory

    return 0;
}