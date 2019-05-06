from typing import List

class Solution:
    def Filter(self, num: int) -> bool:
        copy = num
        while copy != 0:
            digit = copy % 10
            if digit == 0 or num % digit:
                return False
            copy //= 10
        return True
    '''
    def FilterStr(self, num: int) -> bool:
        digits = str(num)
        for digit in digits:
            if digit == '0' or num % int(digit):
                return False
        return True
    '''
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        answer = list()
        for i in range(left, right+1):
            if self.Filter(i):
                answer.append(i)
        return answer

sol = Solution()
left = 1
right = 1000
print(sol.selfDividingNumbers(left, right))
