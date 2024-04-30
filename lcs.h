#ifndef LCS_H
#define LCS_H

using namespace std;

void LCS_Length(const string &X, const string &Y, int m, int n, char **B, int **C);
void Reverse_String(string &str, int length);
string ExtractLCS(const string &X, char **B, int m, int n);

#endif // LCS_H
