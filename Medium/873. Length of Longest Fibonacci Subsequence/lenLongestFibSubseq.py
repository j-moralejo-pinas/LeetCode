class Solution:

    def recursive_search(
        self,
        arr: List[int],
        num_to_idx: Dict[int, int],
        element_pair_length: List[List[bool]],
        first_idx: int,
        second_idx: int,
    ) -> int:
        if element_pair_length[first_idx][second_idx]:
            return 0
        element_sum = arr[first_idx] + arr[second_idx]
        if element_sum in num_to_idx:
            new_second_idx = num_to_idx[element_sum]
            element_pair_length[second_idx][new_second_idx] = True
            new_length = (
                self.recursive_search(
                    arr, num_to_idx, element_pair_length, second_idx, new_second_idx
                )
                + 1
            )
            return new_length
        else:
            return 2

    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        num_to_idx: Dict[int, int] = {el: idx for idx, el in enumerate(arr)}
        element_pair_length: List[List[bool]] = [
            [False for i in range(len(arr))] for j in range(len(arr))
        ]

        max_length = 0

        for i in range(len(arr) - 2):
            for j in range(i + 1, len(arr) - 1):
                if arr[i] + arr[j] > arr[-1]:
                    break
                if element_pair_length[i][j]:
                    max_length = max(max_length, 0)

                else:
                    max_length = max(
                        max_length,
                        self.recursive_search(arr, num_to_idx, element_pair_length, i, j),
                    )

        return max_length if max_length > 2 else 0
