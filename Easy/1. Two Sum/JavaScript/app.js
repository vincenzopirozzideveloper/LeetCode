/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const numMap = {};  // Oggetto per memorizzare i numeri e i loro indici
    for (let i = 0; i < nums.length; i++) {
        const num = nums[i];
        const complement = target - num;
        // Controlliamo se il complemento è già nel dizionario
        if (complement in numMap) {
            // Se troviamo il complemento, ritorniamo gli indici
            return [numMap[complement], i];
        }
        // Altrimenti, aggiungiamo il numero corrente e il suo indice al dizionario
        numMap[num] = i;
    }
    // Se non troviamo nessuna coppia, ritorniamo un risultato vuoto (questo caso non dovrebbe mai verificarsi dato il problema)
    return [];
};

// Esempio di utilizzo della funzione
console.log(twoSum([2, 7, 11, 15], 9));  // Output: [0, 1]
console.log(twoSum([3, 2, 4], 6));       // Output: [1, 2]
console.log(twoSum([3, 3], 6));          // Output: [0, 1]
