class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {

        int n=queries.size();
        vector<bool> res;

        for(auto const &query:queries)
        {
            int p1=0, p2=0;
            bool isMatch=true;

            while(p1<query.length() || p2<pattern.length())
            {
                if(p1<query.length() && p2<pattern.length() && query[p1]==pattern[p2]) 
                {
                    p1++;
                    p2++;
                }
                else if(p1<query.length() && isupper(query[p1]))
                {
                    isMatch=false;
                    break;
                }
                else if(p1<query.length() &&!isupper(query[p1]))
                {
                    p1++;
                }
                else
                {
                    isMatch=false;
                    break;
                }
            }

            res.push_back(isMatch);
        }

        return res;
        
    }
};