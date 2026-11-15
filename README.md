# LeetCode Solutions

C++ solutions to LeetCode problems, written as interview preparation alongside the **ITI Embedded Systems** program.
Each entry lists the approach and its time and space complexity.

**Solved: 42** (20 Easy · 17 Medium · 5 Hard)

| Track | Status |
|-------|--------|
| ITI DSA Challenge | ✅ 16 / 16 complete (5 Hard) |
| Manara Flexible | ✅ Modules 2–3 complete · 🔄 Module 4: 1 / 4 |

---

## ITI DSA Challenge ✅ 16 / 16

### Arrays / Vectors

| # | Problem | Difficulty | Approach | Time | Space | Solution |
|---|---------|------------|----------|------|-------|----------|
| 238 | [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) | Medium | Prefix products stored in the output array, then a right-to-left pass with a running suffix product. No division | O(n) | O(1) extra | [238_product-of-array-except-self.cpp](Problems/238_product-of-array-except-self.cpp) |
| 11 | [Container With Most Water](https://leetcode.com/problems/container-with-most-water/) | Medium | Two pointers from both ends; always move the shorter line, since it can never form a larger container | O(n) | O(1) | [11_container-with-most-water.cpp](Problems/11_container-with-most-water.cpp) |
| 41 | [First Missing Positive](https://leetcode.com/problems/first-missing-positive/) | Hard | Replace values outside `1..n` with `n + 1`, mark each seen value `v` by negating `nums[v − 1]`, then return the first unmarked index | O(n) | O(1) | [41_first-missing-positive.cpp](Problems/41_first-missing-positive.cpp) |

### Linked Lists

| # | Problem | Difficulty | Approach | Time | Space | Solution |
|---|---------|------------|----------|------|-------|----------|
| 19 | [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) | Medium | Two pointers `n` nodes apart; when the fast one reaches the end, the slow one is just before the target | O(n) | O(1) | [19_remove-nth-node-from-end-of-list.cpp](Problems/19_remove-nth-node-from-end-of-list.cpp) |
| 142 | [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/) | Medium | Floyd's algorithm: fast/slow pointers meet inside the cycle, then one restarts at `head` and both move 1 step until they meet at the cycle start | O(n) | O(1) | [142_linked-list-cycle-ii.cpp](Problems/142_linked-list-cycle-ii.cpp) |
| 23 | [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/) | Hard | Pairwise "tournament" merging in place (step 1, 2, 4, …) with an iterative two-list merge | O(N log k) | O(1) | [23_merge-k-sorted-lists.cpp](Problems/23_merge-k-sorted-lists.cpp) |

### Stacks and Queues

| # | Problem | Difficulty | Approach | Time | Space | Solution |
|---|---------|------------|----------|------|-------|----------|
| 622 | [Design Circular Queue](https://leetcode.com/problems/design-circular-queue/) | Medium | Ring buffer: fixed `std::vector`, `head` / `tail` indices wrapped with `%`, and a `count` to tell empty from full | O(1) per op | O(k) | [622_design-circular-queue.cpp](Problems/622_design-circular-queue.cpp) |
| 239 | [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/) | Hard | Monotonic decreasing `std::deque` of indices: pop smaller values from the back, pop expired indices from the front | O(n) | O(k) | [239_sliding-window-maximum.cpp](Problems/239_sliding-window-maximum.cpp) |

### Binary Trees

| # | Problem | Difficulty | Approach | Time | Space | Solution |
|---|---------|------------|----------|------|-------|----------|
| 236 | [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) | Medium | Post-order: each call returns what it found; a node with results from both sides is the LCA | O(n) | O(h) | [236_lowest-common-ancestor-of-a-binary-tree.cpp](Problems/236_lowest-common-ancestor-of-a-binary-tree.cpp) |
| 105 | [Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) | Medium | Preorder gives the next root; a hash map finds its position in inorder, which splits the left and right subtrees | O(n) | O(n) | [105_construct-binary-tree-from-preorder-and-inorder-traversal.cpp](Problems/105_construct-binary-tree-from-preorder-and-inorder-traversal.cpp) |
| 124 | [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/) | Hard | Post-order: each node returns its best one-sided gain (negative sides dropped) and updates a global best with the bent path `left + node + right` | O(n) | O(h) | [124_binary-tree-maximum-path-sum.cpp](Problems/124_binary-tree-maximum-path-sum.cpp) |

### Binary Search Trees

| # | Problem | Difficulty | Approach | Time | Space | Solution |
|---|---------|------------|----------|------|-------|----------|
| 98 | [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/) | Medium | Recursion carrying an allowed `(min, max)` range for each node | O(n) | O(h) | [98_validate-binary-search-tree.cpp](Problems/98_validate-binary-search-tree.cpp) |
| 450 | [Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/) | Medium | Recursive search; 0 or 1 child → replace with the child; 2 children → copy the in-order successor, then delete it | O(h) | O(h) | [450_delete-node-in-a-bst.cpp](Problems/450_delete-node-in-a-bst.cpp) |
| 1008 | [Construct BST from Preorder Traversal](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/) | Medium | Iterative monotonic stack of nodes still waiting for a right child | O(n) | O(n) | [1008_construct-binary-search-tree-from-preorder-traversal.cpp](Problems/1008_construct-binary-search-tree-from-preorder-traversal.cpp) |
| 1382 | [Balance a Binary Search Tree](https://leetcode.com/problems/balance-a-binary-search-tree/) | Medium | In-order traversal → sorted values → rebuild recursively using the middle element as each root | O(n) | O(n) | [1382_balance-a-binary-search-tree.cpp](Problems/1382_balance-a-binary-search-tree.cpp) |
| 1373 | [Maximum Sum BST in Binary Tree](https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/) | Hard | Post-order: each subtree returns `{isBst, min, max, sum}`, so every node checks the BST rule in O(1) | O(n) | O(h) | [1373_maximum-sum-bst-in-binary-tree.cpp](Problems/1373_maximum-sum-bst-in-binary-tree.cpp) |

---

## Manara Flexible Progress

| Module | Topic | Progress | Status |
|--------|-------|----------|--------|
| 2 | Big O Notation | 3 / 3 | ✅ Complete |
| 3 | Arrays, Vectors, Linked Lists | 100% | ✅ Complete |
| 4 | Stacks, Queues, and Heaps | 1 / 4 | 🔄 In progress |

### Module 2: Big O Notation ✅

| # | Problem | Difficulty | Approach | Time | Space | Solution |
|---|---------|------------|----------|------|-------|----------|
| 231 | [Power of Two](https://leetcode.com/problems/power-of-two/) | Easy | Bit trick: `n & (n - 1)` clears the lowest set bit, so a power of two becomes 0 | O(1) | O(1) | [231_power-of-two.cpp](Problems/231_power-of-two.cpp) |
| 1360 | [Number of Days Between Two Dates](https://leetcode.com/problems/number-of-days-between-two-dates/) | Easy | Convert each date to days since 1971 (leap years + month lookup table), then subtract | O(1) | O(1) | [1360_number-of-days-between-two-dates.cpp](Problems/1360_number-of-days-between-two-dates.cpp) |
| 1662 | [Check If Two String Arrays are Equivalent](https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/) | Easy | Concatenate both arrays, then compare the strings | O(n) | O(n) | [1662_Check_If_Two_String_Arrays_Are_Equivalent.cpp](Problems/1662_Check_If_Two_String_Arrays_Are_Equivalent.cpp) |

### Module 3: Arrays, Vectors, Linked Lists ✅

| # | Problem | Difficulty | Approach | Time | Space | Solution |
|---|---------|------------|----------|------|-------|----------|
| 21 | [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) | Easy | Dummy head node + tail pointer; relink nodes in place | O(n + m) | O(1) | [21_merge-two-sorted-lists.cpp](Problems/21_merge-two-sorted-lists.cpp) |
| 121 | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | Easy | One pass: track the lowest price so far and the best profit | O(n) | O(1) | [121_best-time-to-buy-and-sell-stock.cpp](Problems/121_best-time-to-buy-and-sell-stock.cpp) |
| 125 | [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/) | Easy | Filter alphanumeric characters to lowercase, compare with the reverse | O(n) | O(n) | [125_valid-palindrome.cpp](Problems/125_valid-palindrome.cpp) |
| 141 | [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/) | Easy | Floyd's fast/slow pointers: they meet only if there is a cycle | O(n) | O(1) | [141_linked-list-cycle.cpp](Problems/141_linked-list-cycle.cpp) |
| 143 | [Reorder List](https://leetcode.com/problems/reorder-list/) | Medium | Find the middle → reverse the second half → interleave the two halves | O(n) | O(1) | [143_reorder-list.cpp](Problems/143_reorder-list.cpp) |
| 1991 | [Find the Middle Index in Array](https://leetcode.com/problems/find-the-middle-index-in-array/) | Easy | Total sum, then prefix sum: right sum = total − left − current | O(n) | O(1) | [1991_find-the-middle-index-in-array.cpp](Problems/1991_find-the-middle-index-in-array.cpp) |

### Module 4: Stacks, Queues, and Heaps 🔄

| # | Problem | Difficulty | Approach | Time | Space | Solution |
|---|---------|------------|----------|------|-------|----------|
| 496 | [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/) | Easy | Monotonic decreasing stack over `nums2` + hash map for answers | O(n + m) | O(n) | [496_next-greater-element-i.cpp](Problems/496_next-greater-element-i.cpp) |
| 215 | [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/) | Medium | ⏳ Next | | | |
| 973 | [K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/) | Medium | ⏳ Pending | | | |
| 347 | [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/) | Medium | ⏳ Pending | | | |

---

## ITI Tasks

| # | Problem | Difficulty | Approach | Time | Space | Solution |
|---|---------|------------|----------|------|-------|----------|
| 1 | [Two Sum](https://leetcode.com/problems/two-sum/) | Easy | Hash map from value to index; look up `target − x`. Also includes the brute-force version | O(n) · brute O(n²) | O(n) · brute O(1) | [0001-Two_Sum.cpp](Problems/0001-Two_Sum.cpp) |

---

## Additional Practice

### Arrays and Subarrays

| # | Problem | Difficulty | Approach | Time | Space | Solution |
|---|---------|------------|----------|------|-------|----------|
| 53 | [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) | Medium | Kadane's algorithm: extend the current subarray or start fresh at each element | O(n) | O(1) | [53_maximum-subarray.cpp](Problems/53_maximum-subarray.cpp) |
| 918 | [Maximum Sum Circular Subarray](https://leetcode.com/problems/maximum-sum-circular-subarray/) | Medium | Kadane for both max and min subarray; the wrapping answer is `total − min` (unless all values are negative) | O(n) | O(1) | [918_maximum-sum-circular-subarray.cpp](Problems/918_maximum-sum-circular-subarray.cpp) |
| 442 | [Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array/) | Medium | Mark each seen value by negating `nums[v − 1]`; already negative = duplicate | O(n) | O(1) | [0442_find_all_duplicates_in_array.cpp](Problems/0442_find_all_duplicates_in_array.cpp) |

### Stacks and Queues

| # | Problem | Difficulty | Approach | Time | Space | Solution |
|---|---------|------------|----------|------|-------|----------|
| 20 | [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) | Easy | Push opening brackets; each closing bracket must match the top | O(n) | O(n) | [0020-valid-parentheses.cpp](Problems/0020-valid-parentheses.cpp) |
| 225 | [Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/) | Easy | Two queues: move n − 1 elements on `pop`, then `std::swap` (O(1)); top element cached | push/top O(1) · pop O(n) | O(n) | [225-implement-stack-using-queues.cpp](Problems/225-implement-stack-using-queues.cpp) |
| 232 | [Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/) | Easy | Input and output stacks; refill the output stack only when it's empty | amortized O(1) | O(n) | [232_implement-queue-using-stacks.cpp](Problems/232_implement-queue-using-stacks.cpp) |
| 2390 | [Removing Stars From a String](https://leetcode.com/problems/removing-stars-from-a-string/) | Medium | Use the result string as a stack: `push_back` letters, `pop_back` on `*` | O(n) | O(n) | [2390_removing-stars-from-a-string.cpp](Problems/2390_removing-stars-from-a-string.cpp) |

### Linked Lists (building blocks for #143)

| # | Problem | Difficulty | Approach | Time | Space | Solution |
|---|---------|------------|----------|------|-------|----------|
| 206 | [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) | Easy | Iterative: `prev` / `curr` / `next` pointers, reverse each link | O(n) | O(1) | [206_reverse-linked-list.cpp](Problems/206_reverse-linked-list.cpp) |
| 876 | [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/) | Easy | Fast/slow pointers: fast moves 2 steps, slow moves 1 | O(n) | O(1) | [876_middle-of-the-linked-list.cpp](Problems/876_middle-of-the-linked-list.cpp) |

### Binary Trees

| # | Problem | Difficulty | Approach | Time | Space | Solution |
|---|---------|------------|----------|------|-------|----------|
| 94 | [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/) | Easy | Recursive: left → node → right | O(n) | O(h) | [94_binary-tree-inorder-traversal.cpp](Problems/94_binary-tree-inorder-traversal.cpp) |
| 144 | [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/) | Easy | Recursive: node → left → right | O(n) | O(h) | [144_binary-tree-preorder-traversal.cpp](Problems/144_binary-tree-preorder-traversal.cpp) |
| 145 | [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/) | Easy | Recursive: left → right → node | O(n) | O(h) | [145_binary-tree-postorder-traversal.cpp](Problems/145_binary-tree-postorder-traversal.cpp) |
| 100 | [Same Tree](https://leetcode.com/problems/same-tree/) | Easy | Recursively compare values and both subtrees | O(n) | O(h) | [100_same-tree.cpp](Problems/100_same-tree.cpp) |
| 101 | [Symmetric Tree](https://leetcode.com/problems/symmetric-tree/) | Easy | Mirror recursion: compare left-of-one with right-of-the-other | O(n) | O(h) | [101_symmetric-tree.cpp](Problems/101_symmetric-tree.cpp) |
| 107 | [Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/) | Medium | DFS that collects values by depth, then reverses the levels | O(n) | O(n) | [107_binary-tree-level-order-traversal-ii.cpp](Problems/107_binary-tree-level-order-traversal-ii.cpp) |

---

## Patterns Practiced

| Pattern | Problems |
|---------|----------|
| Hash map lookup | 1, 105, 496 |
| Two pointers (opposite ends) | 11 |
| Fast / slow pointers | 19, 141, 142, 143, 876 |
| In-place linked-list rewiring | 21, 23, 143, 206 |
| Stack (incl. monotonic stack) | 20, 225, 232, 496, 1008, 2390 |
| Monotonic deque | 239 |
| Ring buffer | 622 |
| Prefix / suffix sums and products | 238, 1991 |
| Kadane's algorithm | 53, 918 |
| Single-pass running min/max | 121 |
| In-place marking (O(1) extra space) | 41, 442 |
| Bit manipulation | 231 |
| Tree traversals | 94, 107, 144, 145 |
| Tree recursion: return info upward + global best | 124, 236, 1373 |
| BST properties (sorted in-order, value ranges) | 98, 450, 1008, 1382 |
| Build tree from a range / divide by middle | 105, 1382 |

---

## Repository Structure

```
LeetCode/
├── README.md
└── Problems/
    └── <number>_<problem-name>.cpp   # one file per problem
```

## Build and Run

```bash
g++ -std=c++17 -Wall -Wextra -Werror -g -fsanitize=address,undefined Problems/<file>.cpp -o build/run && ./build/run
```

- `-Wall -Wextra`: enable compiler warnings.
- `-Werror`: treat warnings as errors, matching LeetCode's judge.
- `-fsanitize=address,undefined`: catch memory errors and undefined behavior at run time.
