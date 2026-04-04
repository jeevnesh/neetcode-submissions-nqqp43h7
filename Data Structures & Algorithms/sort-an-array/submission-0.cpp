class Solution {
private:
    void mergeTwoSortedArray(vector<int>& nums, int start, int mid, int end){
        int i = start;
        int j = mid+1;
        vector<int> tempArr;
        while(i <= mid && j <= end){
            if(nums[i] < nums[j]){
                tempArr.push_back(nums[i]);
                i++;
            } else{
                tempArr.push_back(nums[j]);
                j++;
            }
        }
        while(i <= mid){
            tempArr.push_back(nums[i]);
            i++;
        }
        while(j <= end){
            tempArr.push_back(nums[j]);
            j++;
        }
        for(int i = 0 ; i < tempArr.size(); i++){
            nums[start+i] = tempArr[i];
        }
    }
    void mergeSort(vector<int>& nums, int start, int end){
        if(start >= end){
            return;
        }
        int mid = start + (end-start)/2;
        mergeSort(nums,start,mid);
        mergeSort(nums,mid+1,end);
        mergeTwoSortedArray(nums,start,mid,end);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};