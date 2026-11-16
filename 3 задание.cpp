#include <iostream>   // Для ввода/вывода
#include <stack>      // Для использования std::stack
#include <stdexcept>  // Для исключений (runtime_error)
using namespace std;  // Стандартное пространство имён

class MinStack { // Объявляем класс нашего стека
private:
    stack<int> data; // Основной стек для хранения элементов
    stack<int> mins; // Вспомогательный стек для хранения минимумов

public:
    void push(int x) { // Метод добавления элемента
        data.push(x); // Кладём элемент в основной стек
        if (mins.empty()) { // Если стек минимумов пуст
            mins.push(x); // Минимум — это сам элемент
        } else {
            mins.push(min(x, mins.top())); // Иначе кладём минимум из x и текущего минимума
        }
    }

    void pop() { // Метод удаления верхнего элемента
        if (data.empty()) throw runtime_error("Стек пуст"); // Если пусто — исключение
        data.pop(); // Удаляем из основного стека
        mins.pop(); // Удаляем из стека минимумов
    }

    bool empty() const { // Метод проверки на пустоту
        return data.empty(); // Возвращаем true, если основной стек пуст
    }

    int top() const { // Метод получения верхнего элемента
        if (data.empty()) throw runtime_error("Стек пуст"); // Если пусто — исключение
        return data.top(); // Возвращаем вершину основного стека
    }

    int getMin() const { // Метод получения минимума за O(1)
        if (mins.empty()) throw runtime_error("Стек пуст"); // Если пусто — исключение
        return mins.top(); // Возвращаем вершину стека минимумов
    }
};

int main() { // Главная функция для демонстрации
    MinStack st; // Создаём объект стека
    st.push(5); // Добавляем 5
    st.push(3); // Добавляем 3
    st.push(7); // Добавляем 7
    st.push(2); // Добавляем 2

    cout << "Минимум: " << st.getMin() << endl; // Выведет 2

    st.pop(); // Удаляем 2
    cout << "Минимум после pop: " << st.getMin() << endl; // Выведет 3

    st.pop(); // Удаляем 7
    cout << "Минимум после pop: " << st.getMin() << endl; // Выведет 3

    st.pop(); // Удаляем 3
    cout << "Минимум после pop: " << st.getMin() << endl; // Выведет 5

    st.pop(); // Удаляем 5
    cout << "Стек пуст? " << (st.empty() ? "да" : "нет") << endl; // Выведет "да"

    return 0; // Завершаем программу
}