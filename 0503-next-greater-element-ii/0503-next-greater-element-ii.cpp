class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n=nums.size();

        stack<int> st;
        vector<int> result(n,-1);

        for(int idx=0;idx<=2*n-1;idx++)
        {
            int circularIdx=idx%n;

            while(!st.empty() && nums[circularIdx]>nums[st.top()])
            {
                int waitingIdx=st.top();

                st.pop();

                result[waitingIdx]=nums[circularIdx];
            }

            if(idx<n)
            {

                st.push(circularIdx);
            }
        }
        
        return result;
    }
};