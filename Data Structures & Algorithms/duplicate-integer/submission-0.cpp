class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> table;
        for(auto &num: nums){
            table[num]++;
            if(table[num] > 1) {return true;}
        }
        return false;
    }
};