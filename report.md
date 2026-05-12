# Emergency Room Priority System — Report

## How the Heap Works

We use a **max-heap** to manage patients. The heap is stored in a `vector`, but it behaves like a binary tree.

- Every parent node has a higher (or equal) priority than its children.
- Priority rule: **higher severity first**. If two patients have the same severity, the one who **arrived earlier** comes first.
- When we insert a patient, we put them at the end and **bubble them up** (`heapifyUp`) until the heap rule is satisfied.
- When we treat (remove) the top patient, we swap the root with the last element, remove the end, and **bubble down** (`heapifyDown`) to fix the heap.

That’s basically it. The vector makes it easy because we can access any index directly, and we don’t need pointers or a real tree structure.

## Why It’s Efficient

| Operation | Time Complexity | Why |
|-----------|----------------|-----|
| Insert    | O(log n)       | One element added, then swaps up the height of the tree. |
| Extract (treat next) | O(log n) | Swap root to end, then swaps down the height of the tree. |
| Peek (view next)     | O(1)     | Root is always at index 0. |

Because the heap is a complete binary tree, its height is always around `log₂(n)`. So even with 1,000 patients, you only need about 10 swaps. That’s very fast.

Compared to a regular array where you’d have to scan everything to find the highest priority patient (O(n)), the heap is way better for a system that keeps adding and removing patients all day.

## Comparison With Other Structures

| Structure | Insert | Extract Max | Notes |
|-----------|--------|-------------|-------|
| **Heap** | O(log n) | O(log n) | Best choice for this problem. Always balanced. |
| **Unsorted Array/List** | O(1) | O(n) | Fast to add, but treating a patient means scanning the whole list. |
| **Sorted Array** | O(n) | O(1) | Fast to treat, but inserting means shifting elements. |
| **BST (Balanced)** | O(log n) | O(log n) | Also works, but more complex to code and not as cache-friendly as a vector. |

For an emergency room, the heap is the sweet spot. It’s simple to write, fast enough, and uses very little memory overhead.

## Custom Heap vs STL priority_queue

We tested both our custom heap and C++’s built-in `priority_queue`.

- **Results**: Both produce the exact same patient order. That means our heap logic is correct.
- **Ease of use**: `priority_queue` is obviously easier — you just declare it and push/pop. But writing our own heap teaches us how it actually works under the hood, which is the whole point of the assignment.
- **Flexibility**: Our custom heap can be modified more easily if we want extra features later (like searching by patient ID to update severity). `priority_queue` doesn’t give you direct access to internal elements, so updating a specific patient is harder.

In real life, I’d probably use `priority_queue` for production code because it’s less code to maintain. But for learning, building it yourself is worth it.
