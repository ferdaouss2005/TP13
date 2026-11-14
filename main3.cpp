
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <initializer_list>

class StackOverflow : public std::exception {
public:
    const char* what() const noexcept override {
        return "Erreur : la pile est pleine !";
    }
};

class StackUnderflow : public std::exception {
public:
    const char* what() const noexcept override {
        return "Erreur : la pile est vide !";
    }
};

template <typename T>
class Stack {
private:
    std::unique_ptr<T[]> data;
    std::size_t capacity;
    std::size_t top;

public:
    Stack(std::size_t capacite = 10)
        : data(std::make_unique<T[]>(capacite)),
          capacity(capacite), top(0) {}

    template <typename Iterator>
    Stack(Iterator debut, Iterator fin) {
        capacity = 0;
        for (Iterator it = debut; it != fin; ++it)
            capacity++;

        data = std::make_unique<T[]>(capacity);
        top = 0;

        for (Iterator it = debut; it != fin; ++it)
            data[top++] = *it;
    }

    void push(const T& valeur) {
        if (top >= capacity)
            throw StackOverflow();

        data[top++] = valeur;
    }

    T pop() {
        if (empty())
            throw StackUnderflow();

        return data[--top];
    }

    const T& peek() const {
        if (empty())
            throw StackUnderflow();

        return data[top - 1];
    }

    bool empty() const {
        return top == 0;
    }

    std::size_t size() const {
        return top;
    }
};

int main() {
    try {
        Stack<int> pile(3);

        pile.push(10);
        pile.push(20);
        pile.push(30);

        std::cout << "Sommet : " << pile.peek() << std::endl;

        std::cout << "Element retire : "
                  << pile.pop() << std::endl;

        std::cout << "Nouveau sommet : "
                  << pile.peek() << std::endl;

        pile.push(40);
        pile.push(50);

    } catch (const StackOverflow& e) {
        std::cout << e.what() << std::endl;
    } catch (const StackUnderflow& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\nInitialisation depuis une collection :" << std::endl;

    int valeurs[] = {1, 2, 3, 4};

    Stack<int> pile2(valeurs, valeurs + 4);

    while (!pile2.empty())
        std::cout << pile2.pop() << " ";

    std::cout << std::endl;

    return 0;
}



