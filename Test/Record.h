#pragma once
#ifndef  RECORD_H
#define RECORD_H

#include<vector>
#include<map>
#include<string>

//C++的原生类，生成库之后该类并不会出现在在C#项目中
class Record {
private:
	std::map<char,std::vector<std::string>>mapping;
public:
	void AddString(std::string str);//加入字符串，以首字符为索引存进mapping中
	std::vector<std::string>GetString(char ch);//根据索引获取字串列表
	std::map<char, std::vector<std::string>>GetMapping();//获取mapping
};

#endif // ! RECORD_H




