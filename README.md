# LeetCode Solutions

C++ solutions to LeetCode problems, written as interview preparation alongside the **ITI Embedded Systems** program.
Each entry lists the approach and its time and space complexity.

**Solved: 17** (14 Easy · 3 Medium) · **Manara Flexible: Modules 2–3 complete, Module 4 in progress**

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

### Stacks and Queues

| # | Problem | Difficulty | Approach | Time | Space | Solution |
|---|---------|------------|----------|------|-------|----------|
| 20 | [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) | Easy | Push opening brackets; each closing bracket must match the top | O(n) | O(n) | [0020-valid-parentheses.cpp](Problems/0020-valid-parentheses.cpp) |
| 225 | [Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/) | Easy | Two queues: move n − 1 elements on `pop`, then `std::swap` (O(1)); top element cached | push/top O(1) · pop O(n) | O(n) | [225-implement-stack-using-queues.cpp](Problems/225-implement-stack-using-queues.cpp) |
| 2390 | [Removing Stars From a String](https://leetcode.com/problems/removing-stars-from-a-string/) | Medium | Use the result string as a stack: `push_back` letters, `pop_back` on `*` | O(n) | O(n) | [2390_removing-stars-from-a-string.cpp](Problems/2390_removing-stars-from-a-string.cpp) |

### Linked Lists (building blocks for #143)

| # | Problem | Difficulty | Approach | Time | Space | Solution |
|---|---------|------------|----------|------|-------|----------|
| 206 | [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) | Easy | Iterative: `prev` / `curr` / `next` pointers, reverse each link | O(n) | O(1) | [206_reverse-linked-list.cpp](Problems/206_reverse-linked-list.cpp) |
| 876 | [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/) | Easy | Fast/slow pointers: fast moves 2 steps, slow moves 1 | O(n) | O(1) | [876_middle-of-the-linked-list.cpp](Problems/876_middle-of-the-linked-list.cpp) |

### Arrays

| # | Problem | Difficulty | Approach | Time | Space | Solution |
|---|---------|------------|----------|------|-------|----------|
| 442 | [Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array/) | Medium | Mark each seen value by negating `nums[v − 1]`; already negative = duplicate | O(n) | O(1) | [0442_find_all_duplicates_in_array.cpp](Problems/0442_find_all_duplicates_in_array.cpp) |

---

## Patterns Practiced

| Pattern | Problems |
|---------|----------|
| Hash map lookup | 1, 496 |
| Fast / slow pointers | 141, 876, 143 |
| In-place linked-list rewiring | 21, 143, 206 |
| Stack (incl. monotonic stack) | 20, 225, 496, 2390 |
| Prefix sum | 1991 |
| Single-pass running min/max | 121 |
| Bit manipulation | 231 |
| In-place marking (O(1) extra space) | 442 |

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
g++ -std=c++17 -Wall -Wextra -g -fsanitize=address,undefined Problems/<file>.cpp -o build/run && ./build/run
```

- `-Wall -Wextra`: enable compiler warnings.
- `-fsanitize=address,undefined`: catch memory errors and undefined behavior at run time.
