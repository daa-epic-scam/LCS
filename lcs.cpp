#include <iostream>
#include "lcs.h"
#include <algorithm>
#include <string>

using namespace std;

// C is the LCS number matrix and B is direction matrix, he used arrows, I'm using D,U,L
void LCS_Length(const string &X, const string &Y, int m, int n, char **B, int **C)
{
    // intialize the first row and col of B and C
    for (int i = 0; i <= m; i++)
    {
        C[i][0] = 0;
        B[i][0] = 'N'; // no direction
    }
    for (int j = 0; j <= n; j++)
    {
        C[0][j] = 0;
        B[0][j] = 'N'; // no direction
    }

    // initialize the rest of B and C as per the subsequence
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

void Reverse_String(string &str)
{
    int start = 0;
    int end = str.length() - 1;
    while (start < end) // iterate from start through end
    {
        // swap the characters at the beginning and end
        char temp = str[start]; 
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

string ExtractLCS(const string &X, char **B, int m, int n)
{
    int i = m, j = n; // building bottom up, starting peeche se
    string lcs = ""; // empty string to concatenate to

    while (i > 0 && j > 0) // stop when we reach the end of one of the strings
    {
        if (B[i][j] == 'D') // concatenate when direction is Diagonal
        {
            lcs += X[i - 1];
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
    Reverse_String(lcs); // reverse the string because it was constructed backwards
    return lcs;
}
