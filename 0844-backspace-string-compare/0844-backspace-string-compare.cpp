class Solution {
public:

    string buildString(string str)
    {
        string res="";

        for(auto const &ch:str)
        {
            if(ch=='#')
            {
                if(res.size()>0)
                {
                    res.pop_back();
                }
            }
            else
            {
                res+=ch;
            }
        }

        return res;
    }
    bool backspaceCompare(string s, string t) {

        //ab##
    //p1 

        //c#d#
    //p2
        // int p1=s.length()-1, p2=t.length()-1;
        // int backspace_s=0, backspace_t=0;

        // while(p1>=0 || p2>=0)
        // {
        //     while(p1>=0)
        //     {
        //         if(s[p1]=='#')
        //         {
        //             backspace_s++;
        //             p1--;
        //         }
        //         else if(s[p1]!='#' && backspace_s>0)
        //         {
        //             p1--;
        //             backspace_s--;
        //         }
        //         else
        //         {
        //             break;
        //         }
                
        //     }

        //     while(p2>=0)
        //     {
        //         if(t[p2]=='#')
        //         {
        //             backspace_t++;
        //             p2--;
        //         }
        //         else if(t[p2]!='#' && backspace_t>0)
        //         {
        //             p2--;
        //             backspace_t--;
        //         }
        //         else
        //         {
        //             break;
        //         }
        //     }

        //     if(p1>=0 && p2>=0)
        //     {
        //         if(s[p1]==t[p2])
        //         {
        //             p1--;
        //             p2--;
        //         }
        //         else
        //         {
        //             return false;
        //         }
        //     }
        //     else if(p1==-1 && p2==-1)
        //     {
        //         return true;
        //     }
        //     else
        //     {
        //         return false;
        //     }
        // }
        
        // return true;


        return (buildString(s)==buildString(t));
    }
};