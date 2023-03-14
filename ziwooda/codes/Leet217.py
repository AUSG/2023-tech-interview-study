'''
Sort Practice: Contains Duplicate
'''

# dict 자료형 활용한 풀이
class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        num = {}
        for i in nums:
            if i not in num:
                num[i] = 1
            else:
                return True
        return False

# Set 자료형 활용한 풀이
class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        n = set(nums)
        if len(nums) != len(n):     return True
        return False

# 한줄풀이
class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        return len(nums) != len(set(nums))
