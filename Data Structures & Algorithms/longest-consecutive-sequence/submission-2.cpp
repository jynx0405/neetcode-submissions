class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        set<int> s(nums.begin(), nums.end());
        vector<int> num(s.begin(), s.end());

        int len = 1;
        int maxlen = 1;

        for (int i = 1; i < num.size(); i++) {
            if (num[i] == num[i - 1] + 1) {
                len++;
            } else {
                len = 1;
            }
            maxlen = max(maxlen, len);
        }

        return maxlen;
    }
};