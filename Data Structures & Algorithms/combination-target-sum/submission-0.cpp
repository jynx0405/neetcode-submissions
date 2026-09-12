class Solution {

public:

    void helper(vector<int>& candidates, int target, int idx,
                vector<int>& ds, vector<vector<int>>& result) {

        if(idx == candidates.size()) {

            if(target == 0) {
                result.push_back(ds);
            }

            return;
        }

        // Take the current candidate
        if(candidates[idx] <= target) {

            ds.push_back(candidates[idx]);

            // Stay at the same index because
            // the same candidate can be used again
            helper(candidates, target - candidates[idx],
                   idx, ds, result);

            // Backtrack
            ds.pop_back();
        }

        // Skip the current candidate
        helper(candidates, target, idx + 1,
               ds, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                        int target) {

        vector<vector<int>> result;
        vector<int> ds;

        helper(candidates, target, 0, ds, result);

        return result;
    }
};