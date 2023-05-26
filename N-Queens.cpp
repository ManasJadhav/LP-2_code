#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<string> &board, int row, int col)
{
    int duplicateRow = row;
    int duplicateCol = col;

    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    row = duplicateRow;
    col = duplicateCol;

    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }

    col = duplicateCol;

    while (row < board.size() && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }

    return true;
};

void solve(vector<vector<string>> &ans, vector<string> &board, int n, int col)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 'Q';
            solve(ans, board, n, col + 1);
            board[row][col] = '.';
        }
    }
}

bool isSafeBB(int row, int col, vector<bool> &rows, vector<bool> &ud, vector<bool> &ld, int n)
{
    if (rows[row] == true || ld[row + col] == true || ud[col - row + n - 1] == true)
        return false;
    return true;
};

void solveBB(vector<vector<string>> &ans, vector<string> board, int n, int col, vector<bool> &rows, vector<bool> &ud, vector<bool> &ld)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafeBB(row, col, rows, ud, ld, n))
        {

            rows[row] = true;
            ld[row + col] = true;
            ud[col - row + n - 1] = true;
            board[row][col] = 'Q';
            solveBB(ans, board, n, col + 1, rows, ud, ld);
            board[row][col] = '.';
            rows[row] = false;
            ld[row + col] = false;
            ud[col - row + n - 1] = false;
        }
    }
}

int main()
{
    // Backtracking -
    int n;
    cout << "Enter the size of Board: ";
    cin >> n;
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));

    // solve(ans, board, n, 0);

    // Branch And Bound -

    vector<bool> rows(n, false);
    vector<bool> ud(2 * n - 1, false);
    vector<bool> ld(2 * n - 1, false);

    solveBB(ans, board, n, 0, rows, ud, ld);

    cout << "Number of Solution for the given " << n << " x " << n << " chess board is : \n";

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << "\n";
        }
        cout << "\n";
    }
    return 0;
}