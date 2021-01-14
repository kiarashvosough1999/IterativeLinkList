template <typename T>
class node {
  public:
    T data;
    node<T> *next;

    node() : next(nullptr) {}
    node(const T& item, node<T> *ptr = nullptr) :
      data(item), next(ptr) {}
};

// Linked list class
template <typename T>
class list {
  public:
    list() {
      // Create the dummy head node
      head = tail = new node<T>();
    }
    list(const list<T>& other) = delete;
    list(list<T>&& other) = delete;
    ~list() {
      while (head->next != nullptr) {
        node<T>* temp = head;
        head = head->next;
        delete temp;
      }
      delete head;
    }

    list<T>& operator=(const list<T>& other) = delete;
    list<T>& operator=(list<T>&& other) = delete;

    // Inner class iterator
    class iterator {
    friend class list;
    private:
      node<T> *nodePtr;
      // The constructor is private, so only our friends
      // can create instances of iterators.
      iterator(node<T> *newPtr) : nodePtr(newPtr) {}
    public:
      iterator() : nodePtr(nullptr) {}

      // Overload for the comparison operator !=
      bool operator!=(const iterator& itr) const {
        return nodePtr != itr.nodePtr;
      }

      // Overload for the dereference operator *
      T& operator*() const {
        return nodePtr->next->data;
      }

      // Overload for the postincrement operator ++
      iterator operator++(int) {
        iterator temp = *this;
        nodePtr = nodePtr->next;
        return temp;
      }
    }; // End of inner class iterator

    iterator begin() const {
      return iterator(head);
    }

    iterator end() const {
      return iterator(tail);
    }

    iterator insert(iterator position,const T& value) {
      node<T>* newNode = new node<T>(value, position.nodePtr->next);
      if (position.nodePtr == tail) tail = newNode;
      position.nodePtr->next = newNode;
      return position;
    }

    iterator erase(iterator position) {
      node<T> *toDelete = position.nodePtr->next;
      position.nodePtr->next = position.nodePtr->next->next;
      if (toDelete == tail) tail = position.nodePtr;
      delete toDelete;
      return position;
    }
  private:
    node<T>* head;
    node<T>* tail;
};