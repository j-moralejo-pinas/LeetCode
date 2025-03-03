class Solution:
    def pivotArray_min_memory_fail(self, nums: List[int], pivot: int) -> List[int]:
        for i in range(1, len(nums)):
            j = i - 1
            if nums[j] >= pivot and nums[i] < pivot:
                while j >= 0 and nums[j] >= pivot:
                    nums[j], nums[j + 1] = nums[j + 1], nums[j]
                    j -= 1
            elif nums[j] > pivot and nums[i] == pivot:
                while j >= 0 and nums[j] > pivot:
                    nums[j], nums[j + 1] = nums[j + 1], nums[j]
                    j -= 1
        return nums

    def pivotArray_low_memory(self, nums: List[int], pivot: int) -> List[int]:
        aux_list = []
        curr_pos = 0

        for elem in nums:
            if elem > pivot:
                aux_list.append(elem)
            elif elem < pivot:
                nums[curr_pos] = elem
                curr_pos += 1

        for i in range(len(nums) - len(aux_list) - curr_pos):
            nums[curr_pos] = pivot
            curr_pos += 1

        for e in aux_list:
            nums[curr_pos] = e
            curr_pos += 1

        return nums

    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        lesser_list = []
        greater_list = []

        for e in nums:
            if e < pivot:
                lesser_list.append(e)
            elif e > pivot:
                greater_list.append(e)
        nums = (
            lesser_list
            + [pivot] * (len(nums) - len(lesser_list) - len(greater_list))
            + greater_list
        )

        return nums

    def pivotArray3(self, nums: List[int], pivot: int) -> List[int]:
        lesser_list = []
        greater_list = []
        count_pivot = 0
        for i in nums:
            if i < pivot:
                lesser_list.append(i)
            elif i > pivot:
                greater_list.append(i)
            else:
                count_pivot += 1
        nums.clear()
        nums = [*lesser_list, *([pivot] * count_pivot), *greater_list]
        return nums
