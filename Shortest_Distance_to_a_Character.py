from typing import List
class Solution:
    def shortestToChar(self, S: str, C: str) -> List[int]:
        Ssize = len(S)
        answer = list()
        E = list()
        for i in range(Ssize):
            if S[i] == C:
                E.append(i)
        for i in range(Ssize):
            answer.append(min([abs(e-i) for e in E]))
        return answer

S = 'loveleetcode'
C = 'e'
sol = Solution()
print(sol.shortestToChar(S, C))