class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.num_sets = n
    def find(self, i):
        if self.parent[i] == i:
            return i
        self.parent[i] = self.find(self.parent[i])
        return self.parent[i]
    def union(self, i, j):
        root_i = self.find(i)
        root_j = self.find(j)
        if root_i != root_j:
            self.parent[root_i] = root_j
            self.num_sets -= 1
            return True
        return False

class Solution:
    def maxStability(self, n: int, edges: list[list[int]], k: int) -> int:
        # Sort by musti (desc) then strength (desc) to prioritize mandatory and high-strength
        edges.sort(key=lambda x: (-x[3], -x[2]))
        
        def check(min_s):
            uf = UnionFind(n)
            upgrades_needed = 0
            edges_count = 0
            
            # 1. Add mandatory edges first
            for u, v, s, m in edges:
                if m == 1:
                    if not uf.union(u, v):
                        return False # Cycle in mandatory edges
                    edges_count += 1
                    if s < min_s: return False # Mandatory edge too weak
            
            # 2. Add optional edges (not upgraded)
            for u, v, s, m in edges:
                if m == 0 and s >= min_s:
                    if uf.union(u, v):
                        edges_count += 1
            
            # 3. Add optional edges (upgraded)
            for u, v, s, m in edges:
                if m == 0 and s < min_s and 2 * s >= min_s:
                    if uf.union(u, v):
                        upgrades_needed += 1
                        edges_count += 1
            
            return uf.num_sets == 1 and upgrades_needed <= k

        # Binary Search on the answer (minimum strength)
        low = 1
        high = 2 * 10**5 + 7 # Max possible strength * 2
        ans = -1
        
        while low <= high:
            mid = (low + high) // 2
            if check(mid):
                ans = mid
                low = mid + 1
            else:
                high = mid - 1
                
        return ans

        