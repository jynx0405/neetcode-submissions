class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> freq(128,0);

        for(char c : t)
            freq[c]++;

        int l = 0;
        int r = 0;

        int need = t.size();

        int minLen = INT_MAX;
        int start = 0;

        while(r < s.size()){

            freq[s[r]]--;
            if(freq[s[r]] >= 0)
                need--;

            r++;

            while(need == 0){

                if(r - l < minLen){
                    minLen = r - l;
                    start = l;
                }

                freq[s[l]]++;

                if(freq[s[l]] > 0)
                    need++;

                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};