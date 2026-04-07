class MyStack {
public:
    queue<int> q;

    MyStack() {
        
    }
    
    void push(int x) {
        if(q.empty()) q.push(x);
        else {
            q.push(x);
            int size = q.size() - 1;
            for(int i = 0; i < size; i++) {
                int front = q.front();
                q.pop();
                q.push(front);
            }
        }
    }
    
    int pop() {
        int front = q.front();
        q.pop();
        return front;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};