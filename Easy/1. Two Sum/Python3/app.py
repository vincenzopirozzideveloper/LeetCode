def two_sum(nums, target):
    # Dizionario per memorizzare i numeri e i loro indici
    num_map = {}
    # Iteriamo attraverso l'array di numeri
    for i, num in enumerate(nums):
        # Calcoliamo il complemento che, se sommato al numero corrente, dà il target
        complement = target - num
        # Controlliamo se il complemento è già nel dizionario
        if complement in num_map:
            # Se troviamo il complemento, ritorniamo gli indici
            return [num_map[complement], i]
        # Altrimenti, aggiungiamo il numero corrente e il suo indice al dizionario
        num_map[num] = i
    # Se non troviamo nessuna coppia, ritorniamo un risultato vuoto (questo caso non dovrebbe mai verificarsi dato il problema)
    return []


# Esempio di utilizzo della funzione
print(two_sum([2, 7, 11, 15], 9))  # Output: [0, 1]
print(two_sum([3, 2, 4], 6))       # Output: [1, 2]
print(two_sum([3, 3], 6))          # Output: [0, 1]
