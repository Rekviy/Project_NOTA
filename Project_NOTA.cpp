#include "Project_NOTA.h"


void testFile();
int main(){
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	//TempGUI();
	//testFile();
	return 0;}




void testFile()
{
	char var = 0;
	Note notation(L"TEST.txt");

	std::wfstream fs;
	fs.exceptions(std::wfstream::badbit | std::wfstream::failbit);
	while (var != 'Q' && var != 'q')
	{
		try
		{
			std::cout << "Открытие файла..." << std::endl;
			fs.open(notation.getFileName(), std::wfstream::app | std::wfstream::in | std::wfstream::out);
			std::cout << "Файл успешно открыт!" << std::endl;
		}
		catch (const std::wfstream::failure& ex)
		{
			std::cout << "ERROR" << ex.what() << std::endl;
			std::cout << "CODE:" << ex.code() << std::endl;
			return;
		}
		catch (const std::exception& ex)
		{
			std::cout << "ERROR" << ex.what() << std::endl;
			return;
		}
		std::cout << "1: запись\t" << "2: чтение\n" << "(Q)uit" << std::endl;
		std::cin >> var;

		switch (var)
		{
		case '1':
			notation.writeNote(&fs);
			break;
		case '2':
			notation.readNote(&fs);
			break;
		default:
			std::cout << "Выход из приложения..." << std::endl;
			break;
		}
		fs.close();
	}

}










void TempGUI()
{
	char action = '1';
	do
	{
		std::cout << "Select action: " << std::endl;
		std::cout
			<< "1. Select note.\n"
			<< "2. Load file.\n"
			<< "3. Save to file.\n"
			<< "4. Create note.\n"
			<< "5. Delete note.\n" 
			<< "(Q)uit." << std::endl;
		std::cin >> action;

		switch (action)
		{
		case '1':
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			break;
		case '5':
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
