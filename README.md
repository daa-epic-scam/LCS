# Longest Common Subsequence (LCS) Algorithm

This project implements the Longest Common Subsequence (LCS) algorithm, which finds the length of the longest subsequence that is common to two given strings.

## Problem Description

Given two strings `s1` and `s2`, the task is to find the length of the longest subsequence that is common to both strings. A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements.

For example, if `s1 = "ABCBDAB"` and `s2 = "BDCABA"`, the longest common subsequence is `"BCBA"`, and its length is `4`.


## Usage
Compile the file by typing `g++ main.cpp` in the terminal. You can specify your input in a `input.txt` file within the `input` directory and provide the name of the file inside the `main` function in `main.cpp`.

The first line of the `input.txt` file contains the first string, while the second line contains the second string.

**Note:** You can use any name for the input file, but make sure the name is correct in `main.cpp` before running the code.

## Time Complexity
Let X = x<sub>1</sub>, x<sub>2</sub>, ..., x<sub>m</sub> be the first input string of length m

Let Y = y<sub>1</sub>, y<sub>2</sub>, ..., y<sub>n</sub> be the second input string of length n

1. **Step 1 (Characterization of an LCS)** involves understanding the optimal substructure of the LCS problem, which is a constant-time operation.

2. **Step 2 (Recursively defining the length of an LCS)** involves defining the recursive formula for the length of the LCS, which is also a constant-time operation.

3. **Step 3 (Computing the length of LCS)** has a nested loop that runs m * n times, and the operations inside the loop are constant time. Therefore, the time complexity of this step is O(mn).

4. **Step 4 (Extracting the LCS)** takes O(m + n) time in the worst case, as it traverses through the table B of size (m+1) x (n+1) in a zigzag fashion.

Since Step 3 dominates the overall time complexity, the overall time complexity of the LCS algorithm is **O(mn)**.

## Space Complexity

The space complexity of the LCS algorithm is O(mn).

1. The algorithm uses a 2D table B of size (m+1) x (n+1) to store the direction information ('↖', '↑', '←') for extracting the LCS.

2. Additionally, the algorithm uses another 2D table C of size (m+1) x (n+1) to store the lengths of LCSs of all subproblems.

Therefore, the total space complexity is **O(mn)** to store these two 2D tables.


