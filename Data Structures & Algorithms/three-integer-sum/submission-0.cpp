class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i-1]==nums[i]){
                continue;
            }
            int start = i+1;
            int end = nums.size() - 1;
            while(start < end) {
                if(nums[start]+nums[end] == -nums[i]) {
                    res.push_back({nums[i],nums[start],nums[end]});
                    start++;
                    end--;
                    while(start < end && nums[start] == nums[start-1]){
        start++;
    }
                }
                else if(nums[start]+nums[end] > -nums[i]) {
                    end--;
                }
                else if(nums[start]+nums[end] < -nums[i]) {
                    start++;
                }
            }
        }
        return res;
        
    }
};
