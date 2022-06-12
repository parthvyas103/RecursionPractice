class Solution {
public:
    void solve(vector<vector<int>> &res, vector<int> curr, int target, vector<int> &candidates, int i){
        if(target == 0){
            res.push_back(curr);
            return;
        }
        if(target < 0) return;
        if(i == candidates.size())
            return;
        solve(res, curr, target, candidates, i+1);
        curr.push_back(candidates[i]);
        solve(res, curr, target-candidates[i],candidates, i);
        curr.pop_back();
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        solve(res, curr, target, candidates, 0);
        return res;
    }
};
