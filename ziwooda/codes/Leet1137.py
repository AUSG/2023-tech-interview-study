''' 
Dynamic Programming Practice: N-th Tribonacci Number
'''
import collections

class Solution:
    dp = collections.defaultdict(int)

    def tribonacci(self, n: int) -> int:
        self.dp[0] = 0
        self.dp[1] = self.dp[2] = 1

        for i in range(3, n+1):
            self.dp[i] = self.dp[i-1] + self.dp[i-2] + self.dp[i-3]

        return self.dp[n]
