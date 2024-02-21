// class Solution
// {
// public:
//     int scoreOfParentheses(string s)
//     {
//         int score = 0;
//         stack<char> st;
//         for (auto ele : s)
//         {
//             if (ele == '(')
//                 st.push(ele);
//             else if (ele == ')')
//             {
//                 int val = 1;
//                 if (st.top() == '(')
//                 {
//                     score += val;
//                     st.pop();
//                     st.push(val + '0');
//                 }
//                 else
//                 {
//                     // two cases - either you have only one value or you have two
//                     int x1 = st.top();
//                     st.pop();
//                     int x2 = st.top();
//                     st.pop();
//                     if (x2 == '(')
//                     {
//                         int val = st.top() - '0';
//                         st.pop();
//                         st.pop();
//                         int newVal = 2 * val;
//                         score += newVal;
//                         st.push(newVal + '0');
//                     }
//                     else{
//                         // its a number...add the two numbers put that into set
//                         int newVal = x1 + x2;
//                         st.push(newVal + '0');
//                     }
//                 }
//             }
//         }
//         int ans = st.top()-'0';
//         return ans;
//     }
// };

// working code
class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        stack<string>st;
        for(auto ele : s){
            if(ele == '(') st.push("(");
            else {
                // ) is encountered now add any value that may come before it
                int temp = 0;
                while(st.top() != "("){
                    temp += stoi(st.top());
                    st.pop();
                }
                // now remove the (
                st.pop();
                if(temp==0) {
                    // there was no value bitch
                    st.push("1");
                }
                else{
                    int val = temp*2;
                    st.push(to_string(val));
                }
            }
        }
        while(!st.empty()){
            score += stoi(st.top());
            st.pop();
        }
        return score;
    }
};