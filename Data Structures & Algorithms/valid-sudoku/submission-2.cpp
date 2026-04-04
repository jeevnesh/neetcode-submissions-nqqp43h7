class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            vector<int> rows(10,0);
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                if(rows[num]){
                    return false;
                } 
                rows[num] = 1;
            }
        }
        for(int j = 0; j < 9; j++){
            vector<int> cols(10,0);
            for(int i = 0; i < 9; i++){
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                if(cols[num]){
                    return false;
                }
                cols[num] = 1;
            }
        }
        for(int i = 0; i < 9; i = i+3){
            for(int j = 0; j < 9; j = j + 3){
                vector<int> box(10,0);
                for(int k = i; k < i+3; k++){
                    for(int l = j; l < j+3; l++){
                        if(board[k][l] == '.') continue;
                        int num = board[k][l] - '0';
                        if(box[num]){
                            return false;
                        }
                        box[num] = 1;
                    }
                }
            }
        }
        return true;
    }
};
