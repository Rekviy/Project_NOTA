#include "commands.h"


CommandMap::CommandMap(){
	coms.insert(std::pair(L"make", make));
	coms.insert(std::pair(L"write", write));
	coms.insert(std::pair(L"del", del));
	coms.insert(std::pair(L"wq", wq));
}
command CommandMap::checkCommand(std::wstring& com) {
	auto it = coms.find(com);
	if (it != coms.end())
		return (*it).second;
	else
		return not_exist;
	
}