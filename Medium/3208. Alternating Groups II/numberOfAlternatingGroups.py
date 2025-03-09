class Solution:

    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:

        alternating_count = 1

        alternating_groups = 0

        colors = colors + colors[: k - 1]

        for i in range(1, len(colors)):
            if colors[i] != colors[i - 1]:
                alternating_count += 1
                if alternating_count >= k:
                    alternating_groups += 1
            else:
                alternating_count = 1

        return alternating_groups

    def numberOfAlternatingGroups_less_speed_and_memory(self, colors: List[int], k: int) -> int:
        alternating_count = 1
        alternating_groups = 0
        len_colors = len(colors)

        for i in range(1, len_colors + k - 1):
            if colors[i % len_colors] != colors[(i - 1) % len_colors]:
                alternating_count += 1
                if alternating_count >= k:
                    alternating_groups += 1
            else:
                alternating_count = 1

        return alternating_groups

    def numberOfAlternatingGroups_very_slow(self, colors: List[int], k: int) -> int:
        first_number = (1 << k + 1) // 3
        second_number = first_number >> 1
        mask = (1 << k) - 1

        curr_number = 0
        colors = colors + colors[: k - 1]
        alternating_groups = 0

        for i in range(k - 1):
            curr_number = (curr_number << 1) + colors[i]

        for i in range(k - 1, len(colors)):
            curr_number = ((curr_number << 1) + colors[i]) & mask
            if curr_number == first_number or curr_number == second_number:
                alternating_groups += 1
        return alternating_groups
