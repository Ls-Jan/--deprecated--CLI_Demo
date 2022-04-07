


#include"Record.h"
#include<iostream>

int main() {
	Record rec;
	rec.AddString("123");
	rec.AddString("134");
	rec.AddString("234");

	auto mapping=rec.GetMapping();
	for (auto p = mapping.begin(); p != mapping.end(); ++p) {
		std::cout << "[" << p->first << "]\n";
		for (auto q = p->second.begin(); q != p->second.end(); ++q) {
			std::cout << *q << "\n";
		}
		std::cout << std::endl;
	}

	return 0;
}


