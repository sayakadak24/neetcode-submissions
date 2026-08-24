class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // We can find if target - nums[i] is present in the set, if yes then return it's index
        unordered_map <int, int> arr;
        for(int i = 0; i<nums.size();i++){
            if(arr.find(target - nums[i]) != arr.end()){
                return {arr[target - nums[i]],i};
            }
            arr[nums[i]] = i;
        }
        return {};
    }
};
