    之前想用类似Leetcode 102题那样，一行行地iterate，但是思路有问题。

    之前想用int i来数行数，odd行先放左孩子，even行先放右孩子。但是这个思路是错的。

    自己画一个binary tree，按照思路一走，会发现到第3、4行时，就不是zigZag了。

###### 新思路是，用2个stack，左stack先push root进去。 而且要用2个while loop！

大while loop用来不让程序没结束就跳出循环，即只要stack a，或，stack b里有元素，我们的程序就要继续
小while loop就负责循环stack a，然后a循环完了，再来循环b。

![](https://i.imgur.com/ERSHh6N.jpg)

![](https://i.imgur.com/DuuJgXd.jpg)
