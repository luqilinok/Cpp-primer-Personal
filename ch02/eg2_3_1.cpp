int ival = 1024;
int &refVal = ival;  //refVal指向ival(是ival的另一个名字)
int &refVal2;  //报错：引用必须被初始化
