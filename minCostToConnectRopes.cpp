/*
Approach --> to get the min cost to connecting the ropes you will have to connect the parts of the ropes with the least length and keep on doing that..this way you will get the least cost always..use min heap to solve this problem..
*/

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long a[], long long n) {
        long long cost = 0;
        pirority_queue<long long, vector<long long>, greater<long long>>pq;
        for(int i = 0; i < n; i++){
            pq.push(a[i]);
        }

        while(pq.size() > 1){
            long long tmp1 = pq.top();
            pq.pop();
            tmp1 += pq.top();
            pq.pop();
            const += tmp1;
            pq.push(tmp1);
        }
        return const;

    }
};
