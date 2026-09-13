class Solution {
public:
    int hammingWeight(uint32_t n) {
        int i=0,count=0;
        while(i<32){
            if(n%2==1) count++;
            n=n>>1;
            i++;
        }
        return  count;
    }
};
