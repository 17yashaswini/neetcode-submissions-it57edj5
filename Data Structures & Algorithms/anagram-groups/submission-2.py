class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        result = {}
        for i in strs:
            key = tuple(sorted(i))
            result.setdefault(key,[]).append(i)
        return list(result.values())