class Solution {
    public:
        int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
            vector<vector<short>> dist(arr.size(), vector<short>(arr.size(),-1));
            for (int i = 0; i < arr.size() - 1; ++i) {
                for (int j = i + 1; j < arr.size(); j++) {
                    if (arr[i] > arr[j]) {
                        dist[i][j] = arr[i] - arr[j];
                    } else {
                        dist[i][j] = arr[j] - arr[i];
                    }
                }
            }
            int count = 0;
            for (int i = 0; i < arr.size() - 2; ++i) {
                for (int j = i + 1; j < arr.size() - 1; j++) {
                    if (dist[i][j] <= a) {
                        for (int k = j + 1; k < arr.size(); k++) {
                            if (dist[j][k] <= b && dist[i][k] <= c) {
                                count++;
                            }
                        }
                    }
                }
            }
            return count;
        }
    };