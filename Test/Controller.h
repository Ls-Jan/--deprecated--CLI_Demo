#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H

using namespace System::Collections::Generic;
//C++的托管类(CLI)，将在C#代码中生效。暴露出来的数据类型必须是System::里头的，且必须用引用^
//托管类必须public要不然在C#项目里访问不到
class Record;
public ref class Controller {
private:
	Record* ptr;
public:
	Controller();
	~Controller();
	void XJ_AddString(System::String^ str);//加入字符串，以首字符为索引保存到Record中
	List<System::String^>^ XJ_GetString(System::Char^ ch);//根据字符获取字串列表
	Dictionary<System::Char,List<System::String^>^>^XJ_GetDict();//获取Record记录
};

#endif
