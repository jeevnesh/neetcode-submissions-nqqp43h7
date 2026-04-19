class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> rows(9);
        vector<unordered_set<int>> cols(9);
        vector<unordered_set<int>> boxes(9);
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0';
                    if(rows[i].find(num) != rows[i].end()) return false;
                    if(cols[j].find(num) != cols[j].end()) return false;
                    int boxIndex = (i/3)*3+(j/3);
                    if(boxes[boxIndex].find(num) != boxes[boxIndex].end()) return false;
                    rows[i].insert(num);
                    cols[j].insert(num);
                    boxes[boxIndex].insert(num);
                }
            }
        }
        return true;
    }
};
