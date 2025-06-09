class Solution:
    def countNextLevel(self, num: int, n: int, ret_list: List[int]) -> None:
        for i in range(10):
            new_num = num + i
            if new_num <= n:
                ret_list.append(new_num)
                self.countNextLevel(new_num * 10, n, ret_list)

    def lexicalOrder(self, n: int) -> List[int]:
        ret_list = []

        num = 1
        for i in range(9):
            new_num = num + i
            if new_num <= n:
                ret_list.append(new_num)
                self.countNextLevel(new_num * 10, n, ret_list)

        return ret_list
