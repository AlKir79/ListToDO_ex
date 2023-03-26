// ToDoList.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

// объявляем структуру для хранения полей задачи
struct ToDo
{
    string title;
    int prioritet;
    string prioritet_s;
    string description;
//    char dte;
 //   char tme;
};

// функция печати меню
void reFreshMenu(bool& sortDay, int& spisok)
{
    system("cls");
    cout << "=================================== Список задач ====================================================" << endl << endl;
    cout << "1 - Добавить   2 - Удалить   3 - Редактировать   ";
    if (sortDay) cout << "4 - Сортировка приоритет   ";
    else cout << "4 - Сортировка день/время  ";
    if (spisok == 1) cout << "5 - Список день ";
    if (spisok == 2) cout << "5 - Список месяц";
    if (spisok == 3) cout << "5 - Список год  ";
    cout << "6 - Выход";
    cout << endl;
    cout << "=====================================================================================================";
    cout << endl << endl;
}

// функция печати списка задач
void printList(ToDo*& list, int& size, bool& sortDay, int& spisok, bool& dealEmpty)
{
    // формируем шапку задач
    cout << "=====================================================================================================" << endl;
    cout << "|# п/п  | Название           | Описание                               |  П  | Дата      | Время      |" << endl;
    cout << "=====================================================================================================" << endl;
    int j = 1;
    string str;
    // собираем строку для вывода задачи
    while (j < size)/* && (dealNotEmpty == false))*/ 
    {
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
        for (size_t i = list[j].prioritet_s.length(); i < 5; i++)
        {
            str += ' ';
        }
        cout << str << endl;
        cout << "-----------------------------------------------------------------------------------------------------" << endl;
        j++;
    }

}

// функция добавления задачи
void addDeal(ToDo*& arr, int& size, bool& dealNotEmpty)
{
    system("cls");
    //объявляем новый динамический массив (на 1 элемент больше)
    ToDo* temp = new ToDo[size + 1];
    // переписываем старый массив в новый
    if (dealNotEmpty) {
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
    cout << "Введите описание задачи (не более 30 символов)";
    cin >> temp[size].description;
    cout << "Введите приоритет задачи (от 1 до 10)";
    cin >> temp[size].prioritet;
    //cout << "Введите дату выполнения задачи";
    //cin.getline(temp[size].dte, 20);
    //cout << "Введите время выполнения задачи";
    //cin.getline(temp[size].tme, 20);
    // удаляем старый массив
    delete[] arr;
    arr = temp;
    size++;
    dealNotEmpty = true;
}

void delDeal()
{

}

// функция работы с меню
void mainMenu(ToDo*& list, int& size, bool& sortDay, int& spisok, bool& dealNotEmpty)
{
    // выводим  меню
    reFreshMenu(sortDay, spisok);
    // выводим список задач
    if (dealNotEmpty) printList(list, size, sortDay, spisok, dealNotEmpty);
    // опрос клавиатуры
    char key = _getch();
    switch (key)
    {
    case '1':
        addDeal(list,size, dealNotEmpty);
        mainMenu(list, size, sortDay, spisok, dealNotEmpty);
        break;
    case '2':
        delDeal;
        mainMenu;
        break;
    }
}


int main()
{
    // русифицируем консоль
    system("chcp 1251>null");
    // первоначальный размер массива структур
    int size = 1;
    // начальные значения сортировки
    bool sortDay = true;
    int spisok = 1;
    bool dealNotEmpty = false;
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
