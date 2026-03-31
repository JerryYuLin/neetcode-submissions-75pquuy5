class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        columns = [set() for _ in range(9)]
        rows = [set() for _ in range(9)]
        subs = [set() for _ in range(9)]

        for i, r in enumerate(board):
            for j, n in enumerate(r):
                if n == ".":
                    continue
                
                sub_row = int(i/3)
                sub_column = int(j/3)
                sub_index = 3 * sub_row + sub_column
                if n in rows[i] or n in columns[j] or n in subs[sub_index]:
                    return False
                else:
                    rows[i].add(n)
                    columns[j].add(n)
                    subs[sub_index].add(n)
        return True
        