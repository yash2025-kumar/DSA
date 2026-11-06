class Solution:
    def countServers(self, n: int, logs: List[List[int]], x: int, queries: List[int]) -> List[int]:
        logs.sort(key=lambda item: item[1])
        sorted_queries = sorted(enumerate(queries), key=lambda item: item[1])

        ans = [0] * len(queries)
        server_counts = Counter()

        j = 0
        k = 0

        for original_idx, query_time in sorted_queries:
            left_bound = query_time - x

            while k < len(logs) and logs[k][1] <= query_time:
                server_id = logs[k][0]
                server_counts[server_id] += 1
                k += 1
            
            while j < len(logs) and logs[j][1] < left_bound:
                server_id = logs[j][0]
                server_counts[server_id] -= 1
                if server_counts[server_id] == 0:
                    del server_counts[server_id]
                j += 1

            ans[original_idx] = n - len(server_counts)

        return ans