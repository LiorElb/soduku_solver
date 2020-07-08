#include <iostream>
#include <string>
#include <vector>
#include "board_fns.hpp"

using namespace std;

bool solve(vector<vector<int>> &board)
{
    pair<int,int> const &location = next_open_slot(board);
    int const &i = location.first;
    int const &j = location.second;
    if (i == -1)
    {
        return true;
    }

    for(int k = 1; k <= 9; k++)
    {
        board[i][j] = k;
        if (is_valid(board) && solve(board))
            return true;
    }
    board[i][j] = 0;
    return false;   
}

int main()
{
    vector<vector<int>> board =
    {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    print_board(board);
    cout << endl << "Solving..." << endl << endl;
    solve(board);
    print_board(board);
}