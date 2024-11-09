#include "Project_NOTA.h"

int main(){
	std::vector<Note*> list;
	srand(time(NULL));
	//setlocale(LC_ALL, "rus");
	loadAllNote(list);
	TempGUI(list);
	
	return 0;
}


void TempGUI(std::vector<Note*> &list)
{
	char action = '1';
	do
	{
		std::cout << "Select action: " << std::endl;
		std::cout
			<< "1. Select note.\n"
			<< "2. Create note.\n"
			<< "3. Delete note.\n" 
			<< "4. Load file.\n"
			<< "(Q)uit." << std::endl;
		std::cin >> action;

		switch (action)
		{
		case '1':
			selectNote(list);
			break;
		case '2':
			createNote(list);
			break;
		case '3':
			deleteNote(list);
			break;
		case '4':
			break;
		case 'q':
		case 'Q':
			std::cout << "Closing application..." << std::endl;
			break;
		default:
			std::cout << "This option doesnt exist." << std::endl;
			break;
		}
	} while (action != 'q' && action != 'Q');
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

void deleteNote(std::vector<Note*>& list)
{
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

void selectNote(std::vector<Note*>& list)
{
	try
	{
		int selection = 0;
		std::cout << "Created Notes: ";
		for (unsigned i = 0; i < list.size(); i++)
			std::wcout << i + 1 << L". " << list[i]->getName();
		std::cout << std::endl << "Press 0 to quit\nSelect: ";
		std::cin >> selection;
		//temp
		if (selection < 1 || selection > list.size()) {
			std::cout << "This item doesn't exist!" << std::endl;
			return;
		}

		NoteUI(list[selection - 1]);
	}
	catch (const std::exception& ex)
	{
		std::cout << "Something went wrong!";
		std::cout << ex.what() << std::endl;
		return;
	}
}

void NoteUI(Note* note)
{
	char var = 0;
	while (var != 'q' && var != 'Q')
	{
		std::cout << "1: Write\t" << "2: Read\n" << "(Q)uit" << std::endl;
		std::cin >> var;

		switch (var)
		{
		case '1':
			writeNote(note);
			break;
		case '2':
			readNote(note);
			system("pause");
			break;
		default:
			std::cout << "Quiting the application..." << std::endl;
			break;
		}

		system("cls");
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
int readNote(Note* note)
{
	std::wcout << *note << std::endl;
	return 0;
}