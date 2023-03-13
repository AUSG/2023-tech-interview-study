'''
Dynamic Programming Practice: Climbing Stairs
'''

import collections

class Solution:
    stairs = collections.defaultdict(int)

    def climbStairs(self, n: int) -> int:
        self.stairs[1] = 1
        self.stairs[2] = 2

        for i in range(3, n+1):
            self.stairs[i] = self.stairs[i-1] + self.stairs[i-2]
        return self.stairs[n]