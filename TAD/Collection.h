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
    void add(E elem); //Void pt ca pot adauga orice si nu trebuie sa stiu daca s-a adaugat sau nu, restrictiile le pun in UI
    bool remove(E elem); //Bool pt ca vreau sa stiu daca am eliminat sau nu un element, adica daca a fost prezent acel element pt eliminare
    bool search(E elem) const;
    int noOccurrences(E elem) const;
    int size() const;
    E getAt(int position) const; //imi da bancnota de pe sirul 500, 500, etc, 100, 100, etc
    ~Collection();
    //getAtType(); imi da bancnota de tipul respectiv
};

#include "Collection.tpp"

#endif //SDA_CPP_COLLECTION_H


