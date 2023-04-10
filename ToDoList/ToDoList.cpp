// ToDoList.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
using namespace std;

// объявляем структуру для хранения полей задачи
struct date
{
	int day;
	int month;
	int year;
};

struct time
{
	int hour;
	int min;
};

struct ToDo
{
	string title;
	int prioritet;
	string prioritet_s;
	string description;
	struct date dte;
	struct time tme;
};

// функция печати меню
void reFreshMenu(bool& sortDay, int& spisok)
{
	system("cls");
	cout << setw(109) << "=================================== Список задач ===========================================================" << endl;
	cout << setw(15) << left << "1 - Добавить" << setw(15) << "2 - Удалить" << setw(15) << "3 - Редактировать   ";
	if (sortDay) cout << setw(30) << left << "5 - Сортировка приоритет";
	else cout << setw(30) << left << "5 - Сортировка день/время";
	if (spisok == 1) cout << setw(19) << left << "6 - Список день ";
	if (spisok == 2) cout << setw(19) << left << "6 - Список месяц";
	if (spisok == 3) cout << setw(19) << left << "6 - Список год  ";
	cout << "7 - Выход";
	cout << endl;
	cout << "============================================================================================================";
	cout << endl << endl;
}

char printStr(ToDo*& list, int& j)
{
	int t = j + 1;
	system("cls");
	cout << "======================================== Редактирование =====================================================" << endl;
	cout << endl;
	// формируем шапку задач
	cout << "=============================================================================================================" << endl;
	cout << "|# п/п  | Название           | Описание                                      |  П  | Дата      | Время      |" << endl;
	cout << "=============================================================================================================" << endl;
	// собираем строку для вывода задачи
		cout << "|" << left << setw(7) << t;
		cout << "|" << left << setw(20) << list[j].title << "|" << setw(47) << list[j].description;
		cout << "|" << setw(5) << list[j].prioritet << "|" << setw(2) << list[j].dte.day << "." << setw(2) << right << list[j].dte.month << ".";
		cout << left << setw(5) << list[j].dte.year << "|" << setw(2) << list[j].tme.hour << ":" << list[j].tme.min;
		cout << endl << "------------------------------------------------------------------------------------------------------------" << endl;
		cout << "Введите поле редактирования " << endl;
		cout << "1 - Название" << endl;
		cout << "2 - Описание" << endl;
		cout << "3 - Приоритет" << endl;
		cout << "4 - Дата" << endl;
		cout << "5 - Время" << endl;
		cout << "6 - Выход" << endl;
		char key = _getch();
		return key;
}

// функция печати списка задач
void printList(ToDo*& list, int& size, bool& sortDay, int& spisok, int& dealEmpty)
{
	// формируем шапку задач
	cout << "=============================================================================================================" << endl;
	cout << "|# п/п  | Название           | Описание                                      |  П  | Дата      | Время      |" << endl;
	cout << "=============================================================================================================" << endl;
	int j = 0;
	// собираем строку для вывода задачи
	while ((j < size) && (dealEmpty == 0))
	{
		int t = j + 1;
		cout << "|" << left << setw(7) << t;
		cout << "|" << left << setw(20) << list[j].title << "|" << setw(47) << list[j].description;
		cout << "|" << setw(5) << list[j].prioritet << "|" << setw(2) <<list[j].dte.day << "." << setw(2) << right << list[j].dte.month << ".";
		cout << left << setw(5) << list[j].dte.year << "|" << setw(2) << list[j].tme.hour << ":" << list[j].tme.min;
        cout << endl << "------------------------------------------------------------------------------------------------------------" << endl;
 j++;
	}
}

// функция добавления задачи
void addDeal(ToDo*& arr, int& size, int& dealEmpty)
{
	system("cls");
	int count = size;
	int s = size;
	if (dealEmpty == 0) count++;
	else s--;
	//объявляем новый динамический массив (на 1 элемент больше)
	ToDo* temp = new ToDo[count];
	// переписываем старый массив в новый
	if (dealEmpty == 0) {
		for (size_t i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
	}
	// и добавляем новый элемент
	cout << "====== Планирование новой задачи ======" << endl;
	cout << endl;
	cout << "Введите название задачи (не более 20 символов)";
	getline(cin, temp[s].title,'\n');
	cout << "Введите описание задачи (не более 30 символов)";
	getline(cin, temp[s].description,'\n');
	cout << "Введите приоритет задачи (от 1 до 10)";
	(cin >> temp[s].prioritet).get();
	cout << "Введите дату выполнения задачи" << endl;
	cout << "Введите день ";
	(cin >> temp[s].dte.day).get();
	cout << "Введите месяц ";
	(cin >> temp[s].dte.month).get();
	cout << "Введите год ";
	(cin >> temp[s].dte.year).get();
	cout << "Введите время выполнения задачи" << endl;
	cout << "Введите часы ";
	(cin >> temp[s].tme.hour).get();
	cout << "Введите минуты ";
	(cin >> temp[s].tme.min).get();
	// удаляем старый массив
	delete[] arr;
	arr = temp;
	if (dealEmpty == 0) size++;
	dealEmpty = 0;
}

void delDeal(ToDo*& arr, int& size, int& dealEmpty)
{
	if (size > 1)
	{
		ToDo* temp = new ToDo[size - 1];
		int str;
		int count = 0;
		cout << "Введите номер строки, которую хотите удалить ";
		cin >> str;
		str--;
		for (size_t i = 0; i < size; i++)
		{
			if (i == str) continue;
			temp[count] = arr[i];
			count++;
		}
		delete[]arr;
		arr = temp;
		size--;
	}
	else dealEmpty = 1;
}

void editDeal(ToDo*& arr, int& size, int& dealEmpty)
{
	int deal, key;
	if (size > 1) {
		cout << "Введите номер строки, которую нужно редактировать ";
		(cin >> deal).get();
		deal--;
		if (deal<0 && deal>size) return;
	}
	else deal = 0;
	// формируем шапку задач
	key = printStr(arr, deal);
	switch (key)
	{
		case '1': 
			cout << "Введите название задачи (не более 20 символов)";
			getline(cin, arr[deal].title);
			key = printStr(arr, deal);
			break;
		case '2':
			cout << "Введите описание задачи (не более 30 символов)";
			getline(cin, arr[deal].description);
			key = printStr(arr, deal);
			break;
		case '3':
			cout << "Введите приоритет задачи (от 1 до 10)";
			(cin >> arr[deal].prioritet).get();
			key = printStr(arr, deal);
			break;
		case '4':
			cout << "Введите дату выполнения задачи" << endl;
			cout << "Введите день ";
			(cin >> arr[deal].dte.day).get();
			cout << "Введите месяц ";
			(cin >> arr[deal].dte.month).get();
			cout << "Введите год ";
			(cin >> arr[deal].dte.year).get();
			key = printStr(arr, deal);
			break;
		case '5':
			cout << "Введите время выполнения задачи" << endl;
			cout << "Введите часы ";
			(cin >> arr[deal].tme.hour).get();
			cout << "Введите минуты ";
			(cin >> arr[deal].tme.min).get();
			key = printStr(arr, deal);
			break;
		case '6':
			return;
	}
}
void sortPrior(ToDo*& arr, int& size)
{
	ToDo temp;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size - i; j++)
		{
			if (arr[j].prioritet < arr[j + 1].prioritet)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

// функция работы с меню
void mainMenu(ToDo*& list, int& size, bool& sortDay, int& spisok, int& dealEmpty)
{
	// выводим  меню
	reFreshMenu(sortDay, spisok);
	// выводим список задач
	if (dealEmpty == 0) printList(list, size, sortDay, spisok, dealEmpty);
	// опрос клавиатуры
	char key = _getch();
	switch (key)
	{
	case '1':
		addDeal(list, size, dealEmpty);
		mainMenu(list, size, sortDay, spisok, dealEmpty);
		break;
	case '2':
		if (dealEmpty == 0)
		{
			delDeal(list, size, dealEmpty);
		}
		mainMenu(list, size, sortDay, spisok, dealEmpty);
		break;
	case '3':
		if (dealEmpty == 0)
		{
			editDeal(list, size, dealEmpty);
		}
		mainMenu(list, size, sortDay, spisok, dealEmpty);
		break;
	case '7':
		exit;
	}
}

//void findDeal()
//{
//    int f;
//    system("cls");
//    cout << "Поиск задачи по " << endl;
//    cout << "1 - название " << endl;
//    cout << "2 - приоритет " << endl;
//    cout << "3 - описание " << endl;
//    cout << "4 - дата " << endl;
//    cout << "5 - время " << endl;
//    cin >> f;
//    switch (f)
//    {
//    case 1:
//
//    }
//
//}

int main()
{
	// русифицируем консоль
	system("chcp 1251>null");
	// первоначальный размер массива структур
	int size = 1;
	// начальные значения сортировки
	bool sortDay = true;
	int spisok = 1;
	int dealEmpty = 1;
	// объявляем массив структур
	ToDo* list = new ToDo[size];
	mainMenu(list, size, sortDay, spisok, dealEmpty);


}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
