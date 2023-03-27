// ToDoList.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
#include <string>
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
    cout << "=================================== Список задач ====================================================" << endl << endl;
    cout << "1 - Добавить   2 - Удалить   3 - Редактировать   4 - Поиск";
    if (sortDay) cout << "5 - Сортировка приоритет   ";
    else cout << "5 - Сортировка день/время  ";
    if (spisok == 1) cout << "6 - Список день ";
    if (spisok == 2) cout << "6 - Список месяц";
    if (spisok == 3) cout << "6 - Список год  ";
    cout << "7 - Выход";
    cout << endl;
    cout << "=====================================================================================================";
    cout << endl << endl;
}
void printStr (ToDo*& list, int& j)
{
    string str, str1;
    str += '|';
    str += ' ';
    str += to_string(j);
    for (size_t i = str.length(); i < 8; i++)
    {
        str += ' ';
    }
    str += '|';
    str += list[j].title;
    for (size_t i = list[j].title.length(); i < 20; i++)
    {
        str += ' ';
    }
    str += '|';
    str += list[j].description;
    for (size_t i = list[j].description.length(); i < 40; i++)
    {
        str += ' ';
    }
    str += '|';
    str += ' ';
    list[j].prioritet_s = to_string(list[j].prioritet);
    str += list[j].prioritet_s;
    for (size_t i = list[j].prioritet_s.length(); i < 4; i++)
    {
        str += ' ';
    }
    str += '|';
    str += ' ';
    str1 = to_string(list[j].dte.day);
    str += str1;
    str += '.';
    str1 = to_string(list[j].dte.month);
    str += str1;
    str += '.';
    str1 = to_string(list[j].dte.year);
    str += str1;
    str += ' ';
    str += '|';
    str += ' ';
    str1 = to_string(list[j].tme.hour);
    str += str1;
    str += ':';
    str1 = to_string(list[j].tme.min);
    str += str1;
    cout << str << endl;
    str.clear();
}

// функция печати списка задач
void printList(ToDo*& list, int& size, bool& sortDay, int& spisok, int& dealNotEmpty)
{
    // формируем шапку задач
    cout << "=====================================================================================================" << endl;
    cout << "|# п/п  | Название           | Описание                               |  П  | Дата      | Время      |" << endl;
    cout << "=====================================================================================================" << endl;
    int j = 1;
    // собираем строку для вывода задачи
    while ((j < size) && (dealNotEmpty==1)) 
    {
        printStr(list, j);
        cout << "-----------------------------------------------------------------------------------------------------" << endl;
        j++;
    }

}

// функция добавления задачи
void addDeal(ToDo*& arr, int& size, int& dealNotEmpty)
{
    system("cls");
    //объявляем новый динамический массив (на 1 элемент больше)
    ToDo* temp = new ToDo[size + 1];
    // переписываем старый массив в новый
    if (dealNotEmpty==1) {
        for (size_t i = 1; i < size; i++)
        {
            temp[i] = arr[i];
        }
    }
    // и добавляем новый элемент
    cout << "====== Планирование новой задачи ======" << endl;
    cout << endl;
    cout << "Введите название задачи (не более 20 символов)";
    cin >> temp[size].title;
    temp[size].title.erase(20);
    cout << "Введите описание задачи (не более 30 символов)";
    cin >> temp[size].description;
    temp[size].description.erase(30);
    cout << "Введите приоритет задачи (от 1 до 10)";    
    cin >> temp[size].prioritet;
    cout << "Введите дату выполнения задачи" << endl;
    cout << "Введите день ";
    cin >> temp[size].dte.day;
    cout << "Введите месяц ";
    cin >> temp[size].dte.month;
    cout << "Введите год ";
    cin >> temp[size].dte.year;
    cout << "Введите время выполнения задачи" << endl;
    cout << "Введите часы ";
    cin >> temp[size].tme.hour;
    cout << "Введите минуты ";
    cin >> temp[size].tme.min;
    // удаляем старый массив
    delete[] arr;
    arr = temp;
    size++;
    dealNotEmpty = 1;
}

void delDeal(ToDo*& arr, int& size, int& dealNotEmpty)
{
    if (size == 1)
    {
        dealNotEmpty = 0;
        arr = {};
        return;
    }
    ToDo* temp = new ToDo[size - 1];
    int str;
    int count = 1;
    cout << "Введите номер строки, которую хотите удалить ";
    cin >> str;
    for (size_t i = 1; i < size; i++)
    {
        if (i == str) continue;
        temp[count] = arr[i];
        count++;
    }
    delete[]arr;
    arr = temp;
    size--;
}

void editDeal(ToDo*& arr, int& size, int& dealNotEmpty)
{
    int deal;
    cout << "Введите номер строки, которую нужно редактировать ";
    cin >> deal;
    if (deal<0&&deal>size) return;
    system("cls");
    cout << "==================== Редактирование =====================" << endl;
    cout << endl;
    cout << "Введите название задачи (не более 20 символов)";
    cin >> arr[deal].title;
    cout << "Введите описание задачи (не более 30 символов)";
    cin >> arr[deal].description;
    cout << "Введите приоритет задачи (от 1 до 10)";
    cin >> arr[deal].prioritet;
    cout << "Введите дату выполнения задачи" << endl;
    cout << "Введите день ";
    cin >> arr[deal].dte.day;
    cout << "Введите месяц ";
    cin >> arr[deal].dte.month;
    cout << "Введите год ";
    cin >> arr[deal].dte.year;
    cout << "Введите время выполнения задачи" << endl;
    cout << "Введите часы ";
    cin >> arr[deal].tme.hour;
    cout << "Введите минуты ";
    cin >> arr[deal].tme.min;
}

// функция работы с меню
void mainMenu(ToDo*& list, int& size, bool& sortDay, int& spisok, int& dealNotEmpty)
{
    // выводим  меню
    reFreshMenu(sortDay, spisok);
    // выводим список задач
    if (dealNotEmpty==1) printList(list, size, sortDay, spisok, dealNotEmpty);
    // опрос клавиатуры
    char key = _getch();
    switch (key)
    {
    case '1':
        addDeal(list,size, dealNotEmpty);
        mainMenu(list, size, sortDay, spisok, dealNotEmpty);
        break;
    case '2':
        if (dealNotEmpty == 1)
        {
            delDeal(list, size, dealNotEmpty);
        }
            mainMenu(list, size, sortDay, spisok, dealNotEmpty);
        break;
    case '3':
        if (dealNotEmpty == 1)
        {
            editDeal(list, size, dealNotEmpty);
        }
            mainMenu(list, size, sortDay, spisok, dealNotEmpty);
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
    int dealNotEmpty = 0;
    // объявляем массив структур
    ToDo* list = new ToDo[size];
    mainMenu(list, size, sortDay, spisok, dealNotEmpty);


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
