class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int count = 0, element = INT_MIN;
        for (auto i : nums) {
            if (count == 0) {
                element = i;
            }
            if (i == element)
                count++;
            else
                count--;
        }
        return element;
    }
};