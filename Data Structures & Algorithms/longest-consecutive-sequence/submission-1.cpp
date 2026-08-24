class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num(nums.begin(),nums.end());
        int longest = 0;
        // We check for the start of the sequence by checking if n-1 exists in nums
        for(int n: num){
            int length = 1;
            if(num.find(n-1) == num.end()){
                // We found the start, now let's check the max length
                
                while(num.find(n+length) != num.end()){
                    length++;
                }
            }
            longest = max(length, longest);
        }
        return longest;
    }
};
