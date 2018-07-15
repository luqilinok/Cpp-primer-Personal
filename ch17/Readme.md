ex17_01

tuple<int,int,int> threeI{10,20,30};

ex17_02

tuple<string,vector<string>,pair<string,int>> t;
  
ex17_03

将TextQuery.h中加上
typedef std::tuple<std::string, std::shared_ptr<std::set<line_no>>,std::shared_ptr<std::vector<std::string>>> QueryResult; 
