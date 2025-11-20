#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        /*
         * Greedy approach: Sort intervals by end point and add numbers as needed.
         * 
         * Time Complexity: O(n log n) - dominated by sorting
         * Space Complexity: O(1) - only tracking two numbers
         */
        
        // Sort by end point, then by start point
        // This maximizes the chance that our chosen numbers cover multiple intervals
        sort(intervals.begin(), intervals.end(), 
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[1] != b[1]) return a[1] < b[1];  // Sort by end
                 return a[0] < b[0];  // Then by start
             });
        
        int result = 0;
        
        // Track the two largest numbers we've added to our set
        // We only need two since each interval requires exactly 2 numbers
        int p1 = -1, p2 = -1;  // Invariant: p1 < p2
        
        for (const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            
            // Determine how many of our tracked numbers fall in this interval
            
            // Case 1: Neither p1 nor p2 is in [start, end]
            // This happens when p2 < start
            if (p2 < start) {
                // Need to add 2 new numbers
                // Choose the two largest: end-1 and end (greedy choice)
                p1 = end - 1;
                p2 = end;
                result += 2;
            }
            // Case 2: Only p2 is in the interval, p1 is too small
            // This happens when p1 < start but p2 >= start
            else if (p1 < start && start <= p2) {
                // We have 1 number already, need 1 more
                if (end == p2) {
                    // p2 is already at the end of interval
                    // Add end-1 to get a new distinct number
                    p1 = end - 1;
                    // p2 stays the same
                } else {
                    // Add end as the new largest number
                    p1 = p2;
                    p2 = end;
                }
                result += 1;
            }
            // Case 3: Both p1 and p2 are in [start, end]
            // (when start <= p1 < p2)
            // Already satisfied, do nothing
        }
        
        return result;
    }
};
