#ifndef LCS_H
#define LCS_H

void LCS_Length(const char *X, const char *Y, int m, int n, char **B, int **C);
void Reverse_String(char *str, int length);
void ExtractLCS(const char *X, char **B, int m, int n, char *lcs);

#endif // LCS_H
