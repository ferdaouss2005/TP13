
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <concepts>

template <typename T>
concept Sortable = requires(T a, T b) {
    { a < b } -> std::convertible_to<bool>;
};

struct Asc {
    template <typename T>
    bool operator()(const T& a, const T& b) const {
        return a < b;
    }
};

struct Desc {
    template <typename T>
    bool operator()(const T& a, const T& b) const {
        return a > b;
    }
};

template <Sortable T, typename Comp = std::less<T>>
void quickSort(std::vector<T>& v, Comp comp = Comp{}) {
    std::sort(v.begin(), v.end(), comp);
}

template <typename T>
void afficher(const std::vector<T>& v) {
    for (const auto& e : v)
        std::cout << e << " ";
    std::cout << std::endl;
}

struct Etudiant {
    std::string nom;
    int note;

    bool operator<(const Etudiant& autre) const {
        return note < autre.note;
    }

    bool operator>(const Etudiant& autre) const {
        return note > autre.note;
    }
};

std::ostream& operator<<(std::ostream& os, const Etudiant& e) {
    os << e.nom << " (" << e.note << ")";
    return os;
}

int main() {
    std::vector<int> nombres = {5, 2, 8, 1, 3};

    quickSort(nombres, Asc{});
    std::cout << "Entiers croissants : ";
    afficher(nombres);

    quickSort(nombres, Desc{});
    std::cout << "Entiers decroissants : ";
    afficher(nombres);

    std::vector<std::string> mots = {
        "Orange", "Banane", "Pomme", "Abricot"
    };

    quickSort(mots);
    std::cout << "Chaines triees : ";
    afficher(mots);

    std::vector<Etudiant> etudiants = {
        {"Sara", 15},
        {"Amine", 12},
        {"Salma", 18}
    };

    quickSort(etudiants, Asc{});
    std::cout << "Etudiants par note croissante : ";
    afficher(etudiants);

    bool test = std::is_sorted(
        nombres.begin(), nombres.end(), Desc{}
    );

    std::cout << "Test de tri decroissant : "
              << (test ? "Reussi" : "Echoue") << std::endl;

    return 0;
}
