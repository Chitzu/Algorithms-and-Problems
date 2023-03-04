#include <iostream>
#include <math.h>
using namespace std;


template <class T>
class ArboreBST;

template <class T>
class Node
{
public:
    T data{};
    Node<T>* st{};
    Node<T>* dr{};

    Node()
    {
        st = NULL;
        dr = NULL;
        data = 0;
    }
    explicit Node(T _data)
    {
        st = NULL;
        dr = NULL;
        data = _data;
    }


    int maxDepth(Node<T>* node)
    {
        if (node == NULL)
            return 0;
        else {
           
            int lDepth = maxDepth(node->st);
            int rDepth = maxDepth(node->dr);

       
            if (lDepth > rDepth)
                return (lDepth + 1);
            else
                return (rDepth + 1);
        }
    }

    int isHeightBalanced(Node<T>* node)
    {
        if (!node) {
            return true;
        }

        int lDepth = maxDepth(node->st);
        int rDepth = maxDepth(node->dr);

        if (abs(lDepth - rDepth) > 1)
            return false;
        return isHeightBalanced(node->st) && isHeightBalanced(node->dr);
    }

    void adauga_d(T const& val) {

        if (val < data)
        {
            if (st)
                st->adauga_d(val);
            else
                st = new Node<T>(val);
        }

        else
        {
            if (dr)
                dr->adauga_d(val);
            else
                dr = new Node<T>(val);
        }

    }

    friend class ArboreBST<T>;


};


template <class T>
class ArboreBST
{
public:
    Node<T>* root{};

    void adauga(T const& val)
    {
        if (!root)
        {
            root = new Node<T>(val);
        }
        else root->adauga_d(val);
    }


    int calculeazaAdancime() {
        return root->maxDepth(root);
    }

    bool esteEchilibrat() {
        return root->isHeightBalanced(root);

    }
};