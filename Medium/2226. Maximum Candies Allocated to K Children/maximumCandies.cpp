class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        //sort(candies.begin(), candies.end());
        int left = 0, right;
        for (int i = 0; i < candies.size(); i++) {
            right = max(right, candies[i]);
        }

        
        int middle;
        long long num_kids;
        vector<int>::reverse_iterator c;
        while (left < right) {
            middle = ((right + left + 1) / 2);
            //cout << left << " " << middle << " " << right << endl;
            num_kids = 0;
            c = candies.rbegin();
            while (c != candies.rend() && num_kids < k) {
                num_kids += *c / middle;
                c++;
            }
            if (num_kids >= k) {
                left = middle;
            } else {
                right = middle - 1;
            }
        }
        return left;
    }
};