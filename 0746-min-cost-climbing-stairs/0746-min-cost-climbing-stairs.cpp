class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        unordered_map<int,int> memo;
        int topStep=cost.size();
        return minCost(topStep,cost,memo);
        
    }

    int minCost(int n, vector<int> &cost, unordered_map<int,int> &memo)
    {
        // base case
        if(n==0) return 0;
        if(n==1) return 0;

        if(memo.count(n))
        {
            return memo[n];
        }

        int cheapestPath=min(minCost(n-1,cost,memo)+ cost[n-1], minCost(n-2,cost,memo)+cost[n-2]);

        memo[n]=cheapestPath;

        return cheapestPath;
    }
};