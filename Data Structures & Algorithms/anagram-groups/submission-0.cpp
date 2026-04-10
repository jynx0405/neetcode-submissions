class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       map<vector<int>,vector<string>> mpp;
       vector<vector<string>> result;
        for(auto str:strs){
            vector<int> v(26,0);
            for(int i=0;i<str.size();i++){
                v[str[i]-'a']++;
            }
            mpp[v].push_back(str);
        }
        for(auto p:mpp){
            result.push_back(p.second);
        }
        return result;

    }
};
