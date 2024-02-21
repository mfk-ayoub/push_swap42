 # Push Swap: Sorting Using Two Stacks
![Push Swap](https://miro.medium.com/v2/resize:fit:720/format:webp/1*_qUuB7vQ716KuLp6bx3-oQ.png)

## Introduction

This project aims to implement a sorting algorithm for an array of integers using two stacks, namely Stack A and Stack B. The objective is to sort the array in ascending order with the least number of instructions.

## Getting Started

### Prerequisites

- C compiler (gcc recommended)
- Make build system (optional but recommended)

### Installation

Clone the repository:

`git clone https://github.com/mfk-ayoub/push_swap42`
- and
  
`cd push_swap42`
### Building the Project
`make`
## Run Project
  # Example:

`./push_swap 4 67 2 10 34`
### Commands

The push swap algorithm uses a set of instructions to manipulate the stacks:

- `sa`: Swap the first two elements of stack A.
- `sb`: Swap the first two elements of stack B.
- `ss`: `sa` and `sb` combined.
- `pa`: Push the top element of stack A to stack B.
- `pb`: Push the top element of stack B to stack A.
- `ra`: Rotate stack A (shift all elements up by one).
- `rb`: Rotate stack B (shift all elements up by one).
- `rr`: `ra` and `rb` combined.
- `rra`: Reverse rotate stack A (shift all elements down by one).
- `rrb`: Reverse rotate stack B (shift all elements down by one).
- `rrr`: `rra` and `rrb` combined.
