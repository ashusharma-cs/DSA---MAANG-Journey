class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {


        int n=nums2.size();
        stack<int> st;
        unordered_map<int,int> mp;
        vector<int> result(nums1.size(),-1);

        for(int idx=0;idx<n;idx++)
        {
            while(!st.empty() && nums2[idx]>st.top())
            {
                int waitingNum=st.top();

                st.pop();

                mp[waitingNum]+=nums2[idx];
            }

            st.push(nums2[idx]);
        }

        for(int idx=0;idx<nums1.size();idx++)
        {
            if(mp.count(nums1[idx]))
            {
                result[idx]=mp[nums1[idx]];
            }
            
        }

        return result;
        
    }
};