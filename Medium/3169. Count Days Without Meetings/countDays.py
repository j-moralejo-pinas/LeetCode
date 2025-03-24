class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        meetings.sort(key=lambda x: x[0], reverse=True)
        num_days = 0
        max_end_time = 0
        while meetings:
            meeting = meetings.pop()
            if meeting[0] > days:
                meetings.clear()
                break
            num_days += max(0, meeting[0] - max_end_time - 1)
            max_end_time = max(max_end_time, meeting[1])
        num_days += max(0, days - max_end_time)
        return num_days