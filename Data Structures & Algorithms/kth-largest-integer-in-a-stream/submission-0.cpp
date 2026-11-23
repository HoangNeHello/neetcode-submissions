class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int n : nums) {
            minHeap.push(n);
        }
    }
    
    int add(int val) {
        int len = minHeap.size();

        minHeap.push(val);

        for (int i=0; i<=len-k; i++) {
            minHeap.pop(); // Should return the kth largest
        }

        return minHeap.top();
    }

private: 
    priority_queue<int, vector<int>, greater<int>> minHeap; // priority_queue is maxHeap by default, so we switch it
    int k; // Need the k to be stored globally for add(val) function
};
