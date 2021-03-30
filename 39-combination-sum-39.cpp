//39. Combination Sum
/*



Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
Example 4:

Input: candidates = [1], target = 1
Output: [[1]]
Example 5:

Input: candidates = [1], target = 2
Output: [[1,1]]
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //we set up a dp array that stores the possible combination from 0 to target
        vector<vector<vector<int>>> dp(target + 1);
        //of course 0 being 0
        dp[0] = {{}};
        
        //iterate through each one of the candidates
        for(int p : candidates) {
            //now we know what candidate we have, we can make up value j, from using candidate p,
            //and combine p with others.
            for (int j = p; j <= target; j ++) {
                //for each iteration, we are making a combination.
                //say this number is p + 2, we are looking for combinations which have sum as p +2

                for ( vector<int> v : dp[j - p]) {
                    //which means, we now can update our dp collection
                    //不论我们之前已经有了哪些dp组合，我们现在有新的了，加到dp array里
                    //v.push_back(p), because currently, we can try another p.
                    //or we can try additional p
                    v.push_back(p);

                    //put this combination to our dp array.
                    dp[j].push_back(v);

                    //this loop stops when we reach [j-p], meaning we had a combination that works.
                }
            }
        }
        //return answer.
        return dp[target];
    }
};