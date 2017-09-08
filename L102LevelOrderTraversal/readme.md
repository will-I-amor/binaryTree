Given a binary tree, return the level order traversal of its nodes' values

        3
       / \
      9  20
     /     \
    15      7
return its level order traversal as:

    [
      [3],
      [9,20],
      [15,7]
    ]
    准备一个deque，和一个vector。deque负责iterate binary tree
    
![](https://i.imgur.com/1TGgxNJ.jpg)
