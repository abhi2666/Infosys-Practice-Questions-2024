/*
given a set of elements partition them into two subsets such that abs differnce 
of them is least and return that difference..

Approach --> you will have to recursively try different combinations that may be 
the answer and out of those find the min one..

2035
*/

class Solution {
private:
    int solve(int idx, int sum, int total, vector<int>&nums){
        if(idx==nums.size()){
            return abs((total-sum) - sum);
        }

        return min(solve(idx+1, sum + nums[idx], total, nums), solve(idx+1, sum, total, nums));
    }
public:
    int minimumDifference(vector<int>& nums) {
        int totalSum = 0;
        for(auto ele : nums) totalSum += ele;
        return solve(0, 0, totalSum, nums);
    }
};