#pragma once
#include <iostream>
#include <utility>

template<typename T>
class Queue {
	size_t current_size = 0;
	size_t current_capacity = 0;
	T* data = nullptr;

	void free();
	void copyFrom(const Queue& other);
	void moveFrom(Queue&& other);
	void resize(size_t newCapacity);

public:
	Queue();
	Queue(const Queue& other);
	Queue& operator=(const Queue& other);
	Queue( Queue&& other) noexcept;
	Queue& operator=( Queue&& other) noexcept;
	~Queue();

	size_t size() const;

	void push(const T& obj);
	void push(T&& obj);
	void pop();
	const T& front() const;
	const T& back() const;

	bool empty() const;

	T& operator[](size_t index);
	const T& operator[](size_t index) const;

};

template<typename T>
inline void Queue<T>::free()
{
	delete[] data;
	data = nullptr;
}


template<typename T>
inline void Queue<T>::copyFrom(const Queue& other)
{
	current_size = other.current_size;
	current_capacity = other.current_capacity;
	data = new T[current_capacity];

	for (size_t i = 0; i < current_size; i++)
	{
		data[i] = other.data[i];
	}
}

template<typename T>
inline void Queue<T>::moveFrom(Queue&& other)
{
	current_size = other.current_size;
	current_capacity = other.current_capacity;
	data = other.data;

	other.current_size = 0;
	other.current_capacity = 0;
	other.data = nullptr;
	
}

template<typename T>
inline void Queue<T>::resize(size_t newCapacity)
{
	current_capacity = newCapacity;
	T* temp = new T[newCapacity];
	for (size_t i = 0; i < current_size; i++)
	{
		temp[i] = data[i];
	}
	delete[]data;
	data = temp;
}

template<typename T>
inline Queue<T>::Queue() : current_capacity(8), current_size(0), data(new T[current_capacity]{}) {}

template<typename T>
inline Queue<T>::Queue(const Queue& other)
{
	copyFrom(other);
}

template<typename T>
inline Queue<T>& Queue<T>::operator=(const Queue& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
inline Queue<T>::Queue(Queue&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
inline Queue<T>& Queue<T>::operator=(Queue&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<typename T>
inline Queue<T>::~Queue()
{
	free();
}

template<typename T>
void Queue<T>::push(const T& obj)
{
	size_t newCapacity = (current_capacity == 0) ? 8 : current_capacity * 2;

	if (current_size == current_capacity) {
		resize(newCapacity);
	}

	data[current_size] = obj;
	current_size++;
}

template<typename T>
void Queue<T>::push(T&& obj)
{
	size_t newCapacity = (current_capacity == 0) ? 8 : current_capacity * 2;

	if (current_size == current_capacity) {
		resize(newCapacity);
	}

	data[current_size] = std::move(obj);
	current_size++;
}

template<typename T>
void Queue<T>::pop()
{
	if (empty()) {
		return;
	}

	for (size_t i = 0; i < current_size - 1; i++)
	{
		data[i] = data[i + 1];
	}

	current_size--;
}

template<typename T>
const T& Queue<T>::front() const
{
	/*if (empty()) {
		
	}*/

	return data[0];
}

template<typename T>
const T& Queue<T>::back() const
{
	//if (empty()) {

	return data[current_size-1];
}

template<typename T>
bool Queue<T>::empty() const
{
	return current_size == 0;
}

template<typename T>
size_t Queue<T>::size() const
{
	return current_size;
}

template<typename T>
const T& Queue<T>::operator[](size_t index) const
{
	return data[index];
}

template<typename T>
T& Queue<T>::operator[](size_t index)
{
	return data[index];
}
