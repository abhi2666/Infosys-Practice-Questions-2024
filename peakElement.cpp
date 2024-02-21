/*
Approach  --> array before the peak element is sorted in ascending order and after the peak element in descending order so to get to the peak element we will use this logic 

Check if the a[mid] > a[mid - 1] or a[mid] > a[mid+1] to find the left or right side of the array
*/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        // check for corner elements seperately
        // for leetcode version.. it is guranteed that the peak element will never be the first or last element and also there will be only one peak element.
        int low = 1, high = a.size()-2, mid;
        while(low <= high){
            mid = (low + high)/2;
            if(a[mid] > a[mid + 1] && a[mid] > a[mid - 1]) return mid;
            else if(a[mid] > a[mid-1]) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};