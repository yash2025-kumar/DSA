from collections import deque

class Solution:
    def minMoves(self, classroom: list[str], energy: int) -> int:
        R, C = len(classroom), len(classroom[0])
        
        # Locate start position and map each 'L' to an index
        start_r, start_c = -1, -1
        litter_map = {}
        
        for r in range(R):
            for c in range(C):
                if classroom[r][c] == 'S':
                    start_r, start_c = r, c
                elif classroom[r][c] == 'L':
                    litter_map[(r, c)] = len(litter_map)
                    
        total_litter = len(litter_map)
        target_mask = (1 << total_litter) - 1
        
        # Queue stores (r, c, mask, current_energy, moves)
        queue = deque([(start_r, start_c, 0, energy, 0)])
        
        # Visited dictionary to store max energy found for a given (r, c, mask)
        visited = {}
        visited[(start_r, start_c, 0)] = energy
        
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        
        while queue:
            r, c, mask, curr_energy, moves = queue.popleft()
            
            if mask == target_mask:
                return moves
                
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                
                if 0 <= nr < R and 0 <= nc < C and classroom[nr][nc] != 'X':
                    next_energy = curr_energy - 1
                    
                    if next_energy < 0:
                        continue
                        
                    next_mask = mask
                    if classroom[nr][nc] == 'L':
                        idx = litter_map[(nr, nc)]
                        next_mask |= (1 << idx)
                        
                    next_energy_val = next_energy
                    if classroom[nr][nc] == 'R':
                        next_energy_val = energy
                        
                    state_key = (nr, nc, next_mask)
                    if state_key not in visited or visited[state_key] < next_energy_val:
                        visited[state_key] = next_energy_val
                        queue.append((nr, nc, next_mask, next_energy_val, moves + 1))
                        
        return -1

        