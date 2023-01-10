#include <iostream>
#include <queue>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node *left;
    Node *right;

    // Constructors
    Node(T d, Node *l, Node *r)
    {
        data = d;
        left = l;
        right = r;
    }

    bool operator==(const Node<T> &n1)
    {
        return (n1.data == this->data && n1.left == this->left && n1.right == this->right);
    }
};

template <class T>
class BinaryTree
{

public:
    // Constructors (ban dau la cay rong)
    BinaryTree()
    {
        root = NULL;
    }
    void InitBTree() { return InitBTree(root); }
    ~BinaryTree() { destroy_tree(); }
    void destroy_tree() { destroy_tree(root); }
    void initRoot(T d) { return initRoot(d, root); }

    Node<T> *getRoot() { return root; }
    void changeRoot(T nd, Node<T> *&t)
    {
        root = new Node<T>(nd, root, NULL);
    }

    Node<T> *findNode(T d) { return findNode(d, root); }
    Node<T> *findParent(T d) { return findParent(root, d); }

    // Insert a node with data d as parent of node child in Tree
    void insertParent(T d, Node<T> *child) { return insertParent(d, child, root); }
    void insertLeftChild(T d, Node<T> *parent) { return insertLeftChild(d, parent, root); }
    void insertRightChild(T d, Node<T> *parent) { return insertRightChild(d, parent, root); }
    void deleteCurrentNode(Node<T> *rm) { root = deleteCurrentNode(root, rm->data); }
    void deleteLeftChild(Node<T> *pr)
    {
        if (pr->left == NULL)
            return;
        else
            root = deleteCurrentNode(root, pr->left->data);
    }
    void deleteRightChild(Node<T> *pr)
    {
        if (pr->right == NULL)
            return;
        else
            root = deleteCurrentNode(root, pr->right->data);
    }
    int getSize() { return getSize(root); }

    // Print tree in inorder (left -> parent -> right)
    void printTree(ostream &out = cout) const { return printTree(root, out); }

    /*

    – DeleteCurrentNode(PNode P): xóa nút hiện trỏ bởi P trong cây

    – DeleteLeftChild(PNode P): xóa nút con trái của P

    – DeleteRightChild(PNode P): xóa nút con phải của P

    */

private:
    Node<T> *root;
    int size;

    void InitBTree(Node<T> *&r)
    {
        r = NULL;
        size = 0;
    }

    // Recursive to delete all nodes of tree
    void destroy_tree(Node<T> *node)
    {
        if (node != NULL)
        {
            destroy_tree(node->left);
            destroy_tree(node->right);
            delete node;
        }
    }

    // Init root node for an empty tree
    void initRoot(T d, Node<T> *&t)
    {
        if (t == NULL)
            t = new Node<T>(d, NULL, NULL);
        else
            cout << "Cay khong rong" << endl;
    }

    Node<T> *findNode(T d, Node<T> *t)
    {
        if (t == NULL)
            return NULL;

        if (t->data == d)
            return t;

        /* then recur on left subtree */
        Node<T> *res1 = findNode(d, t->left);
        // node found, no need to look further
        if (res1)
            return res1;

        /* node is not found in left,
        so recur on right subtree */
        Node<T> *res2 = findNode(d, t->right);
        return res2;
    }

    Node<T> *findParent(Node<T> *node, T d, Node<T> *parent = NULL)
    {
        if (node == NULL)
            return NULL;

        // If current node is the required node
        if (node->data == d)
        {
            return parent;
        }
        else
        {
            Node<T> *res1 = findParent(node->left, d, node);
            if (res1)
                return res1;
            Node<T> *res2 = findParent(node->right, d, node);
            return res2;
        }
    }

    void insertParent(T d, Node<T> *&child, Node<T> *&root)
    {
        // If tree is empty
        if (root == NULL)
        {
            cout << "Chen that bai, cay rong" << endl;
            return;
        }

        Node<T> *cparent = findParent(child->data); // current parent of child node
        // If child is root -> new node being new root
        if (cparent == NULL)
            changeRoot(d, root);
        else
        {
            Node<T> *nparent = new Node<T>(d, child, NULL);
            if (cparent->left->data == child->data)
            {
                cparent->left = nparent;
            }
            else
                cparent->right = nparent;
        }
    }

    void insertLeftChild(T d, Node<T> *&parent, Node<T> *&root)
    {
        Node<T> *leftChild = new Node<T>(d, NULL, NULL);
        if (parent->left == NULL)
            parent->left = leftChild;
        else
        {
            leftChild->left = parent->left;
            parent->left = leftChild;
        }
    }

    void insertRightChild(T d, Node<T> *&parent, Node<T> *&root)
    {
        Node<T> *rightChild = new Node<T>(d, NULL, NULL);
        if (parent->right == NULL)
            parent->right = rightChild;
        else
        {
            rightChild->right = parent->right;
            parent->right = rightChild;
        }
    }

    void printTree(Node<T> *t, ostream &out) const
    {
        if (t != nullptr)
        {
            printTree(t->left, out);
            out << t->data << endl;
            printTree(t->right, out);
        }
    }

    int getSize(Node<T> *root)
    {
        if (root == NULL)
            return 0;
        else
            return (getSize(root->left) + 1 + getSize(root->right));
    }

    Node<T> *deleteCurrentNode(Node<T> *&root, T key)
    {
        if (root == NULL)
            return NULL;
        if (root->left == NULL && root->right == NULL)
        {
            if (root->data == key)
                return NULL;
            else
                return root;
        }
        Node<T> *key_node = NULL;
        Node<T> *temp;
        Node<T> *last;
        queue<Node<T> *> q;
        q.push(root);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp->data == key)
                key_node = temp;
            if (temp->left)
            {
                last = temp; // storing the parent node
                q.push(temp->left);
            }
            if (temp->right)
            {
                last = temp; // storing the parent node
                q.push(temp->right);
            }
        }
        if (key_node != NULL)
        {
            key_node->data = temp->data;
            if (last->right == temp)
                last->right = NULL;
            else
                last->left = NULL;
            delete (temp);
        }
        return root;
    }
};

struct Point
{
    int x;
    int y;

    Point(int dx = 0, int dy = 0)
    {
        x = dx;
        y = dy;
    }
};

ostream &operator<<(ostream &os, const Point &p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}
bool operator==(const Point &p1, const Point &p2)
{
    return (p1.x == p2.x && p1.y == p2.y);
}

int main()
{
    // // Test with int Tree
    // BinaryTree<int> intTree;
    // intTree.initRoot(16);
    // intTree.insertParent(12, intTree.getRoot());
    // intTree.insertLeftChild(20, intTree.getRoot());
    // intTree.insertRightChild(30,intTree.findNode(20));
    // Node<int> *n1 = intTree.findNode(20);
    // intTree.insertRightChild(36, n1);
    // intTree.printTree();

    // Test with Point Tree
    BinaryTree<Point> pTree;
    pTree.initRoot(Point(12, 12));
    pTree.insertParent(Point(16, 2), pTree.getRoot());
    pTree.insertLeftChild(Point(2, 2), pTree.findNode(Point(12, 12)));
    pTree.insertRightChild(Point(20, 23), pTree.findNode(Point(2, 2)));
    pTree.insertRightChild(Point(2, 23), pTree.findNode(Point(12, 12)));
    pTree.insertRightChild(Point(9, 1), pTree.getRoot());
    pTree.insertRightChild(Point(6, 1), pTree.getRoot());
    pTree.insertParent(Point(5, 5), pTree.findNode(Point(2, 2)));
    pTree.insertParent(Point(2, 3), pTree.findNode(Point(12, 12)));
    pTree.printTree();
    cout << "Kich thuoc cua cay la: " << pTree.getSize() << endl;
    cout << "========================" << endl;
    cout << "Xoa nut " << pTree.findNode(Point(12, 12))->data << endl;
    pTree.deleteCurrentNode(pTree.findNode(Point(12, 12)));
    pTree.printTree();
    cout << "Kich thuoc cua cay la: " << pTree.getSize() << endl;
    cout << "========================" << endl;
    cout << "Xoa nut con trai cua " << pTree.findNode(Point(20, 23))->data << endl;
    pTree.deleteLeftChild(pTree.findNode(Point(20, 23)));
    pTree.printTree();
    cout << "Kich thuoc cua cay la: " << pTree.getSize() << endl;
    cout << "========================" << endl;
    cout << "Xoa nut con phai cua " << pTree.findNode(Point(6, 1))->data << endl;
    pTree.deleteRightChild(pTree.findNode(Point(6, 1)));
    pTree.printTree();
    cout << "Kich thuoc cua cay la: " << pTree.getSize() << endl;
    return 0;
}