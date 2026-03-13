class Solution {
public:
    int maxArea(vector<int>& height) {

        int left=0,right=height.size()-1;
        long long maxArea=0;

        while(left<right)
        {
            int length=min(height[left],height[right]);

            int base=right-left;

            long long area=length*base;

            maxArea=max(maxArea,area);

            if(height[left]<height[right])
            {
                left++;
            }
            else if(height[right]<height[left])
            {
                right--;
            }
            else
            {
                left++;
            }


        }

        return (int) maxArea;
        
    }
};