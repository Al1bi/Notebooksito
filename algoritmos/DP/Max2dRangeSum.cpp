int max_2d_range_sum(vector<vector<int>>& A) {
    int n = A.size();
    vector<vector<int>> prefixSum = A;

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            prefixSum[i][j] += prefixSum[i][j - 1];
        }
    }

    int maxSubRect = -127 * 100 * 100; //Minimum possible value

    for (int l = 0; l < n; ++l) {
        for (int r = l; r < n; ++r) {
            int subRect = 0;   
            // Kadane's by row
            for (int row = 0; row < n; ++row) {
                if (l > 0) subRect += prefixSum[row][r] - prefixSum[row][l - 1];
                else subRect += prefixSum[row][r];
                if (subRect < 0) subRect = 0;
                maxSubRect = max(maxSubRect, subRect);
            }
        }
    }
    return maxSubRect;
}