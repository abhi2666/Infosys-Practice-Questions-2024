/*
Approach -> since list is sorted, use binary search. before your element even-odd placement of elements will take place and after the single element, odd-even positioning will prevail.. use this to find the single element using binary search

0 1 2 3 4 5 6 7 8 9 10
1 1 2 2 3 4 4 5 5 6 6 
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-2] != nums[n-1]) return nums[n-1];
        int low = 1, high = nums.size()-2, mid;
        while(low <= high){
            mid = (low + high)/2;
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid + 1]) return nums[mid];
            else if(mid%2 && nums[mid-1]==nums[mid] || mid%2==0 && nums[mid]==nums[mid+1]){
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return -1;
    }
};