# Exercise 1
Given an array of integers and a value, determine if there are any two integers in the array whose sum is equal to the given value.


# Solution

The naive method iterates twice over the array and compares each value within that. Therefore the computational complexity will be O(n^2).

The sort and split solution will first sort the array in O(n log(n)) time, then iterate in O(n) time over the array having an iterator pointing to the smallest and one to the biggest value. Letting approaching the two iterators towards eachother until they meet or find a solution is linear. Due to the sorting we end up with O(n log(n)) time complexity.

The optimal solution is to use a hash table. The hash table has an access/search rate of O(1), meaning constant. Iterating over the set, querying the difference of the sum and the element we are looking at in the hash table will indicate if there is a solution or not within linear time. If no solution is found, we add the element we are looking at currently to the hash table. Therefore this whole method has a time complexity of O(n) and is optimal. 

The hash table is modeled here with an unordered set. The unordered set explicitly contains an implementation of a hash table.

##Good questions to ask
- Can a number occur twice in the input array?
- Are 0 and negative numbers allowed in the array.
