#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums){
    int count = 0;
    int prefixSum = 0;
    for(auto ele : nums){
        prefixSum += ele;
        int root = (int)sqrt(prefixSum);
        if(root*root==prefixSum) ++count;
    }
    // now remove elements and check
    for(int i = 0; i < nums.size(); i++){
        prefixSum -= nums[i];
        int root = (int)sqrt(prefixSum);
        if(root*root==prefixSum) ++count;
    }
}

int main() {
    vector<int> nums = {1, 4, 3, 2};
    cout << solve(nums)<<endl;
    return 0;
}
