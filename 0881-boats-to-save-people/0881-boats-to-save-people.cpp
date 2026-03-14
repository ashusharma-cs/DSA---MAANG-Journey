class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        sort(people.begin(),people.end());

        int left=0, right=people.size()-1;
        int boats=0;
        
        while(left<=right)
        {
            long long weight=people[left]+people[right];

            if(weight<=limit)
            {
                left++;
                right--;
                boats++;
            }
            else
            {
            

                if(people[right]<=limit)
                {
                    boats++;
                    
                }
                right--;
            }
        }

        return boats;
        
    }
};