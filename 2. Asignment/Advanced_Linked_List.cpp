/*
- Create a linked list containing players's numerical orders
    + Circular linked list: 1-> 2 -> 3 ->... -> n -> 1
        . Struct Node
        . Function: addToEmpty: add node for empty list
        . Function: addEnd: add node to the end of the list
        . Function: AddToList: addnode with data from 1 to N
- function: eliminate node in the list
    + Eliminate(last_node,number_of_eliminated_node)
- function: TheWinner(last_node,M (number_of_eliminated_node),N(number_of_initialized_nodes))
*/
/*
The complexity:
    + AddToList function: O(n)
    + The_Winner function: O(n)
    => Complexity: O(n)
*/
#include <iostream>
using namespace std;
  
struct Node {
    int data;
    struct Node* next;
};
  
Node* addToEmpty(struct Node** last, int data)
{
    // This function is only for empty list
    Node *last_ = *last;
    if (last_ != NULL)
        return last_;
  
    // Creating a node dynamically.
    struct Node* temp
        = (struct Node*)malloc(sizeof(struct Node));
  
    // Assigning the data.
    temp->data = data;
    last_ = temp;
  
    // Creating the link.
    last_->next = last_;
    return last_;
}
Node* addEnd(struct Node** last, int data)
{
    Node *last_ = *last;
    if (last_ == NULL)
        return addToEmpty(&last_, data);
  
    // Creating a node dynamically.
    struct Node* temp
        = (struct Node*)malloc(sizeof(struct Node));
  
    // Assigning the data.
    temp->data = data;
  
    // Adjusting the links.
    temp->next = last_->next;
    last_->next = temp;
    last_ = temp;
  
    return last_;
}
void AddToList(Node **last, int N)
{
    for (int i =1; i<=N;i++)
    {
        *last = addEnd(last,i);
    }
}
void EliminateNode(Node** last, int M)
{
    for (int i =1; i<M;i++)
    {
        *last = (*last) -> next;
    }
    Node *temp = (*last)-> next;
    (*last) -> next = temp -> next;
    cout<<"deleted data"<<temp->data<<endl;
    delete(temp);
}
void TheWinner(Node**last, int N, int M)
{
    for (int i=1; i<N;i++)
    {
        EliminateNode(last,M);
        cout<<(*last)->data<<endl;
    }
    cout<<"The Winner is: "<<(*last)->data<<endl;
}
int main()
{
    Node* last = NULL;
    int N,M;
    cout<<"Number of players: "<<endl;
    cin>>N;
    cout<<"Number of eliminated player: "<<endl;
    cin>>M;
    AddToList(&last,N);
    //point to the first node
    Node* begin = last->next;
    TheWinner(&begin,N,M);
    return 0;
}
