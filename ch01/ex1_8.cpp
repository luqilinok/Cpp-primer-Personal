#include<iostream>
int main() {
	//std::cout << "/*";第一个是正确的//
	//std::cout << "*/";第二个是正确的//
	//std::cout << /* "*/"*/; 第三个是错的，错误原因：第一个双引号被注释掉了//
	//std::cout << /*"*/     " /* "    /*"*/;第四个是正确的，第一个分号和最后一个分号都被注释掉了//
	return 0;
}
