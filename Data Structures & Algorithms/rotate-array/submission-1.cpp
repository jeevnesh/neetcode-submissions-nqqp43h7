class Solution {
private:
    void rotateHelper(vector<int>& nums, int start, int end){
        while(start < end){
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int i = 0, n = nums.size(), j = n-1;
        k = k % n;
        rotateHelper(nums,i,j);
        rotateHelper(nums,i,k-1);
        rotateHelper(nums,k,j);
    }
};