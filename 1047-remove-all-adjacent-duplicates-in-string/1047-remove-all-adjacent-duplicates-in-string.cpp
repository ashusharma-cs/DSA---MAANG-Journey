class Solution {
public:
    string removeDuplicates(string s) {

        // int slow=0, fast=0;

        // for(fast;fast<s.length();fast++)
        // {
        //     if(slow>0 && s[fast]==s[slow-1])
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

        string str="";

        for(auto const &c:s)
        {
            if(str.empty())
            {
                str+=c;
            }
            else
            {
                if(str.back()==c)
                {
                    str.pop_back();
                }
                else
                {
                    str+=c;
                }
            }
        }
        
        return str;
    }

    //cabaca
    //  s
    //     f
};