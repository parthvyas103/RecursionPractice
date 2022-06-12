class Solution {
public:
    void solve(vector<vector<int>> &res, vector<int> curr, vector<int> &candidates, int target, int cursum, int i){
        if(target == 0){
            res.push_back(curr);
            return;
        }
        if(target < 0) return;
        if(i == candidates.size())
            return;
        
        solve(res, curr, candidates, target, cursum, i+1);
        curr.push_back(candidates[i]);
        cursum += candidates[i];
        solve(res, curr, candidates, target, cursum, i+1);
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        solve(res, curr, candidates, target, 0, 0);
        return res;
    }
};
