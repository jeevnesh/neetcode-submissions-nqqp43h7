class Solution {
private:
    int partition(vector<int>& nums, int start, int end){
        int pivot = nums[end];
        int i = start-1;
        int j = start;
        while(j < end){
            if(nums[j] < pivot){
                i++;
                swap(nums[i],nums[j]);
            }
            j++;
        }
        swap(nums[i+1], nums[end]);
        return i+1;
    }
    void quickSort(vector<int>& nums, int start, int end){
        if(start >= end){
            return;
        }
        int pivot = partition(nums,start,end);
        quickSort(nums,start,pivot-1);
        quickSort(nums,pivot+1,end);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums,0,nums.size()-1);
        return nums;
    }
};