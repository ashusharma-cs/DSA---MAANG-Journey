class Solution {
public:
    int majorityElement(vector<int>& nums) {

        unordered_map<int,int> mp;

        for(int idx=0;idx<nums.size();idx++)
        {
            mp[nums[idx]]++;
        }

        int threshold=nums.size()/2;
        int ans;

        for(auto const &[key,value]:mp)
        {
            if(value>threshold)
            {
                ans=key;
                break;
            }
        }

        return ans;
        
    }
};