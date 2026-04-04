class NestedIterator {

    queue<int> q;
    void flatten(vector<NestedInteger>& nestedList) {
        for(auto item: nestedList) {
            if(item.isInteger()) q.push(item.getInteger());
            else flatten(item.getList());
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
    }
    
    int next() {
        int front = q.front();
        q.pop();
        return front;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};