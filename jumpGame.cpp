class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dist = 0;
        for(int i = 0; i < nums.size(); i++){
            if(dist < i) return false; // means with your distance you cannot reach the ith index hence will not be able to move forward
            dist = max(dist, i+nums[i]);
        }
        return true;
    }
};