class MinStack {

private:
    
    stack<long long> mainStack;
    long long minVal;
    // stack<int> minStack;

public:
    MinStack() {
        
        
    }
    
    void push(int val) {
        
        // mainStack.push(val);

        // if(!minStack.empty())
        // {
        //     int num=minStack.top();

        //     int minimum=min(val,num);

        //     minStack.push(minimum);
        // }
        // else
        // {
        //     minStack.push(val);
        // }
        long long v=val;
        if(mainStack.empty())
        {
            mainStack.push(v);
            minVal=v;
        }
        else
        {
            if(v<minVal)
            {
                mainStack.push(2*v-minVal);
                minVal=v;
            }
            else
            {
                mainStack.push(v);
            }
        }
    }
    
    void pop() {
        
        // if(!mainStack.empty())
        // {
        //     mainStack.pop();

        //     minStack.pop();
        // }

        if(!mainStack.empty())
        {
            if(mainStack.top()<minVal)
            {
                minVal=2*minVal-mainStack.top();

                mainStack.pop();
            }
            else
            {
                mainStack.pop();
            }
        }
    }
    
    int top() {
        
        if(!mainStack.empty())
        {
           if(mainStack.top()>minVal)
           {
                return mainStack.top();
           }
           else
           {
                return minVal;
           }
        }
        
        return -1;
    }
    
    int getMin() {
        
        return (int) minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */