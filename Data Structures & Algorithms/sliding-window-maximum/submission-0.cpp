class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;

        for(int i=0; i<n; i++){
            // Step 1: Remove useless players
            while(!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Step 2: Remove expired players
            if(!dq.empty() && dq.front() < i-k+1) {
                dq.pop_front();
            }

            dq.push_back(i);

            if(i>= k-1) {ans.push_back(nums[dq.front()]);}
        }
        return ans;
    }
};
