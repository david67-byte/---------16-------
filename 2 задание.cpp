#include <iostream>  // Для ввода/вывода
#include <string>    // Для работы со строками
#include <set>       // Для множества (хранит уникальные слова)
#include <sstream>   // Для разбиения строки на слова (istringstream)
#include <cctype>    // Для функций ispunct и tolower
using namespace std; // Стандартное пространство имён

int main() {
    string line; // Переменная для введённой строки
    getline(cin, line); // Считываем строку целиком с пробелами

    for (char& c : line) { // Проходим по каждому символу строки
        if (ispunct(static_cast<unsigned char>(c))) { // Если символ — знак препинания
            c = ' '; // Заменяем его на пробел, чтобы разделить слова
        } else {
            c = tolower(static_cast<unsigned char>(c)); // Иначе переводим в нижний регистр
        }
    }

    istringstream iss(line); // Создаём поток для чтения слов из строки
    string word; // Переменная для текущего слова
    set<string> seen; // Множество для хранения уже выведенных слов
    bool first = true; // Флаг: true, если это первое выводимое слово

    while (iss >> word) { // Читаем слова по одному
        if (seen.insert(word).second) { // Если слово новое (insert вернул true)
            if (!first) cout << "\n"; // Если это не первое слово, печатаем перевод строки
            cout << word; // Выводим слово
            first = false; // Отмечаем, что первое слово уже напечатано
        }
    }
    cout << endl; // Переводим строку в конце
    return 0; // Завершаем программу
}