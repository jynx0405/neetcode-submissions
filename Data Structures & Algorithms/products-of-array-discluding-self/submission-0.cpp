class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long total_prod = 1;
        int j=-1,zero_cnt=0;
        for(int i=0;i<nums.size();i++){
            total_prod*=nums[i];
            if(nums[i]==0){
                zero_cnt++;
                j=i;
            }
        }
        if(zero_cnt>=2){
            vector<int> v(nums.size(),0);
            return v;
        }
        else if(zero_cnt==1){
            vector<int> v(nums.size(),0);
            long long mul=1;
            for(int i=0;i<j;i++){
                mul*=nums[i];
            }
            for(int i=j+1;i<nums.size();i++){
                mul*=nums[i];
            }
            v[j]=mul;
            return v;
            
        }
        else{
            vector<int> v(nums.size(),0);
            for(int i=0;i<nums.size();i++){
                v[i]=total_prod/nums[i];
            }
            return v;
            
        }
    }
};
