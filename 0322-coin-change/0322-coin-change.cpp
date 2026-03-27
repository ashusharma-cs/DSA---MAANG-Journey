class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        unordered_map<int,int> memo;

        int ans=minCoins(amount, coins, memo);

        if (ans >= 10001) return -1;
        return ans;
        
    }

    int minCoins(int amount, vector<int> &coins, unordered_map<int,int> &memo)
    {
        if(amount==0) return 0;
        if(amount<0) return 10001;

        if(memo.count(amount))
        {
            return memo[amount];
        }

        int minNumberCoins=10001;

        for(auto const &coin:coins)
        {
            int currentCoins=1+minCoins(amount-coin,coins,memo);
            minNumberCoins=min(currentCoins,minNumberCoins);
        }

        memo[amount]=minNumberCoins;

        return minNumberCoins;
    }
};