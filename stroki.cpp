// stroki.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
#include <string>
#include <random>
#include <Windows.h>

// для переворачивания слова задом наперед
string reverse(string word) {
    string rev_word = word;
    reverse(rev_word.begin(), rev_word.end());
    return rev_word;
}

// для удаления гласных букв из слова
string remove_ao(const string word) {
    string result = word;
    result.erase(remove_if(result.begin(), result.end(), [](char c) {
        return string("аеёиоуыэюя").find(c) != string::npos;
        }), result.end());
    return result;
}

// для удаления согласных букв из слова
string remove_sogl(const string word) {
    string result = word;
    result.erase(remove_if(result.begin(), result.end(), [](char c) {
        return string("бвгджзйклмнпрстфхцчшщ").find(c) != string::npos;
        }), result.end());
    return result;
}

// для перемешивания букв в слове
string shuffle(const string& word) {
    string shuffled = word;
    random_device rd;
    mt19937 g(rd());
    shuffle(shuffled.begin(), shuffled.end(), g);
    return shuffled;
}

int main() {

    while (true)
    {
        //для верной кодировки при выводе русских букв
        setlocale(LC_ALL, "RU");
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        setlocale(0, "");

        string word;
        cout << "\n---------------------------------------------------";
        cout << "\n>>> Действия со строками <<<\n";
        cout << "\nВведите слово: ";
        cin >> word;

        int ch;
        cout << "\nВыберите действие:\n";
        cout << "1. Слово задом наперед\n";
        cout << "2. Cлово без гласных\n";
        cout << "3. Cлово без согласных\n";
        cout << "4. Рандомно раскиданыне буквы в слове\n";
        cout << "5. Выход из программы\n";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "\nРезультат слова задом наперёд: " << reverse(word) << endl;
            continue;
        case 2:
            cout << "\nРезультат слова без гласных: " << remove_ao(word) << endl;
            continue;
        case 3:
            cout << "\nРезультат слова без согласных: " << remove_sogl(word) << endl;
            continue;
        case 4:
            cout << "\nРезультат рандомно раскиданынх букв в слове: " << shuffle(word) << endl;
            continue;
        case 5:
            cout << "\nВы завершили работу с программой";
            break;
        default:
            cout << "\nТакой чиселки в меню нет!\n";
            continue;
        }

        return 0;
    }
}