class Solution {
public:
    int tribonacci(int n) {

        unordered_map<int,int> memo;

        return trib(n,memo);
    }

    int trib(int n, unordered_map<int,int> &memo)
    {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;

        if(memo.count(n))
        {
            return memo[n];
        }

        int sum=trib(n-1,memo)+trib(n-2,memo)+trib(n-3,memo);

        memo[n]=sum;

        return sum;
    }
};