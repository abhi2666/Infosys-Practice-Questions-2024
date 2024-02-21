// very chutiya approach -- may not work
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "1000101011";
    int cnt = 0;
    for (int i = 0; i < s.size() - 1;)
    {
        if (s[i] == s[i + 1])
        {
            ++cnt;
            i += 2;
        }
        else
        {
            ++i;
        }
    }

    cout << cnt << endl;
    return 0;
}