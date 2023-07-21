#include <iostream>

template <typename T>
class IntegerValuesQueue
{
private:
    class Node
    {
    public:
        T value;
        Node* ptr;
        Node(T value, Node* ptr = nullptr) : value{ value }, ptr{ ptr } {}
    };
    int size;
    Node* first;
    Node* last;

public:
    IntegerValuesQueue() : size{ 0 }, first{ nullptr }, last{ nullptr } {}

    int getSize() const
    {
        return size;
    }

    bool IsEmpty() const
    {
        return (first == nullptr);
    }

    bool IsFull() const
    {
       
        return false;
    }

    T top()
    {
        if (size > 0)
        {
            return first->value;
        }
        throw std::out_of_range("Queue out of range");
    }

    void Dequeue()
    {
        if (size > 0)
        {
            Node* tmp = first;
            first = tmp->ptr;
            delete tmp;
            size--;
        }
    }

    void Enqueue(T value)
    {
        if (last == nullptr)
        {
            last = new Node(value);
            first = last;
            size++;
            return;
        }
        Node* tmp = new Node(value);
        last->ptr = tmp;
        last = tmp;
        size++;
    }

    void Show() const
    {
        Node* current = first;
        while (current != nullptr)
        {
            std::cout << current->value << " ";
            current = current->ptr;
        }
        std::cout << std::endl;
    }
};

int main()
{
    IntegerValuesQueue<int> object;
    object.Enqueue(2);
    object.Enqueue(5);
    object.Enqueue(8);
    object.Enqueue(1);
    object.Enqueue(4);

    object.Show();

    return 0;
} 
//IsEmpty Ч перев≥рка черги на порожнечу;
 //IsFull Ч перев≥рка черги на заповненн€;
 //Enqueue Ч додаванн€ елемента в чергу;
 //Dequeue Ч видаленн€ елемента з черги;
 //Show Ч в≥дображенн€ вс≥х елемент≥в черги на екран