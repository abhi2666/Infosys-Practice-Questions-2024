#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int exp; // intial experience
    cin >> exp;
    vector<int> power(n), bonus(n);
    for (int i = 0; i < n; i++)
        cin >> power[i];
    for (int i = 0; i < n; i++)
        cin >> bonus[i];
    // create a vector pair of power and bonus
    vector<pair<int, int>> temp;
    for (int i = 0; i < n; i++)
        temp.push_back({power[i], bonus[i]});
    sort(temp.begin(), temp.end());
    int defeatedMonsters = 0;
    for (auto it : temp)
    {
        if (it.first <= exp)
        {
            exp += it.second;
            ++defeatedMonsters;
        }
    }

    cout << defeatedMonsters << endl;

    return 0;
}