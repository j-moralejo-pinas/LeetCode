class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        adjacency_list = [[True, []] for _ in range(n)]

        for e1, e2 in edges:
            adjacency_list[e1][1].append(e2)
            adjacency_list[e2][1].append(e1)

        complete_components = 0
        open_list = []
        for element in adjacency_list:
            if element[0]:
                element[0] = False
                open_list.extend(element[1])
                nodes_in_component = 1
                n_edges = len(element[1])
                is_complete = True
                while open_list:
                    node = open_list.pop()
                    if adjacency_list[node][0]:
                        if len(adjacency_list[node][1]) != n_edges:
                            is_complete = False
                        nodes_in_component += 1
                        adjacency_list[node][0] = False
                        open_list.extend(adjacency_list[node][1])
                if is_complete and n_edges == nodes_in_component - 1:
                    complete_components += 1
        return complete_components
