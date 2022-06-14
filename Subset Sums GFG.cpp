class Solution
{
public:
    void solve(vector<int> &arr, vector<int> &res, int i, int sum){
        if(i == arr.size()){
            res.push_back(sum);
            return;
        }
        sum += arr[i];
        solve(arr, res, i+1, sum);
        sum -= arr[i];
        solve(arr, res, i+1, sum);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> res;
        solve(arr, res, 0, 0);
        return res; 
    }
};
