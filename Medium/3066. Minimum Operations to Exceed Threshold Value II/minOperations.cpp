#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        u_int x = 0, y = 0, size, index, rightChild, smallest;
        size = nums.size();
        for (; y < size; ++y) {
            if (nums[y] < k) {
                nums[x++] = nums[y];
            }
        }
        nums.resize(x);
        size = x;
        make_heap(nums.begin(), nums.end(), greater<int>());
        x = 0;
        while (size > 1) {

            y = nums.front() * 2;
            pop_heap(nums.begin(), nums.end(), greater<int>());
            nums.pop_back();

            y += nums.front();

            if (y < k) {
                nums.front() = y;
                size--;
                index = 0;
                while (true) {
                    rightChild = 2 * index + 2;
                    smallest = rightChild - 1;

                    if (rightChild < size &&
                        nums[rightChild] < nums[smallest]) {
                        smallest = rightChild;
                    }

                    if (smallest >= size || nums[smallest] >= y) {
                        break;
                    }

                    nums[index] = nums[smallest];
                    index = smallest;
                }

                nums[index] = y;
            } else {
                pop_heap(nums.begin(), nums.end(), greater<int>());
                nums.pop_back();
                size -= 2;
            }
            x++;
        }
        if (nums.size() == 1) {
            x++;
        }
        return x;
    }
};