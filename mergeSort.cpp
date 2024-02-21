#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, int low, int mid, int high)
{
    vector<int> temp;
    int left = low, right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (a[left] <= a[right])
        {
            temp.push_back(a[left]);
            left++;
        }
        else
        {
            temp.push_back(a[right]);
            right++;
        }
    }
    // for any element that are left over
    while (left <= mid)
    {
        temp.push_back(a[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(a[right]);
        right++;
    }
    // put back into the array
    for (int i = low; i <= high; i++)
    {
        a[i] = temp[i-low]; // very important
    }
}

void mergeSort(vector<int> &a, int low, int high)
{

    if (low >= high)
        return;
    int mid = (high + low) / 2;
    mergeSort(a, low, mid);
    mergeSort(a, mid + 1, high);
    merge(a, low, mid, high);
}

int main()
{
    vector<int> a = {3, 2, 1, 5, 4};
    cout << "hi" << endl;
    int n = a.size() - 1;
    mergeSort(a, 0, n);
    for (auto ele : a)
        cout << ele << " ";
    return 0;
}