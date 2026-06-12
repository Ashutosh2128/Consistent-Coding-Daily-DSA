class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    double median;

    MedianFinder() {
        median = 0;
    }
    
    void addNum(int num) {
        // 3 possibility can be possible
        // case 1: both heap size is same
        if(maxHeap.size() == minHeap.size()) {
            if(num > median) {
                minHeap.push(num);
                median = minHeap.top();
            }
            else {
                maxHeap.push(num);
                median = maxHeap.top();
            }
        }
        // case 2: maxHeap is one size greater than minHeap
        else if(maxHeap.size() == minHeap.size() + 1) {
            if(num > median) {
                // put in right side simply
                minHeap.push(num);
                median = (maxHeap.top() + minHeap.top()) / 2.0;
            }
            else {
                // put in left side but before that offload one element from maxHeap to minHeap
                int topE = maxHeap.top();
                maxHeap.pop();

                minHeap.push(topE);
                maxHeap.push(num);
                median = (maxHeap.top() + minHeap.top()) / 2.0;
            }
        }
        // case 3 minHeap is one size greater than maxHeap
        else if(maxHeap.size() + 1 == minHeap.size()) {
            if(num > median) {
                // put in right side but before that offload one element from minHeap to maxHeap
                int topE = minHeap.top();
                minHeap.pop();

                maxHeap.push(topE);
                minHeap.push(num);
                median = (maxHeap.top() + minHeap.top()) / 2.0;
            }
            else {
                // put in left side simply
                maxHeap.push(num);
                median = (maxHeap.top() + minHeap.top()) / 2.0;
            }
        }
    }
    
    double findMedian() {
        return median;
    }
};