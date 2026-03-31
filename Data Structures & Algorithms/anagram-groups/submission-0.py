class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        str_map = {}
        for s in strs:
            s_sorted = ''.join(sorted(s))

            if s_sorted in str_map:
                str_map[s_sorted].append(s)
            else:
                str_map[s_sorted] = [s]

        ans = []
        for v in str_map.values():
            ans.append(v)
        return ans
