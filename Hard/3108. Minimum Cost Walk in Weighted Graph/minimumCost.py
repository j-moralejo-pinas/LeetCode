class Solution:
    def minimumCost(
        self, n: int, edges: List[List[int]], query: List[List[int]]
    ) -> List[int]:
        edge_adj = [[] for _ in range(n)]
        for edge in edges:
            edge_adj[edge[0]].append((edge[1], edge[2]))
            edge_adj[edge[1]].append((edge[0], edge[2]))

        nodes_to_check = set(n for (q0, q1) in query for n in (q0, q1))

        component_cost = []
        node_to_component = [-1] * n
        curr_comp = 0
        for node in nodes_to_check:
            if node_to_component[node] < 0:
                open_list = edge_adj[node]
                edge_adj[node] = []
                node_to_component[node] = curr_comp
                total_cost = 131071
                while open_list:
                    closed, cost = open_list.pop()
                    total_cost &= cost
                    open_list.extend(edge_adj[closed])
                    edge_adj[closed] = []
                    node_to_component[closed] = curr_comp
                component_cost.append(total_cost)
                curr_comp += 1
        return [
            (
                component_cost[node_to_component[n1]]
                if node_to_component[n1] == node_to_component[n2]
                else -1
            )
            for (n1, n2) in query
        ]
