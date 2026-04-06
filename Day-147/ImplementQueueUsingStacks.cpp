class MyQueue {
public:
    stack<int> s1, s2;

    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int top = -1;
        if(!s2.empty()) top = s2.top();
        else {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }

            top = s2.top();
        }

        s2.pop();
        return top;
    }
    
    int peek() {
        int top = -1;
        if(!s2.empty()) top = s2.top();
        else {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }

            top = s2.top();
        }

        return top;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};




// Here push required O(n) and top and pop operation required O(1)
// class MyQueue {
// public:
//     void insertAtEnd(stack<int>& s, int element) {
//         if(s.empty()) {
//             s.push(element);
//             return;
//         }

//         int topE = s.top();
//         s.pop();

//         insertAtEnd(s, element);

//         s.push(topE);
//     }

//     stack<int> s;

//     MyQueue() {
        
//     }
    
//     void push(int x) {
//         if(s.empty()) s.push(x);
//         else insertAtEnd(s, x);
//     }
    
//     int pop() {
//         int top = s.top();
//         s.pop();
//         return top;
//     }
    
//     int peek() {
//         return s.top();
//     }
    
//     bool empty() {
//         return s.empty();
//     }
// };