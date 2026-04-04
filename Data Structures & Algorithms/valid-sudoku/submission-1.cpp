class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            unordered_set<char> rows;
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.' && rows.find(board[i][j]) != rows.end()){
                    return false;
                } else if (board[i][j] != '.'){
                    rows.insert(board[i][j]);
                }
            }
        }
        for(int j = 0; j < 9; j++){
            unordered_set<char> cols;
            for(int i = 0; i < 9; i++){
                if(board[i][j] != '.' && cols.find(board[i][j]) != cols.end()){
                    return false;
                } else if (board[i][j] != '.'){
                    cols.insert(board[i][j]);
                }
            }
        }
        for(int i = 0; i < 9; i = i+3){
            for(int j = 0; j < 9; j = j + 3){
                unordered_set<char> box;
                for(int k = i; k < i+3; k++){
                    for(int l = j; l < j+3; l++){
                        if(board[k][l] != '.' &&  box.find(board[k][l]) != box.end()){
                            return false;
                        } else if (board[k][l] != '.'){
                            box.insert(board[k][l]);
                        } 
                    }
                }
            }
        }
        return true;
    }
};
