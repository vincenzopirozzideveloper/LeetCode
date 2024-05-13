using System;
using System.Collections.Generic;

public class app {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> numMap = new Dictionary<int, int>();
        for (int i = 0; i < nums.Length; i++) {
            int complement = target - nums[i];
            if (numMap.ContainsKey(complement)) {
                return new int[] { numMap[complement], i };
            }
            numMap[nums[i]] = i;
        }
        throw new Exception("No two sum solution found");
    }
}

public class Program {
    public static void Main(string[] args) {
        app sol = new app();
        int[] nums = {2, 7, 11, 15};
        int target = 9;
        int[] indices = sol.TwoSum(nums, target);
        Console.WriteLine("Indices: [" + indices[0] + ", " + indices[1] + "]");
    }
}
