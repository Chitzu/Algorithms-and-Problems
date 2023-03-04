#ifndef SDA1_LIST_H
#define SDA1_LIST_H

template <class T>
class List;

template <class T>
class Node
{
    T data{};
    Node<T>* next{};

  public:
    Node() 
    {
        
    }

    explicit Node(T _data)  
    {
        data = _data;
    }

    Node<T>* Next() {
        return next;
    }

    bool isEnd() 
    {
        return next == NULL; 
    }

    ~Node() 
    {
        
    }

    T Data()
    {
        return data;
    }


    Node<T>* Reverse() {
        if (next == NULL) 
            return this;

        if (next->next == NULL) { 
            Node<T>* tmp = next;
            next = NULL; 
            return tmp; 
        } else {
            Node<T> *tmp = next->Reverse(); 
                                            
            next->next = this; 
            next = NULL; 
                         
            return tmp; 
        }
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
        Node<T> *tmp;
        tmp = head->next;
        while (tmp) {
            head->next = tmp->next;
            delete tmp;
            tmp = head->next;
        }
        delete head;
    }

    void push_front(T data) //adaugare nod la inceputul listei
    {
        Node<T> *newNode = new Node<T>(data);
        newNode->next = head->next;
        head->next = newNode;
       //. . . .
    }

    Node<T>* begin() // intoarce pointer la primul nod din lista
    {
        return head->next;
    }

    void Prelucrare(int P1, int P2) // functia ceruta in problema
    {
        Node<T> *pcrt;
        if ((head->next == NULL) || (head->next->next == NULL)) {
            return;
           
        }

        pcrt = head->next; 
        while (pcrt->next != NULL) {
            T dif = abs(pcrt->data - pcrt->next->data);
            if (dif > P1) { 
                T medie = (pcrt->data + pcrt->next->data) / 2;
                Node<T> *pnew = new Node<T>(medie);
                pnew->next = pcrt->next;
                pcrt->next = pnew;
                
            }
            else if (dif < P2) {
                Node<T> *ptmp;
                ptmp = pcrt->next;
                pcrt->next = pcrt->next->next;
                delete ptmp;
                
            }
            else {
                pcrt = pcrt->next;
               
            }
        }
        //. . . . . .
    }

    void Reverse()
    {
        if (head->next) 
            head->next = head->next->Reverse(); 
    }
};


#endif