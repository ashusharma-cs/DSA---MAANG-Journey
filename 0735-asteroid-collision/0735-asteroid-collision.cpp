class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        vector<int> res;

        for(auto const &asteroid: asteroids)
        {
            if(asteroid>0)
            {
                res.push_back(asteroid);
            }
            else
            {
                bool survived=true;
                while(res.size()>=1 && res[res.size()-1]>0)
                {
                    int num=res.back();

                    if(num<abs(asteroid))
                    {
                        res.pop_back();
                        survived=true;
                    }
                    else if(num>abs(asteroid))
                    {
                        survived=false;
                        break;
                    }
                    else
                    {
                        res.pop_back();
                        survived=false;
                        break;
                    }
                }

                if(survived) res.push_back(asteroid);
            }
        }

        return res;
        
    }
};