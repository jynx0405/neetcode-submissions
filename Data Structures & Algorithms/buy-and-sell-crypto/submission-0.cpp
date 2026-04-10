class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_cost=0;
        int cost=0;
        for(int i=0;i<prices.size();i++){
            for(int j=i+1;j<prices.size();j++){
                max_cost=max(max_cost,prices[j]-prices[i]);
            }
        }
        return max_cost;
    }
};
