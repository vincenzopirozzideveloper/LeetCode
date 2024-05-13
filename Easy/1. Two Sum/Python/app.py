# type: ignore 
# This directive tells the Python type checker (Pylance) to ignore type checking for this line/file, useful for bypassing unresolved import errors or incompatible library usage.
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        num_map = {}  # Dizionario per tenere traccia degli indici dei numeri
        for i, num in enumerate(nums):
            complement = target - num
            if complement in num_map:
                return [num_map[complement], i]
            num_map[num] = i
        return []  # Restituisce una lista vuota se non viene trovata nessuna soluzione

# Codice per testare la funzione
if __name__ == "__main__":
    sol = Solution()
    nums = [2, 7, 11, 15]
    target = 9
    print sol.twoSum(nums, target)  # Output atteso: [0, 1]
