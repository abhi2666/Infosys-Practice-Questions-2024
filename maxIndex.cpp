/*
Input:
n = 9
arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
Output: 
6

Approach -> form two arrays that store min element from left and max element from right..
at last traverse them to get the result..
*/

class Solution{
public:
    int maxIndexDiff(int a[], int n) {
        vector<int>mn(n), mx(n);
        mn[0] = a[0];
        mx[n-1] = a[n-1];
        for(int i = 1; i < n; i++){
            mn[i] = min(mn[i-1], a[i]);
            mx[n-i-1] = max(mx[n-i], a[n-i-1]);
        }
        // now compare them
        int i = 0, j = 0, ans = 0;
        while(i < n && j < n){
            if(mx[j] >= mn[i]){
                ans = max(ans, j-i);
                j++;
            }
            else i++;
        }
        return ans;
    }

};