class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        

        int n=temperatures.size();
        vector<int> result(n,0);
        stack<int> st;

        for(int idx=0;idx<n;idx++)
        {
            while(!st.empty() && temperatures[idx]>temperatures[st.top()])
            {
                int waitingIndex=st.top();

                st.pop();

                result[waitingIndex]=idx-waitingIndex;
            }

            st.push(idx);
        }

        return result;
    }
};