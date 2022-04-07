#include "Controller.h"
#include"Record.h"

Controller::Controller(){
	ptr = new Record();
}

Controller::~Controller(){
	delete ptr;
}

void Controller::XJ_AddString(System::String^ str){
	ptr->AddString(std::string((char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str)).ToPointer()));
}

List<System::String^>^ Controller::XJ_GetString(System::Char^ ch){
//	mbstowcs_s(ch->ToChar(gcnew System::Globalization::CultureInfo("zh-chs-Hans")));
//	System::Convert::ToByte(ch);
	std::vector<std::string> rst = ptr->GetString(System::Convert::ToByte(ch));
//	std::vector<std::string> rst = ptr->GetString(ch->ToByte(gcnew System::Globalization::CultureInfo("zh-chs-Hans")));
	auto data=gcnew List<System::String^>();
	for (auto i = rst.begin(); i != rst.end(); ++i)
		data->Add(gcnew System::String(i->data()));
	return data;
}

Dictionary<System::Char, List<System::String^>^>^ Controller::XJ_GetDict(){
	auto data =gcnew Dictionary<System::Char, List<System::String^>^>();
	auto tmp = ptr->GetMapping();
	for (auto i = tmp.begin(); i != tmp.end(); ++i) {
		char key = i->first;
		for (auto j = i->second.begin(); j != i->second.end(); ++j) {
			char key = i->first;
			std::string str = *j;
			if (data->ContainsKey(key) == false)
				data->Add(key, gcnew List<System::String^>());
			data[System::Char(key)]->Add(gcnew System::String(str.data()));
		}
	}
	return data;
}



