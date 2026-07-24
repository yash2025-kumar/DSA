class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        n = len(nums)
        pair_xor = set()
        for i in range(n):
            for j in range(i, n):
                pair_xor.add(nums[i] ^ nums[j])

        triplet_xor = set()
        for p in pair_xor:
            for k in range(n):
                triplet_xor.add(p ^ nums[k])

        return len(triplet_xor)