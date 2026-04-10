class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        map<char,int> mpp;

        for(int l = 0, r = 0; r < s.size();) {
            
            if(mpp.find(s[r]) != mpp.end()) {
                mpp.erase(s[l]);
                l++;
            }
            else {
                mpp[s[r]]++;
                maxlen = max(maxlen, r - l + 1);
                r++;
            }
        }

        return maxlen;
    }
};