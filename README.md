# INF224_Project
Telecom Paris INF224 Project

## C++
Q4. Comment appelle-t'on ce type de méthode et comment faut-il les déclarer ?
    Methode virtual. On declare dans la classe de base le methode display en virtual 
    et on aujoute '= 0' a la fin pour que ca soit une methode virtual pure qui signifie que 
    cette methode ne peut pas etre implemente dans la classe de base et on doit faire override 
    dans les classe qui l'heritent.

Q5. Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ?
    Polymorphisme.

    Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ?
    Il faut initialiser le tableau avec des éléments Multimedia.

    Quel est le type des éléments du tableau : le tableau doit-il contenir des objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java.
    Le tableau doit contenir des pointeurs vers ces objets. 
    En java, ca se passe avec la reference, ce qui est similaire que pointeur.

Q7. La copie d'objet peut également poser problème quand ils ont des variables d'instance qui sont des pointeurs. 
    Quel est le problème et quelles sont les solutions ?

    Le problème est que les pointeurs pointent vers la même adresse mémoire que les objets d'origine. La solution est de faire une copie profonde. Il faut redéfini l'opérateur d'affectation.

    ```c++
    Film &Film::operator=(const Film &film)
    {
        if (this != &film)
        {
            Multimedia::operator=(film);
            this->duration = film.duration;
            this->chapters = new string[film.nbChapters];
            for (unsigned int i = 0; i < film.nbChapters; i++)
            {
                this->chapters[i] = film.chapters[i];
            }
        }
        return *this;
    }

    Film::Film(const Film &from) : Video(from), chapterCount(from.chapterCount)
    {
        if (from.chapters)
        {
            this->setChapters(from.chapters, from.chapterCount);
        }
        else
        {
            chapters = nullptr;
        }
    }
    ```
Q8. On rappelle aussi que la liste d'objets doit en fait être une liste de pointeurs d'objets. Pourquoi ?

    Pour pouvoir stocker des objets de type Photo, Video et Film dans le tableau.

Q10. Les méthodes précédentes permettent d'assurer la cohérence de la base de données car quand on crée un objet on l'ajoute à la table adéquate. 
     Par contre, ce ne sera pas le cas si on crée un objet directement avec new (il n'appartiendra à aucune table). Comment peut-on l'interdire, afin que seule la classe servant à manipuler les objets puisse en créer de nouveaux ?*

    On peut interdire la création d'objets directement avec new en rendant le constructeur de la classe Multimedia privé, et définir la classe DataMap comme amie de la classe Multimedia. 

Q12,13 Non traitées

## Java Swing

Q1. Lancez votre programme, cliquez plusieurs fois sur les deux premiers bouton, retaillez la fenêtre. Que constate-t'on ?

    On constate que le texte dépasse de la fenêtre, nous l'insérons au sein d'un composant `JScrollPane` qui rajoute un ascenseur vertical et horizontal lorsque c'est nécessaire.
