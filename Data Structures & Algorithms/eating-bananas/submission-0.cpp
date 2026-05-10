class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //brute force
        int maxPile = *max_element(piles.begin(), piles.end());
        for (int k = 1; k < maxPile; k++) {
            int time = 0;
            for (auto p : piles) {
                time += (p + k - 1) / k;
                if (time > h) break;
            }
            if (time <= h) return k;
        }
        return maxPile;
    }
};
