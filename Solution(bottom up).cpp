class Solution {
public:
    typedef long long ll;

    // Function to calculate the maximum sum of a balanced subsequence.
    // A balanced subsequence is defined by the condition: nums[j] - j <= nums[i] - i
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        vector<ll> ans(n, 0);  // ans[i] stores the maximum balanced subsequence sum ending at index i
        ll maxans = nums[0];   // Initialize max answer with the first element

        for (int i = 0; i < n; i++) {
            ans[i] = nums[i];  // Each subsequence starts with at least the current element

            // Check for all previous elements that satisfy the balanced condition
            for (int j = 0; j < i; j++) {
                if (nums[j] - j <= nums[i] - i) {
                    // Update ans[i] if extending the subsequence ending at j increases the sum
                    ans[i] = max(ans[i], ans[j] + nums[i]);
                }
            }

            // Update the global maximum subsequence sum
            maxans = max(maxans, ans[i]);
        }

        return maxans;  // Return the maximum balanced subsequence sum
    }
};
