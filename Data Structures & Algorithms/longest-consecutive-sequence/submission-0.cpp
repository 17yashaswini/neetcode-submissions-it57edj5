class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    
    // Put all numbers into a hash set
    // This lets us check if a number exists in O(1) time
    // Duplicates are automatically removed by the set
    unordered_set<int> seen(nums.begin(), nums.end());
    
    // This will store our final answer
    int maxLength = 0;
    
    // Loop through every number in the array
    for (int i = 0; i < nums.size(); i++) {
        
        // Only start counting if nums[i] is a sequence START
        // A number is a start only if (num - 1) does NOT exist in the set
        // e.g. 2 is a start if 1 is not in the set
        if (seen.count(nums[i] - 1) == 0) {
            
            int curr = nums[i]; // current number we're checking
            int length = 1;     // sequence length starts at 1
            
            // Step 5: Keep going as long as next consecutive number exists
            // e.g. if curr = 2, check if 3 exists, then 4, then 5...
            while (seen.count(curr + 1)) {
                curr++;     // move to next number
                length++;   // increment sequence length
            }
            
            // Step 6: Update max length if current sequence is longer
            maxLength = max(maxLength, length);
        }
    }
    
    // Step 7: Return the longest sequence length found
    return maxLength;
}
};
