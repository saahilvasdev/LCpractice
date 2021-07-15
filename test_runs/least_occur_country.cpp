/*

Write a function that given a list of countries, returns the country(s) that occur the least times
i.e - ["Argentina", "Cuba", "Chile", "Argentina"] -> ["Cuba", "Chile"]
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {

    public:
    vector<string> least_occur_country (vector<string> countries ) {
        unordered_map <string, int> mp;
        vector<string> ans;
        // add countries to the mp
        for (auto c : countries) {
            //如果map原本没有
            if (mp.find(c) == mp.end()) {
                mp.emplace(c, 1);
            }
            //如果map有
            else {
                mp.find(c)->second++;
            }
        }

        unordered_map<string,int>::iterator it;
        int counter = INT_MAX;
        for (it = mp.begin(); it != mp.end(); it++) {
            if (it->second < counter) {
                counter = it->second;
                ans.clear();//remove all current elements
                ans.push_back(it->first);
            }
            else if (it->second == counter) {
                ans.push_back(it->first);
            }
            
        }

        return ans;
    }

};


int main () {

}