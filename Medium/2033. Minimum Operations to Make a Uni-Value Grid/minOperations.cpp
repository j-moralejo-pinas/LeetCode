class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            // vector<int> elems;
            // elems.reserve(grid.size() * grid[0].size());
            // sort(elems.begin(), elems.end());
            // int median = elems[elems.size() / 2];
    
            int low = INT_MAX, high = INT_MIN;
            int m = grid[0][0] % x;
            for (const vector<int>& row : grid) {
                for (const int& cell : row) {
                    if (cell % x != m) return -1;
                    low = min(low, cell);
                    high = max(high, cell);
                }
            }
    
            int half_matrix_size = (grid.size() * grid[0].size() + 1) / 2;
    
            int median;
            int count, closest_median, closest_above_median;
    
            while (low != high) {
                count = 0;
                median = (low + high) / 2;
                closest_median = low;
                closest_above_median = high;
                for (const vector<int>& row : grid) {
                    for (const int& cell : row) {
                        if (cell <= median) {
                            closest_median = max(closest_median, cell);
                            count++;
                        } else {
                            closest_above_median = min(closest_above_median, cell);
                        }
                    }
                }
                if (count < half_matrix_size) {
                    low = closest_above_median;
                } else {
                    high = closest_median;
                }
            }
            count = 0;
            for (vector<int>& row : grid) {
                for (int& cell : row) {
                    count += abs((cell-low) / x);
                }
            }
            return count;
        }
    };