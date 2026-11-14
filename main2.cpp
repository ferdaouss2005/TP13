
#include <iostream>
#include <initializer_list>
#include <stdexcept>

template <typename T, int N, int M>
class Matrice {
private:
    T data[N][M];

public:
    Matrice() {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                data[i][j] = T{};
    }

    Matrice(std::initializer_list<T> valeurs) : Matrice() {
        if (valeurs.size() != N * M)
            throw std::invalid_argument("Nombre de valeurs incorrect");

        int k = 0;
        for (const T& valeur : valeurs) {
            data[k / M][k % M] = valeur;
            k++;
        }
    }

    Matrice operator+(const Matrice& autre) const {
        Matrice resultat;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                resultat.data[i][j] = data[i][j] + autre.data[i][j];

        return resultat;
    }

    template <int P>
    Matrice<T, N, P> operator*(const Matrice<T, M, P>& autre) const {
        Matrice<T, N, P> resultat;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < P; j++) {
                T somme{};

                for (int k = 0; k < M; k++)
                    somme += data[i][k] * autre.data[k][j];

                resultat.data[i][j] = somme;
            }
        }

        return resultat;
    }

    template <typename U, int L, int C>
    friend std::ostream& operator<<(std::ostream& os,
                                    const Matrice<U, L, C>& matrice);
};

template <typename T, int N, int M>
std::ostream& operator<<(std::ostream& os,
                         const Matrice<T, N, M>& matrice) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            os << matrice.data[i][j] << "\t";
        os << std::endl;
    }
    return os;
}

int main() {
    Matrice<int, 2, 2> A{1, 2, 3, 4};
    Matrice<int, 2, 2> B{5, 6, 7, 8};

    std::cout << "Addition :" << std::endl;
    std::cout << A + B;

    std::cout << "Multiplication :" << std::endl;
    std::cout << A * B;

    Matrice<double, 2, 2> C{1.5, 2.5, 3.5, 4.5};
    Matrice<double, 2, 2> D{2.0, 1.0, 1.0, 2.0};

    std::cout << "Matrices double :" << std::endl;
    std::cout << C + D;

    return 0;
}
