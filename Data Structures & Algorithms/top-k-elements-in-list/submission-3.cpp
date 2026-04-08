class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size();i++){
            mp[nums[i]]++;
        }
        int n=nums.size();
        vector<vector<int>> buckets(n+1);
        for(auto &[nums,freq] : mp){
            buckets[freq].push_back(nums);
        }
        vector<int> result;
        for(int i=n;i>=1;i--){
            for(auto nums:buckets[i]){
                result.push_back(nums);
                if(result.size() == k) return result;
            }
        }
        return result;
    }
};
