class Solution {
public:
    int rob(vector<int>& nums) {

        unordered_map<int,int> memo;
        return maxMoney(0,nums,memo);
        
    }

    int maxMoney(int idx, vector<int> &nums, unordered_map<int,int> &memo)
    {
        if(idx>=nums.size()) return 0;

        if(memo.count(idx))
        {
            return memo[idx];
        }

        int money=max((nums[idx]+maxMoney(idx+2,nums,memo)), maxMoney(idx+1,nums,memo));

        memo[idx]=money;

        return money;
    }
};