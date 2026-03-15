class Fancy:

    def __init__(self):
        self.vals = []
        self.a = 1
        self.b = 0
        self.MOD = 10**9 + 7

    def append(self, val: int) -> None:
        inv_a = pow(self.a, self.MOD - 2, self.MOD)
        original_val = (val - self.b) * inv_a % self.MOD
        self.vals.append(original_val)

    def addAll(self, inc: int) -> None:
        self.b = (self.b + inc) % self.MOD

    def multAll(self, m: int) -> None:
        self.a = (self.a * m) % self.MOD
        self.b = (self.b * m) % self.MOD

    def getIndex(self, idx: int) -> int:
        if idx >= len(self.vals):
            return -1

        original_val = self.vals[idx]
        current_val = (self.a * original_val + self.b) % self.MOD
        return current_val


# Your Fancy object will be instantiated and called as such:
# obj = Fancy()
# obj.append(val)
# obj.addAll(inc)
# obj.multAll(m)
# param_4 = obj.getIndex(idx)