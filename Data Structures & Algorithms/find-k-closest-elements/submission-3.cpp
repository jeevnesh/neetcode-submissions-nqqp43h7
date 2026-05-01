class Solution {
private:
    int binarySearch(vector<int>& arr, int num){
        int left = 0, right = arr.size();
        while(left < right){
            int mid = left + (right-left)/2;
            if(arr[mid] < num){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return left;
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int insertionIndex = binarySearch(arr,x);
        int left = insertionIndex - 1, right = insertionIndex;
        while(k > 0){
            if(left < 0){
                right++;
            }else if(right >= n){
                left--;
            }else if(abs(x-arr[left]) <= abs(x-arr[right])){
                left--;
            }else{
                right++;
            }
            k--;
        }
        return vector<int>(arr.begin()+left+1,arr.begin()+right);
    }
};