#pragma once
#include <ostream>
using  namespace std;

#include <iostream>
template <class T>
class LinkedLinearList{
private:
		class Node{
		public:
			T	mData;
			Node*	mPrev;
			Node*	mNext;
        };

public:
	class Iterator{
	public:
		//constructors:
		Iterator ():mCurNode (NULL){}

		Iterator (const Iterator &other):mCurNode (other.mCurNode){}
		
		Iterator (Node* node):mCurNode (node){}
		
		//overloading operators:
		virtual Iterator& operator++(){ // preincrement
			// Write your code here
            mCurNode = mCurNode->mNext;
            return *this;

		}

		virtual Iterator operator++(int dummy){ // postincrement
			// Write your code here
			Iterator old = *this;
			++*this;
            return old;

		}

		virtual Iterator& operator--(){ // predecrement
			mCurNode = mCurNode->mPrev;
			return *this;
		}

		virtual Iterator operator--(int dummy){ // postdecrement
			// Write your code here
			Iterator old = *this;
            --*this;
            return old;
		}

		bool operator!=(const Iterator& right)const {
			// Write your code here
            return mCurNode != right.mCurNode;
		}

		bool operator==(const Iterator& right)const {
			// Write your code here
            return mCurNode == right.mCurNode;
		}

		T* operator->() const {
			// Write your code here
            return &mCurNode->mData;
		}

		T& operator*() const {
			// Write your code here
            return mCurNode->mData;
		}

		friend class LinkedLinearList;
	private:
//		const LinkedLinearList<T> *mLinkedList;
		Node *mCurNode;
	};

	LinkedLinearList(void){
		mSize = 0;
		mHeaderNode = new Node();
		mHeaderNode->mNext = mHeaderNode;
		mHeaderNode->mPrev = mHeaderNode;
	}

	virtual ~LinkedLinearList(void) {
		Node *n, *nn; 
		for (n = mHeaderNode->mNext; n != mHeaderNode;){
			nn = n->mNext;
			delete n;
			n = nn;
		}
		delete mHeaderNode;
	}

public:
	virtual Iterator begin() const {
		// Write your code here
        return Iterator(mHeaderNode->mNext);
	}

	virtual Iterator end() const {
		// Write your code here
        return Iterator(mHeaderNode);
	}

	virtual Iterator rbegin() const {
		// Write your code her
        return Iterator(mHeaderNode->mPrev);
	}

	virtual Iterator rend() const {
		// Write your code her
        return Iterator(mHeaderNode);
	}

	// The returned iterator would point to the inserted element.
	virtual Iterator insert (Iterator it, const T& data) {

        Node* newnode = new Node();
        newnode->mData = data;
        newnode->mNext = it.mCurNode->mNext;
        it.mCurNode->mNext = newnode;
        it.mCurNode->mNext->mPrev = it.mCurNode;
        mHeaderNode->mPrev = it.mCurNode->mNext;
        mSize++;
        return ++it;

	}

	virtual void reversed(){

        Node* current = mHeaderNode;
        Node *prev = NULL, *next = NULL;

        while (current != NULL) {

            next = current->mNext;

            current->mNext = prev;

            prev = current;
            current = next;
        }
        mHeaderNode = prev;
	}

    virtual bool search(const T& data)
    {
        Node* newnode = new Node();
        newnode->mData = data;

        Node* current = mHeaderNode; // Initialize current
        int i = 0;
        while (i < size())
        {
            i++;
            if (current->mData == data)
                return true;
            current = current->mNext;
        }
        return false;
    }
	// The returned iterator would point to the element after the removed one.
	virtual Iterator remove (Iterator it){

		it.mCurNode->mPrev->mNext = it.mCurNode->mNext;
		mSize--;
        return ++it;
	}

	virtual int size() const {
		return mSize;
	};

private:
	Node* mHeaderNode;
	int mSize;
};

template <class T>
std::ostream& operator<<(std::ostream& os, const LinkedLinearList<T>& ll){
	typename LinkedLinearList<T>::Iterator itr;

	for (itr = ll.begin(); itr != ll.end(); itr++)
		os << *itr << "\t";
	os << "\n";
	return os;
}

template <class T>
bool operator==(const T& left, const T& right){
    return  left == right;
}

