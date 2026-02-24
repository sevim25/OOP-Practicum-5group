#include <iostream>

struct Student {
    char name[50];
    unsigned facultyNumber;
    char password[50];

    bool isValidPassword(const char* logPassword) {
        if (!logPassword) return false;

        for (int i = 0; logPassword[i] != '\0' && password[i] != '\0'; i++) {
            if (logPassword[i] != password[i])
                return false;
        }
    
        return true;
    }

    void printStrudentInfo() {
        
        std::cout << "name: " << name << '\n';
        
        std::cout <<"FN: " << facultyNumber << '\n';
        if (isValidPassword(password)) {
            std::cout << "password: " << password;
        }
    }

    void changePassword(const char* oldPassword, const char* newPassword) {
        if (!oldPassword && !newPassword) return;

        if (isValidPassword(oldPassword)) {

            int i = 0;
            while (newPassword[i] != '\0') {
                password[i] = newPassword[i];
                i++;
            }
            password[i] = '\0';
        }

    }
};

int main()
{
    Student s = { "Sevim", 12345, "pass123" };
    s.printStrudentInfo();
    std::cout << '\n';
    s.changePassword("pass123", "newPass456");
    std::cout << '\n';
    s.printStrudentInfo();
}

