
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        vector<int>ans;
        while(i < m && j < n){
            if(nums1[i] < nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while(i < m){
            ans.push_back(nums1[i++]);
        }
        while(j < n){
            ans.push_back(nums2[j++]);
        }
        nums1.clear();
        nums1 = ans;
    }
};

/*
Another approach would be to use the extra space at the end that is given and put the max element there.. easily possible with the help of basic traversing..just compare elements and put the greater one at the last  
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n - 1, k = m + n - 1;
        while(j >= 0){
            if(i >= 0 && nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--];
            }
            else{
                nums1[k--] = nums1[j--];
            }
        }      
    }
};