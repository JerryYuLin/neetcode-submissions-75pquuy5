class Solution:
    def isValid(self, s: str) -> bool:
        left_bracket = {'(':')', '{':'}', '[':']'}
        right_bracket = {')', '}', ']'}

        bracket_buffer = []

        for ch in s:
            if ch in left_bracket:
                bracket_buffer.append(left_bracket[ch])
            else:
                if not bracket_buffer or bracket_buffer.pop() != ch:
                    return False
        
        if bracket_buffer:
            return False
        
        return True