class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> table;
        for(auto &num: nums){
            table[num]++;
        }
        vector<pair<int,int>> ind;
        for(auto &t: table){
            ind.push_back(t);
        }
        
        sort(ind.begin(),ind.end(),[](pair<int,int>&a, pair<int,int>&b){
            return a.second > b.second;
        });
        vector<int> result;
        for(int i=0; i<k; i++) {
            result.push_back(ind[i].first);
        }
        return result;
    }
};
