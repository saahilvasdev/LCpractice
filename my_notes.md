# c++ stl practice :https://www.hackerrank.com/domains/cpp/stl/page/1
# system design
## Grokking the System Design Interview https://www.educative.io/courses/grokking-the-system-design-interview?affiliate_id=5749180081373184/
## [经验总结] 一篇文章解决所有system design面试 https://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=559285&extra=page%3D1%26filter%3Dtypeid%26typeid%3D1025%26typeid%3D1025
## 学习如何设计大型系统 https://github.com/donnemartin/system-design-primer/blob/master/README-zh-Hans.md

# OOD
## [经验总结] 稍微讲两句关于OOD的闲话吧。。关于怎么学，扯淡，以及怎么用 https://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=176958&extra=page%3D1%26filter%3Dtypeid%26typeid%3D1025%26typeid%3D1025

# 刷题记录
## 05-09-2021 第一次使用markdown做笔记
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
 ## 刷题记录： 05-10-2021
 ### 今天预约了面试时间,希望定在五月24,这样还有两周时间.
 #### 学习了 How Your Amazon Interview Examples Are Assessed- Inside Info From A Bar Raiser
 #### https://www.youtube.com/watch?v=2JL4lQUhp0E
 #### 工作占用时间太多了！
 #### 98. Validate Binary Search Tree
 #### O(n) time, O(h) space
 1. 思路：left less than cur, right greater than cur.
 2. cur is the max of all left, cur is the min of all right
 3. tail recursion
 4. deal with INT_MAX, INT_MIN, NULL as inputs
 ```c++
 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root->left && !root->right)
            return true;
        return isValidBST(root, NULL, NULL);
    }
```
    
```c++
    // int* cur_max is an int pointer, aka address.
    // int* cur_min is an int pointer.
    // hence we can pass in INT_MAX and INT_MIN without any problem:
    // we didn't compare them to default INT_MAX INT_MIN, because defaults dont exist.
    bool isValidBST(TreeNode* root, int* cur_max, int* cur_min) {
        if (root == nullptr)
            return true;
        
        if ( (cur_max && root->val >= *cur_max) || ( cur_min && root->val <= *cur_min ) )
            return false;
        return isValidBST(root->left, &(root->val), cur_min) && isValidBST(root->right, cur_max, &(root->val) );
    }
};
```
**使用指针来代替值，这样初始值不存在，就没有INT_MAX INT_MIN作为输入的困扰**

## 刷题记录： 05-16-2021
### LC 16. 3SUM
#### O(n^2) time
#### O(1) space
```c++
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //because we are returning sum, we can sort the array/vector
        sort(nums.begin(), nums.end());
        
        int diff = INT_MAX;
        int sz = nums.size();
        
        for (int i = 0; i < sz && diff != 0; i++) {
            int lo = i+1, hi = sz -1;
            
            while (lo < hi) {
                int sum = nums[i] + nums[lo] + nums[hi];// current 
                if (abs(target - sum) < abs(diff)) {
                    diff = target - sum; //update diff
                }
                if (sum < target)
                    lo ++;
                else // sum >= target
                    hi --;
            }
        }
        
        return target - diff;
        
    }
};
```

### LC 28. Implement strStr()
#### 返回第一个出现str的位置，注意重复的就不要了。
```c++
class Solution {
public:
    int strStr(string haystack, string needle) {
        //return 0 if needle is empty
        if(needle == "")
            return 0;
        
        int ind = -1;
        
        for (int j = 0; j < haystack.size(); j++) {
            if(haystack[j] == needle[0]) {
                for (int i = 0; i < needle.size(); i ++) {
                    if(haystack[j+i] != needle[i]) 
                    {
                        break;
                    }
                    if (i == needle.size() - 1) {
                        ind = j;
                        j = haystack.size();
                    }
                }
            }
        }
        
        return ind;
    }
};
```

### LC 48. rotate image
#### o(n) time, o(1) space
#### swap all four corners, then shift pointer
```c++
class Solution {
public:
    
   
        
    void rotate(vector<vector<int>>& matrix) {
        
        if(matrix.size() < 1)
            return;
        if(matrix[0].size() < 1)
            return;
        
        //there are four corners swaping with each other.
        int n = matrix.size(); //it is a square
        
        for(int i = 0; i < (n+1)/2; i++) {
            for(int j = 0; j < n /2; j++) {
                int tmp = matrix[n - 1- j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 -i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 -i];
                matrix[j][n - 1 - i] = matrix[i][j];
                matrix[i][j] = tmp;
            }
            
        }
        
    }
};
```
### lc 206. reverse linked list
#### 一定要3个指针，重新复习一次

```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * prev = nullptr;
        ListNode * cur = head;
        
        while (cur != nullptr) {
            head = cur->next;
            cur->next = prev;
            
            prev = cur;
            cur = head;
        }
        
        return prev;
    }
};
```

### LC 23. Merge k Sorted Lists
#### time o(nlogk) k is the number of lists
#### space o(n) by creating a new list, o(k) by implementing priority queue
```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    struct compare{
        bool operator()(ListNode* &left, ListNode* &right) {
            return left->val > right->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> q;
        
        for(auto l : lists) {
            if(l)
                q.push(l);
        }
        ListNode* head = new ListNode(0);
        ListNode* tmp = head;
        
        while (!q.empty()) {
            ListNode* p = q.top();
            q.pop();
            
            tmp->next = new ListNode(p->val);
            tmp = tmp->next;
            if(p->next) q.push(p->next);
        }
        
        return head->next;
    }
};
```

#### Gifting-groups (lc547)

####  LC. 210. Course Schedule II (Topological sort)
##### time complexicty o(v+e) space complexity o(v+e)

##### solution:
``` c++
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> pre_req (numCourses);
        vector<int> idg (numCourses);
        
        for (auto pre : prerequisites) {
            pre_req[pre[1]].push_back(pre[0]); //pre[1] is the before class, pre[0] is the after class
            idg[pre[0]]++; //all these class need an additional class to access them
        }
        
        vector<int> ans;
        queue<int> Q; //for the bfs
        int taken_num = 0 ;//num of courses taken
        for (int i = 0; i < idg.size(); i ++) {
            if (idg[i] == 0) { //this course has no require
                Q.push(i); //push it into queue
                //ans.push_back(i); //take this course
            }
        }
        
        while (!Q.empty() ) {
            int curr = Q.front(); // current course
            Q.pop();
            
            if(find(ans.begin(), ans.end(), curr) != ans.end()) {
                //it is taken
                return {};
            }
            ans.push_back(curr);
            taken_num ++;
            //reduce idg of this course's after course
            for(auto course : pre_req[curr]) {
                idg[course]--;
                if(idg[course] == 0) 
                    Q.push(course);
            }
        }
        if(taken_num ==numCourses)
            return ans;
        return {};
    }
};
```
