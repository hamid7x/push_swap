*This project has been created as part of the 42 curriculum by houkaamo.*

# Push_swap

## Description

`Push_swap` is a sorting algorithm project from the 42 curriculum that involves sorting data on a stack with a limited set of instructions. The goal is to sort integers using two stacks (A and B) with the **minimum number of operations possible**.

The project implements a **hybrid sorting strategy**:

1. **LIS (Longest Increasing Subsequence)**: Identifies the largest already-sorted subset in the initial stack to minimize moves.  
2. **Turk Algorithm**: Calculates optimal insertion costs for elements moving from stack B back to stack A.  
3. **Cost Optimization**: Determines rotation directions (up/down) for both stacks and executes simultaneous rotations when beneficial.

The algorithm handles three cases:

- **Size 2:** Simple swap  
- **Size 3-5:** Optimized small stack sorting  
- **Size 6+:** LIS + Turk algorithm approach  
---
### Available Operations
- **sa, sb, ss** → Swap top two elements

- **pa, pb** → Push between stacks

- **ra, rb, rr** → Rotate 

- **rra, rrb, rrr** → Reverse Rotate 

## Instructions

### Compilation

```
make
```
### Execution
```
./push_swap <list_of_integers>
```
### Example:
```
./push_swap 4 67 3 87 23
```

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

## Technical Choices
- **LIS Strategy**: Keeps maximum sorted elements in place, reducing total moves

- **Cost-based Selection**: Greedy approach selecting locally optimal moves

- **Direction Optimization**: Uses rr/rrr when both stacks rotate in the same direction

- **Memory Management**: Dynamic allocation for LIS arrays with proper cleanup
## Resources
Longest Increasing Subsequence (GeeksforGeeks)

Push_swap Turk Algorithm (Medium)

42 School man pages: man 3 printf, man 3 malloc

AI Usage Disclosure
AI assistance was used for the following tasks:

Concept explanation: Understanding the LIS algorithm and Turk algorithm concepts

Code review: Reviewing cost calculation logic and rotation optimization

README composition: Structuring documentation and clarifying algorithm explanations

All core algorithm implementation, data structure design, and operation logic was written manually.

