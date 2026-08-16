class Solution {
private:
    void rotateArray(vector<int>& nums, int start, int end){
        while(start < end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) return;
        k = k % n;
        int i = 0, j = nums.size()-1;
        rotateArray(nums, i, j);
        rotateArray(nums, i, k-1);
        rotateArray(nums, k, j);
    }
};