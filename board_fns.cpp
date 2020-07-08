#include "board_fns.hpp"
#include <iostream>
#include <unordered_map>
#include <unordered_set>


using namespace std;

bool is_valid(vector<vector<int>> const &board) 
{
    unordered_map<int, unordered_set<int>> rows;
    unordered_map<int, unordered_set<int>> columns;
    unordered_map<int, unordered_set<int>> squares;
    for (int i = 0; i < board.size(); i++) 
    {
      for (int j = 0; j < board[0].size(); j++) 
      {
        int const &num = board[i][j];
        if (num != 0) 
        {
          int const square_idx = (i / 3 ) * 3 + j / 3;  // squares are 3x3 indexed like so - |_0_|,|_1_|,|_2_|
                                                        //                                   |_3_|,|_4_|,|_5_|
                                                        //                                   |_6_|,|_7_|,|_8_|
          if (rows[i].count(num) != 0 || columns[j].count(num) != 0 || squares[square_idx].count(num) != 0)
            return false; // duplicate found in row/column/square
          rows[i].insert(num);
          columns[j].insert(num);
          squares[square_idx].insert(num);
        }
      }
    }
    return true; // no duplicates found
  }

void print_board(vector<vector<int>> const &board)
{
    for (vector<int> const &row : board)
    {
        for (int const &num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}

pair<int,int> next_open_slot(vector<vector<int>> const &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == 0)
                return make_pair(i, j);
        }
    }
    return make_pair(-1, -1);
}
