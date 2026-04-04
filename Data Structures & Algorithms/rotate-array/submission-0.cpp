class Solution {
private:
    void rotateHelper(vector<int>& nums, int left, int right) {
        while(left <= right){
            swap(nums[left],nums[right]);
            left++;
            right--;
        }
    } 
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        rotateHelper(nums,0,n-1);
        rotateHelper(nums,0,k-1);
        rotateHelper(nums,k,n-1);
    }
};