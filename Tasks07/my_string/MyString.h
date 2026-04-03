#pragma once
#include <iostream>
#include <functional>
#include <compare>

class MyString {
private:
	char* data = nullptr;
	size_t size = 0;
	size_t capacity = 0;
	
	void free();
	void copyFrom(const MyString& other);
	void moveFrom(MyString&& other);
	void resize(size_t newCap);	

	//helper functions
	bool isLower(char ch);
	bool isUpper(char ch);
	char toUpperChar(char ch);
	char toLowerChar(char ch);

public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	MyString(MyString&& other) noexcept;
	MyString& operator=(MyString&& other) noexcept;
	~MyString();

	size_t getSize() const;
	size_t getCapacity() const;

	const char* getData() const;

	char operator[](size_t index);
	const char operator[](size_t index) const;
	MyString& operator+=(const MyString& other);

	void toUpper();
	void toLower();
	void reverse();
	MyString getSubstring(size_t startIndex, size_t length) const;

	MyString& insert(size_t index, char ch);
	MyString& insert(size_t index, const char* str);
	MyString& insert(size_t index, const MyString& str);

	MyString& erase(size_t index);
	MyString& erase(size_t index, size_t count);

	bool contains(char ch) const;
	bool contains(const char* str) const;
	bool contains(const MyString& str) const;
};

MyString operator+(const MyString& str1, const MyString& str2);

bool operator==(const MyString& str1, const MyString& str2);
bool operator!=(const MyString& str1, const MyString& str2);
bool operator<(const MyString& str1, const MyString& str2);
bool operator<=(const MyString& str1, const MyString& str2);
bool operator>(const MyString& str1, const MyString& str2);
bool operator>=(const MyString& str1, const MyString& str2);

//std::strong_ordering operator<=>(const MyString& str1, const MyString& str2);

std::ostream& operator<<(std::ostream& os, const MyString& str);
std::istream& operator>>(std::istream& is, MyString& str);