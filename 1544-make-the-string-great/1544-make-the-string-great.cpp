class Solution {
public:
    string makeGood(string s) {

        // int slow=0, fast=0;
        // //leEeetcode
        // // s
        // //     f

        // for(fast;fast<s.length();fast++)
        // {
        //     if(slow>0 && abs(s[fast]-s[slow-1])==32)
        //     {
        //         slow--;
        //     }
        //     else
        //     {
        //         s[slow]=s[fast];
        //         slow++;
        //     }
        // }
        
        // return s.substr(0, slow);

        string result="";

        for(auto const &ch:s)
        {
            if(!result.empty() && abs(result.back()-ch)==32)
            {
                result.pop_back();
            }
            else
            {
                result+=ch;
            }
        }

        return result;
    }
};