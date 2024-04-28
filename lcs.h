#ifndef LCS_H
#define LCS_H

void LCS_Length(const char *X, const char *Y, int m, int n, char B[51][51], int C[51][51]);
void Reverse_String(char *str, int length);
void ExtractLCS(const char *X, char B[51][51], int m, int n, char *lcs);

#endif // LCS_H