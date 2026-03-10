class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        long long left=0, right=nums.size()-1;

        long long idx=-1;
        long long mid;

        while(left<=right)
        {
            mid=left+(right-left)/2;

            if(nums[mid]==target)
            {
                idx=mid;
                break;
            }
            else if(nums[mid]<target)
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }

        return (idx==-1?left:idx);
        
    }
};