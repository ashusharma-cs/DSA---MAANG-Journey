class Solution {
public:
    int compress(vector<char>& chars) {

        int slow=0, fast=0;
        int n=chars.size();

        while(fast<chars.size())
        {
            int j=fast;

            while(j<n && chars[j]==chars[fast])
            {
                j++;
            }

            int length=j-fast;

            chars[slow]=chars[fast];
            slow++;

            if(length>1)
            {
                string num=to_string(length);

                for(auto const &digit:num)
                {
                    chars[slow]=digit;
                    slow++;
                }
            }

            fast=j;
        }

        return slow;
        
    }
};