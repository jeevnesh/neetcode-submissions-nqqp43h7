class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<char>> rows(10, vector<char>(10, '.'));
        vector<vector<char>> cols(10, vector<char>(10, '.'));
        vector<vector<char>> boxes(10, vector<char>(10, '.'));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int boxIndex = 3 * (i / 3) + (j / 3);
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                if (rows[i][num] != '.' || cols[j][num] != '.' || boxes[boxIndex][num] != '.')
                    return false;
                rows[i][num] = 'x';
                cols[j][num] = 'x';
                boxes[boxIndex][num] = 'x';
            }
        }
        return true;
    }
};
