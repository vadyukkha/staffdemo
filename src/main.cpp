#include <iostream>
#include "../include/Project.h"
#include "../include/Factory.h"

int main() {
    srand(time(nullptr));
    // создание штата сотрудников на основе файла
    std::map<int64_t, Employee *> staff = Factory_Staff::make_staff();

    // присвоение отработанного времени
    for(const auto& emp : staff) {
        emp.second->setWorkTime(rand() % 40 + 1);
    }

    // расчет зарплаты
    for(const auto& emp: staff) {
        emp.second->calcSalary();
    }

    // вывод данных о зарплате
    for (const auto& emp : staff) {
        emp.second->printInfo();
        std::cout << std::endl;
    }

    return 0;
}
