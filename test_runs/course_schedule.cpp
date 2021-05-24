#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
    public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> pre_req (numCourses);
        vector<int> idg (numCourses);

        for (int i = 0; i < prerequisites.size(); i++) {
            int pre = prerequisites[i][1];
            int post = prerequisites[i][0];
            pre_req[pre].push_back(post); // all the post course of pre
            idg[post]++;
        }

        //push all the 0 indegree into Q
        queue<int> Q;
        set<int> taken;
        for (int i = 0; i < numCourses; i++) {
            if(idg[i] == 0) 
                Q.push(i);
        }

        //start bfs
        while(!Q.empty()) {
            int curr = Q.front();
            Q.pop();

            if (taken.find(curr) != taken.end()) {
                //we see this course twice,there is a loop
                //fail
                return false;
            }
            taken.insert(curr);

            for (int i = 0; i < pre_req[curr].size(); i ++) {
                idg[pre_req[curr][i]] --;

                if (idg[pre_req[curr][i]] == 0)
                    Q.push(pre_req[curr][i]);
            }
        }
        cout <<"taken size is "<< taken.size()<<endl;
        return taken.size() == numCourses;

    }
    
    bool find_course(vector<int> taken, int course) {
        for (auto i : taken) {
            if (i == course) 
                return true;
        }
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> course_prereq(numCourses);
        vector<int> idg(numCourses);
        int n = numCourses;
        //add courses to course_prereq : pre course {prereq1, prereq2, prereq3, etc}
        //in degree of post ++
        for(int i = 0; i < prerequisites.size(); i++) {
            int post = prerequisites[i][1];
            int pre = prerequisites[i][0];
            course_prereq[pre].push_back(post);
            idg[post]++;
        }
        
        
        //push all the 0 indegree into Q
        queue<int> Q;
        vector<int> taken ;

        for(int i = 0; i < n; i++) {
            if (idg[i] == 0) {
                Q.push(i);
                taken.push_back(i);
            }
        }
        
        //start our BFS
        while(!Q.empty()) {
            int curr = Q.front();
            Q.pop();
            n--;
            
                     
            //now we can access all the course that has this as pre
            //so their idg --
            for(int i = 0; i < course_prereq[curr].size(); i ++) {
                idg[course_prereq[curr][i]] --;
                
                if(idg[course_prereq[curr][i]] == 0) {
                    Q.push(course_prereq[curr][i]);
                    taken.push_back(course_prereq[curr][i]);
                }
            }                      
        }
        if (n == 0) {
            reverse(taken.begin(), taken.end());
            return taken;
        }
        return {};
    }
};




int main() {
    vector<vector<int>> test = {{1,0},{2,1},{3,2}};
    Solution sol;
    string t_f;
    //bool result = sol.canFinish(4, test);
    vector<int> result = sol.findOrder(4, test);
    //result ? t_f = "true": t_f = "false";

    cout <<"The result for can finish is ";
    for (auto i : result) {
        cout << i << " ";
    }
    cout<<endl;
}