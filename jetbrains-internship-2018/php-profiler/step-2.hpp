#include <exception>
#include <initializer_list>
#include <mutex>
#include <vector>

class BinaryTree {
public:
    class ForwardIterator;
    friend ForwardIterator;
    using Lock = std::unique_lock<std::mutex>;

public:
    BinaryTree(std::initializer_list<int> values) :
            nodes{values}
    {
    }

    void Insert(const int value, const int position) {
        Lock{mutex};
        // The task does not specify how binary tree should be balanced,
        // so I suppose that is OK. :)
        auto iter = nodes.begin() + position;
        nodes.insert(iter, value);
    }

    void Remove(const int position) {
        Lock{mutex};
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

    // Iterator will take unique_lock for object
    // and move it to the new one when ++ is called.
    std::mutex mutex;

public:
    class ForwardIterator {
    private:
        using Lock = std::unique_lock<std::mutex>;

    public:
        explicit ForwardIterator(BinaryTree* _object, unsigned long long _position) :
                object{_object},
                position{_position},
                lock{std::move(Lock(object->mutex))}
        {
        }

        int& operator*() const {
            if (*this == object->end()) {
                throw std::range_error("Cannot dereference end-iterator.");
            }
            object->nodes[position];
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
        Lock lock{};
    };
};
