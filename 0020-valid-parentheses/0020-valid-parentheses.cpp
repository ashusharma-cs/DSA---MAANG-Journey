class Solution {
public:
    // bool isMatch(char left, char right) {
    //     if (left == '(' && right == ')')
    //         return true;
    //     if (left == '{' && right == '}')
    //         return true;
    //     if (left == '[' && right == ']')
    //         return true;

    //     return false;
    // }
    bool isValid(string s) {


       stack<char> st;

       for(auto const &c:s)
       {
            if(c=='(')
            {
                st.push(')');
            }
            else if(c=='{')
            {
                st.push('}');
            }
            else if(c=='[')
            {
                st.push(']');
            }
            else
            {
                if(st.empty() || st.top()!=c)
                {
                    return false;
                }
                else
                {
                    st.pop();
                }
            }
       }

       return (st.empty());
    }
};

// what am I trying to do here with a single list?  Items react and destroy each
// other

// ({[]
// s
// f