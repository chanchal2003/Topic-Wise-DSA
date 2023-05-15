#include <bits/stdc++.h>
using namespace std;

class Node
{
private:
    int data;
    Node *previous;
    Node *next;

public:
    Node(int data)
    {
        this->data = data;
        this->previous = NULL;
        this->next = NULL;
    }
    friend class DoublyLinkedList;
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    // Add First in Doubly Linked List
    void addFirstNode(Node *node)
    {
        if (size == 0)
        {
            head = tail = node;
        }
        else
        {
            node->next = head;
            head->previous = node;
            head = node;
        }
    }
    void addFirst(int val)
    {
        Node *newNode = new Node(val);
        addFirstNode(newNode);
    }

    // Add Last in Doubly Linked List
    void addLastNode(Node *node)
    {
        if (size == 0)
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            node->previous = tail;
            tail = node;
        }
    }
    void addLast(int val)
    {
        Node *newNode = new Node(val);
        addFirstNode(newNode);
    }

    // Add At in Doubly Linked List
    void addNodeAt(int index, Node *node)
    {
        if (index == 0)
        {
            addFirstNode(node);
        }
        else if (index == size)
        {
            addLastNode(node);
        }
        else
        {
            Node *forwardNode = getNodeAt(index);
            Node *previousNode = forwardNode->previous;

            previousNode->next = node;
            node->previous = previousNode;

            node->next = forwardNode;
            forwardNode->previous = node;

            size++;
        }
    }
    void addAt(int index, int val)
    {
        if ((index < 0) || (index >= (size + 1))) // Index Is Invalid Exception
        {
            return;
        }
        else
        {
            Node *node = new Node(val);
            addNodeAt(index, node);
        }
    }

    // Remove First In Doubly Linked List
    Node *removeFirstNode()
    {
        if (size == 1)
        {
            head = tail = NULL;
        }
        else
        {
            Node *forward = head->next;
            head->next = NULL;
            forward->previous = NULL;

            head = forward;
        }

        size--;
        return head;
    }
    int removeFirst()
    {
        if (size == 0)
        {
            cout << "List Is Empty : ";
            return -1;
        }

        return removeFirstNode()->data;
    }

    // Remove Last In Doubly Linked List
    Node *removeLastNode()
    {
        if (size == 1)
        {
            head = tail = NULL;
        }
        else
        {
            Node *TailPreviousNode = tail->previous;
            TailPreviousNode->next = NULL;
            tail->previous = NULL;

            tail = TailPreviousNode;
        }

        size--;
        return tail;
    }
    int removeLast()
    {
        if (size == 0)
        {
            cout << "List Is Empty : ";
            return -1;
        }

        return removeLastNode()->data;
    }

    // Remove At in Doubly Linked List
    Node *removeNodeAt(int index)
    {
        if (index == 0)
        {
            return removeFirstNode();
        }
        else if (index == (size - 1))
        {
            return removeLastNode();
        }
        else
        {
            Node *node = getNodeAt(index);
            Node *previousNode = node->previous;
            Node *forwardNode = node->next;

            previousNode->next = forwardNode;
            forwardNode->previous = previousNode;

            node->previous = node->next = NULL;

            size--;
            return node;
        }
    }
    int removeAt(int index)
    {
        if (size == 0) // List Is Empty Exception
        {
            cout << "List Is Empty : ";
            return -1;
        }

        if ((index < 0) || (index >= size)) // Index Is Invalid Exception
        {
            return -1;
        }

        return removeNodeAt(index)->data;
    }

    // Size of Doubly Linked List
    int Size()
    {
        return this->size; // this is a pointer which points to that class object variable only
    }

    // isEmpty of Doubly Linked List
    bool isEmpty()
    {
        return (this->size == 0);
    }

    // Get First and Last In Doubly Linked List
    int getFirst()
    {
        if (size == 0)
        {
            cout << "List Is Empty : ";
            return -1;
        }

        return head->data;
    }

    int getLast()
    {
        if (size == 0)
        {
            cout << "List Is Empty : ";
            return -1;
        }

        return tail->data;
    }

    // Get At In Doubly Linked List
    Node *getNodeAt(int index)
    {
        Node *current = head;
        while (index-- > 0)
        {
            current = current->next;
        }
        return current;
    }
    int getAt(int index)
    {
        if (size == 0) // List Is Empty Exception
        {
            cout << "List Is Empty : ";
            return -1;
        }

        if ((index < 0) || (index >= size)) // Index Is Invalid Exception
        {
            return -1;
        }

        return getNodeAt(index)->data;
    }

    // Add Before Node in Doubly Linked List
    void addBefore(Node *referenceNode, int data)
    {
        Node *newNode = new Node(data);
        Node *previousNode = referenceNode->previous;
        if (previousNode == NULL) // Means the newNode should be the head of the Doubly Linked List
        {
            newNode->next = referenceNode;
            referenceNode->previous = newNode;

            this->head = newNode;
        }
        else
        {
            previousNode->next = newNode;
            newNode->previous = previousNode;

            newNode->next = referenceNode;
            referenceNode->previous = newNode;
        }
        this->size++;
    }
    void addBefore(int index, int data)
    {
        Node *node = getNodeAt(index);
        addBefore(node, data);
    }

    // Add After Node in Doubly Linked List
    void addAfter(Node *referenceNode, int data)
    {
        Node *newNode = new Node(data);
        Node *forwardNode = referenceNode->next;
        if (forwardNode == NULL) // Means the newNode should be the tail of the Doubly Linked List
        {
            referenceNode->next = newNode;
            newNode->previous = referenceNode;

            this->tail = newNode;
        }
        else
        {
            referenceNode->next = newNode;
            newNode->previous = referenceNode;

            newNode->next = forwardNode;
            forwardNode->previous = newNode;
        }
        this->size++;
    }
    void addAfter(int index, int data)
    {
        Node *node = getNodeAt(index);
        addAfter(node, data);
    }

    // Remove Before Node in Doubly Linked List
    int removeBefore(Node *referenceNode)
    {
        if (referenceNode->previous == NULL)
        {
            cout << "Location Is Invalid : ";
            return -1;
        }

        Node *previousNode = referenceNode->previous;
        if (previousNode->previous == NULL)
        {
            previousNode->next = NULL;
            referenceNode->previous = NULL;

            this->head = referenceNode;
        }
        else
        {
            previousNode->previous->next = referenceNode;
            referenceNode->previous = previousNode->previous;

            previousNode->previous = NULL;
            previousNode->next = NULL;
        }

        this->size--;
        return previousNode->data;
    }
    int removeBefore(int index)
    {
        Node *node = getNodeAt(index);
        return removeBefore(node);
    }

    // Remove After Node in Doubly Linked List
    int removeAfter(Node *referenceNode)
    {
        if (referenceNode->next == NULL)
        {
            cout << "Location Is Invalid : ";
            return -1;
        }

        Node *forwardNode = referenceNode->next;
        if (forwardNode->next == NULL) // forwardNode is a tail Node
        {
            referenceNode->next = NULL;
            forwardNode->previous = NULL;

            this->tail = referenceNode;
        }
        else
        {
            referenceNode->next = forwardNode->next;
            forwardNode->next->previous = forwardNode->previous;

            forwardNode->previous = NULL;
            forwardNode->next = NULL;
        }

        this->size--;
        return forwardNode->data;
    }
    int removeAfter(int index)
    {
        Node *node = getNodeAt(index);
        return removeAfter(node);
    }

    // Remove Given Node in Doubly Linked List
    int removeNode(Node *referenceNode)
    {
        Node *previousNode = referenceNode->previous;
        Node *forwardNode = referenceNode->next;

        if (this->size == 1)
        {
            this->head = NULL;
            this->tail = NULL;
        }
        else if (previousNode == NULL)
        {
            this->head = forwardNode;
        }
        else if (forwardNode == NULL)
        {
            this->tail = previousNode;
        }
        else
        {
            previousNode->next = forwardNode;
            forwardNode->previous = previousNode;
        }

        referenceNode->previous = NULL;
        referenceNode->next = NULL;
        this->head->previous = NULL;
        this->tail->next = NULL;

        this->size--;
        return referenceNode->data;
    }
    int removeNode(int index)
    {
        Node *node = getNodeAt(index);
        return removeNode(node);
    }

    // Display Forward & Backward in Doubly Linked List
    void displayForward()
    {
        Node *current = this->head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void displayBackward()
    {
        Node *current = this->tail;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->previous;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList obj;
    int index, val;
    int option;
    do
    {
        cout << " ------------------ MENU ------------------ " << endl;
        cout << " 1. Add First in Doubly Linked List " << endl;
        cout << " 2. Add Last in Doubly Linked List " << endl;
        cout << " 3. Add At a Index in Doubly Linked List " << endl;
        cout << " 4. Remove First in Doubly Linked List " << endl;
        cout << " 5. Remove Last in Doubly Linked List " << endl;
        cout << " 6. Remove At a Index in Doubly Linked List " << endl;
        cout << " 7. Size of Doubly Linked List " << endl;
        cout << " 8. IsEmpty of Doubly Linked List " << endl;
        cout << " 9. Get First of Doubly Linked List " << endl;
        cout << " 10. Get Last of Doubly Linked List " << endl;
        cout << " 11. Get At a Index in Doubly Linked List " << endl;
        cout << " 12. Add Before Node in Doubly Linked List " << endl;
        cout << " 13. Add After Node in Doubly Linked List " << endl;
        cout << " 14. Remove Before Node in Doubly Linked List " << endl;
        cout << " 15. Remove After Node in Doubly Linked List " << endl;
        cout << " 16. Remove Given Node in Doubly Linked List " << endl;
        cout << " 17. Display Forward in Doubly Linked List " << endl;
        cout << " 18. Display Backward in Doubly Linked List " << endl;
        cout << " Enter option : ";
        cin >> option;
        switch (option)
        {
        case 1:
            cin >> val;
            obj.addFirst(val);
            break;
        case 2:
            cin >> val;
            obj.addLast(val);
            break;
        case 3:
            cin >> index >> val;
            obj.addAt(index, val);
            break;
        case 4:
            obj.removeFirst();
            break;
        case 5:
            obj.removeLast();
            break;
        case 6:
            cin >> index;
            obj.removeAt(index);
            break;
        case 7:
            obj.Size();
            break;
        case 8:
            obj.isEmpty();
            break;
        case 9:
            obj.getFirst();
            break;
        case 10:
            obj.getLast();
            break;
        case 11:
            cin >> index;
            obj.getAt(index);
            break;
        case 12:
            cin >> index >> val;
            obj.addBefore(index, val);
            break;
        case 13:
            cin >> index >> val;
            obj.addAfter(index, val);
            break;
        case 14:
            cin >> index;
            obj.removeBefore(index);
            break;
        case 15:
            cin >> index;
            obj.removeAfter(index);
            break;
        case 16:
            cin >> index;
            obj.removeNode(index);
            break;
        case 17:
            obj.displayForward();
            break;
        case 18:
            obj.displayBackward();
            break;
        }
    } while (option >= 1 && option <= 18);

    return 0;
}