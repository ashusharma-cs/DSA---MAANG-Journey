class BrowserHistory {

private:

    stack<string> backStack;
    stack<string> forwardStack;
    string currentPage;

public:

    
    BrowserHistory(string homepage) {
        
        currentPage=homepage;
    }
    
    void visit(string url) {
        
        // put the currentPage in the backStack
        backStack.push(currentPage);

        // update the currentPage to new url
        currentPage=url;

        // empty the forwardStack(create a new timeline)
        forwardStack=stack<string>();
    }
    
    string back(int steps) {

        // currentPage goes to the forward stack
        // pop the top from the backStack and update current Page

        while(steps>0 && !backStack.empty())
        {
            forwardStack.push(currentPage);
            string lastURL=backStack.top();

            currentPage=lastURL;

            backStack.pop();

            steps--;
        }

        return currentPage; 
    }
    
    string forward(int steps) {

        // currentPage goes to the backStack
        // pop the top from the forwardStack and update the currentPage

        while(steps>0 && !forwardStack.empty())
        {
            backStack.push(currentPage);

            string nextURL=forwardStack.top();

            currentPage=nextURL;

            forwardStack.pop();

            steps--;
        }

        return currentPage;
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */