#include <conio.h>
#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <time.h>  
#include <windows.h>
#include <cstdlib>

using namespace std;
#define col_bank  4
#define row_bank  4
#define col_comp  24
#define col_ground 24
#define row_ground 10
#define row_comp  5
#define col_user  24
#define row_user  14+4
#define news_row  22
#define news_col 5
#define size_col  115
#define size_row  25
#define begin_template 0
#define name_game 1
bool check_doman(int choose, int size_of_user)
{
    if (choose > size_of_user)
    {
        void ckeck_validation_of_card();

        return false;
    }
    return true;
}
int y;
void gotoxy(short a, short b);    //simple here we init declare the gotoxy function

#define data_left Data_Left
#define data_right Data_Right
using  namespace  std;
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
void ckeck_validation_of_card() {
    gotoxy(news_col, news_row);
    std::cout << "the card  in not  valid  ....choose anoter one please";

}
class demons
{
public:
    Node* total;
    Node* user;
    Node* comp;
    Node* bank;
    Node* Ground;

    demons();

    void Printlist(Node* n);
    void Printlist_comp(Node* n);
    void Printlist_user(Node* n);
    void deleteelement(Node** headref, int key_left, int key_right);
    void delete_Printlist(Node* n);
    void delete_Printlist_comp(Node* n);
    void delete_Printlist_user(Node* n);
    int getCount(Node* head);

    //////////////arafa function/////////////////
    int Get_Right_edge_number(Node* head_ref);
    int Get_Left_edge_number(Node* head_ref);
    Node* play_Choose_card(Node* head_ref, int left_edge, int right_edge);
    void push_Front(Node** Ground, int left, int right);
    Node* First_Play_for_comp_card(Node* head);
    int Check_buffa(Node* temp);
    void print_game(Node* user, Node* comp, Node* bank);
    Node* computer_play_once(Node* ground, int left_edge, int right_edge);
    void Computer_take_from_bank(Node** bank, Node** comp);
    void user_take_from_bank(Node** bank, Node** user);
    bool add_to_ground(Node** ground, Node** player, int position_card);
    void print_ground(Node* ground);
    bool check_ability(Node* turn, Node* ground);
    int comp_play(Node* ground, Node* comp);
    bool Choose_Random_Mode();
    int get_data_sum(Node* Cards, int size_of_card);
    bool Check_if_closed(Node* Ground, Node* User, Node* Comp, Node* Bank);
    void getwin_0length(Node* user, Node* comp, int size_of_user, int size_of_comp);

    void Winner_if_it_closed(Node* User, Node* Comp, int size_comp, int size_user);




    /**/
};
/* emplementation  of  arafa function **/

void demons::getwin_0length(Node* user, Node* comp, int size_of_user, int size_of_comp)
{
    if (size_of_user == 0)
    {
        gotoxy(news_col, news_row);
        std::cout << "                                                                           ";
        gotoxy(news_col, 1 + news_row);
        std::cout << "                                                                           ";
        gotoxy(news_col, news_row);
        std::cout << "( you win )     score -->  (" << get_data_sum(comp, size_of_comp) << " )" << endl;
    }
    else
    {
        gotoxy(news_col, news_row);
        std::cout << "                                                                           ";
        gotoxy(news_col, 1 + news_row);
        std::cout << "                                                                           ";
        gotoxy(news_col, news_row);
        std::cout << "( computer won )     score -->  (" << get_data_sum(user, size_of_user) << " )" << endl;
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
    std::cout << "Ur turn, choose a card" << endl;
    int card = 0;
label:
    cin >> card;
    if (card > 6 || card < 0)
    {
        std::cout << "choose right card" << endl;
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
        std::cout << "can't play this card" << endl;
        goto label;
    }
    return head;


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
    // ss = Check_buffa(first);        //cout << ss->next->Data_Left << "  " << ss->next->Data_Right << endl;

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
    Node* ptrc = *comp;
    Node* new_node = new Node();
    new_node = *bank;
    ptrc->appendLast(&ptrc, new_node->Data_Left, new_node->Data_Right);
    deleteelement(&(*bank), new_node->Data_Left, new_node->Data_Right);

}

int demons::Check_buffa(Node* temp)
{
    Node* comp = temp;
    for (int i = 1; i < 7; i++)
    {
        if (comp->Data_Right == 6 && comp->Data_Left == 6)
        {
            return i;
        }
        else if (comp->Data_Right == 5 && comp->Data_Left == 5)
        {
            return i;

        }
        else if (comp->Data_Right == 4 && comp->Data_Left == 4)
        {
            return i;

        }
        else if (comp->Data_Right == 3 && comp->Data_Left == 3)
        {
            return i;

        }
        else if (comp->Data_Right == 2 && comp->Data_Left == 2)
        {
            return i;

        }
        else if (comp->Data_Right == 1 && comp->Data_Left == 1)
        {
            return i;

        }
        else if (comp->Data_Right == 0 && comp->Data_Left == 0)
        {
            return i;

        }
        comp = comp->next;
    }
    return 0;

}



/***/

void demons::Printlist(Node* n) //Printing a Linked List
{
    int x = 0;

    while (n != NULL)
    {
        gotoxy(col_bank, x + row_bank);
        std::cout << "   [" << n->data_left; std::cout << "|";
        std::cout << n->data_right << "]";
        n = n->next;
        x++;
    }

}
void demons::Printlist_user(Node* n) //Printing a Linked List
{
    y = 1;
    if (getCount(n) <= 9)
    {
        gotoxy(col_user, row_user);


        while (n != NULL)
        {
            std::cout << "  " << y << " [" << n->data_left; std::cout << "|";
            std::cout << n->data_right << "]";
            n = n->next;
            y++;
        }
    }
    else if (getCount(n) <= 18)
    {
        gotoxy(col_user, row_user);

        for (int i = 0; i < 9; i++)
        {
            std::cout << "   " << y << " [" << n->data_left; std::cout << "|";
            std::cout << n->data_right << "]";
            n = n->next;
            y++;
        }
        gotoxy(col_user, 1 + row_user);


        while (n != NULL)
        {
            std::cout << "  " << y << "-[" << n->data_left; std::cout << "|";
            std::cout << n->data_right << "]";
            n = n->next;
            y++;
        }

    }
    else
    {
        gotoxy(col_user, row_user);

        for (int i = 0; i < 9; i++)
        {
            std::cout << "   " << y << " [" << n->data_left; std::cout << "|";
            std::cout << n->data_right << "]";
            n = n->next;
            y++;
        }
        gotoxy(col_user, 1 + row_user);
        for (int i = 0; i < 9; i++)
        {
            std::cout << "  " << y << "-[" << n->data_left; std::cout << "|";
            std::cout << n->data_right << "]";
            n = n->next;
            y++;

        }
        gotoxy(col_user, 2 + row_user);

        while (n != NULL)
        {
            std::cout << "  " << y << "-[" << n->data_left; std::cout << "|";
            std::cout << n->data_right << "]";
            n = n->next;
            y++;
        }

    }

}
void demons::Printlist_comp(Node* n) //Printing a Linked List
{
    y = 1;
    if (getCount(n) <= 9)
    {
        gotoxy(col_comp, row_comp);


        while (n != NULL)
        {
            std::cout << "  " << y << " [" << n->data_left; std::cout << "|";
            std::cout << n->data_right << "]";
            n = n->next;
            y++;
        }
    }
    else if (getCount(n) <= 18)
    {
        gotoxy(col_comp, row_comp);

        for (int i = 0; i < 9; i++)
        {
            std::cout << "   " << y << " [" << n->data_left; std::cout << "|";
            std::cout << n->data_right << "]";
            n = n->next;
            y++;
        }
        gotoxy(col_comp, 1 + row_comp);


        while (n != NULL)
        {
            std::cout << "  " << y << "-[" << n->data_left; std::cout << "|";
            std::cout << n->data_right << "]";
            n = n->next;
            y++;
        }

    }
    else
    {
        gotoxy(col_comp, row_comp);

        for (int i = 0; i < 9; i++)
        {
            std::cout << "   " << y << " [" << n->data_left; std::cout << "|";
            std::cout << n->data_right << "]";
            n = n->next;
            y++;
        }
        gotoxy(col_comp, 1 + row_comp);
        for (int i = 0; i < 9; i++)
        {
            std::cout << "  " << y << "-[" << n->data_left; std::cout << "|";
            std::cout << n->data_right << "]";
            n = n->next;
            y++;

        }
        gotoxy(col_comp, 2 + row_comp);

        while (n != NULL)
        {
            std::cout << "  " << y << "-[" << n->data_left; std::cout << "|";
            std::cout << n->data_right << "]";
            n = n->next;
            y++;
        }

    }

}
bool demons::add_to_ground(Node** ground, Node** player, int position_card)
{
    Node* ptrp = *player;
    Node* ptrg = *ground;

    for (int i = 1; i < position_card; i++)
        ptrp = ptrp->next;

    if (getCount(*ground) == 0)
    {
        push_Front(ground, ptrp->Data_Left, ptrp->Data_Right);
        deleteelement(player, ptrp->Data_Left, ptrp->Data_Right);

        return true;
    }
    else
    {
        int right = Get_Right_edge_number(ptrg);
        int left = Get_Left_edge_number(ptrg);

        if (ptrp->Data_Left == left)
        {
            push_Front(ground, ptrp->Data_Right, ptrp->Data_Left);
            deleteelement(player, ptrp->Data_Left, ptrp->Data_Right);
            return true;
        }
        else if (ptrp->Data_Right == left)
        {
            push_Front(ground, ptrp->Data_Left, ptrp->Data_Right);
            deleteelement(player, ptrp->Data_Left, ptrp->Data_Right);
            return true;
        }
        else if (ptrp->Data_Left == right)
        {
            ptrg->appendLast(ground, ptrp->Data_Left, ptrp->Data_Right);
            deleteelement(player, ptrp->Data_Left, ptrp->Data_Right);
            return true;
        }
        else if (ptrp->Data_Right == right)
        {
            ptrg->appendLast(ground, ptrp->Data_Right, ptrp->Data_Left);
            deleteelement(player, ptrp->Data_Left, ptrp->Data_Right);
            return true;

        }
        else {

            ckeck_validation_of_card();
            return false;

        }
    }

}

/**//////////////////////////////////////////////////////
void demons::user_take_from_bank(Node** bank, Node** user)
{
    Node* ptru = *user;

    Node* new_node = new Node();
    new_node = *bank;
    ptru->appendLast(&ptru, new_node->Data_Left, new_node->Data_Right);
    deleteelement(&(*bank), new_node->Data_Left, new_node->Data_Right);
}
/**//////////////////////////////////////////////////////
/***/
HANDLE console_color;
int x1 = 0;
/***/
void  demons::print_ground(Node* ground)
{
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    x1 = 0;
    if (getCount(ground) <= 9)
    {

        gotoxy(col_ground, row_ground);



        while (ground != NULL)
        {
            if (!(ground->next) || x1 == 0)
            {
                SetConsoleTextAttribute(console_color, 4);
                x1++;
            }
            else
                SetConsoleTextAttribute(console_color, 15);
            std::cout << "[" << ground->data_left; std::cout << "|";
            std::cout << ground->data_right << "]";
            ground = ground->next;
            SetConsoleTextAttribute(console_color, 15);

        }
    }
    else if (getCount(ground) <= 18)
    {
        gotoxy(col_ground, row_ground);

        for (int i = 0; i < 9; i++)
        {
            if (!(ground->next) || x1 == 0)
            {
                SetConsoleTextAttribute(console_color, 4);
                x1++;
            }
            else
                SetConsoleTextAttribute(console_color, 15);
            std::cout << "[" << ground->data_left; std::cout << "|";
            std::cout << ground->data_right << "]";
            ground = ground->next;
            SetConsoleTextAttribute(console_color, 15);


        }
        int i = 0;

        while (ground != NULL)
        {
            gotoxy(36 - 5 * i + 1 + col_ground, 2 + row_ground);

            if (!(ground->next) || x1 == 0)
            {
                SetConsoleTextAttribute(console_color, 4);
                x1++;
            }
            else
                SetConsoleTextAttribute(console_color, 15);
            std::cout << "   [" << ground->Data_Right; std::cout << "|";
            std::cout << ground->Data_Left << "]";
            ground = ground->next;
            SetConsoleTextAttribute(console_color, 15);
            i++;
        }

    }
    else
    {
        gotoxy(col_ground, row_ground);

        for (int i = 0; i < 9; i++)
        {
            if (!(ground->next) || x1 == 0)
            {
                SetConsoleTextAttribute(console_color, 4);
                x1++;
            }
            else
                SetConsoleTextAttribute(console_color, 15);
            std::cout << "[" << ground->data_left; std::cout << "|";
            std::cout << ground->data_right << "]";
            ground = ground->next;
            SetConsoleTextAttribute(console_color, 15);

        }
        for (int i = 0; i < 9; i++)
        {
            gotoxy(36 - 5 * i + 1 + col_ground, 2 + row_ground);

            if (!(ground->next) || x1 == 0)
            {
                SetConsoleTextAttribute(console_color, 4);
                x1++;
            }
            else
                SetConsoleTextAttribute(console_color, 15);
            std::cout << "[" << ground->Data_Right; std::cout << "|";
            std::cout << ground->Data_Left << "]";
            ground = ground->next;
            SetConsoleTextAttribute(console_color, 15);

        }
        gotoxy(col_ground, 4 + row_ground);

        while (ground != NULL)
        {
            if (!(ground->next) || x1 == 0)
            {
                SetConsoleTextAttribute(console_color, 4);
                x1++;
            }
            else
                SetConsoleTextAttribute(console_color, 15);
            std::cout << "[" << ground->data_left; std::cout << "|";
            std::cout << ground->data_right << "]";
            ground = ground->next;
            SetConsoleTextAttribute(console_color, 15);

        }

    }
}

void demons::delete_Printlist_user(Node* n) //Printing a Linked List
{
    gotoxy(col_user, row_user);
    std::cout << "                                                                                             ";
    gotoxy(col_user, 1 + row_user);
    std::cout << "                                                                                             ";
    gotoxy(col_user, 2 + row_user);
    std::cout << "                                                                                             ";
}
void demons::delete_Printlist(Node* n) //Printing a Linked List
{
    std::cout << getCount(n);
    for (int i = 14; i > getCount(n); i--)
    {
        gotoxy(col_bank, -1 + i + row_bank);

        std::cout << "    " << ' '; std::cout << " ";
        std::cout << ' ' << " ";

    }

}

int demons::getCount(Node* head)
{
    // Base Case
    int x7 = 0;
    while (head != NULL)
    {
        x7++;
        head = head->next;
    }
    return x7;
}

/**/
void demons::deleteelement(Node** headref, int key_left, int key_right) {

    Node* temp = *headref;
    Node* prev = NULL;


    if (temp != NULL && temp->Data_Right == key_right && temp->data_left == key_left) { //special case :: if the head is to be deleted 
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

        comp->appendLast(&comp, current->Data_Left, current->Data_Right);
        deleteelement(&total, current->Data_Left, current->Data_Right);


    }


    srand(time(NULL));
    while (count < 28)
    {
        current = total;
        i = 28 - count;
        x = rand() % i;

        for (int i = 0; i < x; i++)
            current = current->next;
        count++;
        bank->appendLast(&bank, current->Data_Left, current->Data_Right);
        deleteelement(&total, current->Data_Left, current->Data_Right);

    }

};

void print_template()
{
    HANDLE console_color;
    console_color = GetStdHandle(
        STD_OUTPUT_HANDLE);
    gotoxy(begin_template + 3 * size_col / 8, begin_template + name_game);
    SetConsoleTextAttribute(console_color, 30);
    std::cout << "/ THE DOMINO's GAME /";

    gotoxy(begin_template + 3 * size_col / 8, begin_template + 1 + name_game);
    std::cout << "/////////////////////";

    gotoxy(begin_template, begin_template);
    for (int i = 0; i < size_col; i++)
        std::cout << '/';
    for (int i = 0; i < size_row; i++)
    {
        gotoxy(begin_template, begin_template + i);

        std::cout << '/';
    }


    for (int i = 0; i < size_row; i++)
    {
        gotoxy(size_col + begin_template, begin_template + i);

        std::cout << '/';
    }
    gotoxy(begin_template, begin_template + size_row);
    for (int i = 0; i < size_col; i++)
    {

        std::cout << '/';

    }
    gotoxy(+4 + col_bank, -1 + row_bank);
    std::cout << "BANK";
    gotoxy(10 + begin_template + 3 * size_col / 8, 2 + begin_template + 1 + name_game);

    std::cout << "COMPUTER";

    gotoxy(12 + begin_template + 3 * size_col / 8, 14 + begin_template + 2 + name_game);
    std::cout << "..YOU..";

    SetConsoleTextAttribute(console_color, 15);

}
bool demons::check_ability(Node* turn, Node* ground)
{
    if (ground == NULL)
        return true;
    int left = Get_Left_edge_number(ground);
    int right = Get_Right_edge_number(ground);

    while (turn != NULL)
    {
        if (left == turn->Data_Left || left == turn->Data_Right || right == turn->Data_Right || right == turn->Data_Left)
            return true;
        turn = turn->next;

    }
    return false;
}
int demons::comp_play(Node* ground, Node* comp)
{
    if (ground == NULL)
        return 1;
    int left = Get_Left_edge_number(ground);
    int right = Get_Right_edge_number(ground);
    int n = 1;
    while (comp != NULL)
    {
        if (left == comp->Data_Left || left == comp->Data_Right || right == comp->Data_Right || right == comp->Data_Left)
            return n;
        comp = comp->next;
        n++;
    }
    //return false;
}
void demons::delete_Printlist_comp(Node* n)
{
    gotoxy(col_comp, row_comp);
    std::cout << "                                                                           ";
    gotoxy(col_comp, 1 + row_comp);
    std::cout << "                                                                           ";
    gotoxy(col_comp, 2 + row_comp);
    std::cout << "                                                                           ";
}
/****/

void demons::Winner_if_it_closed(Node* User, Node* Comp, int size_comp, int size_user)
{
    int score_comp = 0;
    int score_user = 0;
    int score_difference = 0;
    score_comp = get_data_sum(Comp, size_comp);
    score_user = get_data_sum(User, size_user);


    if (score_user > score_comp)
    {
        // computer winner

        score_difference = score_comp - score_user;

        gotoxy(news_col, news_row);
        std::cout << "                                                                           ";
        gotoxy(news_col, 1 + news_row);
        std::cout << "                                                                           ";
        gotoxy(news_col, news_row);
        std::cout << "( computer wins )     score -->  (" << score_comp << "  -" << score_user << " )" << endl;
    }
    else
    {
        // user winner

        score_difference = score_user - score_comp;

        gotoxy(news_col, news_row);
        std::cout << "                                                                           ";
        gotoxy(news_col, 1 + news_row);
        std::cout << "                                                                           ";
        gotoxy(news_col, news_row);
        std::cout << "( User wins )     score -->  (" << score_comp << "  - " << score_user << " )" << endl;

    }
}
bool demons::Check_if_closed(Node* Ground, Node* User, Node* Comp, Node* Bank)
{
    int Bank_size = getCount(Bank);
    if (Bank_size == 0 && check_ability(User, Ground) == 0, check_ability(Comp, Ground) == 0)
    {
        return 1;       // closed
    }
    else
    {
        return 0;       //still open
    }
}
/*  bool demons::Get_Winner(Node* Ground, Node* Bank, Node* User, Node* Comp)
  {
      int user_size = getCount(User);
      int comp_size = getCount(Comp);
      int bank_size = getCount(Bank);
      if (Check_if_closed(Ground, User, Comp, Bank))
      {
          if (get_data_sum(User) > get_data_sum(Comp))
          {
              return 0;  // computer winner
          }
          else
          {
              return 1;  // user winner

          }
      }
      else if (user_size == 0 && comp_size != 0)
      {
          return 1; // user winner
      }
      else if (comp_size == 0 && user_size != 0)
      {
          return 0; //computer winner
      }



  }*/
  /*  int demons::Score_difference(Node* Ground, Node* Bank, Node* User, Node* Comp)
    {
        int Winner = Get_Winner(Ground, Bank, User, Comp);
        switch (Winner)
        {
        case 0:
        {
            return (get_data_sum(Comp) - get_data_sum(User));
            break;
        }
        case 1:
        {
            return (get_data_sum(User) - get_data_sum(Comp));
            break;

        }
        default:
            break;
        }
        return 0;
    }*/

int demons::get_data_sum(Node* Cards, int size_of_card)
{

    int sum = 0;
    for (int i = 0; i < size_of_card; i++)
    {
        sum = sum + ((Cards->Data_Left) + (Cards->Data_Right));

        Cards = Cards->next;
        if (Cards == NULL)
            break;
    }
    return sum;
}
bool demons::Choose_Random_Mode()
{
    srand(time(0));
    int random_Value = rand();
    return(random_Value % 2);               //  0 ---> Computer begins
}                                           //  1 ---> User begins

/***/
void main()
{
    demons nyazi;
    Node* ptru = nyazi.user;
    Node* ptrc = nyazi.comp;
    Node* ptrg = nyazi.Ground;
    Node* ptrb = nyazi.bank;
    int x5, size_of_user = nyazi.getCount(ptru), size_of_comp = nyazi.getCount(ptrc), size_of_bank = nyazi.getCount(ptrb);

    print_template();

    /*  for (int i = 0; i < 20; i++)
      {
          nyazi.Printlist_user(ptru);

          nyazi.Printlist(ptrb);
          nyazi.Printlist_comp(ptrc);
          nyazi.print_ground(ptrg);
          gotoxy(news_col, news_row);
          cin >> x5;
   nyazi.user_take_from_bank(&ptrb, &ptru);

      nyazi.add_to_ground(&ptrg,& ptru, x5);
      nyazi.delete_Printlist(ptrb);

      }
     */
    nyazi.Printlist_user(ptru);
    //  nyazi.delete_Printlist_user(ptru);

    //  nyazi.delete_Printlist(ptrb);
    nyazi.Printlist_comp(ptrc);
    nyazi.print_ground(ptrg);
    nyazi.Printlist(ptrb);

    while (1)
    {
    leable1:
        nyazi.Printlist_user(ptru);

        if (size_of_user > 0)
            if (nyazi.check_ability(ptru, ptrg))
            {
                gotoxy(news_col, news_row);
                cout << "                                                       ";
                gotoxy(news_col, 1 + news_row);
                cout << "                                                       ";
                gotoxy(news_col, news_row);
                cout << "please enter the no. of card ";
            again:
                cin >> x5;
                if (x5 > size_of_user)
                {
                    ckeck_validation_of_card();
                    goto again;
                }

                if (nyazi.add_to_ground(&ptrg, &ptru, x5))
                {
                    size_of_user--;
                    nyazi.print_ground(ptrg);
                    if (size_of_user == 0)
                        goto win;
                    nyazi.delete_Printlist_user(ptru);
                    gotoxy(news_col, news_row);
                    cout << "                                                       ";
                    gotoxy(news_col, 1 + news_row);
                    cout << "                                                       ";
                }
                else goto again;

            }
            else if (size_of_bank > 0)
            {
                size_of_user++;
                size_of_bank--;
                nyazi.user_take_from_bank(&ptrb, &ptru);
                nyazi.delete_Printlist(ptrb);
                //nyazi.delete_Printlist_user(ptru);
                nyazi.Printlist_user(ptru);

                goto leable1;

            }
            else if (nyazi.Check_if_closed(ptrg, ptru, ptrc, ptrb))
                goto end1;
            else goto computer;
        else goto win;

    computer:
        nyazi.Printlist_comp(ptrc);

        if (size_of_comp > 0)
            if (nyazi.check_ability(ptrc, ptrg))
            {
                nyazi.add_to_ground(&ptrg, &ptrc, nyazi.comp_play(ptrg, ptrc));
                size_of_comp--;
                if (size_of_comp == 0)
                    goto win;
                nyazi.delete_Printlist_comp(ptrc);

                nyazi.Printlist_comp(ptrc);

                nyazi.print_ground(ptrg);

            }
            else if (size_of_bank > 0)
            {
                nyazi.Computer_take_from_bank(&ptrb, &ptrc);
                size_of_bank--;
                size_of_comp++;
                nyazi.delete_Printlist(ptrb);
                nyazi.Printlist_comp(ptrc);
                nyazi.Printlist_comp(ptrc);

                goto computer;
            }
            else if (nyazi.Check_if_closed(ptrg, ptru, ptrc, ptrb))
                goto end1;
            else goto leable1;



    }
win:
    nyazi.delete_Printlist_user(ptru);
    nyazi.delete_Printlist_comp(ptrc);

    nyazi.getwin_0length(ptru, ptrc, size_of_user, size_of_comp);
    // _getch();
    goto end1;


end1:
    {
        nyazi.Winner_if_it_closed(nyazi.user, nyazi.comp, size_of_comp, size_of_user);

    }
}

void gotoxy(short x, short y)           //Introduction of gotoxy function//                                               
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h, c);
}