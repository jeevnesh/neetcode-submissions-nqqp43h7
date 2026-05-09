/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
   private:
    int binarySearch(long long start, long long end) {
        if (start > end) return -1;
        long long mid = start + (end - start) / 2;
        int retValue = guess(mid);
        if (retValue == -1) {
            return binarySearch(start, mid - 1);
        } else if (retValue == 1) {
            return binarySearch(mid + 1, end);
        }
        return mid;
    }

   public:
    int guessNumber(int n) { return binarySearch(1, n); }
};