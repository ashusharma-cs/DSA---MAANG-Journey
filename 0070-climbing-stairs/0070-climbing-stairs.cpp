class Solution {
public:
    int climbStairs(int n)
    {
        unordered_map<int,int> memo;

        return climb(n,memo);
    }
    int climb(int n, unordered_map<int,int> &memo) {
        
        //base case
        if(n==1) return 1;
        if(n==2) return 2;

        if(memo.count(n))
        {
            return memo[n];
        }

        int ways=climb(n-1,memo)+climb(n-2,memo);

        memo[n]=ways;

        return ways;
    }
};