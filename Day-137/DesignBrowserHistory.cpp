class BrowserHistory {
    stack<string> browserStack;
    stack<string> forwardStack;
public:
    BrowserHistory(string homepage) {
        browserStack.push(homepage);
    }
    
    void visit(string url) {
        while(!forwardStack.empty()) forwardStack.pop();
        browserStack.push(url);
    }
    
    string back(int steps) {
        while(steps--) {
            if(browserStack.size() > 1) {
                forwardStack.push(browserStack.top());
                browserStack.pop();
            }
            else break;
        }

        return browserStack.top();
    }
    
    string forward(int steps) {
        while(steps--) {
            if(!forwardStack.empty()) {
                browserStack.push(forwardStack.top());
                forwardStack.pop();
            }
            else break;
        }

        return browserStack.top();
    }
};