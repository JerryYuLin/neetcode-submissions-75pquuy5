class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        """
        :type tokens: List[str]
        :rtype: int
        """
        operator = {'+', '-', '*', '/'}
        n_stack = []

        for token in tokens:
            if token not in operator:
                n = int(token)
                n_stack.append(n)
            else:
                n1 = n_stack.pop()
                n2 = n_stack.pop()

                if token == '+':
                    result = n1 + n2
                elif token == '-':
                    result = n2 - n1
                elif token == '*':
                    result = n1 * n2
                else:
                    result = int(float(n2) / n1)

                n_stack.append(result)
        
        return n_stack[0]