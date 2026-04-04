class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i = 0, n = arr.size();
        vector<int> ans;
        while(i+k<n){
            if(x-arr[i] > arr[i+k]-x){
                i++;
            }else{
                break;
            }
        }
        for(int j = i; j < i+k; j++){
            ans.push_back(arr[j]);
        }
        return ans;
    }
};