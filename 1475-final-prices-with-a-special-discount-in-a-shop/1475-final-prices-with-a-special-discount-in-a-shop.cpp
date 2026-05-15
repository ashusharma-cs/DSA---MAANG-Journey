class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {

        stack<int> st;
        vector<int> result(prices.size());

        for(int idx=0;idx<prices.size();idx++)
        {
            while(!st.empty() && prices[idx]<=prices[st.top()])
            {
                int waitingIndex=st.top();
                int price=prices[waitingIndex];
                int discount=price-prices[idx];
                st.pop();
                result[waitingIndex]=discount;
            }

            st.push(idx);
        }

        while(!st.empty())
        {
            int idx=st.top();
            result[idx]=prices[idx];
            st.pop();
        }
        
        return result;
    }
};