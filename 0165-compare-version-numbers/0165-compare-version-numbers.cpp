class Solution {
public:
    int compareVersion(string version1, string version2) {

        int p1=0, p2=0;
        int res=0;

        while(p1<version1.length() || p2<version2.length())
        {
            string num1="";
            string num2="";

            while(p1<version1.length() && version1[p1]!='.')
            {
                num1+=version1[p1];
                p1++;
            }


            while(p2<version2.length() && version2[p2]!='.')
            {
                num2+=version2[p2];
                p2++;
            }

            if(num1.empty())
            {
                num1='0';
            }

            if(num2.empty())
            {
                num2='0';
            }
            int n1=stoi(num1);
            int n2=stoi(num2);

            if(n1<n2) return res=-1;
            else if(n1>n2) return res=1;

            p1++;
            p2++;
        }

        return res;
        
    }
};