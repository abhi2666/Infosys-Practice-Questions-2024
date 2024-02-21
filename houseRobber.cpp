class Solution{
public:
    int houseRobber(int idx, vector<int> &temp, vector<int>&dp)
    {
        if (idx == 0)
            return temp[idx];
        if(idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];
        int take = temp[idx] + houseRobber(idx - 2, temp, dp);
        int notTake = houseRobber(idx - 1, temp, dp);
        return dp[idx] = max(take, notTake);
    }
    int rob(vector<int> &nums)
    {

        int n = nums.size();
        vector<int>dp(n, -1);
        return houseRobber(n-1, nums, dp);
    }

};