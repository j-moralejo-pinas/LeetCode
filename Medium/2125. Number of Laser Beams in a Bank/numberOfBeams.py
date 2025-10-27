from itertools import islice
class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        total_lasers = 0
        prev_floor_lasers = bank[0].count("1")
        for floor in islice(bank, 1, None):
            curr_lasers = floor.count("1")
            if curr_lasers > 0:
                total_lasers += curr_lasers * prev_floor_lasers
                prev_floor_lasers = curr_lasers
        return total_lasers
