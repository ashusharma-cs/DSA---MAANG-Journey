class Solution {
public:

    bool isPossible(vector<int> &bloomDay, int m, int k, long long guessDays)
    {
        int noOfBouquets=0;
        int flowers=0;

        for(auto const &day:bloomDay)
        {
            if(day<=guessDays)
            {
                flowers++;

                if(flowers==k)
                {
                    noOfBouquets++;
                    flowers=0;

                    if(noOfBouquets==m) return true;
                }
            }
            else
            {
                flowers=0;
            }
        }

        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        if((long long) m*k>bloomDay.size()) return -1;

        long long left=*min_element(bloomDay.begin(),bloomDay.end());

        long long right=*max_element(bloomDay.begin(),bloomDay.end());

        long long ans;
        long long mid;

        while(left<=right)
        {
            mid=left+(right-left)/2;

            if(isPossible(bloomDay,m,k,mid))
            {
                ans=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        
        return (int) ans;
    }
};