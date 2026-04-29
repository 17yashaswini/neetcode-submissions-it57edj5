class Solution:


    def encode(self, strs: List[str]) -> str:
        result = ""
        for i in range(len(strs)):
            result += str(len(strs[i])) + "#" + strs[i]
        return result

    def decode(self, s: str) -> List[str]:
        result = []
        i = 0
        while i < len(s):
            j = s.index('#',i)
            length = int(s[i:j])
            word = s[j+1 : j+1+length]
            result.append(word)
            i = j+1+length
        return result




