#include <atomic>
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

    void Insert(const int value, const int position) {
        changed = true;
        // The task does not specify how binary tree should be balanced,
        // so I suppose that is OK. :)
        auto iter = nodes.begin() + position;
        nodes.insert(iter, value);
    }

    void Remove(const int position) {
        changed = true;
        auto iter = nodes.begin() + position;
        nodes.erase(iter);
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

    // When iterater is created, it will set changed to false.
    // Insert and Remove set to true.
    std::atomic<bool> changed{false};

public:
    class ForwardIterator {
    public:
        explicit ForwardIterator(BinaryTree* _object, unsigned long long _position) :
                object{_object},
                position{_position}
        {
            object->changed = false;
        }

        int& operator*() const {
            if (object->changed) {
                throw std::runtime_error("Tree was changed.");
            } else if (*this == object->end()) {
                throw std::range_error("Cannot dereference end-iterator.");
            }
            object->nodes[position];
        }

        ForwardIterator& operator++() {
            if (object->changed) {
                throw std::runtime_error("Tree was changed.");
            } else if (*this == object->end()) {
                throw std::range_error("Cannot increment end-iterator.");
            }
            ++position;
            return *this;
        }

        bool operator==(const ForwardIterator& other) const {
            if (object->changed) {
                throw std::runtime_error("Tree was changed.");
            }
            return object == other.object && position == other.position;
        }

        bool operator!=(const ForwardIterator& other) const {
            if (object->changed) {
                throw std::runtime_error("Tree was changed.");
            }
            return !(*this == other);
        }

    private:
        BinaryTree* object{nullptr};
        unsigned long long position{0};
    };
};
