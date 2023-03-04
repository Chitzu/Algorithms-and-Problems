#include <string>
#include <vector>

using namespace std;
class Node {

public:

    std::string nume;
    double medie;
    Node* next;
     int count;
    Node()
    {
        next = NULL;
        nume = "";
        medie = 0;
        count = 0;
    }


    Node(std::string n, double m)
    {
        nume = n;
        medie = m;
        next = NULL;
        count = 0;
    }

    

    friend class Lista;
};


class Lista {
public:

    Node* head{};
    Lista() {
        head = new Node;
    }

    virtual ~Lista()
    {
        Node* tmp = head;
        while (tmp)
        {
            head = tmp->next;
            delete tmp;
            tmp = head;
        }
    }

    void adaugaStudent(std::string nume, double medie)
    {
        Node* temp = new Node(nume, medie);
        temp->next = head->next;
        head->next = temp;
        

        if (temp->next == NULL)
        {
            temp->count = 0;
        }
        else {
            temp->count = temp->next->count + 1;
        }
        // afisare();
    }

    int length(Node* current)
    {
        int count1 = 0;
        while (current != NULL) {
            current = current->next;
            count1++;

        }
        return count1;
    }

    void merge(Node** start1, Node** end1, Node** start2, Node** end2)
    {

        Node* temp = NULL;
        
            if ((*start1)->medie > (*start2)->medie) {
                swap(*start1, *start2);
                swap(*end1, *end2);

            }
        

             Node* astart = *start1, * aend = *end1;
             Node* bstart = *start2, * bend = *end2;
             Node* bendnext = (*end2)->next;
        while (astart != aend && bstart != bendnext) {
            if ((astart->next->medie > bstart->medie) || ((astart->next->medie == bstart->medie) && (astart->next->nume.compare(bstart->nume) < 0))){
                temp = bstart->next;
                bstart->next = astart->next;
                astart->next = bstart;
                bstart = temp;
            }
            astart = astart->next;
        }
        if (astart == aend)
            astart->next = bstart;
        else
            *end2 = *end1;
    }



    void mergeSort(Node** head)
    {
        if (*head == NULL)
            return;
        Node* start1 = NULL;
        Node* end1 = NULL;
        Node* start2 = NULL;
        Node* end2 = NULL;
        Node* prevend = NULL;
         int len = length(*head);


        for ( int gap = 1; gap < len; gap = gap * 2) {
            start1 = *head;
            while (start1) {
                bool isFirstIter = 0;
                if (start1 == *head)
                    isFirstIter = 1;

                 int counter = gap;
                end1 = start1;
                while (--counter && end1->next)
                {
                    end1 = end1->next;
                }
                start2 = end1->next;
                if (!start2)
                {

                    break;


                }
                counter = gap;
                end2 = start2;

                while (--counter && end2->next)
                {
                    end2 = end2->next;
                }
                Node* temp = end2->next;
                merge(&start1, &end1, &start2, &end2);

                if (isFirstIter)
                    *head = start1;
                else
                    prevend->next = start1;

                prevend = end2;
                start1 = temp;

            }
            prevend->next = start1;
        }
    }

    

    std::vector<int> returneazaIndecsiSortati() {
        vector<int> v;

        mergeSort(&head);
        Node* current = head->next;
        while (current != NULL)
        {
            v.push_back(current->count);
            current = current->next;
        }
         int size = v.size();
        for ( int i = 0; i < size / 2; ++i)
        {
            if (i != size - i - 1)
            {
                swap(v[i], v[size - i - 1]);
            }
        }
        return v;
    }
};
