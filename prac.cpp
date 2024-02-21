class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>result;
        int k, l;
        for(int i = 0; i < nums.size(); i++)
        {
            // skip repeating element 
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            for(int j = i+1; j < nums.size(); j++)
            {
                // skip repeating element
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                k = j+1, l = nums.size()-1;
                while(k < l)
                {
                    long long int sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target){
                        vector<int>ans = {nums[i], nums[j], nums[k], nums[l]};
                       
                        result.push_back(ans);
                        k++;
                        l--;
                        // now skip any repeating element
                        while(k < l && nums[k] == nums[k-1]) k++;
                        while(l > k && nums[l] == nums[l +1]) l--;
                    }
                    else if(sum < target) k++;
                    else l--;

                }

            }
        }
        return result;
    }
};