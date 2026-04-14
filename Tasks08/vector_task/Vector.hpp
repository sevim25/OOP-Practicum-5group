#pragma once
#include <iostream>

template <typename T>
class Vector {
private:
	size_t size = 0;
	size_t capacity = 8;
	T* data = nullptr;

	void resize(size_t newCapacity);

	void free();
	void copyFrom(const Vector& other);
	void moveFrom(Vector&& other);

public:
	Vector();
	explicit Vector(size_t n);

	Vector(const Vector& other);
	Vector& operator=(const Vector& other);

	Vector( Vector&& other) noexcept;
	Vector& operator=(Vector&& other) noexcept;

	~Vector();

	Vector(size_t n, const T& obj);

	size_t getSize() const;
	size_t getCapacity() const;

	void push_back(const T& obj);
	void push_back(T&& obj);

	void insert(size_t idx, const T& obj);
	void insert(size_t idx, T&& obj);

	void erase(size_t idx);

	T* begin();
	const T* begin() const;

	T* end();
	const T* end() const;

	T& operator[](size_t index);
	const T& operator[](size_t index) const;

	void shrink_to_fit();

	bool empty() const;
	void clear();
};

template<typename T>
void Vector<T>::resize(size_t newCapacity) {

	capacity = newCapacity;
	T* temp = new T[newCapacity];

	for (size_t i = 0; i < size; i++)
	{
		temp[i] = data[i];
	}

	delete[] data;
	data = temp;
}

template<typename T>
inline void Vector<T>::free()
{
	delete[] data;
	data = nullptr;
}

template<typename T>
inline void Vector<T>::copyFrom(const Vector& other)
{
	size = other.size;
	capacity = other.capacity;

	data = new T[capacity];
	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

template<typename T>
inline void Vector<T>::moveFrom(Vector&& other)
{
	size = other.size;
	capacity = other.capacity;
	data = other.data;

	other.data = nullptr;
	other.size = 0;
	other.capacity = 0;
}


template<typename T>
inline Vector<T>::Vector() : size(0), capacity(8), data(new T[capacity]{}) {}

template<typename T>
inline Vector<T>::Vector(size_t n) : size(n), capacity(n), data(new T[capacity]{}) {}

template<typename T>
inline Vector<T>::Vector(size_t n, const T& obj) : size(n), capacity(n), data(new T[n]{})
{

	for (size_t i = 0; i < size; i++)
	{
		data[i] = obj;
	}
}

template<typename T>
inline Vector<T>::Vector(const Vector& other)
{
	copyFrom(other);
}

template<typename T>
inline Vector<T>& Vector<T>::operator=(const Vector& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
inline Vector<T>::Vector(Vector&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
inline Vector<T>& Vector<T>::operator=(Vector&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<typename T>
inline Vector<T>::~Vector()
{
	free();
}

template<typename T>
size_t Vector<T>::getSize() const {
	return size;
}

template<typename T>
size_t Vector<T>::getCapacity() const{
	return capacity;
}

template<typename T>
inline void Vector<T>::push_back(const T& obj)
{
	if (size == capacity) {
		size_t newCap = (capacity == 0) ? 2 : capacity * 2;
		resize(newCap);
	}


	data[size] = obj;
	size++;
}

template<typename T>
inline void Vector<T>::push_back(T&& obj)
{
	if (size == capacity) {
		size_t newCap = (capacity == 0) ? 2 : capacity * 2;
		resize(newCap);
	}


	data[size] = std::move(obj);
	size++;
}

template<typename T>
inline void Vector<T>::insert(size_t idx, const T& obj)
{
	if (idx > size) return;
	if (size == capacity) {
		size_t newCap = (capacity == 0) ? 2 : capacity * 2;
		resize(newCap);
	}

	for (size_t i = size; i > idx; i--)
	{
		data[i] = data[i - 1];
	}

	data[idx] = obj;
	size++;
}

template<typename T>
inline void Vector<T>::insert(size_t idx, T&& obj)
{
	if (idx > size) return;
	if (size == capacity) {
		size_t newCap = (capacity == 0) ? 2 : capacity * 2;
		resize(newCap);
	}


	for (size_t i = size; i > idx; i--)
	{
		data[i] = std::move(data[i - 1]);
	}

	data[idx] = std::move(obj);
	size++;
}

template<typename T>
inline void Vector<T>::erase(size_t idx)
{
	if (idx >= size) return;
	
	for (size_t i = idx; i < size-1; i++)
	{
		data[i] = data[i + 1];
	}
	size--;
}

template<typename T>
T* Vector<T>::begin() {
	return data;
}

template<typename T>
const T* Vector<T>::begin() const {
	return data;
}

template<typename T>
T* Vector<T>::end() {
	return data + size;
}

template<typename T>
const T* Vector<T>::end() const {
	return data + size;
}

template<typename T>
void Vector<T>::shrink_to_fit() {
	capacity = size;
	resize(capacity);
}

template<typename T>
bool Vector<T>::empty() const {
	return size == 0;
}

template<typename T>
void Vector<T>::clear() {
	size = 0;
}
template<typename T>
T& Vector<T>::operator[](size_t index) {
	return data[index];
}

template<typename T>
const T& Vector<T>::operator[](size_t index) const {
	return data[index];
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v) {
	for (size_t i = 0; i < v.getSize(); i++)
	{
		os << v[i] << " ";
	}

	return os;
}