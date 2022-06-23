class Solution {
public:
    void solve(vector<string> &res, int open, int close, string curr){
        if(close < open) return;
        if(open == 0 && close == 0){
            res.push_back(curr);
            return;
        }    
        if(open < 0) return; 
        if(close < 0) return;
        solve(res, open-1, close, curr+'(');
        solve(res, open, close-1, curr+')');
    }
    
    vector<string> generateParenthesis(int n) {
        int open = n;
        int close = n;
        vector<string> res;
        solve(res, open, close, "");
        return res;
    }
};
