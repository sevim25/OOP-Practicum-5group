#pragma once
#include <iostream>

template <typename K, typename V>
struct Pair {
	K first;
	V second;

	Pair() = default;
	Pair(const K& key, const V& value);

	bool operator==(const Pair<K,V>& other) const;
	bool operator!=(const Pair<K, V>& other) const;
};

template<typename K, typename V>
inline Pair<K, V>::Pair(const K& key, const V& value) : first(key), second(value) {}

template<typename K, typename V>
inline bool Pair<K, V>::operator==(const Pair<K, V>& other) const
{
	return (first == other.first) && (second == other.second);
}

template<typename K, typename V>
inline bool Pair<K, V>::operator!=(const Pair<K, V>& other) const
{
	return !(*this == other);
}
