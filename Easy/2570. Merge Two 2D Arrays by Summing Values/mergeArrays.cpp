class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                        vector<vector<int>>& nums2) {
            vector<vector<int>> mergedArray;
            // mergedArray.reserve(max(nums1.size(), nums2.size()));
            int i = 0, j = 0;
    
            while (i < nums1.size() || j < nums2.size()) {
                if (i < nums1.size() && j < nums2.size() &&
                    nums1[i][0] == nums2[j][0]) {
                    nums1[i][1] += nums2[j][1];
                    mergedArray.push_back(move(nums1[i]));
                    i++;
                    j++;
                } else if (j == nums2.size() ||
                           (i < nums1.size() && nums1[i][0] < nums2[j][0])) {
                    mergedArray.push_back(move(nums1[i]));
                    i++;
                } else {
                    mergedArray.push_back(move(nums2[j]));
                    j++;
                }
            }
            return mergedArray;
        }
        vector<vector<int>> mergeArrays2(vector<vector<int>>& nums1,
                                         vector<vector<int>>& nums2) {
            if (nums1.size() < nums2.size()) {
                nums1.swap(nums2);
            }
            queue<vector<int>> auxQueue;
            int i = 0, j = 0;
            while (i < nums1.size() || j < nums2.size() || !auxQueue.empty()) {
                if (i < nums1.size()) {
                    auxQueue.push(move(nums1[i]));
                    if (j == nums2.size() || auxQueue.front()[0] < nums2[j][0]) {
                        nums1[i] = move(auxQueue.front());
                        auxQueue.pop();
                    } else if (auxQueue.front()[0] == nums2[j][0]) {
                        auxQueue.front()[1] += nums2[j][1];
                        nums1[i] = move(auxQueue.front());
                        auxQueue.pop();
                        j++;
                    } else {
                        nums1[i] = move(nums2[j]);
                        j++;
                    }
                } else {
                    if (!auxQueue.empty()) {
                        if (j == nums2.size() ||
                            auxQueue.front()[0] < nums2[j][0]) {
                            nums1.push_back(move(auxQueue.front()));
                            auxQueue.pop();
                        } else if (auxQueue.front()[0] == nums2[j][0]) {
                            auxQueue.front()[1] += nums2[j][1];
                            nums1.push_back(move(auxQueue.front()));
                            auxQueue.pop();
                            j++;
                        } else {
                            nums1.push_back(move(nums2[j]));
                            j++;
                        }
                    } else {
                        nums1.push_back(move(nums2[j]));
                        j++;
                    }
                }
                i++;
            }
            return move(nums1);
        }
    };