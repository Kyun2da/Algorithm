import collections
from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = collections.defaultdict(list)

        for word in strs:
            anagrams[''.join(sorted(word))].append(word)
        return anagrams.values()


sol1 = Solution()

print(sol1.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))
