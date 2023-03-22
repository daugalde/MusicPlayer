#include <string>
#include "Menu.h"
#include "User.h"
#include "AppManager.h"

int main() {

	AppManager manager;

	manager.LoadMusicData();

	int yourchoice = 0;

	string confirm = "";

	Menu::Displaymenu();

	do
	{
		getline(cin, confirm);

		if (confirm.length() == 0) {

			Menu::Displaymenu();
			confirm = " ";
			continue;
		}

		switch (confirm[0])
		{
		case '1':
			manager.DataManager();
			yourchoice = 5;
			break;
		case '2':
			manager.MusicPlayerManager();
			yourchoice = 5;
			break;
		case '3':
			manager.ReportManager();
			yourchoice = 5;
			break;
		case '4':
			cout << "Desea Salir ? Presione Y\n";
			getline(cin, confirm);
			if (confirm == "Y" || confirm == "y")
			{
				confirm = "";
			}
			else {
				confirm = " ";
			}
		default:
			Menu::Displaymenu();
			break;
		}

	} while (confirm.length() != 0);

	return 0;
}
