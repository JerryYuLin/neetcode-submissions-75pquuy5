class Solution:
    def __init__(self):
        self.ans = []

    def generateParenthesis(self, n: int) -> List[str]:
        """
        :type n: int
        :rtype: List[str]
        """
        def insertParenthesis(n, current_string, left_p_num, right_p_num):
            if left_p_num < n:
                insertParenthesis(n, current_string+"(", left_p_num+1, right_p_num)
            
            if right_p_num < left_p_num:
                insertParenthesis(n, current_string+")", left_p_num, right_p_num+1)
            
            if n == left_p_num and n == right_p_num:
                self.ans.append(current_string)

        insertParenthesis(n, "", 0, 0)
        return self.ans