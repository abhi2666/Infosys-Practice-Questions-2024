/*
Algorithm to find prime numbers in a range..here we will find from 2 to n
Approach -> create a vector with n+1 size where index represent the element ..
start from 2 and mark all the elements that are greater than equal to 2...do this for 3, 5,
till n (only from elements that are not marked).
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 100;
    vector<bool> dp(n + 1, true); // false means that elements are marked
    for (int i = 2;  i <= n; i++)
    {
        if (dp[i] == true)
        {
            // means you can start from this element
            for (int j = i*i; j <= n; j+=i)
            {
                dp[j] = false; // marked
            }
        }
    }
    int cnt = 0;
    // do not include 0, 1 because they are not prime numbers
    for (int i = 2; i < n + 1; i++)
    {
        if (dp[i])
            ++cnt;
    }
    cout << cnt << endl;
    return 0;
}