class Solution {
   private:
    bool binarySearch(int start, int end, int n, vector<vector<int>>& matrix, int target) {
        if (start > end) return false;
        int mid = start + (end - start) / 2;
        int rowIndex = mid / n;
        int colIndex = mid % n;
        if (matrix[rowIndex][colIndex] == target)
            return true;
        else if (matrix[rowIndex][colIndex] < target) {
            return binarySearch(mid + 1, end, n, matrix, target);
        } else {
            return binarySearch(start, mid - 1, n, matrix, target);
        }
    }

   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        return binarySearch(0, m * n - 1, n, matrix, target);
    }
};
