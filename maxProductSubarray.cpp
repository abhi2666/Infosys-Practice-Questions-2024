class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int suffixProd = 1, prefixProd = 1;
        int ans = 0, n = nums.size();
        if(n == 1) return nums[0];
        for(int i = 0; i < nums.size(); i++)
        {
            // if you encounter zero then restart the prefix/sufix
            if(prefixProd == 0) prefixProd = 1;
            if(suffixProd == 0) suffixProd = 1;
            prefixProd = prefixProd * nums[i];
            suffixProd = suffixProd * nums[n-1-i];
            ans = max(ans, max(prefixProd, suffixProd));
        }
        return ans;
    }
};