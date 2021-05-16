#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
/*
leetcode 1799.
You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.

In the ith operation (1-indexed), you will:

    Choose two elements, x and y.
    Receive a score of i * gcd(x, y).
    Remove x and y from nums.

Return the maximum score you can receive after performing n operations.

The function gcd(x, y) is the greatest common divisor of x and y.
*/




class Solution {
    public:
    int gcd (int a, int b) {
        if (b == 0) return a;

        return gcd( b, a%b);
    }
    int numberGame(vector<int>& nums) {

    }
}


int main () {
    // 1. Number Game
    Solution test_peice = Solution();


}