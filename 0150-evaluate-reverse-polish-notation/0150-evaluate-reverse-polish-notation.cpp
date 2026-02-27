class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        int result;
        stack<int> st;

        for(auto const &token:tokens)
        {
            if(token=="+" || token=="-" || token=="*" || token=="/")
            {
               if(!st.empty())
                {
                    int rightOperand=st.top();
                    st.pop();

                    int leftOperand=st.top();
                    st.pop();
                    if(token=="+")
                    {
                        int sum=leftOperand+rightOperand;
                        st.push(sum);
                    }
                    else if(token=="-")
                    {
                        int diff=leftOperand-rightOperand;
                        st.push(diff);
                    }
                    else if(token=="*")
                    {
                        int prod=leftOperand*rightOperand;
                        st.push(prod);
                    }
                    else
                    {
                        int div=leftOperand/rightOperand;
                        st.push(div);
                    }
                }
            }
            else
            {
                st.push(stoi(token));
            }
        }
        
        if(!st.empty())
        {
            result=st.top();
        }

        return result;
    }
};