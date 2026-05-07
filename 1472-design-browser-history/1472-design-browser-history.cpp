class BrowserHistory {
public:

    stack<string> backStack;
    stack<string> forwardStack;
    string currentPage;

    BrowserHistory(string homepage) {

        currentPage=homepage;
    }
    
    void visit(string url) {

        backStack.push(currentPage);

        currentPage=url;

        forwardStack=stack<string>();
        
    }
    
    string back(int steps) {

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

        while(steps>0 && !forwardStack.empty())
        {
            backStack.push(currentPage);
            string lastURL=forwardStack.top();

            currentPage=lastURL;

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