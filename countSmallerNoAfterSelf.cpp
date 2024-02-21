class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i = n-1; i >= 0; i--){
            while(st.size() > 0 && st.top() > nums[i]) st.pop();
            if(st.size()==0) ans[i] = 0;
            else ans[i] = st.size();
            st.push(nums[i]);
        }
        return ans;
    }
};