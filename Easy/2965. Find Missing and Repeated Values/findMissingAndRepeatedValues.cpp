class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            vector<bool> found(grid.size() * grid.size() + 1, false);
            vector<int> res;
            for (vector<vector<int>>::iterator i = grid.begin(); i != grid.end();
                i++) {
                for (vector<int>::iterator j = i->begin(); j != i->end(); j++) {
                    if (found[*j]) {
                        res.push_back(*j);
                    }
                    found[*j] = true;
                }
            }
            for (int idx = 1; idx < found.size(); ++idx) {
                if (!(found[idx])) {
                    res.push_back(idx);
                    return res;
                }
            }
            return res;
        }

        vector<int> findMissingAndRepeatedValues_math(vector<vector<int>>& grid) {
            long long sum = 0, sqrSum = 0;
            long long total = grid.size() * grid.size();

            // Calculate actual sum and squared sum from grid
            for (vector<vector<int>>::iterator i = grid.begin(); i != grid.end();
                i++) {
                for (vector<int>::iterator j = i->begin(); j != i->end(); j++) {
                    sum += (*j);
                    sqrSum += static_cast<long long>(*j) * (*j);
                }
            }

            long long sumDiff = sum - total * (total + 1) / 2;
            long long sqrDiff = sqrSum - total * (total + 1) * (2 * total + 1) / 6;

            int repeat = (sqrDiff / sumDiff + sumDiff) / 2;
            int missing = (sqrDiff / sumDiff - sumDiff) / 2;

            return {repeat, missing};
        }
    };