class Solution {
public:
    
    bool isValid(vector<vector<char>> &board, int i, int j, char c){
        int row = i - i %3; int column = j - j % 3;
        for(int x = 0; x < 9; x++) if(board[i][x] == c) return false;
        for(int y = 0; y < 9; y++) if(board[y][j] == c) return false;
        for(int x=0; x<3; x++)
        for(int y=0; y<3; y++)
        if(board[row+x][column+y] == c) return false;
        return true;
    }
    
    bool solve(vector<vector<char>> &board, int i, int j){
        if(i == 9) return true;
        if(j == 9) return solve(board, i+1, 0);
        if(board[i][j] != '.') return solve(board, i, j+1);
        
        for(char c = '1'; c <= '9'; c++){
            if(isValid(board, i, j, c)){
                board[i][j] = c;
                if(solve(board, i, j+1)) return true;
                board[i][j] = '.';
            }
        }
        
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
        return;
    }
};
