''' Dynamic Programming Practice'''
''' 피보나치 수열'''
# 메모이제이션 기법 (Top-Down)
import collections

class Solution:
    d = collections.defaultdict(int)

    def fib(self, n: int) -> int:
        if n <= 1: return n
        if self.d[n] != 0: return self.d[n]
        
        self.d[n] = self.fib(n-1) + self.fib(n-2)
        return self.d[n]

# Tabulation 기법 (Bottom-Up)
class Solution:
    d = collections.defaultdict(int)
    
    def fib(self, n: int) -> int:
        self.d[0] = 0; self.d[1] = 1

        for i in range(2, n+1):
            self.d[i] = self.d[i-1] + self.d[i-2]
        return self.d[n]

        