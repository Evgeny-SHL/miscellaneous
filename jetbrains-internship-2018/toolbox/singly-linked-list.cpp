#include <iostream>
#include <utility>

template<class T>
class SinglyLinkedList {
public:
    SinglyLinkedList() = default;
    SinglyLinkedList(T&& _value);
    ~SinglyLinkedList();

    SinglyLinkedList* InsertElementBefore(T&& _value);
    SinglyLinkedList* Rotate();
    void PrintValues();

private:
    SinglyLinkedList<T>* next{nullptr};
    T value{};

    SinglyLinkedList(SinglyLinkedList* const _next, T&& _value);
    SinglyLinkedList* rotateNextLink( SinglyLinkedList<T>* prev );
};

template<class T>
SinglyLinkedList<T>::SinglyLinkedList( T&& _value ) :
    value{std::move(_value)}
{
}

template<class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    delete next;
}

template<class T>
SinglyLinkedList<T>* SinglyLinkedList<T>::InsertElementBefore(T&& _value) {
    return new SinglyLinkedList(this, std::move(_value));
}

template<class T>
SinglyLinkedList<T>* SinglyLinkedList<T>::Rotate() {
    if (next == nullptr) {
        return this;
    }

    return next->rotateNextLink( this );
}

template<class T>
void SinglyLinkedList<T>::PrintValues() {
    std::cout << value << std::endl;
    if (next != nullptr) {
        next->PrintValues();
    }
}

template<class T>
SinglyLinkedList<T>::SinglyLinkedList(SinglyLinkedList* const _next, T&& _value) :
    next{_next},
    value{std::move(_value)}
{
}

template<class T>
SinglyLinkedList<T>* SinglyLinkedList<T>::rotateNextLink( SinglyLinkedList<T>* prev ) {
    auto last = next == nullptr ? this : next->rotateNextLink( this ) ;
    prev->next = nullptr;
    next = prev;
    return last;
}

int main() {
    SinglyLinkedList<int>* list = new SinglyLinkedList<int>{1};

    list = list->InsertElementBefore( 2 );
    list = list->InsertElementBefore( 3 );
    list = list->InsertElementBefore( 4 );
    list = list->InsertElementBefore( 5 );
    list = list->InsertElementBefore( 6 );
    list = list->InsertElementBefore( 7 );

    list->PrintValues();

    std::cout << std::endl;
    list = list->Rotate();

    list->PrintValues();

    return 0;
}
