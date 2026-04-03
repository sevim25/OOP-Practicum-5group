#include "MyString.h"
#include <cstring>
#pragma warning (disable : 4996)

void MyString::free() {
	delete[] data;
	data = nullptr;
}

void MyString::copyFrom(const MyString& other)
{
	size = other.size;
	capacity = other.capacity;
	
	data = new char[capacity];
	strcpy(data, other.data);
	
}

void MyString::moveFrom(MyString&& other)
{
	data = other.data;
	size = other.size;
	capacity = other.capacity;

	other.data = nullptr;
	other.size = 0;
	other.capacity = 0;
}

void MyString::resize(size_t newCap) {
	capacity = newCap;

	char* res = new char[newCap];
	strcpy(res, data);
	delete[]data;
	data = res;
}


MyString::MyString() : MyString("")
{
}

MyString::MyString(const char* data) : size(0), capacity(2)
{
	if (data == nullptr) {
		this->data = new char[1];
		this->data[0] = '\0';
		size = 0;
	}

	this->data = new char[strlen(data) + 1];
	strcpy(this->data, data);

}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

MyString::MyString(MyString&& other) noexcept
{
	moveFrom(std::move(other));
}

MyString& MyString::operator=(MyString&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

MyString::~MyString()
{
	free();
}

size_t MyString::getSize() const
{
	return size;
}

size_t MyString::getCapacity() const
{
	return capacity;
}

const char* MyString::getData() const
{
	return data;
}

//operators

MyString& MyString::operator+=(const MyString& other)
{
	size_t resSize = size + other.size;
	if (resSize + 1 > capacity) {
		resize(resSize + 1);
	}

	for (size_t i = 0; i < other.size; i++)
	{
		data[size + i] = other.data[i];
	}

	size = resSize;
	data[size] = '\0';

	return *this;
}

char MyString::operator[](size_t index) {
	return data[index];
}

const char MyString::operator[](size_t index) const {
	return data[index];
}

MyString operator+(const MyString& str1, const MyString& str2)
{

	MyString result = str1;
	result += str2;

	return result;
}

bool operator==(const MyString& str1, const MyString& str2)
{
	if (str1.getSize() != str2.getSize()) return false;
	if (strcmp(str1.getData(), str2.getData()) == 0) {
		return true;
	}

	return false;
}

bool operator!=(const MyString& str1, const MyString& str2) {
	return !(str1 == str2);
}

bool operator<(const MyString& str1, const MyString& str2)
{
	return (strcmp(str1.getData(), str2.getData()) < 0);
}

bool operator>=(const MyString& str1, const MyString& str2) {
	return !(str1 < str2);
}

std::strong_ordering operator<=>(const MyString& str1, const MyString& str2)
{
	return std::strong_ordering();
}

bool operator>(const MyString& str1, const MyString& str2) {
	return (str2 < str1);
}

bool operator<=(const MyString& str1, const MyString& str2) {
	return !(str2 < str1);
}

//std::strong_ordering operator<=>(const MyString& str1, const MyString& str2)
//{
//	return (strcmp(str1.getData(), str2.getData()) <=> 0);
//}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
	os << str.getData();
	return os;
}

std::istream& operator>>(std::istream& is, MyString& str)
{
	char temp[1024];
	is >> temp;
	str = MyString(temp);

	return is;
}

//String functions

bool MyString::isLower(char ch)
{
	return ch >= 'a' && ch <= 'z';
}

bool MyString::isUpper(char ch)
{
	return ch >= 'A' && ch <= 'Z';
}

char MyString::toUpperChar(char ch)
{
	if (isLower(ch)) {
		return ch - 'a' + 'A';
	}
	return ch;
}

char MyString::toLowerChar(char ch)
{
	if (isUpper(ch)) {
		return ch + ('a' - 'A');
	}
	return ch;
}

void MyString::toUpper()
{
	if (!data) return;
	for (size_t i = 0; i < size; i++)
	{
		data[i] = toUpperChar(data[i]);
	}
}

void MyString::toLower()
{
	if (!data) return;
	for (size_t i = 0; i < size; i++)
	{
		data[i] = toLowerChar(data[i]);
	}
}

MyString MyString::getSubstring(size_t startIndex, size_t length) const
{
	if (startIndex >= size) return MyString();
	char* sub = new char[length + 1];
	for (size_t i = 0; i < length; i++)
	{
		sub[i] = data[startIndex + i];
	}
	sub[length] = '\0';

	MyString result(sub);
	delete[] sub;

	return result;;
}

void MyString::reverse()
{
	if (!data || size <= 1) return;
	size_t start = 0;
	size_t end = data[size - 1];

	while(start < end)
	{
		std::swap(data[start], data[end]);
		start++;
		end--;
	}
}

MyString& MyString::insert(size_t index, char ch)
{
	if (index > size) return *this;
	char* res = new char[size + 2];
	size_t i = 0;

	while(i < index)
	{
		res[i] = data[i];
		i++;
	}

	res[i] = ch;

	while (i < size) {
		res[i+1] = data[i];
		i++;
	}

	res[size+1] = '\0';
	delete[] data;

	data = res;
	size++;

	return *this;
}

MyString& MyString::insert(size_t index, const char* str)
{
	if (index > size || !str) return *this;
	size_t resSize = size + strlen(str);
	char* res = new char[resSize + 1];

	for (size_t i = 0; i < index; i++) {
		res[i] = data[i];
	}

	for (size_t i = 0; i < strlen(str); i++) {
		res[index + i] = str[i];
	}

	for (size_t i = index; i < size; i++)
	{
		res[strlen(str) + i] = data[i];
	}

	size = resSize;
	res[size] = '\0';

	delete[] data;
	data = res;

	return *this;
}

MyString& MyString::insert(size_t index, const MyString& str)
{
	return insert(index, str.data);
}

MyString& MyString::erase(size_t index)
{
	if (index >= size) return *this;

	for (size_t i = index; i < size - 1; i++)
	{
		data[i] = data[i + 1];
	}

	size--;
	data[size] = '\0';

	return *this;
}

MyString& MyString::erase(size_t index, size_t count)
{
	if (index >= size || count >= size || index+count >size) return *this;

	size_t resSize = size - count;

	for (size_t i = index; i < resSize; i++)
	{
		data[i] = data[i + count];
	}

	size = resSize;
	data[size] = '\0';

	return* this;
}

bool MyString::contains(char ch) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (data[i] == ch) {
			return true;
		}
	}

	return false;
}

bool MyString::contains(const char* str) const
{
	if (!data || !str) return false;
	
	size_t sizeStr = strlen(str);
	if (sizeStr > size) return false;

	for (size_t i = 0; i <= size - sizeStr; i++)
	{
		bool match = true;
		for (size_t j = 0; j < sizeStr; j++)
		{
			if (data[i + j] != str[j]) {
				match = false;
				break;
			}
		}

		if (match) {
			return true;
		}
	}
	return false;
}

bool MyString::contains(const MyString& str) const
{
	return contains(str.data);
}
