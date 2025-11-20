class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        """
        Greedy approach: Sort intervals by end point and add numbers as needed.

        Time Complexity: O(n log n) - dominated by sorting
        Space Complexity: O(1) - only tracking two numbers
        """
        # Sort by end point, then by start point
        # This maximizes the chance that our chosen numbers cover multiple intervals
        intervals.sort(key=lambda x: (x[1], x[0]))

        result = 0

        # Track the two largest numbers we've added to our set
        # We only need two since each interval requires exactly 2 numbers
        p1, p2 = -1, -1  # Invariant: p1 < p2

        for start, end in intervals:
            # Determine how many of our tracked numbers fall in this interval

            # Case 1: Neither p1 nor p2 is in [start, end]
            # This happens when p2 < start
            if p2 < start:
                # Need to add 2 new numbers
                # Choose the two largest: end-1 and end (greedy choice)
                p1, p2 = end - 1, end
                result += 2

            # Case 2: Only p2 is in the interval, p1 is too small
            # This happens when p1 < start but p2 >= start
            elif p1 < start <= p2:
                # We have 1 number already, need 1 more
                # Add the largest number from this interval
                if end == p2:
                    # p2 is already at the end of interval
                    # Add end-1 to get a new distinct number
                    p1 = end - 1
                    # p2 stays the same
                else:
                    # Add end as the new largest number
                    p1 = p2
                    p2 = end
                result += 1

            # Case 3: Both p1 and p2 are in [start, end]
            # (when start <= p1 < p2)
            # Already satisfied, do nothing

        return result
