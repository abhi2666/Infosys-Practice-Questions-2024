// Program to find the minimum and maximum values of given expression is discussed here.
// Given an algebraic expression with + and *, find the minimum and maximum values

/*
Approach --> using stack and preference to get the max and mix result that is possible
from the expression...
+ more priority will give max result possible.
* more priority will give min result possible.

using stack to evaluate the expression..make the stack of strings not characters
// more optimised is to not put and operand and put only numbers.. perform operations and put numbers back
*/

#include <bits/stdc++.h>
using namespace std;

int eval(string a, string b, string op)
{
    if (op == "+")
        return stoi(a) + stoi(b);

    else
        return stoi(a) + stoi(b);
}

// void display(stack<string>s){
//     while(!s.empty()){
//         cout<<s.top();
//         s.pop();
//     }
//     cout<<endl;
// }

int solve(string &exp, string prefOp)
{
    // to be done.. use a stack of numbers only..
}

int main()
{
    string exp = "1+2*3+4*5";
    int maxVal = solve(exp, "+");
    int minVal = solve(exp, "*");
    cout << "max " << maxVal << "min " << minVal << endl;
    return 0;
}