#include <iostream>

using std::cin;
using std::cout;

enum Position {
	SoftwareEngineer,
	SeniorSoftwareEngineer, 
	EngineerManager, 
	LeadSoftwareEngineer,
	Unknown
};

struct Employee {
	char name[50];
	Position position;
	double salary;
	int rate;

	void initEmployee() {
		cout << "Name: ";
		cin.getline(name, 50);

		cout << "Position: ";
		int posInput;
		cin >> posInput;
		position = (Position)posInput;

		cout << "Salary: ";
		cin >> salary;

		cout << "Rate: ";
		cin >> rate;

		cin.ignore();
	}

	void printEmployee() {
		cout << "Name: " << name << '\n';
		cout << "Position: " << position << '\n';
		cout << "Salary: " << salary << '\n';
		cout << "Rate: " << rate << '\n';
	}

	void changeSalary(double newSalary) {
		salary = newSalary;
	}

	void changeRate( double newRate) {
		rate = newRate;
	}

	void changePosition( Position newPosition) {
		position = newPosition;
	}
};

int strCompare(const char* strA, const char* strB) {
	int i = 0;
	for (i=0; strA[i] != '\0' && strB[i] != '\0'; i++)
	{
		if (strA[i] != strB[i]) {
			return  (unsigned char)strA[i] - (unsigned char)strB[i];
		}
	}
	return  (unsigned char)strA[i] - (unsigned char)strB[i];
}

void swap(Employee& a, Employee& b) {
	Employee temp = a;
	a = b;
	b = temp;
}

void sortNameAlphabetically(Employee* employees, int size) {

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (strCompare(employees[j].name, employees[j + 1].name) > 0) {
				swap(employees[j], employees[j + 1]);
			}
		}
	}
}


struct Company {
	Employee employees[100];
	int countEmployees;
	double avgSalary;

	void initCompany() {
		cout << "count of employees: ";
		cin >> countEmployees;

		cin.ignore();
		for (int i = 0; i < countEmployees; i++)
		{
			employees[i].initEmployee();
			cout << '\n';
		}
	}

	double getTotalAvgSalary() {
		double sum = 0;
		for (int i = 0; i < countEmployees; i++)
		{
			sum += employees[i].salary;
		}
		return sum / countEmployees;
	}

	void employeesHighSalary() {
		avgSalary = getTotalAvgSalary();
		sortNameAlphabetically(employees, countEmployees);
		for (int i = 0; i < countEmployees; i++)
		{
			if (employees[i].salary > avgSalary) {
				employees[i].printEmployee();
			}
		}
	}

	void minAndMaxRate() {

		int min = employees[0].rate;
		int max = employees[0].rate;

		for (int i = 1; i < countEmployees; i++) {
			if (employees[i].rate < min) min = employees[i].rate;
			if (employees[i].rate > max) max = employees[i].rate;
		}

		cout << "Smallest rate: " << min << '\n';
		cout << "Largest rate: " << max << '\n';
	}

	void printAvgSalaryForEachPos() {
		double sumSE = 0;
		double sumSSE = 0;
		double sumEM = 0;
		double sumLSE = 0;

		int countSE = 0;
		int countSSE = 0;
		int countEM = 0;
		int countLSE = 0;

		for (int i = 0; i < countEmployees; i++)
		{
			if (employees[i].position == SoftwareEngineer) {
				countSE++;
				sumSE += employees[i].salary;
			}
			else if (employees[i].position == SeniorSoftwareEngineer) {
				countSSE++;
				sumSSE += employees[i].salary;
			}
			else if (employees[i].position == EngineerManager) {
				countEM++;
				sumEM += employees[i].salary;
			}
			else if (employees[i].position == LeadSoftwareEngineer) {
				countLSE++;
				sumLSE += employees[i].salary;
			}
		}
		
		cout << "Average salary for Software Engineer: " << sumSE / countSE << '\n';
		cout << "Average salary for Senior Software Engineer " << sumSSE / countSSE << '\n';
		cout << "Average salary for Engineer Manager: " << sumEM / countEM << '\n';
		cout << "Average salary for Lead Software Engineer: " << sumLSE / countLSE << '\n';
		
	}

	void printNamesByPosition() {
		for (int i = 0; i < countEmployees; i++)
		{
			if (employees[i].position == SoftwareEngineer) {
				cout << "Software Engineers: " << employees[i].name << '\n';
			}
			else if (employees[i].position == SeniorSoftwareEngineer) {
				cout << "Senior Software Engineers: " << employees[i].name << '\n';
			}
			else if (employees[i].position == EngineerManager) {
				cout << "Engineer Managers: " << employees[i].name << '\n';
			}
			else if (employees[i].position == LeadSoftwareEngineer) {
				cout << "Lead Software Engineers: " << employees[i].name << '\n';
			}
		}
	}

	void printNamesByRate( int rate) {
		for (int i = 0; i < countEmployees; i++)
		{
			if (employees[i].rate == rate) {
				cout << "Rate = " << rate << ": " << employees[i].name;
			}
			
		}
	}
};

int main() {
	Company myCompany;

	myCompany.initCompany();
	cout << '\n';

	double avgSalayComp = myCompany.getTotalAvgSalary();
	cout << "The company's average salary is " << avgSalayComp << '\n';

	myCompany.employeesHighSalary();
	cout << '\n';

	myCompany.minAndMaxRate();
	cout << '\n';

	myCompany.printAvgSalaryForEachPos();
	cout << '\n';

	myCompany.printNamesByPosition();
	
}
