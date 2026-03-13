class Solution {
public:

    bool isPossible(vector<int> &nums, int threshold, long long guessDivisor)
    {
        long long currentSum=0;

        for(auto const &num:nums)
        {
            currentSum+=((num+guessDivisor)-1)/guessDivisor;
        }

        return(currentSum<=threshold);
    }
    int smallestDivisor(vector<int>& nums, int threshold) {

        long long left=1;
        long long right=*max_element(nums.begin(),nums.end());

        long long ans;
        long long mid;

        while(left<=right)
        {
            mid=left+(right-left)/2;

            if(isPossible(nums,threshold,mid))
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