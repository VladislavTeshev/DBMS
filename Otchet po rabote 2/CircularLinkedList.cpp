#include "CircularLinkedList.h"

Node::Node(const int data_) noexcept : data(data_) {}

Node::~Node() noexcept
{
	this->next = nullptr;
}

CircularLinkedList::CircularLinkedList() noexcept : head(nullptr) {}

CircularLinkedList::~CircularLinkedList() noexcept
{
    Node* currentNode = this->head; 
    Node* headPtr = currentNode;
    while (currentNode)
    {
        Node* nextNode = currentNode->next;    

        if (currentNode != headPtr) {
            delete currentNode;                   
        }

        if (nextNode == headPtr) {          
            delete headPtr;
            currentNode = nullptr;
        }
        else {
            currentNode = nextNode;                     
        }
    }
    head = nullptr;
}

void CircularLinkedList::add_node(const int data_) noexcept
{
    auto node = new Node(data_);

    if (head == nullptr)
    {
        head = node;
        node->next = head;
    }

    else
    {
        Node* ptr = head;

        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = node;
        node->next = head;

        head = node;
    }
}

Node* CircularLinkedList::delete_head(Node *node)
{
    Node* temp = node->next;
    Node* p = head;
    if (head == nullptr) 
        return nullptr;
    if (p->next == head)
    {
        delete head;
        return nullptr;
    }
    while (p->next != head)
    { 
        p = p->next;
    }
    p->next = temp; 
    delete head;

    return temp; 
}

void CircularLinkedList::remove() noexcept
{
    head = delete_head(head);
}

bool CircularLinkedList::find_node(const int data_) const noexcept
{
    if (head == nullptr)
    {
        throw invalid_argument("Не существует узла с данным значением!");
    }

    Node* current = head->next;

    while (current != head)
    {
        if (current->data == data_)
            return current != nullptr;
        else
            current = current->next;
    }
    return current == nullptr;
}

string CircularLinkedList::print_list() const
{
    ostringstream tmpStream;

    if (head == nullptr)
    {
        throw invalid_argument("Список пуст!");
    }
    else
    {
        Node* temp = head;

        do {
            tmpStream << temp->data << ",";
            temp = temp->next;
        } while (temp != head);
    }
    return tmpStream.str();
}
