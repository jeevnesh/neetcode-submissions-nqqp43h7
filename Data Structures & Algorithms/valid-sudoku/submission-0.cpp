class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& nums) {
        //check for row
        for(int i = 0 ; i < nums.size(); i++){
            unordered_set<char> seen;
            for(int j = 0 ; j < nums[j].size(); j++){
                if(nums[i][j] != '.' && !seen.insert(nums[i][j]).second){
                    return false;
                }
            }
        }
        //check for column
        for(int j = 0 ; j < nums[0].size(); j++){
            unordered_set<char> seen;
            for(int i = 0 ; i < nums.size(); i++){
                if(nums[i][j] != '.' && !seen.insert(nums[i][j]).second){
                    return false;
                }
            }
        }
        //check for subBox
        for(int row = 0 ; row < 9; row += 3){
            for(int col = 0 ; col < 9; col += 3){
                unordered_set<char> seen;
                for(int i = row ; i < row + 3; i++){
                    for(int j = col ; j < col + 3; j++){
                        if(nums[i][j] != '.' && !seen.insert(nums[i][j]).second){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
