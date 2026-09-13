#include<unordered_set>
#include<unordered_map>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>>row; 
        unordered_map<int, unordered_set<char>>col;
        map<pair<int, int>, unordered_set<char>>sq;
        for(int r=0; r<board.size(); r++){
            for(int c=0; c<board[r].size(); c++){
                if(board[r][c]=='.') continue;
                pair<int, int>sqkey = {r/3, c/3};
                if(row[r].count(board[r][c]) || col[c].count(board[r][c]) || sq[sqkey].count(board[r][c])) return false;
                row[r].insert(board[r][c]);
                col[c].insert(board[r][c]);
                sq[sqkey].insert(board[r][c]);
            }
        }
        return true;
    }
};
