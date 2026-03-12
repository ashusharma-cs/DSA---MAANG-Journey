class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {

        string resString="";
        // set<string> st;
        int maxLength=0;

        for(auto const &word:dictionary)
        {
            if(word.length()>s.length()) continue;
            
            int p1=0, p2=0;

            while(p1<word.length() && p2<s.length())
            {
                if(word[p1]==s[p2])
                {
                    p1++;
                    p2++;
                }
                else
                {
                    p2++;
                }
            }

            if(p1==word.length())
            {
                int length=word.length();
                
                if(maxLength<length)
                {
                    maxLength=length;
                    resString=word;
                    
                }
                else if(maxLength==length)
                {
                    if(word<resString)
                    {
                        resString=word;
                    }
                }
            }
        }

        return resString;
        
    }
};