class Solution {
public:
    int calPoints(vector<string>& operations) {

        vector<int> res;

        for(auto const &ope:operations)
        {
           if(ope=="+" || ope=="D" || ope=="C")
           {
                if(res.size()>0)
                {
                    if(ope=="+" && res.size()>=2)
                    {
                        int rightOperand=res.back();
                        int leftOperand=res[res.size()-2];

                        int sum=leftOperand+rightOperand;

                        res.push_back(sum);
                    }
                    else if(ope=="D")
                    {
                        int operand=res.back();

                        res.push_back(2*operand);
                    }
                    else
                    {
                        res.pop_back();
                    }
                }
           }
           else
           {
                res.push_back(stoi(ope));
           }
        }

        int total=std::accumulate(res.begin(),res.end(),0);
        
        return total;
    }
};