class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> maxHeap;

        maxHeap.push(a);
        maxHeap.push(b);
        maxHeap.push(c);

        int count = 0;

        while(maxHeap.size() > 1) {
            int first = maxHeap.top();
            maxHeap.pop();
            int second = maxHeap.top();
            maxHeap.pop();

            count++;
            first--;
            second--;

            if(first >= 1) maxHeap.push(first);
            if(second >= 1)maxHeap.push(second);
        }

        return count;
    }
};