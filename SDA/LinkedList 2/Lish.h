#ifndef SDA1_LIST_H
#define SDA1_LIST_H
#include<math.h>

using namespace std;
template <class T>
class List;

template <class T>
class Node
{
    T data{};
    int nr_es;  // nr esantioane
    Node<T>* next{};

public:
    Node() // numai daca este necesar
    {
        next = NULL;
        nr_es = 1;
    }

    explicit Node(T _data)  // numai daca este necesar
    {
        data = _data;
        nr_es = 1;
        next = NULL;
    }

    ~Node() // numai daca este necesar
    {
        delete next;
    }

    unsigned long long Data();  // NU SE MODIFICA

    Node<T>* Next()
    {
        return next;
    }

    friend class List<T>;
};

template <class T>
class List
{
    Node<T>* head{};

public:
    List() // numai daca este necesar
    {
        head = new Node<T>;
    }

    ~List() // numai daca este necesar
    {

        delete head;
    }

    void push_front(T data) //adaugare nod la inceputul listei
    {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head->next;
        head->next = newNode;
    }

    Node<T>* begin() // intoarce pointer la primul nod din lista
    {
        return head->next;
    }
    void afisare() {
        Node<T>* tmp;
        tmp = head->next;
        int i = 0;
        while (tmp) {

            cout << i << " " << tmp->data << " " << tmp->nr_es << endl;
            i++;
            tmp = tmp->next;
        }
    }
    void Prelucrare(int dif) // functia ceruta in problema
    {
        Node<T>* curent;
        Node<T>* ferestre;
        curent = head->next->next;
        ferestre = head->next;

        int val_medie = ferestre->data;
        while (curent)
        {
            if (abs(ferestre->data - curent->data) < dif)
            {
                val_medie += curent->data;
                ferestre->nr_es += 1;
            }
            else
            {

                while (ferestre->next != curent)
                {
                    Node<T>* temporar = ferestre->next->next;

                    ferestre->next = NULL;
                    delete ferestre->next;

                    ferestre->next = temporar;
                }

                ferestre->data = val_medie / ferestre->nr_es;
              
                ferestre = curent;

                val_medie = ferestre->data;
            }
            if(curent->next==NULL && ferestre->nr_es!=1) ferestre->data = val_medie / ferestre->nr_es;
            curent = curent->next;
        }

        if (ferestre->next != NULL)
        {
            while (ferestre->next != NULL)
            {
                Node<T>* temporar = ferestre->next->next;


                ferestre->next = NULL;

                delete ferestre->next;

                ferestre->next = temporar;
            }
        }
    }
};

#endif