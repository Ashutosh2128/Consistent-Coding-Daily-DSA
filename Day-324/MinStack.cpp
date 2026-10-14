class MinStack {
public:
    vector<pair<int, int>> st;

    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()) st.push_back({value, value});
        else {
            int min = st.back().second > value ? value : st.back().second;
            st.push_back({value, min});
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */











 // class MinStack {
// public:
//     stack<int> st;
//     int min = INT_MAX;

//     void getMinimum() {
//         if(st.empty()) return;

//         int topE = st.top();
//         st.pop();

//         min = min > topE ? topE : min;
//         getMinimum();

//         st.push(topE);
//     }

//     MinStack() {
        
//     }
    
//     void push(int value) {
//         st.push(value);
//         min = min > value ? value : min;
//     }
    
//     void pop() {
//         if(st.top() == min) {
//             st.pop();
//             min = INT_MAX;
//             getMinimum();
//         }
//         else st.pop();
//     }
    
//     int top() {
//         return st.top();
//     }
    
//     int getMin() {
//         if(min == INT_MAX) getMinimum();
//         return min;
//     }
// };