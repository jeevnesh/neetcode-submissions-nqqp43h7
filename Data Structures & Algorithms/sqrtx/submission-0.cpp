class Solution {
   private:
    int sqrt(int start, int end, int x, int ans) {
        if (start > end) return ans;
        int mid = start + (end - start) / 2;
        long long square = 1LL * mid * mid;
        if (square == x)
            return mid;
        else if (square < x) {
            return sqrt(mid + 1, end, x, mid);
        } else {
            return sqrt(start, mid - 1, x, ans);
        }
    }

   public:
    int mySqrt(int x) {
        if (x < 2) return x;
        return sqrt(1, x / 2, x, 0);
    }
};