#include "Project_NOTA.h"


void testFile();
int main(){
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	//TempGUI();
	testFile();
	return 0;}




void testFile()
{
	char var = 0;
	Note notation(L"TEST.txt");

	while (var != 'q'&& var !='Q')
	{
		std::cout << "1: запись\t" << "2: чтение\n" << "(Q)uit" << std::endl;
		std::cin >> var;

		switch (var)
		{
		case '1':
			notation.writeNote();
			break;
		case '2':
			notation.readNote();
			break;
		default:
			std::cout << "Выход из приложения..." << std::endl;
			break;
		}
		system("cls");
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
