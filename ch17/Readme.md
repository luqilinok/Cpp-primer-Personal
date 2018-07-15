ex17_01

tuple<int,int,int> threeI{10,20,30};

ex17_02

tuple<string,vector<string>,pair<string,int>> t;
  
ex17_03

将TextQuery.h中加上
typedef std::tuple<std::string, std::shared_ptr<std::set<line_no>>,std::shared_ptr<std::vector<std::string>>> QueryResult; 

ex17_07

对于本题，只是简单使用搜索结果，pair和tuple都是简单直接的实现方式。若搜索结果还需要进行复杂的计算、处理，那么定义一个类对其进行封装更好

ex17_08

Sales_data（）是Sales_data的默认构造函数，对所有数据成员都采用值初始化，因此isbn被初始化为空字符串，因此，在输出结果中，将看不到数目的isbn

ex17_09

（a）bitset<64> bitvec(32) 表示bitvec有64位，其中第5位（2^5=32）是1，其余各位都是0
（b）bitset<32> bv(1010101）表示bv有32位，其中第0、2、4、6位是1，其余各位都是0
（c）bv是8位，用bstr来对其进行初始化，若入读的字符串不是淡出的二进制字符串，程序会抛出invalid_argument异常
