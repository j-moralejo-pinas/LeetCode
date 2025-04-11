class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        # Ordeno
        nums.sort()
        biggest_subset_length = []
        biggest_idx = -1
        biggest_size = 0
        for idx, n in enumerate(nums):
            biggest_subset_length.append(1)
            for j in range(idx - 1, -1, -1):
                if (
                    n % nums[j] == 0
                    and biggest_subset_length[-1] <= biggest_subset_length[j]
                ):
                    biggest_subset_length[-1] = biggest_subset_length[j] + 1
            if biggest_subset_length[-1] > biggest_size:
                biggest_size = biggest_subset_length[-1]
                biggest_idx = idx

        biggest_list = [nums[biggest_idx]]

        for idx in range(biggest_idx - 1, -1, -1):
            if biggest_list[-1] % nums[idx] == 0:
                biggest_list.append(nums[idx])
        return biggest_list

    def largestDivisibleSubset_b(self, nums: List[int]) -> List[int]:
        # Ordeno
        nums.sort()
        biggest_subsets = []
        biggest_subset = set()
        for idx, n in enumerate(nums):
            biggest_subsets.append(set([n]))
            dont_check_set = set()
            for j in range(idx - 1, -1, -1):
                if nums[j] not in dont_check_set and n % nums[j] == 0:
                    dont_check_set.update(biggest_subsets[j])
                    if len(biggest_subsets[-1]) <= len(biggest_subsets[j]):
                        biggest_subsets[-1] = set([n])
                        biggest_subsets[-1].update(biggest_subsets[j])
            if len(biggest_subsets[-1]) > len(biggest_subset):
                biggest_subset = biggest_subsets[-1]
        print(biggest_subsets)
        return list(biggest_subset)
