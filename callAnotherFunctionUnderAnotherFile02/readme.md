这个也是调用另一文件里的function。  此时调用的是BFS下的

    void printLevelOrder(Node* root)
但是这个function同时又调用了BFS.cpp里的其他函数，那么在BFS.h头文件里，其他函数也要声明才行
