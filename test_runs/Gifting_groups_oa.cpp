#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int find (vector<int>& parents, int kid) {
        if(parents[kid] == 0) {
            return kid;
        }

        return parents[kid] = find(parents, parents[kid]); //comppression
    }

    void connect (vector<int> &parents, int kid_a, int kid_b, int &count) {
        int p_a = find(parents, kid_a);
        int p_b = find(parents, kid_b);

        if (p_a != p_b) {
            parents[p_a] = p_b;
            count--; // one less group;
        }
    }
    int findCircleNum (vector<vector<int>> & isConnected) {
        vector<int> parents (isConnected.size()+1, 0);
        
        int n = isConnected.size();
        int count = n;
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    connect(parents, i, j, count);
                    isConnected[j][i] = 0;
                }
            }
        }

        return count;
    }
};

class Solution1 {

public:
    int find (vector<int> &parents, int kid) {
        if (parents[kid] == 0) {
           return kid;
        }
        
        return parents[kid] = find (parents, parents[kid]);
    }
    
    void connect (vector<int> &parents, int kid_a, int kid_b, int &count) {
        int p_a = find(parents, kid_a);
        int p_b = find(parents, kid_b);
        
        if( p_a != p_b) {
            parents[p_a] = p_b;
            count--;
        }
        
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> parents (isConnected.size(), 0);
        int n = isConnected.size();
        int count = n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if( isConnected[i][j] == 1) {
                    connect(parents, i, j, count);
                    isConnected[j][i]=0;
                }
            }
        }
        
        return count;
    }
};

int main () {
    vector<vector<int>> test1 = {{1,0,0},{0,1,0},{0,0,1}};
    vector<vector<int>> test2 ={{1,1,0},{1,1,0},{0,0,1}};
    vector<vector<int>> test3 ={{1,1,1},{1,1,1},{1,1,1}};
    Solution sol;
    cout<<"test1 ans is "<< sol.findCircleNum(test1)<<endl;
    cout<<"test2 ans is "<< sol.findCircleNum(test2)<<endl;
    cout<<"test3 ans is "<< sol.findCircleNum(test3)<<endl;
}

