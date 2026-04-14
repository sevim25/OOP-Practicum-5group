#pragma once
#include "../Pair_task/Pair.hpp"
#include <iostream>
#include <utility>

template <typename K, typename V>
class Map {
	Pair<K, V>* data;
	size_t current_size = 0;
	size_t current_capacity = 8;
	
	void resize(size_t newCap);

	void free();
	void copyFrom(const Map& other);
	void moveFrom(Map&& other);

public:
	Map();
	Map(const K& key, const V& value);

	Map(const Map& other);
	Map& operator=(const Map& other);

	Map(Map&& other) noexcept;
	Map& operator=( Map&& other) noexcept;

	~Map();

	size_t size()const;
	size_t capacity() const;

	bool add(const K& key, const V& value);
	bool add(const K& key, V&& value);
	void remove(const K& key);

	bool contains(const K& key) const;
	bool empty() const;

	V& operator[](const K& key);

	friend std::ostream& operator<<(std::ostream& os, const Map<K, V>& map) {
		for (size_t i = 0; i < map.size(); i++) {
			os << map.data[i].first << " - " << map.data[i].second << '\n';
		}
		os << '\n';
		return os;
	}
}; 

template<typename K, typename V>
void Map<K, V>::resize(size_t newCap) {
	current_capacity = newCap;

	Pair<K, V>* temp = new Pair<K, V>[newCap];
	for (size_t i = 0; i < current_size; i++)
	{
		temp[i] = data[i];
	}
	delete[] data;
	data = temp;
}

template <typename K, typename V>
void Map<K, V>::free() {
	delete[] data;
	data = nullptr;
}

template<typename K, typename V>
inline void Map<K, V>::copyFrom(const Map& other)
{
	current_size = other.current_size;
	current_capacity = other.current_capacity;

	data = new Pair<K, V>[current_capacity];
	for (size_t i = 0; i < current_size; i++)
	{
		data[i] = other.data[i];
	}

}

template<typename K, typename V>
inline void Map<K, V>::moveFrom(Map&& other)
{
	current_size = other.current_size;
	current_capacity = other.current_capacity;
	data = other.data;

	other.data = nullptr;
	other.current_capacity = 0;
	other.current_size = 0;
}

template<typename K, typename V>
inline Map<K, V>::Map() : current_capacity(8), current_size(0)
{
	data = new Pair<K, V>[current_capacity];
}

template<typename K, typename V>
inline Map<K, V>::Map(const K& key, const V& value) : current_capacity(8), current_size(1)
{
	data = new Pair<K, V>[current_capacity];
	data[0].first = key;
	data[0].second = value;
}

template<typename K, typename V>
inline Map<K, V>::Map(const Map& other)
{
	copyFrom(other);
}

template<typename K, typename V>
inline Map<K,V>& Map<K, V>::operator=(const Map& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename K, typename V>
inline Map<K, V>::Map(Map&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename K, typename V>
inline Map<K,V>& Map<K, V>::operator=(Map&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<typename K, typename V>
inline Map<K, V>::~Map()
{
	free();
}

template<typename K, typename V>
size_t Map<K, V>::size() const {
	return current_size;
}

template<typename K, typename V>
size_t Map<K, V>::capacity() const {
	return current_capacity;
}

template<typename K, typename V>
inline bool Map<K, V>::add(const K& key, const V& value)
{
	if (current_size == current_capacity) {
		resize(current_capacity * 2);
	}

	for (size_t i = 0; i < current_size; i++)
	{
		if (data[i].first == key) {
			return false;
		}
	}

	data[current_size].first = key;
	data[current_size].second = value;
	current_size++;

	return true;
}

template<typename K, typename V>
inline bool Map<K, V>::add(const K& key, V&& value)
{
	if (current_size == current_capacity) {
		resize(current_capacity * 2);
	}

	for (size_t i = 0; i < current_size; i++)
	{
		if (data[i].first == key) {
			return false;
		}
	}

	data[current_size].first = key;
	data[current_size].second = std::move(value);
	current_size++;

	return true;
}

template<typename K, typename V>
inline void Map<K, V>::remove(const K& key)
{
	
	for (size_t i = 0; i < current_size; i++)
	{
		if (data[i].first == key) {
			std::swap(data[i], data[current_size - 1]);
			current_size--;
			return;
		}
	}
}

template<typename K, typename V>
inline bool Map<K, V>::contains(const K& key) const
{
	for (size_t i = 0; i < current_size; i++)
	{
		if (data[i].first == key) {
			return true;
		}
	}
	return false;
}

template<typename K, typename V>
inline bool Map<K, V>::empty() const
{
	return current_size == 0;
}

template<typename K, typename V>
inline V& Map<K, V>::operator[](const K& key)
{
	for (size_t i = 0; i < current_size; i++)
	{
		if (data[i].first == key) {
			return data[i].second;
		}
	}

	add(key, V());
	return data[current_size-1].second;
}
