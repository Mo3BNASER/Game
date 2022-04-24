#include <stdlib.h>
#include <iostream>
#include <time.h>
#define data_left Data_Left
#define data_right Data_Right
using  namespace  std;
void play();


class Node //Creating a Node with single pointer
{
public:
    int Data_Right;
    int Data_Left;
    Node* next; //Pointer of class (Node) to data of its type
    void appendLast(Node** head_ref, int new_data_left, int new_data_right);

};
void Node::appendLast(Node** head_ref, int new_data_left, int new_data_right) //Insert at the end of the linked list
{
    Node* new_node = new Node();
    Node* last = *head_ref; // Pointer to move along the Linked List iteratively
    new_node->data_right = new_data_right;
    new_node->data_left = new_data_left;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    // return;
}
class demons
{
public:
    Node* total;
    Node* user;
    Node* comp;
    Node* Ground;

    demons();

    void Printlist(Node* n);
    void appendLast(Node** head_ref, int new_data_left, int new_data_right);//Insert at the end of the linked list
    void deleteelement(Node** headref, int key_left, int key_right);
    int Get_Right_edge_number(Node* head_ref);
    int Get_Left_edge_number(Node* head_ref);
    Node* play_Choose_card(Node* head_ref, int left_edge, int right_edge);
    void print_card_selected(Node* Card_selected);
    void push_Front(Node** Ground, int left, int right);
    Node* First_Play_for_comp_card(Node* head);
    Node* Check_buffa(Node* user);
    void print_game(Node* user, Node* comp, Node* bank);
    Node* computer_play_once(Node* ground, int left_edge, int right_edge);
    void Computer_take_from_bank(Node** bank, Node** comp);


};

void demons::Printlist(Node* n) //Printing a Linked List
{
    int  x = 0;
    while (n != NULL)
    {
        cout << x << " ------------ " << endl;
        cout << " |  " << n->Data_Left << "  |  " << n->Data_Right << "   |" << endl;
        cout << "  ------------ " << endl;
        //                                                                              --------------
        //                                                                              |  R  |  L   |
        //                                                                              --------------

        n = n->next;
        x++;
    }

}
void demons::appendLast(Node** head_ref, int new_data_left, int new_data_right) //Insert at the end of the linked list
{
    Node* new_node = new Node();
    Node* last = *head_ref; // Pointer to move along the Linked List iteratively
    new_node->data_right = new_data_right;
    new_node->data_left = new_data_left;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    // return;
}
void demons::deleteelement(Node** headref, int key_left, int key_right) {

    Node* temp = *headref;
    Node* prev = NULL;


    if (temp != NULL && temp->data_left == key_left && temp->data_left == key_left) { //special case :: if the head is to be deleted
        *headref = temp->next;
        delete temp;
    }

    else {

        while (temp != NULL && (temp->data_right != key_right || temp->data_left != key_left)) {
            prev = temp;
            temp = temp->next;

        }

        if (temp == NULL && temp->data_right != key_right && temp->data_left != key_left)
            return;

        if (temp->data_left == key_left && temp->data_right == key_right) {
            prev->next = temp->next;
            delete temp;
        }

    }


}
int demons::Get_Right_edge_number(Node* head_ref)                                         //fun 1
{

    Node* last = head_ref; // Pointer to move along the Linked List iteratively

    if (head_ref == NULL)
    {
        return 0;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }
    return (last->Data_Right);
    // return;


}
int demons::Get_Left_edge_number(Node* head)
{
    return head->Data_Left;
}
Node* demons::play_Choose_card(Node* head, int Ground_left_edge, int Ground_right_edge)                 // return a card chosen by player  (index)
{
    cout << "Ur turn, choose a card" << endl;
    int card = 0;
label:
    cin >> card;
    if (card > 6 || card < 0)
    {
        cout << "choose right card" << endl;
        goto label;
    }
    int k = 0;
    while (k != card)
    {
        head = head->next;
        k++;
    }
    //check if it has common data with ground or not
    while (!((head->Data_Left == Ground_left_edge) || (head->Data_Right == Ground_right_edge)))
    {
        cout << "can't play this card" << endl;
        goto label;
    }
    return head;


}
void demons::print_game(Node* user, Node* comp, Node* bank)
{
    Printlist(user);
    cout << "///////////////////////////////////////////////\n";
    Printlist(comp);
    cout << "///////////////////////////////////////////////\n";
    Printlist(bank);
}
void demons::print_card_selected(Node* Card_selected)
{
    cout << "U chose" << endl;
    cout << " --------------" << endl;
    cout << " |  " << Card_selected->Data_Left << "  |  " << Card_selected->Data_Right << "   |" << endl;
    cout << " --------------" << endl;
}
void demons::push_Front(Node** Ground, int left, int right)
{
    Node* new_node = new Node();
    new_node->Data_Left = left;
    new_node->Data_Right = right;

    new_node->next = (*Ground);
    (*Ground) = new_node;
    return;
}

Node* demons::First_Play_for_comp_card(Node* comp)
{
    Node* first = new Node();
    Node* ss = new Node();

    first = comp;
    ss = Check_buffa(first);        //cout << ss->next->Data_Left << "  " << ss->next->Data_Right << endl;

    return ss;

}
Node* demons::computer_play_once(Node* ground, int left_edge, int right_edge)
{
    for (int i = 0; i < 7; i++)
    {
        if (ground->Data_Left == left_edge && ground->Data_Right == right_edge)
        {
            return ground;
        }
    }

}
void demons::Computer_take_from_bank(Node** bank, Node** comp)
{
    Node* new_node = new Node();
    new_node = *bank;
    deleteelement(&(*bank), new_node->Data_Left, new_node->Data_Right);
    appendLast(&(*comp), new_node->Data_Left, new_node->Data_Right);
}

Node* demons::Check_buffa(Node* comp)
{
    Node* temp = comp;
    for (int i = 0; i < 7; i++)
    {
        if (comp->Data_Right == 6 && comp->Data_Left == 6)
        {
            return comp;
        }
        else if (comp->Data_Right == 5 && comp->Data_Left == 5)
        {
            return comp;

        }
        else if (comp->Data_Right == 4 && comp->Data_Left == 4)
        {
            return comp;

        }
        else if (comp->Data_Right == 3 && comp->Data_Left == 3)
        {
            return comp;

        }
        else if (comp->Data_Right == 2 && comp->Data_Left == 2)
        {
            return comp;

        }
        else if (comp->Data_Right == 1 && comp->Data_Left == 1)
        {
            return comp;

        }
        else if (comp->Data_Right == 0 && comp->Data_Left == 0)
        {
            return comp;

        }
        comp = comp->next;
    }
    return temp;

}
demons::demons()
{
    int x;

    Node* current = total;
    for (int i = 0; i < 7; i++)
    {
        total->appendLast(&total, 0, i);

    }
    for (int i = 1; i < 7; i++)
    {
        total->appendLast(&total, 1, i);

    }
    for (int i = 2; i < 7; i++)
    {
        total->appendLast(&total, 2, i);

    }
    for (int i = 3; i < 7; i++)
    {
        total->appendLast(&total, 3, i);

    }

    for (int i = 4; i < 7; i++)
    {
        total->appendLast(&total, 4, i);

    }
    for (int i = 5; i < 7; i++)
    {
        total->appendLast(&total, 5, i);

    }
    for (int i = 6; i < 7; i++)
    {
        total->appendLast(&total, 6, i);

    }
    int i = 0, count = 0;
    srand(time(NULL));
    while (count < 7)
    {
        current = total;
        i = 28 - count;
        x = rand() % i;

        for (int i = 0; i < x; i++)
            current = current->next;
        count++;
        user->appendLast(&user, current->Data_Left, current->Data_Right);
        deleteelement(&total, current->Data_Left, current->Data_Right);

    }
    srand(time(NULL));
    while (count < 14)
    {
        current = total;
        i = 28 - count;
        x = rand() % i;

        for (int i = 0; i < x; i++)
            current = current->next;
        count++;
        user->appendLast(&comp, current->Data_Left, current->Data_Right);
        deleteelement(&total, current->Data_Left, current->Data_Right);

    }





};


int main()
{
    play();



}

void play()
{
    demons game;               // make class object 
    Node* ptr = game.user;     // make user card linked list 
    Node* ptr0 = game.comp;    // make computer card linked list
    Node* ptr1 = game.total;   //
    game.print_game(ptr, ptr0, ptr1);
    // cout<< game.Get_Right_edge_number(ptr)<<" "<< game.Get_Left_edge_number(ptr);




    Node* Ground = new Node;                                         // make ground linked list and put buffa in ground
    Node* temp = game.First_Play_for_comp_card(game.comp);
    cout << temp->Data_Left << "  " << temp->Data_Right << endl;
    Ground->Data_Left = temp->Data_Left;
    Ground->Data_Right = temp->Data_Right;
    game.deleteelement(&game.comp, temp->Data_Left, temp->Data_Right);
    Ground->next = nullptr;
    game.Printlist(Ground);



    // game.push_Front(&Ground, temp->Data_Left, temp->Data_Right);



    // int Ground_Right_Edge = game.Get_Left_edge_number(Ground);           // get the right edge on the ground
     //int Ground_Left_Edge = game.Get_Right_edge_number(Ground);           // get the left edge on the ground

    // cout << "left  " << Ground_Left_Edge << "  right  " << Ground_Right_Edge << endl;


    // Node* Card_Selected_by_user = game.play_Choose_card(game.user, Ground_Left_Edge, Ground_Right_Edge);
    // game.print_card_selected(Card_Selected_by_user);
    //saaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaad

}