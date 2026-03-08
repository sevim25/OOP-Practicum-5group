#include <iostream>
#include <print>
#include <cstring>
#pragma warning(disable : 4996) // за strcpy

using std::cin;
using std::cout;

enum class Category {
	Italian, Chinese, American, French, Japanese
};

class Restaurant {
private:
	char name[100];
	Category category;
	bool isOpen = true;
	double rating = 0;
	double averagePrice = 0;

public:
	Restaurant() {

	}

	Restaurant(const char* name, Category cat, double avgPrice) {
		strcpy(this->name, name);
		category = cat;
		averagePrice = avgPrice;
		isOpen = true;
		rating = 0;
	};

	const char* getName() const {
		return name;
	}

	Category getCategory() const {
		return category;
	}

	bool isOpened() const {
		return isOpen;
	}

	double getRating() const {
		return rating;
	}

	double getAveragePrice() const {
		return averagePrice;
	}

	void setRate(double newRating) {
		rating = (rating + newRating) / 2;
	}

	void open() {
		isOpen = true;
	}

	void close() {
		isOpen = false;
	}


	const char* toString(const Category& c) const {
		switch (c) {
		case Category::Italian: return "Italian";
		case Category::Chinese: return "Chinese";
		case Category::American:return "American";
		case Category::French: return "French";
		case Category::Japanese: return "Japanese";
		default:
			return "Unknown";
		}
	}

	void print() const {
		std::println("{} - {} restaurant", name, toString(category));

		if (isOpen) {
			cout << "is open" << '\n';
		}
		else
			cout << "is closed" << '\n';

		std::println("Rating: {}, Average price: {}", rating, averagePrice);
	}
};

class RestaurantChain {
private:
	Restaurant restaurants[100];
	int count = 0;

public:
	RestaurantChain(const Restaurant* restaurants, int count) : count(count) {
		for (int i = 0; i < count; i++)
		{
			this->restaurants[i] = restaurants[i];
		}
	}

	RestaurantChain(const Restaurant* restaurants, int counter, Category category) {
		for (int i = 0; i < counter; i++)
		{
			if (category == restaurants[i].getCategory()) {
				this->restaurants[count] = restaurants[i];
				count++;
			}
		}
	}

	bool addRestaurant(const Restaurant& newRestaurant) {

		if (count >= 0 && count < 100) {
			restaurants[count] = newRestaurant;
			count++;

			return true;
		}

			return false;
	}

	void removeRestaurant( const char* newName) {
		for (int i = 0; i < count; i++)
		{
			if (strcmp(restaurants[i].getName(), newName) == 0) {
				for (int j = i; j < count - 1; j++)
				{
					restaurants[j] = restaurants[j + 1];
				}
				count--;
			}
		}
	}

	int getCount() const {
		return count;
	}

	void sortRestaurantsByPrice() {
		for (int i = 0; i < count - 1; i++)
		{
			for (int j = 0; j < count - i -1; j++)
			{
				if (restaurants[j].getAveragePrice() > restaurants[j + 1].getAveragePrice()) {
					std::swap(restaurants[j], restaurants[j + 1]);
				}
			}
		}
	}

	const Restaurant* getMostExpensive(int num) {
		sortRestaurantsByPrice();

		if (num > count)
			num = count;

		Restaurant* mostExpensive = new Restaurant[num];
		
		for (int i = 0; i < num; i++)
		{
			mostExpensive[i] = restaurants[count - num + i];
		}

		return mostExpensive;
	}

	void printOpen() const {
		for (int i = 0; i < count; i++)
		{
			if (restaurants[i].isOpened()) {
				restaurants[i].print();
			}
			cout << '\n';
		}
	}

	void rateAll(double rating) {
		for (int i = 0; i < count; i++)
		{
			restaurants[i].setRate(rating);
			if (restaurants[i].getRating() < 1) {
				restaurants[i].close();
			}
		}
	}

	double getAveragePriceForCategory(Category category) {
		double sumAvg = 0;
		int counter = 0;

		for (int i = 0; i < count; i++)
		{
			if (restaurants[i].getCategory() == category) {
				sumAvg += restaurants[i].getAveragePrice();
				counter++;
			}
		}
		return sumAvg / counter;
	}
};


int main()
{
	Restaurant myRestaurants[3] = {
			{"Italiano ", Category::Italian, 55.5},
			{"Americano", Category::American, 20.5},
			{"Chinese ", Category::Chinese, 70.5}
	};

	RestaurantChain chain(myRestaurants, 3);
	Restaurant newRestaurant = { "My Restaurant", Category::Japanese, 32.5 };
	chain.addRestaurant(newRestaurant);

	double avg = chain.getAveragePriceForCategory(Category::Italian);
	std::println("The average price for Italian category is {}", avg);
	cout << '\n';

	const Restaurant* expensive = chain.getMostExpensive(2);
	std::println("---The 2 most expensive restaurants are---");

	for (int i = 0; i < 2; i++)
	{
		expensive[i].print();
	}

	delete[] expensive;

	cout << '\n';

	std::println("---All open restaurants---");
	chain.printOpen();

	chain.rateAll(4);
	chain.removeRestaurant("Americano");
}