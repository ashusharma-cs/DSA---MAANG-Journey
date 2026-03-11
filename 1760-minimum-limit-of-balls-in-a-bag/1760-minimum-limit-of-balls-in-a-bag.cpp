class Solution {
public:

    bool isPossible(vector<int> &nums, int maxOperations, long long guessPenalty)
    {
        int currentOperations=0;

        for(auto const &num:nums)
        {
            if(num>guessPenalty)
            {
                currentOperations+=(num-1)/(int) guessPenalty;

                if(currentOperations>maxOperations) return false;
            }
        }

        return true;

    }
    int minimumSize(vector<int>& nums, int maxOperations) {

        long long left=1, right=*max_element(nums.begin(),nums.end());

        long long ans=right;

        long long mid;

        while(left<=right)
        {
            mid=left+(right-left)/2;

            if(isPossible(nums,maxOperations,mid))
            {
                ans=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }

        return (int) ans;
        
    }
};