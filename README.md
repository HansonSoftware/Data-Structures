## Big O Notation

Big O notation is a way of describing the performance of an algorithm. It gives us an idea of how the runtime of an algorithm scales as the input size increases.

Big O notation uses mathematical notation to describe the upper bound of an algorithm's runtime. For example, an algorithm with a runtime of O(n) will take at most n steps to complete, where n is the size of the input.

Here are some common time complexities, in ascending order:

- O(1) (constant time) - the runtime is independent of the input size
- O(log n) (logarithmic time) - the runtime increases logarithmically with the input size
- O(n) (linear time) - the runtime increases linearly with the input size
- O(n log n) - the runtime increases with the product of the input size and the log of the input size
- O(n^2) (quadratic time) - the runtime is the square of the input size
- O(n^3) (cubic time) - the runtime is the cube of the input size
- O(2^n) (exponential time) - the runtime increases exponentially with the input size

It's important to note that Big O notation describes the worst-case runtime of an algorithm. There may be inputs for which the algorithm runs faster, but we are interested in the upper bound on the runtime.

## Data Structures

Here is a summary of the time complexities of common operations for some common data structures:

### Arrays

Arrays are simple data structures that store a contiguous block of memory.

| Operation  | Time Complexity |
|------------|----------------|
| Access     | O(1)           |
| Search     | O(n)           |
| Insertion  | O(n)           |
| Deletion   | O(n)           |

### Linked Lists

Linked lists are data structures that consist of a sequence of nodes, each containing a value and a pointer to the next node in the list.

| Operation  | Time Complexity |
|------------|----------------|
| Access     | O(n)           |
| Search     | O(n)           |
| Insertion  | O(1)           |
| Deletion   | O(1)           |

### Stacks

Stacks are data structures that support push and pop operations, with the last element added being the first element removed (last-in, first-out).

| Operation  | Time Complexity |
|------------|----------------|
| Access     | O(n)           |
| Search     | O(n)           |
| Push       | O(1)           |
| Pop        | O(1)           |
### Queues

Queues are data structures that support enqueue and dequeue operations, with the first element added being the first element removed (first-in, first-out).

| Operation  | Time Complexity |
|------------|----------------|
| Access     | O(n)           |
| Search     | O(n)           |
| Enqueue    | O(1)           |
| Dequeue    | O(1)           |

### Hash Tables

Hash tables are data structures that store key-value pairs and use a hash function to efficiently map keys to indices in an array.

| Operation  | Time Complexity |
|------------|----------------|
| Access     | O(1)           |
| Search     | O(1)           |
| Put        | O(1)           |
| Get        | O(1)           |

### Binary Search Trees

Binary search trees are data structures that store a tree of nodes, with each node containing a value and pointers to left and right child nodes. The left child must have a value less than its parent, and the right child must have a value greater than or equal to its parent.

| Operation  | Time Complexity |
|------------|----------------|
| Access     | O(h)           |
| Search     | O(h)           |
| Insertion  | O(h)           |
| Deletion   | O(h)           |

where h is the height of the tree. The height of a tree can range from O(log n) for a balanced tree to O(n) for a degenerate tree.

### Graphs

Graphs are data structures that consist of a set of vertices (nodes) and edges connecting them. There are many different types of graphs, and the time complexities of operations can vary depending on the specific implementation.

Here are the time complexities for some common operations on graphs:

| Operation  | Time Complexity |
|------------|----------------|
| Access     | O(1)           |
| Search     | O(v + e)       |
| Insertion  | O(1)           |
| Deletion   | O(1)           |

where v is the number of vertices and e is the number of edges.
