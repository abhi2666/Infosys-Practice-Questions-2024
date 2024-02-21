/*
Approach is to use map to keep track of the distinct element you got at ay moment and if it exceeds the k then just remove the elements from the start.
*/
class Solution {
private:
    int solve(vector<int>&nums, int k){
        int count = 0;
        int i = 0, j = 0, n = nums.size();
        unordered_map<int, int>mp; // ele and freq
        while(j < n){
            mp[nums[j]]++;
            while(mp.size() > k){
                // move i to remove elements
                mp[nums[i]]--;
                if(mp[nums]==0) mp.erase(nums[i]);
                i++;
            }
            // put the count of subarrays that are formed
            count += j - i + 1;
            j++;
        }
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};