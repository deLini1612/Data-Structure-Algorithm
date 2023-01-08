#include <iostream>
using namespace std;

struct Node
{

    int sbd;      
    string hoTen; 
    Node *left;   
    Node *right;  

    Node(int s, string h, Node *l, Node *r)
    {
        sbd = s;
        hoTen = h;
        left = l;
        right = r;
    }
};

class BSTree
{

public:                                      
    BSTree() { root = NULL; }                 
    ~BSTree() { makeEmpty(); }               
    bool isEmpty() { return (root == NULL); } 
    void makeEmpty() { makeEmpty(root); }     
    void insert(int sbd, string hoTen)
    {
        return insert(sbd, hoTen, root);
    } 
    Node *search(int sbd)
    {
        return search(sbd, root);
    }

    Node *findParent(int val) { return findParent(root, val); }
    void insertParent(int sbd, string hoTen, Node *&child) {return insertParent(sbd, hoTen, child,root);}

    Node *findNode(int sbd) { return findNode(sbd, root); }

    void printTree(ostream &out = cout) const
    {
        return printTree(root, out);
    };

private:
    Node *root; 
    void makeEmpty(Node *&t)
    {
        if (t == NULL)
            return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = NULL;
    }

 
    void insert(int sbd, string hoTen, Node *&t)
    {
        if (t == NULL) 

            t = new Node(sbd, hoTen, NULL, NULL);

        else if (sbd < t->sbd)

            insert(sbd, hoTen, t->left);

        else if (sbd > t->sbd)

            insert(sbd, hoTen, t->right);

        else
            ;
    }

    Node *search(int sbd, Node *t)
    {
        if (t == NULL)
        {
            return NULL;
        }
        if (sbd == t->sbd)
        {
            return t;
        }
        if (sbd < t->sbd)
        {
            return search(sbd, t->left);
        }
        if (sbd > t->sbd)
        {
            return search(sbd, t->right);
        }
        return NULL;
    }
    void printTree(Node *t, ostream &out) const
    {
        if (t != nullptr)
        {

            printTree(t->left, out);

            out << t->sbd << ": "<< t->hoTen << endl;

            printTree(t->right, out);
        }
    }

    Node *findNode(int sbd, Node *t)
    {
        if (t == NULL)
            return NULL;

        if (t->sbd == sbd)
            return t;

       
        Node *res1 = search(sbd, t->left);
        
        if (res1)
            return res1;

        
        Node *res2 = search(sbd, t->right);
        return res2;
    }

    Node *findParent(Node *node, int val, Node *parent = NULL)
    {
        if (node == NULL)
            return NULL;

      
        if (node->sbd == val)
        {
            return parent;
        }
        else
        {
            Node *res1 = findParent(node->left, val, node);
            if (res1)
                return res1;
            Node *res2 = findParent(node->right, val, node);
            return res2;
        }
    }

    void changeRoot(int sbd, string hoTen, Node *&t)
    {
        root = new Node(sbd,hoTen, root, NULL);
    }

    void insertParent(int sbd, string hoTen, Node *&child, Node *&root)
    {
        
        Node *cparent = findParent(child->sbd);
        if (cparent == NULL)
            changeRoot(sbd, hoTen, root);
        else
        {
            Node *nparent = new Node (sbd, hoTen ,child, NULL);
            if (cparent->left == child)
            {
                cparent->left = nparent;
            }
            else
                cparent->right = nparent;
        }
    }
};
int main()
{

    BSTree bst; 
    // Chen mot so sinh vien moi vao cay.
    bst.insert(5, "Tuan");
    bst.insert(6, "Lan");
    bst.insert(3, "Cong");
    bst.insert(8, "Huong");
    bst.insert(7, "Binh");
    bst.insert(4, "Hai");
    bst.insert(2, "Son"); 
    // Tim hai sinh vien co so bao danh 4 va 9.
    Node *n1 = bst.search(4);
    Node *n2 = bst.search(9); 
    // In ket qua tim kiem
    // if (n1 != NULL)
        cout << "Sinh vien voi SBD=4 la " << n1->hoTen << endl;
    if (n2 == NULL)
        cout << "Khong tim thay sinh vien voi SBD=9" << endl; // Lam rong cay.
    bst.printTree();
    cout <<"========================"<<endl;
    bst.insertParent(12,"Linh",n1);
    bst.printTree();
    Node *p1 = bst.findParent(3);
    if (p1 != NULL)
        cout << "Nut cha nut co SBD=3 la " << p1->sbd << endl;
    bst.makeEmpty();
    if (bst.isEmpty())
        cout << "Cay da bi xoa rong" << endl;
    return 0;
}