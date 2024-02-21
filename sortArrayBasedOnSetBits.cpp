/*
Approach -> you have to write a comp for the sort function that sort the elements based on the number of set bits they have in ascending order.

you can write a logic to get the set bits of a number or you can use a builtin function for this purpose also called __buitlin_popcount() to find the number of set bits in the number..
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 15;
    cout<<__builtin_popcount(n)<<endl;
    return 0;
}

class Solution {
private:
    static int comp(int a, int b){
        int setBits_A = __builtin_popcount(a);
        int setBits_B = __builtin_popcount(b);
        if(setBits_A < setBits_B) return true;
        else if(setBits_A==setBits_B){
            if(a < b) return true;
        }
        return false;
    }
public:
    vector<int> sortByBits(vector<int>& a) {
        sort(a.begin(), a.end(), comp);
        return a;
    }
};