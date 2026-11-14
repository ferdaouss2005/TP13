

#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>

template <typename T>
class ArrayDyn {
private:
    T* data;
    std::size_t capacity;
    std::size_t size;

    void agrandir() {
        std::size_t nouvelleCapacite = (capacity == 0) ? 2 : capacity * 2;
        T* nouveau = new T[nouvelleCapacite];

        for (std::size_t i = 0; i < size; i++)
            nouveau[i] = data[i];

        delete[] data;
        data = nouveau;
        capacity = nouvelleCapacite;
    }

public:
    class Iterator {
    private:
        T* ptr;

    public:
        Iterator(T* p = nullptr) : ptr(p) {}

        T& operator*() const { return *ptr; }

        Iterator& operator++() {
            ++ptr;
            return *this;
        }

        Iterator& operator--() {
            --ptr;
            return *this;
        }

        bool operator!=(const Iterator& autre) const {
            return ptr != autre.ptr;
        }
    };

    ArrayDyn() : data(nullptr), capacity(0), size(0) {}

    ArrayDyn(std::size_t capacite)
        : data(new T[capacite]), capacity(capacite), size(0) {}

    ArrayDyn(const ArrayDyn& autre)
        : data(new T[autre.capacity]),
          capacity(autre.capacity), size(autre.size) {
        for (std::size_t i = 0; i < size; i++)
            data[i] = autre.data[i];
    }

    ArrayDyn& operator=(const ArrayDyn& autre) {
        if (this != &autre) {
            T* nouveau = new T[autre.capacity];

            for (std::size_t i = 0; i < autre.size; i++)
                nouveau[i] = autre.data[i];

            delete[] data;
            data = nouveau;
            capacity = autre.capacity;
            size = autre.size;
        }
        return *this;
    }

    ~ArrayDyn() {
        delete[] data;
    }

    void push_back(const T& valeur) {
        if (size == capacity)
            agrandir();

        data[size++] = valeur;
    }

    void pop_back() {
        if (size == 0)
            throw std::out_of_range("Tableau vide");

        --size;
    }

    T& operator[](std::size_t index) {
        if (index >= size)
            throw std::out_of_range("Indice invalide");
        return data[index];
    }

    const T& operator[](std::size_t index) const {
        if (index >= size)
            throw std::out_of_range("Indice invalide");
        return data[index];
    }

    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + size); }

    std::size_t getSize() const { return size; }
};

class Etudiant {
public:
    std::string nom;
    int age;

    Etudiant(std::string n = "", int a = 0)
        : nom(n), age(a) {}

    friend std::ostream& operator<<(std::ostream& os,
                                    const Etudiant& e) {
        os << e.nom << " - " << e.age << " ans";
        return os;
    }
};

int main() {
    ArrayDyn<int> nombres;
    nombres.push_back(10);
    nombres.push_back(20);
    nombres.push_back(30);

    std::cout << "Tableau d'entiers : ";
    for (auto& e : nombres)
        std::cout << e << " ";
    std::cout << std::endl;

    ArrayDyn<std::string> mots;
    mots.push_back("Bonjour");
    mots.push_back("C++");
    mots.push_back("Templates");

    std::cout << "Tableau de chaines : ";
    for (auto& e : mots)
        std::cout << e << " ";
    std::cout << std::endl;

    ArrayDyn<Etudiant> etudiants;
    etudiants.push_back(Etudiant("Sara", 21));
    etudiants.push_back(Etudiant("Amine", 22));

    std::cout << "Tableau d'etudiants :" << std::endl;
    for (auto& e : etudiants)
        std::cout << e << std::endl;

    return 0;
}



