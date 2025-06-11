class Solution {
public:
    typedef long long ll;  // Define a shorthand for 'long long' as 'll' for readability

    map<string, ll> mp;  // Memoization map to store computed results for states

    // Recursive helper function to calculate the maximum balanced subsequence sum
    ll hlo(vector<int>& nums, int i, int prevelement) {
        if (i >= nums.size()) 
            return 0;  // Base case: reached the end of the array

        // Generate a unique key for the current state based on index and previous element
        string findy = to_string(prevelement) + "-" + to_string(i);

        // If this state has already been computed, return the stored result
        if (mp.find(findy) != mp.end()) 
            return mp[findy];

        ll take = 0;

        // Check the balanced condition before including nums[i] in the sum
        if (prevelement == -1 || nums[i] - i >= nums[prevelement] - prevelement) {
            take = (ll)nums[i] + hlo(nums, i + 1, i);  // Include current element and move forward
        }

        // Skip the current element
        ll nottaken = hlo(nums, i + 1, prevelement);

        // Store the result in the memoization map and return the maximum of both choices
        return mp[findy] = max<ll>(take, nottaken);
    }

    // Main function to initiate the recursion and return the final result
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();

        // Handle case when all elements are negative; return the max element directly
        long long ans = *max_element(begin(nums), end(nums));
        if (ans <= 0) 
            return ans;

        // Start recursive process with no previous element selected
        return hlo(nums, 0, -1);
    }
};
