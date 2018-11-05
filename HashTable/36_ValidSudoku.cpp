#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> row;
            unordered_set<char> col;
            unordered_set<char> box;
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (row.count(board[i][j]) != 0)
                        return false;
                    else
                        row.insert(board[i][j]);
                }
                if (board[j][i] != '.') {
                    if (col.count(board[j][i]) != 0)
                        return false;
                    else
                        col.insert(board[j][i]);
                }
                if (board[3*(i/3)+(j/3)][(i%3)*3+(j%3)] != '.') {
                    if (box.count(board[3*(i/3)+(j/3)][(i%3)*3+(j%3)]) != 0)
                        return false;
                    else
                        box.insert(board[3*(i/3)+(j/3)][(i%3)*3+(j%3)]);
                }
            }
        }
        return true;
    }
};