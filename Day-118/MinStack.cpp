class MinStack {
public:
    vector<pair<int, int>> v;

    MinStack() {
        
    }
    
    void push(int val) {
        int min = val;
        if(v.empty()) {
            v.push_back({val, val});
            return;
        }
        min = val < v.back().second ? val : v.back().second;
        v.push_back({val, min});
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v.back().first;
    }
    
    int getMin() {
        return v.back().second;
    }
};