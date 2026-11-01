# LeetCode Solutions

C++ solutions to LeetCode problems — interview preparation alongside the ITI Embedded Systems program.

## Problems

| # | Problem | Difficulty | Topic | Approach | Time | Space | Source | Solution |
|---|---------|------------|-------|----------|------|-------|--------|----------|
| 1 | [Two Sum](https://leetcode.com/problems/two-sum/) | Easy | Array, Hash Table | Hash map from value to index; look up `target - x` | O(n) | O(n) | ITI DSA Task 2 | [0001-Two_Sum.cpp](Problems/0001-Two_Sum.cpp) |
| 442 | [Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array/) | Medium | Array, Hash Table | Mark each seen value by negating `nums[v - 1]` | O(n) | O(1) | Practice | [0442_find_all_duplicates_in_array.cpp](Problems/0442_find_all_duplicates_in_array.cpp) |

## Conventions

- One file per problem in `Problems/`, named by its LeetCode number.
- Each file contains the `Solution` code plus a `main()` with edge-case tests.
- Built with `g++ -std=c++17 -Wall -Wextra -g -fsanitize=address`.