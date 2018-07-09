ex16_01

当调用一个函数模板时，编译器会利用给定的函数实参来推断模板实参，用此实际实参代替模板参数来创建出一个新的“实例”，也就是一个真正可以调用的函数，这个过程称为实例化

ex16_03

在gcc-4.8.1中，对两个Sales_data对象调用compare函数模板，编译器会报告如下错误。原因是compare是用<运算符来比较两个对象的，需要类型T实现定义<运算符，但是Sales_data类没有定义<运算符，所以会报错
error:no match for 'operator<'(operand types are 'const Sales_data') and 'const Sales_data'
