# TP13

EXERCICE1


<img width="348" height="133" alt="image" src="https://github.com/user-attachments/assets/c5de4f31-e4c6-4a7d-ac6b-37d7f99b311a" />


Dans cet exercice, j'ai créé un conteneur générique ArrayDyn à l'aide d'un template. Il permet de stocker différents types de données dans un tableau dynamique. J'ai implémenté les constructeurs, le constructeur de copie, l'opérateur d'affectation, les méthodes push_back et pop_back, ainsi que l'opérateur [] avec contrôle des bornes. J'ai également créé un itérateur personnalisé permettant de parcourir le conteneur avec une boucle range-based for. Enfin, j'ai testé le conteneur avec des entiers, des chaînes de caractères et des objets Etudiant.

EXERCICE2

<img width="216" height="231" alt="image" src="https://github.com/user-attachments/assets/e2a1f9e2-b5f6-4b00-9280-fa753278eda4" />


Dans cet exercice, j'ai développé une classe générique Matrice<T, N, M> permettant de représenter des matrices de dimensions fixes. J'ai utilisé un tableau statique à deux dimensions et un constructeur par défaut ainsi qu'un constructeur avec une liste d'initialisation. J'ai surchargé les opérateurs + et * pour effectuer l'addition et la multiplication matricielle, et l'opérateur << pour afficher les matrices. J'ai testé les opérations avec des matrices de type int et double.


EXERCICE3

<img width="334" height="193" alt="image" src="https://github.com/user-attachments/assets/273846ae-7299-443d-930f-bfe2c3abc5ff" />


Dans cet exercice, j'ai créé une classe générique Stack<T> qui représente une pile avec une capacité limitée. J'ai utilisé std::unique_ptr<T[]> pour gérer automatiquement la mémoire du tableau dynamique. J'ai implémenté les méthodes push, pop, peek et empty, ainsi que deux exceptions personnalisées StackOverflow et StackUnderflow. J'ai également ajouté un constructeur permettant d'initialiser la pile à partir d'une collection grâce à deux itérateurs. Enfin, j'ai testé les opérations et la gestion des erreurs.

EXERCICE4

<img width="443" height="205" alt="image" src="https://github.com/user-attachments/assets/b6a16daf-8a09-439c-9643-4511a9e864f5" />


Dans cet exercice, j'ai utilisé les concepts C++20 pour définir le concept Sortable, qui vérifie qu'un type possède l'opérateur inférieur. J'ai créé une fonction générique quickSort qui accepte un vecteur et un comparateur. J'ai également implémenté deux foncteurs Asc et Desc pour effectuer un tri croissant ou décroissant. J'ai testé le tri avec des entiers, des chaînes de caractères et une structure Etudiant possédant l'opérateur de comparaison. Enfin, j'ai utilisé std::is_sorted pour vérifier le résultat du tri.
