#include "Project_NOTA.h"

int main(){
	std::vector<Note*> list;
	srand(time(NULL));
	//setlocale(LC_ALL, "rus");
	UI(list);
	
	return 0;
}

void createNote(std::vector<Note*>& list){
	std::wstring dir;
	std::wstring name;
	std::cout << "Enter name for Note: ";
	std::wcin >> name;

	std::cout << "Enter directory name for Note: ";
	std::wcin >> dir;
	Note* temp = new Note(name, dir);
	list.push_back(temp);
	temp->saveNote();
}

void deleteNote(std::vector<Note*>& list){
	std::cout << "Enter the name of the Note you want to delete." << std::endl;
	std::wstring name;
	std::wcin >> name;
	std::wcout << L"Notes found: \n";
	unsigned count = 0;
	std::vector<unsigned> found;
	for (unsigned i = 0; i < list.size(); i++)
	{
		if (list[i]->getName() == name)
		{
			found.push_back(i);
			++count;
			std::wcout<< list[i]->getFile();
		}
	}
	switch (count)
	{
	case 0:
		std::wcout << L"Note with this name, " + name + L" ,doesn't exist."<<std::endl;
		return;
	case 1:
		std::wcout << "Do you want to delete this Note? Y/N";
		wchar_t select;
		std::wcin >> select;
		if (select == L'Y' || select == L'y')
			delete list[found[0]];
		break;
	default:
		std::wcout << L"Which Note do you want to delete?";
		std::cin >> count;
		//сделать нормальное удаление
		break;
	}
	//todo удаление из тех файла по хешу
	std::wcout << "Note was sucessful deleted!" << std::endl;
}

void loadAllNote(std::vector<Note*>& list) {
	
	while (Settings::endOfSettingsFile())
	{
		Note* temp = new Note;
		Settings::loadNote(*temp);
		list.push_back(temp);

	}
}

void NoteUI(Note* note){
	std::wcout << *note << std::endl;
	while (true){
	}
}

int writeNote(Note* note) {
	std::wstring buff = L"";
	std::cout << "(Q) to quit" << std::endl;
	while (true)
	{
		std::wcin >> buff;
		if (buff == L"Q" || buff == L"q")
			break;
		note->write(buff);
	}
	return 0;

}


void UI(std::vector<Note*> &list){
	CommandMap cm;
	while (true){
		system("cls");
		std::cout << "Comand list: " <<
			"\n1. make - creates new note" <<
			"\n2. write - open note to editing" <<
			"\n3. del - delete's note" <<
			"\n wq - to exit" << std::endl;
		std::cout << "Command: ";
		
		std::vector<std::wstring> com;
		try{
			std::wstring input;
			std::getline(std::wcin, input);
			for (int i = 0, prev_end = 0; i < input.size() + 1; ++i) {
				if (input[i] == L' ' || input[i] == L'\0') {
					com.push_back(input.substr(prev_end, i - prev_end));
					prev_end = i + 1;
					continue;
				}
			}
		}
		catch (const std::exception& ex){
			std::cout<<"\n" << ex.what() << std::endl;
		}
		

		switch (cm.checkCommand(com[0])) {
		case make:
			createNote(list);
			break;
		case write:
			break;
		case del:
			deleteNote(list);
			break;
		case wq:
			std::cout << "Closing application..." << std::endl;
			return;
		default:
			std::cout << "Invalid command!" << std::endl;
			break;
		}
		system("pause");
	}
	
}