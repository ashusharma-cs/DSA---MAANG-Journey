class Solution {
public:
    string decodeString(string s) {

        stack<int> numStack;
        stack<string> strStack;

        int currentNum=0;
        string currentStr="";

        for(auto const &ch:s)
        {
            if(ch=='[')
            {
                numStack.push(currentNum);
                strStack.push(currentStr);

                currentNum=0;
                currentStr="";
            }
            else if(isalpha(ch))
            {
                currentStr+=ch;
            }
            else if(ch==']')
            {
                if(!numStack.empty())
                {
                    int k=numStack.top();
                    numStack.pop();

                    string repeatedStr="";
                    for(int i=0;i<k;i++)
                    {
                        repeatedStr+=currentStr;
                    }

                    if(!strStack.empty())
                    {
                        string previousStr=strStack.top();

                        currentStr=previousStr+repeatedStr;

                        strStack.pop();
                    }
                }
            }
            else
            {
                currentNum=currentNum*10+(ch-'0');
            }
        }

        return currentStr;
        
    }
};