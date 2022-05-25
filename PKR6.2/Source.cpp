#include <iostream>
#include <Windows.h>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* link;
    Info info;
};

void enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->link = NULL;
    if (last != NULL)
        last->link = tmp;
    last = tmp;
    if (first == NULL)
        first = tmp;
}

void print(Elem* first)
{
    while (first != NULL)
    {
        cout << first->info << " ";
        first = first->link;
    }
}

void dequeue(Elem*& first, Elem*& last)
{
    while (first != NULL)
    {
        Elem* tmp = first->link;
        Info value = first->info;
        delete first;
        first = tmp;
        if (first == NULL)
            last == NULL;
    }
}

bool Scan(Elem*& L)
{
    while (L->link != NULL)
    {
        if (L->info == L->link->info)
        {
            return true;
        }
        else
        {
            L = L->link;
        }
    }
    return false;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Elem* first = NULL,
        * last = NULL;

    int N, value;

    cout << "Введіть кількість елементів: "; cin >> N;

    for (int i = 0; i < N; i++)
    {
        cout << "Введіть значення " << i + 1 << " елементу: "; cin >> value;
        enqueue(first, last, value);
    }
    cout << endl;

    cout << "Список: "; print(first); cout << endl << endl;

    if (Scan(first))
    {
        cout << "Список містить пару сусідніх елементів " 
             << "з однаковим значенням інформаційного поля" << endl << endl;
    }
    else
    {
        cout << "Список НЕ містить пару сусідніх елементів " 
             << "з однаковим значенням інформаційного поля" << endl << endl;
    }

    dequeue(first, last);

    system("pause");
    return 0;
}