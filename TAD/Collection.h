#ifndef SDA_CPP_COLLECTION_H
#define SDA_CPP_COLLECTION_H

template <typename E> // tip multime, E poate fi orice (string int etc), dar interfata e aceeasi; la fel adaug un element, ca e numar ca e altceva
struct Pair {
    E elem;
    int freq;
};

template <typename E>
class Collection {
private:
    Pair<E>* elems; //Aceasta implementare presupune ca tipul E are operator = și este copiabil
    // elems = vector dinamic, vectorul meu o sa fie un vector de perechi (o pereche grupeaza elem E si frecventa de cate ori apare (asa am definit struct pereche))
    int length;
    int capacity;
    void resize();

    //E fiind declarat pereche, el poate fi orice

public:
    Collection();
    Collection(const Collection& source);
    Collection& operator=(const Collection& source);
    void add(E elem);
    bool remove(E elem);
    bool search(E elem) const;
    int noOccurrences(E elem) const;
    int size() const;
    E getAt(int position) const;
    ~Collection();
};

#include "Collection.tpp"

#endif //SDA_CPP_COLLECTION_H