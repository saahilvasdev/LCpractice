### Amazon OA bank

#### fresh delivery
class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& allLocations, int numDeliveries) {
        vector<vector<int>> ans;
        if(allLocations.size()==0)return ans;

        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<allLocations.size();i++)
        {
            int dist=allLocations[i][0]*allLocations[i][0]+allLocations[i][1]*allLocations[i][1];
            
            pq.push({dist,{allLocations[i][0],allLocations[i][1]}});
            if(pq.size()>numDeliveries)
                pq.pop();
            
        }
        while(!pq.empty())
        {
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }

};

#### Robot in Circle
======
#### Number Game (hard)
======
#### Find All Combination of Numbers that Sum to a Target
======
#### Fill the Truck
##### my solution:
```c++
//compare for sorting
bool compare(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
class Solution {
public:

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int total_units = 0;
        for (auto box : boxTypes) {
            
            if(truckSize <box[0] ) { //remaining box fill up truck
                total_units += truckSize * box[1];
                return total_units;
            }
            else {
                truckSize -= box[0];
                total_units += box[0] * box[1];
            }
        }
        
        return total_units;
    }
};
```
======
#### Slowest Key
======
#### Five Star Sellers
======
#### Number of Ways to Split Into Primes
======
#### Storage Optimization
======
#### Music Pair
======
#### Minimum Difficulty of a Job Schedule
======
#### Autoscale Policy, Utilization Check
======
#### Optimal Utilization
======
#### Merge Two Sorted Lists
======
#### Two Sum - Unique Pairs
======
#### Shopping Patterns
##### leetcode :https://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph/
##### algo.monster : https://algo.monster/problems/shopping_patterns
##### solution:
We need to:

Find the trios
Find the degree of each trios
2) is easy because the degree of a trio is the sum of (degree of each node - 2). -2 because the edges between trio nodes are not counted. The degree of a node is simply the number of elements in its adjacency list.

To find a trio, let's start with the definition of a trio: three nodes connected by edges between each other. How do we do this in code?

For each node u, we loop through each node v in its adjacency list u_ns. And for each of v, we loop through each node w in its adjacency list v_ns. If a node w is also in the adjacency list of u, then we have found a trio.

There is one last optimization: if we simply write the above nested loop, we may get duplicates, e.g. (u, v, w), (u, w, v), (v, u, w), (v, w, u), (w, u, v), (w, v, u) all refer to the same trio. We can avoid duplicates by establishing order and only counting trios where u < v < w. If this is not clear to you, we recommend taking a look at dedup section of a previous lesson.
##### code:
```java
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
class Solution {
    public static int shoppingPatterns(int productsNodes, List<Integer> productsFrom, List<Integer> productsTo) {
        // WRITE YOUR BRILLIANT CODE HERE
        // node -> set of neighbors
        return 0;
        List<HashSet<Integer>> neighbors = IntStream.range(0, productsNodes).mapToObj(i -> new HashSet<Integer>()).collect(Collectors.toList());
        for (int i = 0; i < productsFrom.size(); i++) {
            // convert from 1-based to 0-based indexing
            int u = productsFrom.get(i) - 1;
            int v = productsTo.get(i) - 1;
            neighbors.get(u).add(v);
            neighbors.get(v).add(u);
        }
        int minSum = Integer.MAX_VALUE;
        // all (u, v, w) where
        // - (u, v), (v, w), (u, w) are neighbors (trio)
        // - u < v < w (to avoid duplicates, as optimization)
        for (int u = 0; u < neighbors.size(); u++) {
            HashSet<Integer> u_ns = neighbors.get(u);
            for (int v : u_ns) {
                if (v < u)
                    continue;
                for (int w : u_ns) {
                    HashSet<Integer> v_ns = neighbors.get(v);
                    if (w < u || !v_ns.contains(w))
                        continue;
                    HashSet<Integer> w_ns = neighbors.get(w);
                    // each neighbors set include the other 2 in the trio,
                    // which we don't count in product score
                    int curSum = u_ns.size() + v_ns.size() + w_ns.size() - 6;
                    minSum = Math.min(minSum, curSum);
                }
            }
        }
        return minSum != Integer.MAX_VALUE ? minSum : -1;
    }
    public static List<String> splitWords(String s) {
        return s.isEmpty() ? List.of() : Arrays.asList(s.split(" "));
    }
```


======
#### Amazon Prime Air Delivery Route
======
#### Reorder Data in Log Files
======
#### Top K Frequently Mentioned Keywords
======
#### Shopping Options
##### Description
A customer wants to buy a pair of jeans, a pair of shoes, a skirt, and a top but has a limited budget in dollars. Given different pricing options for each product, determine how many options our customer has to buy 1 of each product. You cannot spend more money than the budgeted amount.

Example
priceOfJeans = [2, 3]
priceOfShoes = [4]
priceOfSkirts = [2, 3]
priceOfTops = [1, 2]
budgeted = 10

The customer must buy shoes for 4 dollars since there is only one option. This leaves 6 dollars to spend on the other 3 items. Combinations of prices paid for jeans, skirts, and tops respectively that add up to 6 dollars or less are [2, 2, 2], [2, 2, 1], [3, 2, 1], [2, 3, 1]. There are 4 ways the customer can purchase all 4 items.

Function Description

Complete the getNumberOfOptions function in the editor below. The function must return an integer which represents the number of options present to buy the four items.

getNumberOfOptions has 5 parameters:
int[] priceOfJeans: An integer array, which contains the prices of the pairs of jeans available.
int[] priceOfShoes: An integer array, which contains the prices of the pairs of shoes available.
int[] priceOfSkirts: An integer array, which contains the prices of the skirts available.
int[] priceOfTops: An integer array, which contains the prices of the tops available.
int dollars: the total number of dollars available to shop with.

Constraints

1 ≤ a, b, c, d ≤ 103
1 ≤ dollars ≤ 109
1 ≤ price of each item ≤ 109
Note: a, b, c and d are the sizes of the four price arrays
##### Solution
```java
Solution:
import java.util.ArrayList;
import java.util.List;
public class solution123 {
public static int shoppingOptionCount(List items, int budget) {
if (budget < 0)
return 0;

if (items.size() == 1)
    return singleItemShoppingCount(items.get(0), budget);

int count = 0;
for (int p : items.get(0)) {
    if (p <= budget) {
        List<List<Integer>> newItems = new ArrayList<>(items);
        newItems.remove(0);
        count += shoppingOptionCount(newItems, budget - p);
    }
}
return count;
}
public static int singleItemShoppingCount(List prices, int budget) {
int count = 0;
for (int p : prices) {
if (p <= budget)
count += 1;
}
return count;
}
public static void main(String[] args) {
List l1 = new ArrayList<>();
l1.add(4);
List l2 = new ArrayList<>();
l2.add(3);
l2.add(4);
l2.add(1);
List l3 = new ArrayList<>();
l3.add(3);
l3.add(2);
List l4 = new ArrayList<>();
l4.add(4);
List<List> l5 = new ArrayList<>();
l5.add(l1);
l5.add(l2);
l5.add(l3);
l5.add(l4);
System.out.println(m1(l5, 12));
}
}
```

=====
#### Items in Containers
##### problem:
Given a string s consisting of items as "*" and closed compartments as an open and close "|", an array of starting indices startIndices, and an array of ending indices endIndices, determine the number of items in closed compartments within the substring between the two indices, inclusive.

An item is represented as an asterisk *
A compartment is represented as a pair of pipes | that may or may not have items between them.
Example:
s = '|**|*|*'
startIndices = [1,1]
endIndices = [5,6]

The String has a total 2 closed compartments, one with 2 items and one with 1 item. For the first par of indices, (1,5), the substring is '|**|*'. There are 2 items in a compartment.
For the second pair of indices, (1,6), the substring is '|**|*|' and there 2+1=3 items in compartments.
Both of the answers are returned in an array. [2,3].
```java
class Result {
	public static List<Integer> numberOfItems(String s, List<Integer> startIndices, List<Integer> endIndices) {
		// Write your code here
		
		}
}
```
##### solution:
```java
public static List<Integer> numberOfItems(String s, List<List<Integer>> ranges) {
        int n = s.length();
        Map<Integer, Integer> map = new HashMap();
        int sum = 0;
        int cumSum = 0;
        boolean started = false;
        for(int i = 0; i < n; i++){
            if(s.charAt(i) == '|'){
                if(started){
                    cumSum += sum;
                    map.put(i,cumSum);
                }
                else
                    map.put(i,0);
                started = true;
                sum = 0;
            }else{
                sum++;
            }
        }
        int right = -1;
        int[] rightBoundary = new int[n];
        for(int i = n-1; i >=0; i--){
            if(s.charAt(i) == '|'){
                right = i;
            }
            rightBoundary[i] = right;    
        }
        int left = -1;
        int[] leftBoundary = new int[n];
        for(int i = 0; i < n; i++){
            if(s.charAt(i) == '|'){
                left = i;
            }
            leftBoundary[i] = left;    
        }
        List<Integer> res = new ArrayList();
        for(List<Integer> items: ranges){
            int start = rightBoundary[items.get(0)];
            int end = leftBoundary[items.get(1)];
            if(start != -1 && right != -1 && start < end){
                res.add(map.get(end) - map.get(start));
            }else
                res.add(0);
                
        }
        return res;
    }
```
================================
#### Amazon Music Runtime ==Find Pair With Given Sum
##### problem
Amazon music is working on a new feature to pair songs together to play while on bus.The goal of this feature is to select two songs from the list that will end exactly 30 secondsbefore the listener reaches their stop.You are tasked with writing the method that selects the songs from a list. Each song is assigned a unique id, numbered from 0 to N-1.

Assumptions:

You will pick exactly 2 songs.
you cannot pick the same song twice.
if you have multiple pais with the same total time, select the pair with the longest song.
there are atleast 2 songs available.
write an alorithm to return ID's of the 2 songs whose combined runtime will finish exactly 30 seconds before the bus arrives, keeping the original order. If no such pair is possible, return a pair with <-1,-1>.

input:
rideDuration = 90
songDuration = {1,10,25,35,60}

output:
[2,3]
##### solution
```java
public class Main {
    
    private static int[] test(int rideDuration, int[] songDuration){
        
        if (rideDuration <= 30) return new int[2];
        int playListOver = rideDuration - 30;
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < songDuration.length; i++){
            if (map.containsKey(songDuration[i])){
                return new int[] {map.get(songDuration[i]), i};
            } else{
                map.put(playListOver - songDuration[i], i);
            }
        }
        return null;
    }
    public static void main(String[] args) {

        int[] ans = test(90, new int[] {1,10,25,35,60});
        System.out.println("[" + ans[0] + ", " + ans[1] + "]");
    }
}
```
=====
#### Treasure Island
##### problem:
You have a map that marks the location of a treasure island. Some of the map area has jagged rocks and dangerous reefs. Other areas are safe to sail in. There are other explorers trying to find the treasure. So you must figure out a shortest route to the treasure island.

Assume the map area is a two dimensional grid, represented by a matrix of characters. You must start from the top-left corner of the map and can move one block up, down, left or right at a time. The treasure island is marked as X in a block of the matrix. X will not be at the top-left corner. Any block with dangerous rocks or reefs will be marked as D. You must not enter dangerous blocks. You cannot leave the map area. Other areas O are safe to sail in. The top-left corner is always safe. Output the minimum number of steps to get to the treasure.

Example:

Input:
[['O', 'O', 'O', 'O'],
 ['D', 'O', 'D', 'O'],
 ['O', 'O', 'O', 'O'],
 ['X', 'D', 'D', 'O']]

Output: 5
Explanation: Route is (0, 0), (0, 1), (1, 1), (2, 1), (2, 0), (3, 0) The minimum route takes 5 steps.
##### solution
```java
// https://leetcode.com/discuss/interview-question/347457/Amazon-or-OA-2019-or-Treasure-Island
public class Main {
    private static final int[][] DIRS = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    public static int minSteps(char[][] grid) {
        Queue<Point> q = new ArrayDeque<>();
        q.add(new Point(0, 0));
        grid[0][0] = 'D'; // mark as visited
        for (int steps = 1; !q.isEmpty(); steps++) {
            for (int sz = q.size(); sz > 0; sz--) {
                Point p = q.poll();
            
                for (int[] dir : DIRS) {
                    int r = p.r + dir[0];
                    int c = p.c + dir[1];
                    
                    if (isSafe(grid, r, c)) {
                        if (grid[r][c] == 'X') return steps;
                        grid[r][c] = 'D';
                        q.add(new Point(r, c));
                    }
                }
            }
        }
        return -1;
    }
    
    private static boolean isSafe(char[][] grid, int r, int c) {
        return r >= 0 && r < grid.length && c >= 0 && c < grid[0].length && grid[r][c] != 'D';
    }
    
    private static class Point {
        int r, c;
        Point(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }
    
    public static void main(String[] args) {
        char[][] grid = {{'O', 'O', 'O', 'O'},
                         {'D', 'O', 'D', 'O'},
                         {'O', 'O', 'O', 'O'},
                         {'X', 'D', 'D', 'O'}};
        System.out.println(minSteps(grid));
    }
}
```
==========
#### two sum (movie theater)

#### leet code 547 (union find)

#### Nearest Cities
##### problem
Amazon Online Assessment Nearest Cities

There are Fulfillment Centers in multiple cities within a large geographic region. The cities are arranged on a graph that has been divided up like an ordinary Cartesian plane. Each city is located at an integral (x, y) coordinate intersection. City names and locations are given in the form of three arrays: c, x, and y, which are aligned by the index to provide the city name (c[i]), and its coordinates, (x[i], y[i]).
Write an algorithm to determine the name of the nearest city that shares either an x or a y coordinate with the queried city. If no other cities share an xory coordinate, return NONE. If two cities have the same distance to the queried city, q[i], consider the one with an alphabetically smaller name (i.e. 'ab' < 'aba' < 'abb') as the closest choice.
The distance is denoted on a Euclidean plane: the difference in x plus the difference in y.

Input
The input to the function/method consists of six arguments:
numOfCities, an integer representing the number of cities;
cities, a list of strings representing the names of each city [i];

xCoordinates, a list of integers representing the X coordinates of each city[i];
yCoordinates, a list of integers representing the Y-coordinates of each city[i];
numOfQueries, an integer representing the number of queries;
queries, a list of strings representing the names of the queried cities.

Output
Return a list of strings representing the name of the nearest city that shares either an x or a y coordinate with the queried city.

Constraints
1 <= numOfCities, numOfQueries < 10^ 5
1 < xCoordinates[i], yCoordinates[i] <= 10^ 9
1 < length of queries[i] and cities[i] <= 10

Note
Each character of all c[i] and q[i] is in the range ascii[a-z, 0-9,-].
All city name values, c[i], are unique. All cities have unique coordinates.

Example:
Input:
numOfCities = 3
cities = ["c1", "c2","c3"]
xCoordinates = [3, 2, 1]
yCoordinates = [3, 2, 3]
numOfQueries = 3
queries = ["c1", "c2", "c3"]
Output:
["c3", NONE, "c1"]
Explanation:
There are three points(3,3), (2,2) and (1,3) represent the coordinates of the cities on the graph. The nearest city to c1 is c3, which shares a y value (distance = (3-1) + (3-3) = 2).
City c2 does not have a nearest city as none share an x or y with c2, so this query returns NONE. A query of c3 returns c1 based on the first calculation. The return array after all queries are complete is [c3, NONE, c1].

Example:
Input:
numOfCities = 5
cities = ["c1", "c2", "c3", "c4", "c5"]
xCoordinates = [100, 200, 300, 400, 500]
yCoordinates = [100, 200, 300, 400, 500]
numOfQueries = 5
queries = ["c1", "c2", "c3", "c4", "c5"]
Output
[NONE, NONE, NONE, NONE, NONE]
Explanation:
No nearest cities because none share the same x or y.
##### solution

====================
#### Demolition Robot
##### problems
Given a matrix with values 0 (trenches) , 1 (flat) , and 9 (obstacle) you have to find minimum distance to reach 9 (obstacle). If not possible then return -1.
The demolition robot must start at the top left corner of the matrix, which is always flat, and can move on block up, down, right, left.
The demolition robot cannot enter 0 trenches and cannot leave the matrix.
Sample Input :
[1, 0, 0],
[1, 0, 0],
[1, 9, 1]]
Sample Output :
3
This question can be solved by using BFS or DFS.
##### solutions (bfs)

==========
#### 315 https://leetcode.com/problems/count-of-smaller-numbers-after-self/
##### 求需要多少个swap之后能恢复list的顺序，与散药物非常接近
##### https://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=756723&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3086%5D%5Bvalue%5D%3D11%26searchoption%5B3086%5D%5Btype%5D%3Dradio%26searchoption%5B3046%5D%5Bvalue%5D%3D5%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26sortid%3D311%26orderby%3Ddateline

#### media encoder
同下，只是 num of files 改成 time，意思一樣
https://www.csestack.org/minimum-cost-merging-files/


#### Find Pair With Given Sum == Amazon Music Runtime
##### problem
Given a list of positive integers nums and an int target, return indices of the two numbers such that they add up to a target - 30.

Conditions:

You will pick exactly 2 numbers.
You cannot pick the same element twice.
If you have muliple pairs, select the pair with the largest number.
Example 1:

Input: nums = [1, 10, 25, 35, 60], target = 90
Output: [2, 3]
Explanation:
nums[2] + nums[3] = 25 + 35 = 60 = 90 - 30
Example 2:

Input: nums = [20, 50, 40, 25, 30, 10], target = 90
Output: [1, 5]
Explanation:
nums[0] + nums[2] = 20 + 40 = 60 = 90 - 30
nums[1] + nums[5] = 50 + 10 = 60 = 90 - 30
You should return the pair with the largest number.

##### solution
```java
// https://leetcode.com/discuss/interview-question/356960
public class Main {
    
    public static List<Integer> findPair(List<Integer> nums, int target) {
        target -= 30;
        Map<Integer, Integer> map = new HashMap<>();
        List<Integer> result = Arrays.asList(-1, -1);
        int largest = 0;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums.get(i);
            if ((nums.get(i) > largest || complement > largest) && map.containsKey(complement)) {
                result.set(0, map.get(complement));
                result.set(1, i);
                largest = Math.max(nums.get(i), complement);
            }
            map.put(nums.get(i), i);
        }
        return result;
    }

    public static void main(String[] args) {
        test(Arrays.asList(1, 10, 25, 35, 60), 90);
        test(Arrays.asList(20, 50, 40, 25, 30, 10), 90);
        test(Arrays.asList(5, 55, 40, 20, 30, 30), 90);
    }
    
    private static void test(List<Integer> nums, int target) {
        System.out.println(findPair(nums, target));
    }
}
```
=====
#### dutch national flag problem（LeetCode 75）
#### merge two sorted list（LeetCode 21)
#### 1099 two sum less than k变种
##### Memory Consumption

Memory Consumption
其实就是大家常说的Flight题

有两个数组 如下形式, 每个代表一个application, 第一个数代表index, 代表application会使用的内存
[[1, 100], [2, 200], [3, 500] ...]
[[1, 200], [2, 300], [3, 900] ...]
给一个最大的Memory数例如1000
从第一和第二个数组中个找出一个application 总内存小于1000
这个题的答案是[3, 2], 既取第一个array中的3, 500和第二个array中的2, 300 总共用800 memory < 1000
#### 973 k closest变种
#### Transaction logs 
放map里 count， 然后把大于等于threshold的id都选出来，再排序。
##### problem
The 1st question was Transaction logs.

A Company parses logs of online store user transactions/activity to flag fraudulent activity.

The log file is represented as an Array of arrays. The arrays consist of the following data:

[ <# of transactions>]

For example:

[345366 89921 45]

Note: the data is space delimited

So, the log data would look like:

[
[345366 89921 45],
[029323 38239 23]
...
]
Write a function to parse the log data to find distinct users that meet or cross a certain threshold.

The function will take in 2 inputs:
logData: Log data in form an array of arrays

threshold: threshold as an integer

Output:
It should be an array of userids that are sorted.

If same userid appears in the transaction as userid1 and userid2, it should count as one occurrence, not two.

Example:
Input:
logData:

[
[345366 89921 45],
[029323 38239 23],
[38239 345366 15],
[029323 38239 77],
[345366 38239 23],
[029323 345366 13],
[38239 38239 23]
...
]
threshold: 3

Output: [345366 , 38239, 029323]
Explanation:
Given the following counts of userids, there are only 3 userids that meet or exceed the threshold of 3.

345366 -4 , 38239 -5, 029323-3, 89921-1
##### solution
It can be solved using a HashMap, for counting occurrences. If the log is not the same
put into the HashMap. Then, check the Threshold, if it is equal or greater insert into
the list to be returned.
```java

public static String[] parseLogs(List<List<String>> logs, int t) {

		List<String> ans = new ArrayList<String>();
		HashMap<String, Integer> hmap = new HashMap<String, Integer>();

		for (List<String> lst : logs) {
			String[] arrStr = lst.get(0).split("\\s+");

			if (arrStr[0] != arrStr[1]) {
				hmap.put(arrStr[0], hmap.getOrDefault(arrStr[0], 0) + 1);
				hmap.put(arrStr[1], hmap.getOrDefault(arrStr[1], 0) + 1);
			}
		}
		for (Map.Entry<String, Integer> e : hmap.entrySet()) {
			if (e.getValue() >= t) {
				ans.add(e.getKey());
			}
		}

		return (String[]) ans.stream().map(String::new).toArray(String[]::new);
		//[345366, 38239, 029323]
	}
```

#### Gifting-Groups
https://aonecode.com/amazon-onli ... oups/Friend-Circles
解法和#1一样，DFS。 这次好好看清楚了input，input还是一个list of string， 每个string代表一个node的adjacent matrix。

#### 1401 https://leetcode.com/problems/circle-and-rectangle-overlapping/

#### prime order prioritization

#### Substrings and distinct characters

You're given a string S of lower case alphabets. Let Xi be the number of substrings with atleast i distinct characters.

Determine the value of Xi for all i, where i can take values in range [1, 26] (both inclusive)

Constraints:
N (length of S) is upto 5 * 10**5

Examples:
S = aabc

For X1 -> 4 * (5) / 2 -> 10 (No of substrings with atleast 1 distinct characters)
For X2 -> substrings with atleast 2 distinct characters are (aab, aabc, bc, abc, ab) -> 5
For X3 -> substrings with atleast 3 distinct characters are (aabc, abc) -> 2
For Xi where i >= 4, No substrings can have alteast > 4 distinct characters
So, the answer will be [10, 5, 2, 0, 0, 0, 0, 0, 0, ----, 0] (length of the output must be 26 for Xi where i is from 1 to 26)

####