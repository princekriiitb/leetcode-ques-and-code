#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        // Structure to hold interval data alongside the original index
        struct Interval {
            int start, end, weight, id;
        };
        
        vector<Interval> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        
        // Sort intervals based on start time
        sort(arr.begin(), arr.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        
        // Extract start times to utilize std::upper_bound for binary searching
        vector<int> starts(n);
        for (int i = 0; i < n; ++i) {
            starts[i] = arr[i].start;
        }
        
        // dp[i][k] stores a pair of {max_weight, chosen_indices} 
        // for the suffix starting at index 'i' with at most 'k' intervals chosen.
        // Using long long for weight to prevent integer overflow.
        using State = pair<long long, vector<int>>;
        vector<vector<State>> dp(n + 1, vector<State>(5, {0LL, {}}));
        
        for (int i = n - 1; i >= 0; --i) {
            // Find the first interval that starts strictly after the current interval ends
            int next_i = upper_bound(starts.begin(), starts.end(), arr[i].end) - starts.begin();
            
            for (int k = 1; k <= 4; ++k) {
                // Choice 1: Skip the current interval
                long long skip_weight = dp[i + 1][k].first;
                const vector<int>& skip_indices = dp[i + 1][k].second;
                
                // Choice 2: Take the current interval
                long long take_weight = arr[i].weight + dp[next_i][k - 1].first;
                vector<int> take_indices = dp[next_i][k - 1].second;
                take_indices.push_back(arr[i].id);
                
                // Sort the selected indices to maintain the lexicographical requirement
                sort(take_indices.begin(), take_indices.end());
                
                // Decision logic: Maximize weight, break ties using std::vector's built-in lexicographical operator '<'
                if (take_weight > skip_weight) {
                    dp[i][k] = {take_weight, take_indices};
                } else if (take_weight < skip_weight) {
                    dp[i][k] = {skip_weight, skip_indices};
                } else {
                    if (take_indices < skip_indices) {
                        dp[i][k] = {take_weight, take_indices};
                    } else {
                        dp[i][k] = {skip_weight, skip_indices};
                    }
                }
            }
        }
        
        return dp[0][4].second;
    }
};