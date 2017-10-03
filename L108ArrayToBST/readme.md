Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

不用AVL tree来解，因为是sorted array，只要每次drag出array里mid的值来，把这个值当成root就可以了

注意mid的算法

    int mid = start+(end-start)/2
