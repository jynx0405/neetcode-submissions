class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        map<char,int> mpp_t;
        bool one_subarray_found =false;
        string res="";
        int len=0;

        for(int i=0;i<t.size();i++){
            mpp_t[t[i]]++;
        }

        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                map<char,int> mpp_sub_s;

                for(int k=i;k<=j;k++){
                    mpp_sub_s[s[k]]++;
                }

                bool a_value_not_found=false;

                for(auto e:mpp_t){
                    if(mpp_sub_s[e.first] < e.second) {   
                        a_value_not_found=true;
                        break;
                    }
                }

                if(a_value_not_found) continue;  

                string ans="";
                for(int k=i;k<=j;k++){
                    ans+=s[k];
                }

                if(one_subarray_found){
                    res=(ans.size()<res.size())?ans:res;
                }
                else{
                    res=ans;
                    one_subarray_found = true;  
                }
            }
        }
        return res;
    }
};