class Solution {
public:
    int fib(int n) {
        int first = 0, second = 1, next;
        while(n--){
            next = first+second;
            first = second;
            second = next;
        }
        return first;
    }
};