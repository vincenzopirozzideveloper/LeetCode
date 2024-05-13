<?php

class Solution {
    function twoSum($nums, $target) {
        $numMap = [];
        for ($i = 0; $i < count($nums); $i++) {
            $complement = $target - $nums[$i];
            if (array_key_exists($complement, $numMap)) {
                return [$numMap[$complement], $i];
            }
            $numMap[$nums[$i]] = $i;
        }
        return null;  // Restituisce null se non trova nessuna soluzione
    }
}

// Test del codice
$solution = new Solution();
$nums = [2, 7, 11, 15];
$target = 9;
$result = $solution->twoSum($nums, $target);
echo "Indices: [" . implode(", ", $result) . "]\n";
?>
