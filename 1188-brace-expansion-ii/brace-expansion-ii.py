class Solution:
    def braceExpansionII(self, expression: str) -> list[str]:
        def dfs(expr: str) -> set[str]:
            groups = [[]]
            layer = 0
            start = 0

            for i, c in enumerate(expr):
                if c == '{':
                    if layer == 0:
                        start = i + 1
                    layer += 1
                elif c == '}':
                    layer -= 1
                    if layer == 0:
                        inner_set = dfs(expr[start:i])
                        if not groups[-1]:
                            groups[-1] = list(inner_set)
                        else:
                            groups[-1] = [s1 + s2 for s1 in groups[-1] for s2 in inner_set]
                elif c == ',' and layer == 0:
                    groups.append([])
                elif layer == 0:
                    if not groups[-1]:
                        groups[-1] = [c]
                    else:
                        groups[-1] = [s + c for s in groups[-1]]

            return {word for group in groups for word in group}

        return sorted(list(dfs(expression)))