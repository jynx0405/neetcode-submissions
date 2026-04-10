class Solution {
public:

    string encode(vector<string>& strs) {
        char sep = '₹';   
        string res = "";
        
        for (auto &s : strs) {
            res += s;
            res += sep;
        }
        return res;
    }

    vector<string> decode(string s) {
        char sep = '₹';
        vector<string> res;
        string val = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != sep) {
                val += s[i];
            } else {
                res.push_back(val);
                val = "";
            }
        }

        return res;   
    }
};