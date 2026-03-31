class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        s_count = {}

        for c in s:
            if c in s_count:
                s_count[c] += 1
            else:
                s_count[c] = 1
        
        for c in t:
            if c in s_count:
                s_count[c] -= 1

                if s_count[c] < 0:
                    return False
            else:
                return False
        return True
        