现在总共有3个文件： helloWorld.cpp      test.cpp  和 helloWorld.h

我想在test的main函数里调用helloWorld.cpp里的函数

###### 需要注意的注意事项：

- 头文件必须和被调用文件的文件名一致。比如helloWorld.h和helloWorld.cpp

- 3个文件在同一文件夹

- 被调用的文件helloWorld.cpp 不能有main()函数

- 在test里要#include "helloWorld.h"

- 在terminal compile时，要g++ helloWorld.cpp 和 test.cpp。就是所有文件要一起compile
