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

ex17_10

如果需要整数保存测试解答，那么对于10个问题的测验，只需要一个短整型对象即可，如果改为100道题，则需要4个32位整数（32*4>100)或者是2个64位整数(2*64>100)即可，而且修改的并不仅仅是数据结构，所有对整型数进行操作来解答和评分的代码都要进行相应的修改工作量很大
采用bitset有明显的优势：当题目数改变时，我们只需要改变bitset的规模，而操作bitset来完成改答案、评分的代码则只需要进行很小的修改
最佳的方式是定义一个类模板，它有一个模板参数表示题目数，有一个bitset成员保存解答，然后定义一些成员函数来完成改答案、评分等操作，当题目数发生变化，我们只需要实例化一个新版本即可，其他代码均无需改动

ex17_14

regex r("[[:alnum]]+\\.(cpp|cxx|cc)$",regex::icase),运行程序后，产生如下的错误：
regex_error(error_ctype):The expression contained an invalid character class name.
code:1


ex17_16

如果pattern只是"[^c]ei",则只与"?ei"形式的字符串进行匹配，其中?是除c之外的字符，因此，输出的只是错误拼写的部分，而不是包含错误拼写的完整单词

ex17_19

当子表达式未匹配时，其str()会返回空string，仍然可以合法使用

ex17_23

"(\\d{5}))((-?)(\\d{4}))?"

ex17_31

在循环内定义b和e，那么每个循环步都会用默认的种子（0）重新初始化随机数引擎e，因此，调用b（e）永远得到了是特定随机数序列的第一个数，游戏的先行者永远是固定的
而在循环定义外，则可以保持引擎的状态，每次得到随机数序列中的下一个值，游戏的先行者会改变

ex17_32

如果在循环内定义resp，则其生命周期仅在循环体内，而while循环条件判断不属于循环体，因此，在进行循环条件的判定时，resp已经被销毁了，程序会产生编译错误
