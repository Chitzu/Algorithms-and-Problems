#ifndef SDA_QUEUE_H
#define SDA_QUEUE_H

using namespace std;

template <class T>
class Queue;

template <class T>
class Node
{
    T reducere50{};
    T reducereC{};
    T timp{};

    Node<T>* next{};

public:
    Node()
    {
        next = nullptr;
        reducere50 = 0;
        reducereC = 0;
        timp = 0;
    }

    explicit Node(T r5, T rc, T t)
    {
        reducere50 = r5;
        reducereC = rc;
        timp = t;
        next = nullptr;

    }

    ~Node() //obligatoriu
    {
        delete next;
    }

    friend class Queue<T>;
};

template <class T>
class Queue
{
    Node<T>* head{};
    Node<T>* tail{};


public:
    Queue()
    {
        head = new Node<T>();
        head->next = NULL;
        tail = head;
    }

    ~Queue() //obligatoriu
    {
        delete head;
    }

    void push(T r5, T rc, T t) //adauga nod in coada
    {
        tail->next = new Node<T>(r5,rc,t);
        tail = tail->next;
        tail->next = NULL;
    }

    void pop() // elimina nod din coada
    {
        if (head->next == tail) {
            tail = head;
        }
        Node<T>* tmp = head->next;
        head->next = head->next->next;
        tmp->next = NULL;
        delete tmp;
    }

    bool empty() //verifica daca coada este goala
    {
        if (head == tail)return true;
        return false;
    }

    void afisare() {
        Node<T>* tmp;
        tmp = head->next;
        int i = 1;
        while (tmp!=NULL) {

            cout << i << " " << tmp->reducere50 << " " << tmp->reducereC << " " << tmp->timp << endl;
            i++;
            tmp = tmp->next;
        }
    }

    void Prelucrare() {
        Node<T>* tmp;
        tmp = head->next;
        int i = 1;
        int SB50 = 0, SBC = 0, maxim = 0,client=0;
        while (tmp != NULL) {

            SB50 +=tmp->reducere50;
            SBC +=tmp->reducereC;
            if (tmp->timp > maxim) { maxim = tmp->timp; client = i; }

            i++;
            tmp = tmp->next;
        }
        cout << SB50 << " " << SBC << " " << client << " " << maxim<<endl;
    }

    T& front() //intoarce referinta la data primului nod din coada
    {
        return head->next->data;
    }

    T& back() //intoarce referinta data ultimului nod din coada
    {
        return tail->data;
    }

};

#endif