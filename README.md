*This project has been created as part of the 42 curriculum by houkaamo.*

# Push_swap

## Description

`Push_swap` is a sorting algorithm project from the 42 curriculum that requires sorting data on a stack with a limited set of instructions. The goal is to sort integers using two stacks (A and B) with the **minimum number of operations possible**.

The project implements a **hybrid sorting strategy**:

1. **LIS (Longest Increasing Subsequence)**: Identifies the largest already-sorted subset in the initial stack to minimize moves.  
2. **Turk Algorithm**: Calculates optimal insertion costs for elements moving from stack B back to stack A.  
3. **Cost Optimization**: Determines rotation directions (up/down) for both stacks and executes simultaneous rotations when beneficial.

The algorithm handles three cases:

- **Size 2:** Simple swap  
- **Size 3-5:** Optimized small stack sorting  
- **Size 6+:** LIS + Turk algorithm approach  
---
### Allowed Operations
- **sa, sb, ss** → Swap top two elements

- **pa, pb** → Push between stacks

- **ra, rb, rr** → Rotate 

- **rra, rrb, rrr** → Reverse Rotate 

## Instructions

### Compilation

```
make
make bonus
```

### Execution:
```
➜  push_swap git:(main) ✗ ./push_swap 4 67 3 87 23
```

## Parsing & Error Handling

The program checks for:

- Invalid characters (non-numeric input)

- Duplicate numbers

- Integer overflow / underflow

- Empty arguments

- Already sorted input

If any error is detected:

- The program prints Error to stderr

- All allocated memory is freed

- The program exits immediately


## Algorithm Overview
  ### Phase 1: LIS Extraction
   
   - Computes the Longest Increasing Subsequence to identify elements that stay in stack A.

   - Pushes all non-LIS elements to stack B using pb.

### Phase 2: Turk Algorithm

   - For each element in stack B:

   - Calculate cost in B: Distance to top (rotation direction: Up or Down)

   - Find target in A: Smallest larger element (or minimum if none exists)

   - Calculate cost in A: Distance to bring target to top

   - Total cost: Sum of costs, or max if same direction (allows simultaneous rotation)

   - Execute: Move cheapest element to A, repeat until B is empty

### Phase 3: Final Rotation
   - Rotate stack A until the minimum element is at top

## Bonus: Checker Program

The bonus part includes a checker program that validates the correctness of the operations produced by push_swap.

How the Checker Works

- Parses the same input as push_swap

- Reads instructions from standard input

- Applies each operation to stacks A and B

- Verifies the final state

### Execution Example
```
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
OK
./checker 4 67 3 87 23
pb
pb
rra
KO
```
**Output:**

OK → Stack A is sorted and stack B is empty

KO → Sorting failed

## Technical Choices
- **LIS algorithm**: Keeps maximum sorted elements in place, reducing total moves

- **Cost-based Selection**: Greedy approach selecting locally optimal moves

- **Direction Optimization**: Uses rr/rrr when both stacks rotate in the same direction

- **Memory Management**: Dynamic allocation for arrays with proper cleanup


## Resources

- 42 Push Swap Subject PDF
  - **Turk algorithm**[https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)(medium)  
  - **Longest Increasing Subsequence**[https://en.wikipedia.org/wiki/Longest_increasing_subsequence](https://en.wikipedia.org/wiki/Longest_increasing_subsequence)(wikipedia)
  - **Longest Increasing Subsequence**[https://www.youtube.com/watch?v=MrPa5EFcDCU](https://www.youtube.com/watch?v=MrPa5EFcDCU)(tutorial)
## Use of AI
AI tools were used for:
- Clarify and understand concepts ( Longest Increasing Subsequence, Turk algorithm)
- Review algorithm logic and cost calculation strategies

