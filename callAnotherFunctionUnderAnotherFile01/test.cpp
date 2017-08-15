#include <iostream>
#include "helloWorld.h"
using namespace std;
int foo(int a){
	int b = a*10;
	return b;
}
int main()
{
	int a = 5;
	int b = foo(a);
	hello();
	return 0;
}
