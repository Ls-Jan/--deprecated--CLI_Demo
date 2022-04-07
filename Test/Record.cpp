#include"Record.h"

void Record::AddString(std::string str){
	mapping[str[0]].push_back(str);
}

std::vector<std::string> Record::GetString(char ch){
	if (mapping.find(ch) == mapping.end())
		return std::vector<std::string>();
	return mapping[ch];
}

std::map<char, std::vector<std::string>> Record::GetMapping(){
	return mapping;
}
