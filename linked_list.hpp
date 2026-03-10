/*
* LinkedList.hpp
* Written by : 
* Modified   : 
*
* This class represents the template implementation for a LinkedList class.
* This file should be used in conjunction with Assignment 1 for SENG1120.
*/ 

template <typename T>
LinkedList<T>::LinkedList() 
{
    head = new Node<T>();
    tail = new Node<T>();
    T data;  

    head->set_data(data);
    tail->set_data(data);

    head->set_next(tail);
    tail->set_prev(head);

    current = head;
    count = 0;
}



template <typename T>
LinkedList<T>::~LinkedList() 
{

}

template <typename T>
void LinkedList<T>::push_front(const T& data) 
{
	current = head->get_next();
	insert(data);
}

template <typename T>
void LinkedList<T>::push_back(const T& data) 
{
	current = tail;
	insert(data);
}

template <typename T>
void LinkedList<T>::insert(const T& data) 
{
	Node<T>* newNode = new Node<T>(data);
	newNode->set_next(current->get_next());
	newNode->set_prev(current);
	current->get_next()->set_prev(newNode);
	current->set_next(newNode);
	current = newNode;
	count++;
}

template <typename T>
T LinkedList<T>::pop_front()
{
	current = head->get_next();
	return remove();
}

template <typename T>
T LinkedList<T>::pop_back()
{
	current = tail->get_prev();
	return remove();
}

template <typename T>
T LinkedList<T>::remove()
{
	if ( current == head || current == tail || count == 0) {

		return T();
	}
	
	T removedData = current->get_data();
	Node<T>* prevNode = current->get_prev();
	Node<T>* nextNode = current->get_next();

	prevNode->set_next(nextNode);
	nextNode->set_prev(prevNode);

	delete current;
	current = head;

	count--;

	return removedData;
}

template <typename T>
void LinkedList<T>::clear()
{
current = head->get_next();

while (current != tail)
{
	Node<T>* nextNode = current->get_next();
	delete current;
	current = nextNode;
	
}
count = 0;
head->set_next(tail);
tail->set_prev(head);
}

template <typename T>
T& LinkedList<T>::front() const
{
if (head->get_next() != tail) {
	return head->get_next()->get_data();
}
return T();
}

template <typename T>
T& LinkedList<T>::back() const
{
if (tail->get_prev() != head) {
	return tail->get_prev()->get_data();
}

return T();
}

template <typename T>
T& LinkedList<T>::get_current() const
{
if ( current == head || current == tail)
	{
		throw std::runtime_error( "exception thrown");
	}
	return current->get_data();
}



template <typename T>
void LinkedList<T>::begin()
{
    current = head->get_next();
}


template <typename T>
void LinkedList<T>::end() 
{
    current = tail->get_prev();
}

template <typename T>
void LinkedList<T>::forward() 
{
	if ( current != tail) {
		current = current->get_next();
	}

}

template <typename T>
void LinkedList<T>::backward() 
{
	if (current != head) {
		current = current->get_prev();
	}
}

template <typename T>
int LinkedList<T>::size() const
{
	return count;
}

template <typename T>
bool LinkedList<T>::empty() const
{
	return count == 0;
}


template <typename T>
bool LinkedList<T>::search(const T& target)
{
    Node<T>* current = head->get_next();

    while (current != tail)
    {
        if (current->get_data() == target) 
        {
            return true;
        }
        current = current->get_next();
    }

    return false;
}

