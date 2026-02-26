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

        // int slow=0, fast=0;

        // for(fast;fast<s.length();fast++)
        // {
        //     if(slow>0 && isMatch(s[slow-1], s[fast]))
        //     {
        //         slow--;
        //     }
        //     else
        //     {
        //         s[slow]=s[fast];
        //         slow++;
        //     }
        // }

        // return slow==0;

        stack<int> st;

        for (int idx = 0; idx < s.length(); idx++) {
            if (s[idx] == '{' || s[idx] == '(' || s[idx] == '[') {
                st.push(s[idx]);
            } else {
                if (s[idx] == ')') {
                    // 1. Is the stack empty? (We have a ')' but no opening
                    // bracket ever existed)
                    if (st.empty())
                        return false;

                    // 2. Does the top of the stack match?
                    if (st.top() == '(') {
                        st.pop(); // It's a match! Remove the '(' from the
                                  // stack.
                    } else {
                        return false; // Mismatch! (e.g., top was a '{', but we
                                      // got a ')')
                    }
                } else if (s[idx] == '}') {
                    // 1. Is the stack empty? (We have a ')' but no opening
                    // bracket ever existed)
                    if (st.empty())
                        return false;

                    // 2. Does the top of the stack match?
                    if (st.top() == '{') {
                        st.pop(); // It's a match! Remove the '(' from the
                                  // stack.
                    } else {
                        return false; // Mismatch! (e.g., top was a '{', but we
                                      // got a ')')
                    }
                } else {
                    // 1. Is the stack empty? (We have a ')' but no opening
                    // bracket ever existed)
                    if (st.empty())
                        return false;

                    // 2. Does the top of the stack match?
                    if (st.top() == '[') {
                        st.pop(); // It's a match! Remove the '(' from the
                                  // stack.
                    } else {
                        return false; // Mismatch! (e.g., top was a '{', but we
                                      // got a ')')
                    }
                }
            }
        }

        return (st.empty()?true:false);
    }
};

// what am I trying to do here with a single list?  Items react and destroy each
// other

// ({[]
// s
// f