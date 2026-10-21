class BrowserHistory {
public:

    stack<string> currentHistory ;
    stack<string> forwardHistory ;

    BrowserHistory(string homepage) {
        currentHistory = stack<string>() ;
        forwardHistory = stack<string>();

        currentHistory.push(homepage);

    }
    
    void visit(string url) {
        currentHistory.push(url);

        while(!forwardHistory.empty()) {
            forwardHistory.pop();
        }
    }
    
    string back(int steps) {
        while(steps>0) {
            if(currentHistory.size()>1) {
                string backTab = currentHistory.top();
                currentHistory.pop();
                forwardHistory.push(backTab);
            }

            else {
                break ;
            }
            steps--;
        }
        return currentHistory.top();
    }
    
    string forward(int steps) {
         while(steps>0) {
            if(forwardHistory.size()>0) {
                string forwardTab = forwardHistory.top();
                forwardHistory.pop();
                currentHistory.push(forwardTab);
            }

            else {
                break ;
            }
            steps--;
        }

        return currentHistory.top() ;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */