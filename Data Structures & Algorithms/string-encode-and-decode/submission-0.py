class Solution:

    def encode(self, strs: List[str]) -> str:
        s = ""
        for st in strs:
            s += "(s)" + st + "(/s)"
        return s

    def decode(self, s: str) -> List[str]:
        s_list = s.split("(/s)")
        ans_list = []
        for i, s in enumerate(s_list):
            if i == len(s_list)-1 and s == "":
                break

            ans_list.append(s.replace("(s)", ""))
        return ans_list
