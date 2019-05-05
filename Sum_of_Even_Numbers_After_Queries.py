from typing import List
'''
class Solution:
    def sumEvenAfterQueries(self, A: List[int], queries: List[List[int]]) -> List[int]:
        answer = list()
        for querie in queries:
            A[querie[1]] += querie[0]
            answer.append(sum(a for a in A if not a % 2))
        return answer
'''
class Solution:
    def sumEvenAfterQueries(self, A: List[int], queries: List[List[int]]) -> List[int]:
        result = sum(a for a in A if not a % 2)
        answer = list()
        for querie in queries:
            if not A[querie[1]] % 2:
                result -= A[querie[1]]
            A[querie[1]] += querie[0]
            if not A[querie[1]] % 2:
                result += A[querie[1]]
            answer.append(result)
        return answer

A = [1, 2, 3, 4]
queries = [[1,0], [-3, 1], [-4, 0], [2, 3]]
sol = Solution()
print(sol.sumEvenAfterQueries(A, queries))