class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        last_node = n - 1
        adjacency = [[] for _ in range(n)]
        for r in roads:
            adjacency[r[0]].append((r[2], r[1]))
            adjacency[r[1]].append((r[2], r[0]))

        priority_queue = [(0, 0)]

        best_cost = [math.inf] * n
        best_cost[0] = 0
        best_paths = [0] * n
        best_paths[0] = 1

        while priority_queue:
            curr_dist, curr_node = heapq.heappop(priority_queue)
            if curr_dist > best_cost[curr_node]:
                continue
            for dist, node in adjacency[curr_node]:
                new_dist = curr_dist + dist
                if new_dist < best_cost[node]:
                    best_cost[node] = new_dist
                    best_paths[node] = best_paths[curr_node]
                    heapq.heappush(priority_queue, (new_dist, node))
                elif new_dist == best_cost[node]:
                    best_paths[node] += best_paths[curr_node]
            adjacency[curr_node] = []

        return best_paths[last_node] % 1000000007
