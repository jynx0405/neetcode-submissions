class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0;
        int r=heights.size()-1;
        int water=0;
        int max_water=0;
        while(l<r){
            water=(r-l)*min(heights[l],heights[r]);
            max_water=max(water,max_water);
            if(heights[l]>heights[r]){
                r--;
            }
            else{
                l++;
            }
        }
        return max_water;
    }
};
