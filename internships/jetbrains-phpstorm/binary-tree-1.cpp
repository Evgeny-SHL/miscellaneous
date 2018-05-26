#include <exception>
#include <initializer_list>
#include <vector>

class BinaryTree {
public:
    class ForwardIterator;
    friend ForwardIterator;

public:
    BinaryTree(std::initializer_list<int> values) :
            nodes{values}
    {
    }

    // For range type concept
    ForwardIterator begin() {
        return ForwardIterator(this, 0);
    }

    ForwardIterator end() {
        return ForwardIterator(this, nodes.size());
    }

private:
    // It is suitable to save nodes as elements of vector,
    // because forward iterator should iterate layer by layer.
    std::vector<int> nodes;

public:
    class ForwardIterator {
    public:
        explicit ForwardIterator(BinaryTree* _object, unsigned long long _position) :
                object{_object},
                position{_position}
        {
        }

        int& operator*() const {
            if (*this == object->end()) {
                throw std::range_error("Cannot dereference end-iterator.");
            }
            return object->nodes[position];
        }

        ForwardIterator& operator++() {
            if (*this == object->end()) {
                throw std::range_error("Cannot increment end-iterator.");
            }
            ++position;
            return *this;
        }

        bool operator==(const ForwardIterator& other) const {
            return object == other.object && position == other.position;
        }

        bool operator!=(const ForwardIterator& other) const {
            return !(*this == other);
        }

    private:
        BinaryTree* object{nullptr};
        unsigned long long position{0};
    };
};
