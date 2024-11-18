#ifndef _COMMANDS_H_
#define _COMMANDS_H_
#include <map>
#include <string>
enum command{
	not_exist=-1,
	make, write, del , wq
};
enum param{

};

class CommandMap{
public:
	CommandMap();
	command checkCommand(std::wstring& com);
private:
	std::map<std::wstring, command> coms;
	std::map<std::wstring, param> params;
};

#endif