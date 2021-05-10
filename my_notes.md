# 05-09-2021 第一次使用markdown做笔记
## Amazon 电面准备
### 目前不知道电面时间，只知道存在电面  
### 准备思路：  
1. 记录准备过程和思路，随时调整计划。  
2. 刷题，限定刷题量，目前计划是每天8题，4道取自花花刷题，4道取自当前高频题。
3. 复习c++ STL DFS, BFS, Tree, Graph, PQ, Stack
4. 早起锻炼身体，让自己具备体力和精力
5. 注意休息时间和饮食计划配套。

## 刷题记录： 05-09-2021
### 重新开了leetcode session，周日晚终于开始刷题，先来1道：
#### 346. Moving Average from Data Stream
#### tag: Amazon Queue Design
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.  
Implement the MovingAverage class:  
``MovingAverage(int size)`` Initializes the object with the size of the window size.  
``double next(int val)`` Returns the moving average of the last size values of the stream.
 
```c++
class MovingAverage {
public:
    /** Initialize your data structure here. */
    
    vector<double> sum; //注意sum 是double
    int id, size;
    
    // why size + 1?
    // because we want the rotation to be "size"
    MovingAverage(int size) : sum(size + 1, 0) { 
        id = 0;
        this->size = size;
    }
    
    int mod (int x) {
        return x % (size + 1);
    }
    
    //finish the code part without rotation
    //then add in mod function and replace ''id'' with ''mod(id)''
    double next(int val) {
        id++;
        sum[mod(id)] = sum[mod(id - 1)] + val;
        if (id - size >= 0) { // current id is out of size window
            return (sum[mod(id)] - sum[mod(id - size)]) / size;
        } else {
            return sum[mod(id)] / id; //when id is smaller than size window
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
 ```
 