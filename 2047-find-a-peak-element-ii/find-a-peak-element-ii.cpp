class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int maxEl = INT_MIN;
            int maxCol = -1;
            for (int j = 0; j < m; j++) {
                if (mat[mid][j] > maxEl) {
                    maxEl = mat[mid][j];
                    maxCol = j;
                }
            }
            int upper = (mid > 0) ? mat[mid - 1][maxCol] : -1;
            int lower = (mid < n - 1) ? mat[mid + 1][maxCol] : -1;
            if (maxEl > upper && maxEl > lower) {
                return {mid, maxCol};
            } else if (upper > maxEl) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};