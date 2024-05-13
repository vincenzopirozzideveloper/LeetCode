function twoSum(nums: number[], target: number): number[] {
    const numMap: { [key: number]: number } = {};  // Using an object as a map
    for (let i = 0; i < nums.length; i++) {
        const num = nums[i];
        const complement = target - num;
        if (complement in numMap) {
            return [numMap[complement], i];
        }
        numMap[num] = i;
    }
    return [];
}

// Testing the function
console.log(twoSum([2, 7, 11, 15], 9));  // Output: [0, 1]
console.log(twoSum([3, 2, 4], 6));       // Output: [1, 2]
console.log(twoSum([3, 3], 6));          // Output: [0, 1]
