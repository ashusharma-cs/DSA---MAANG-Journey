class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        // int result;
        // stack<int> st;

    //     for(auto const &token:tokens)
    //     {
    //         if(token=="+" || token=="-" || token=="*" || token=="/")
    //         {
    //            if(st.size()>=2)
    //             {
    //                 int rightOperand=st.top();
    //                 st.pop();

    //                 int leftOperand=st.top();
    //                 st.pop();
    //                 if(token=="+")
    //                 {
    //                     int sum=leftOperand+rightOperand;
    //                     st.push(sum);
    //                 }
    //                 else if(token=="-")
    //                 {
    //                     int diff=leftOperand-rightOperand;
    //                     st.push(diff);
    //                 }
    //                 else if(token=="*")
    //                 {
    //                     int prod=leftOperand*rightOperand;
    //                     st.push(prod);
    //                 }
    //                 else
    //                 {
    //                     int div=leftOperand/rightOperand;
    //                     st.push(div);
    //                 }
    //             }
    //         }
    //         else
    //         {
    //             st.push(stoi(token));
    //         }
    //     }
        
    //     if(!st.empty())
    //     {
    //         result=st.top();
    //     }

    //     return result;
    // }

    stack<int> st;
    
    for(auto const &token:tokens)
    {
        if(token!="+"&&token!="-" && token!="*" && token!="/")
        {
            st.push(stoi(token));
        }
        else
        {
            if(!st.empty())
            {
                int num2=st.top();
                st.pop();
                int num1=st.top();
                st.pop();
                
                
                if(token=="+")
                {
                    int sum=num1+num2;
                    st.push(sum);
                }
                else if(token=="-")
                {
                    int diff=num1-num2;
                    st.push(diff);
                }
                else if(token=="*")
                {
                    int prod=num1*num2;
                    st.push(prod);
                }
                else
                {
                    int quotient=num1/num2;
                    st.push(quotient);
                }
            }
        }
    }
    
    return st.top();
    }
};