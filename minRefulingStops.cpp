/*
Input: target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
Output: 2
Explanation: We start with 10 liters of fuel.
We drive to position 10, expending 10 liters of fuel.  We refuel from 0 liters to 60 liters of gas.
Then, we drive from position 10 to position 60 (expending 50 liters of fuel),
and refuel from 10 liters to 50 liters of gas.  We then drive to and reach the target.
We made 2 refueling stops along the way, so we return 2.

Approach --> how can you take the least numbers of stations there is? by the picking the stations with the most gas present.. so we will use priority queue to do this (max-heap)..

Also when picking a station we have to check also if we can reach there or not..
*/

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int total = 0, n = stations.size();
        int count = 0, i = 0; // number of stations visited
        priority_queue<int, vector<int>>pq;
        while(total < target){ // keep on trying different stations 
            total += startFuel;
            startFuel = 0;
            if(total >= target) return count;
            while(i < n && total >= stations[i][0]) pq.push(stations[i++][1]); // putting the gas present at all the reachable stations inside the pq.. pq will make the max gas at the top which we will eventually pick
            if(pq.empty()) return -1; // you cannot reach any station with the total(fuel) you have
            startFuel = pq.top(); // now this is your new fuel
            pq.pop(); // station's fuel is exhausted fuck it off
            ++count; // one new station is added 
        }
        return count;
    }
};