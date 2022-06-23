class Solution {
public:
    void solve(string s, vector<string> &res, string curr, int index){
        if(index == s.size()){
            res.push_back(curr);
            return;
        }    
        if(!isalpha(s[index])){
          curr.push_back(s[index]);
          solve(s, res, curr, index+1);
          return;
        } 
        curr.push_back(tolower(s[index]));
        solve(s, res, curr, index+1);
        curr.pop_back();
        curr.push_back(toupper(s[index]));
        solve(s, res, curr, index+1);
        curr.pop_back();
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        solve(s, res, "", 0);
        return res;
    }
};
