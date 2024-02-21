int solve(int idx, int target, vector<int> &a)
{
    if (target == 0)
        return 1;
    if (idx == 0)
        return (a[idx] == target) ? 1 : 0;

    int notTaken = solve(idx - 1, target, a);
    int taken = 0;
    if (a[idx] <= target)
    {
        taken = solve(idx - 1, target - a[idx], a);
    }
    return taken + notTaken;
}
int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    return solve(n, k, arr);
}

