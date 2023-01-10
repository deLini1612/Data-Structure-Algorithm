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
    void insert(int sbd, string hoTen) { return insert(sbd, hoTen, root); }
    Node *search(int sbd) { return search(sbd, root); }
    void deleteNode(int sbd) { root = deleteNode(root, sbd); }
    //Print tree in inorder (left -> parent -> right)
    void printTree(ostream &out = cout) const { return printTree(root, out); };

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
            return NULL;
        if (sbd == t->sbd)
            return t;
        if (sbd < t->sbd)
            return search(sbd, t->left);
        if (sbd > t->sbd)
            return search(sbd, t->right);
        return NULL;
    }

    Node *deleteNode(Node *root, int sbd)
    {
        if (root == NULL)
            return root;

        if (root->sbd > sbd)
        {
            root->left = deleteNode(root->left, sbd);
            return root;
        }
        else if (root->sbd < sbd)
        {
            root->right = deleteNode(root->right, sbd);
            return root;
        }

        // Case: delete root
        // If one of the children is empty
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // If both children exist
        else
        {
            Node *succParent = root;

            // Find successor (is the min element of the right tree of root)
            Node *succ = root->right;
            while (succ->left != NULL)
            {
                succParent = succ;
                succ = succ->left;
            }
            if (succParent != root)
                succParent->left = succ->right;
            else
                succParent->right = succ->right;
            root->sbd = succ->sbd;

            delete succ;
            return root;
        }
    }

    void printTree(Node *t, ostream &out) const
    {
        if (t != nullptr)
        {
            printTree(t->left, out);
            out << t->sbd << ": " << t->hoTen << endl;
            printTree(t->right, out);
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
    if (n1 != NULL)
        cout << "Sinh vien voi SBD=4 la " << n1->hoTen << endl;
    if (n2 == NULL)
        cout << "Khong tim thay sinh vien voi SBD=9" << endl; // Lam rong cay.
    cout << "========================" << endl;
    bst.printTree();
    cout << "========================" << endl;
    bst.deleteNode(5);
    bst.printTree();
    cout << "========================" << endl;
    bst.makeEmpty();
    if (bst.isEmpty())
        cout << "Cay da bi xoa rong" << endl;
    return 0;
}