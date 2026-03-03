class Solution {
public:
    string removeStars(string s) {
        
        string str="";

        for(auto const &ch:s)
        {
            if(ch!='*')
            {
                str+=ch;
            }
            else
            {
                if(str.length()>0)
                {
                    str.pop_back();
                }
            }
        }

        return str;
    }
};