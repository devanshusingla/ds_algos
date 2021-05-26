## Square Root Decomposition Technique

**This technique helps us to reduce Time Complexity by a factor of sqrt(n).**

The key concept of this technique is to decompose given array into small chunks specifically of size sqrt(n).

Let’s say we have an array of n elements and we decompose this array into small chunks of size sqrt(n). We will be having exactly sqrt(n) such chunks provided that n is a perfect square. Therefore, now our array on n elements is decomposed into sqrt(n) blocks, where each block contains sqrt(n) elements (assuming size of array is perfect square).

Let’s consider these chunks or blocks as an individual array each of which contains sqrt(n) elements and you have computed your desired answer(according to your problem) individually for all the chunks. Now, you need to answer certain queries asking you the answer for the elements in range l to r(l and r are starting and ending indices of the array) in the original n sized array.

The naive approach is simply to iterate over each element in range l to r and calculate its corresponding answer. Therefore, the Time Complexity per query will be O(n).

**Sqrt Decomposition Trick :** As we have already precomputed the answer for all individual chunks and now we need to answer the queries in range l to r. Now we can simply combine the answers of the chunks that lie in between the range l to r in the original array. So, if we see carefully here we are jumping sqrt(n) steps at a time instead of jumping 1 step at a time as done in naive approach.

**Time Complexity :** the leftover parts of range after removing complete chunks will take <= 2 sqrt(n) steps and and since total complete chunks are <= sqrt(n), numer of steps for summation of complete chunks in range <= sqrt(n). Hence total time complexity < 3 sqrt(n) = O(sqrt(n))

##### Copied and pasted from (https://www.geeksforgeeks.org/sqrt-square-root-decomposition-technique-set-1-introduction/)[https://www.geeksforgeeks.org/sqrt-square-root-decomposition-technique-set-1-introduction/]
