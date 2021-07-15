Amazon-vo-bank.md
# 07-15 2021
# find median from data stream
``` c++
class MedianFinder {
    priority_queue <int> maxHeap;
    priority_queue <int, vector<int>, greater<int> > minHeap;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || maxHeap.top() > num) {
            maxHeap.push(num);
        }
        else {
            minHeap.push(num);
        }
        
        //balance
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            if (maxHeap.empty()) {
                return 0;
            }
            else {
                double med = (maxHeap.top() + minHeap.top()) /2.0;
                return med;
            }
        }
        
        else {
            return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```

# 07-15 2021
# meeting room II
```c++
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // sort the meetings by starting time. 
        // we start by creating rooms for the meetings and putting them in a heap
        // minHeap of their finish times.
        // whenever a new meeting is seen, we check the top of the heap, if
        // it is supposed to be finished before this meeting starts, then we can
        // occupy the same room. In that case, just let that meeting finish (pop the
        // heap min) and insert this meeting.
        // If the earliest finishing meeting is after this meeting could start, we 
        // need a new room. In that case, when we add another meeting, we check the
        // number of rooms currently required.
        sort(intervals.begin(), intervals.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (auto v : intervals) {
            // check if the last meetings need to be completed
            // before this meeting starts.
            if (!pq.empty() && pq.top() <= v[0]) {
                pq.pop();
            }
            
            // start this meeting and enter the end time.
            pq.push(v[1]);
        }
        
        return pq.size();
    }
};
```