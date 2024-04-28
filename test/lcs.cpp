#include <iostream>
#include <fstream>
#include <string>
#include "lcs.h"

using namespace std;

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
