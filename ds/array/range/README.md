# Best Method for Range Queries

For range queries like hcf, lcm, min, etc of given range of array can be best computed using Segment Trees as clearly visible through comparison.

## Comparison

### Naive Approach

Preprocessing time: O(1)
Memory Used: O(1)
Query Processing Time: O(n)

### Creating 2D table for all possible ranges

Preprocessing time: O(n^2)
Memory Used: O(n^2)
Query Processing Time: O(1)

### Sparse Table

Preprocessing time: O(nlg n)
Memory Used: O(nlg n)
Query Processing time: O(lg n)

### Segment Trees

Preprocessing time: O(n)
Memory Used: O(n)
Query processing time: O(lg n)
