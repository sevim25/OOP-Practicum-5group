#pragma once
#include <iostream>
#include <utility>

template<typename T>
class Stack {
	size_t current_size = 0;
	size_t current_capacity = 0;
	T* data = nullptr;

	void free();
	void copyFrom(const Stack& other);
	void moveFrom(Stack&& other);

	void resize(size_t newCapacity);

public:
	Stack();
	Stack(const Stack& other);
	Stack& operator=(const Stack& other);

	Stack( Stack&& other) noexcept;
	Stack& operator=( Stack&& other) noexcept;

	~Stack();

	size_t size() const;

	void push(const T& obj);
	void push(T&& obj);
	void pop();
	const T& top() const;
	bool empty() const;

	friend std::ostream& operator<<(std::ostream& os, const Stack<T>& s) {
		for (size_t i = 0; i < s.current_size; i++)
		{
			os << s.data[i] << " ";
		}
		os << '\n';
		return os;
	}

};

template<typename T>
inline void Stack<T>::resize(size_t newCapacity)
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
inline void Stack<T>::free()
{
	delete[]data;
	data = nullptr;
}

template<typename T>
inline void Stack<T>::copyFrom(const Stack& other)
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
inline void Stack<T>::moveFrom(Stack&& other)
{
	current_size = other.current_size;
	current_capacity = other.current_capacity;
	data = other.data;

	other.current_size = 0;
	other.current_capacity = 0;
	other.data = nullptr;
}

template<typename T>
inline Stack<T>::Stack() : current_capacity(8), current_size(0), data(new T[current_capacity]{}) {}

template<typename T>
inline Stack<T>::Stack(const Stack& other)
{
	copyFrom(other);
}

template<typename T>
inline Stack<T>& Stack<T>::operator=(const Stack& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
inline Stack<T>::Stack(Stack&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
inline Stack<T>& Stack<T>::operator=(Stack&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<typename T>
inline Stack<T>::~Stack()
{
	free();
}

template<typename T>
size_t Stack<T>::size() const
{
	return current_size;
}

template<typename T>
inline void Stack<T>::push(const T& obj)
{
	size_t newCap = (current_capacity == 0) ? 8 : current_capacity * 2;
	if (current_size == current_capacity) {
		resize(newCap);
	}

	data[current_size] = obj;
	current_size++;

}

template<typename T>
inline void Stack<T>::push(T&& obj)
{
	size_t newCap = (current_capacity == 0) ? 8 : current_capacity * 2;
	if (current_size == current_capacity) {
		resize(newCap);
	}

	data[current_size] = std::move(obj);
	current_size++;
}

template<typename T>
inline void Stack<T>::pop()
{
	current_size--;
}

template<typename T>
const T& Stack<T>::top() const
{
	return data[current_size - 1];
}

template<typename T>
bool Stack<T>::empty() const
{
	return current_size == 0;
}
