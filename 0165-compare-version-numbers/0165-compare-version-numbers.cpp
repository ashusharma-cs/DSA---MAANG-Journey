class Solution {
public:
    int compareVersion(string version1, string version2) {

        int p1=0, p2=0;
        int res=0;

        while(p1<version1.length() || p2<version2.length())
        {
            int num1=0;
            int num2=0;

            while(p1<version1.length() && version1[p1]!='.')
            {
                num1=num1*10+(version1[p1]-'0');
                p1++;
            }


            while(p2<version2.length() && version2[p2]!='.')
            {
                num2=num2*10+(version2[p2]-'0');
                p2++;
            }

           
            if(num1<num2) return res=-1;
            else if(num1>num2) return res=1;

            p1++;
            p2++;
        }

        return res;
        
    }
};