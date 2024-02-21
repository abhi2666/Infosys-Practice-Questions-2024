/*
Approach -> using two pointers approach to pick the right set of elements by fixing two elements
each time
*/
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            while (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n; j++)
            {
                while (j > i +1 && nums[j] == nums[j - 1]) continue;
                int k = j + 1, l = n - 1;
                while (k < l)
                {
                    long long int sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if (sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        // now move k and l so as to not pick any duplicates
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (l > k && nums[l] == nums[l + 1])
                            l--;
                    }
                    else if (sum < target)
                        k++;
                    else
                        l--;
                }
            }
        }
        return ans;
    }
};

