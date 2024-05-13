import java.util.HashMap;

public class app {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> numMap = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (numMap.containsKey(complement)) {
                return new int[] {numMap.get(complement), i};
            }
            numMap.put(nums[i], i);
        }
        throw new IllegalArgumentException("No two sum solution");  // Se non viene trovata nessuna soluzione
    }

public static void main(String[] args) {
    app sol = new app();
    int[] nums = {2, 7, 11, 15};
    int target = 9;
    int[] indices = sol.twoSum(nums, target);
    System.out.println("Indices: [" + indices[0] + ", " + indices[1] + "]");
}

}
