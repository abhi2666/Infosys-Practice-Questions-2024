class Solution {
private:
    void solve(int open, int close, int n, string temp, vector<string>&ans){
        if(open==n && close==n){
            ans.push_back(temp);
            return;
        }
        // there is no restriction of how to pick open just make sure it is less than n
        if(open < n){
            solve(open+1, close, n, temp+'(', ans);
        }
        // when picking close make sure that no. of open '(' are more always
        if(open > close) solve(open, close+1, n, temp+')', ans);
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(0, 0, n, "", ans);
        return ans;
    }
};