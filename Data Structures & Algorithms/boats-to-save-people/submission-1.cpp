class Solution {
   public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int ans = 0, i = 0, j = people.size() - 1;
        while (i <= j) {
            int sum = people[i] + people[j];
            if (sum <= limit) i++;
            j--;
            ans++;
        }
        return ans;
    }
};