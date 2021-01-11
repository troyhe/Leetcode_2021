class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> bigHeap;
    priority_queue<int, vector<int>, less<int>> smallHeap;
    bool equal;
    // keep bigHeap.size() >= smallHeap
public:
    /** initialize your data structure here. */
    MedianFinder() {
        equal = true;
    }
    
    void addNum(int num) {
        if (bigHeap.empty() || num >= bigHeap.top()){
            bigHeap.push(num);
            if (equal) equal = false;
            else {
                smallHeap.push(bigHeap.top());
                bigHeap.pop();
                equal = true;
            }
        } else {
            smallHeap.push(num);
            if (!equal) equal = true;
            else {
                bigHeap.push(smallHeap.top());
                smallHeap.pop();
                equal = false;
            }
        }
    }
    
    double findMedian() {
        if (!equal) return bigHeap.top();
        return (bigHeap.top() + smallHeap.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
