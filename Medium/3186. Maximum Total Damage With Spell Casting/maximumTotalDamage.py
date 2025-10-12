class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:
        power_counts = {}
        for p in power:
            power_counts[p] = power_counts.get(p, 0) + 1
        power_amount_list = [(k, v * k) for k, v in power_counts.items()]
        power_amount_list.append((-10, 0))
        power_amount_list.sort(key=lambda p: p[0])

        j = 0

        max_power = [0]

        max_val = 0

        for i in range(1, len(power_amount_list)):
            while j < i and power_amount_list[j][0] < power_amount_list[i][0] - 2:
                max_val = max(max_val, max_power[j])
                j += 1
            max_power.append(max_val + power_amount_list[i][1])
        return max(max_power[-3:])
