int merge(vector<int> &a, int low, int mid, int high)
{
    int cnt = 0;
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
            // means left is greater
            cnt += (mid - left + 1);
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
        a[i] = temp[i - low]; // very important
    }
    return cnt;
}

int mergeSort(vector<int> &a, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return 0;
    int mid = (high + low) / 2;
    cnt += mergeSort(a, low, mid);
    cnt += mergeSort(a, mid + 1, high);
    cnt += merge(a, low, mid, high);
    return cnt;
}

int numberOfInversions(vector<int> &a, int n)
{
    return mergeSort(a, 0, n - 1);
}