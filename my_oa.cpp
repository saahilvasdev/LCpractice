//amazon oa
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

struct point {
    int x;
    int y;

    point () {
        x=0;
        y=0;
    }
    point(int first, int second) {
        x=first;
        y=second;
    }
};
int distanceTravresed(vector<vector<int>> lot) {
    point start;
    queue <point> q;
    q.push(start);
    int row;
    int col;
    list visited;
    int[][] direct = {{0,1}, {0,-1},{1,0},{-1,0}};
    int ans = 0;
    while( !q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            point cur = q.poll();
            if (cur == dest) {
                return ans;
            }
            for (int[] dir : direct) {
                int x = dir[0] + cur.x;
                int y = dir[1] + cur.y;
                if (x < row && y < col && grid[x][y] != obstacle && ! visisted[point]) {
                    q.offer(new point(x, y));
                    visited.add(point);
                }
            }
        }
        ans++;

    }
    return -1;
}


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

int distanceTraverserd(vector<vector<int>>& lot) {
    if (!lot.size() || !lot[0].size()) return 0;
    int steps = 0;
    int m = lot.size(), n = lot[0].size();

    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    queue<pair<int, int>>q;
    unordered_set<string> set;
    q.push({0, 0});

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            pair<int, int> p = q.front();
            q.pop();
            
            if (lot[p.first][p.second] == 9)
                return steps;
            string temp = to_string(p.first) + "," + to_string(p.second);
            if (set.find(temp) != set.end())
                continue;
            for (auto d : dir) {
                int newX = p.first + d[0];
                int newY = p.second + d[1];

                if (newX < 0 || newY < 0 || newX >= m || newY >= n || lot[newX][newY] == 0)
                    continue;
                q.push({newX, newY});
            }
        }
        steps++;
    } 

    return -1;
}