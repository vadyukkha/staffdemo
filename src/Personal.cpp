#include "../include/Personal.h"

Personal::Personal(const int64_t id, const std::string& name,
                   const int64_t work_time, const int64_t payment, Positions position)
    : Employee(id, name, work_time, position, payment), salary_(0) {}

void Personal::printInfo() {
    std::cout << "Name: " << name_ << std::endl;
    std::cout << "Position: " << enum_print_[position_] << std::endl;
    std::cout << "Work time: " << work_time_ << std::endl;
    std::cout << "Payment: " << payment_ << std::endl;
    std::cout << "Salary: " << salary_ << std::endl;
}

int64_t Personal::calcBonusSalary(int64_t bonus) {
    return bonus;
}

int64_t Personal::calcBaseSalary(const int64_t salary, const int64_t work_time_salary) {
    return salary * work_time_salary;
}

Driver::Driver(const int64_t id, const std::string& name,
               const int64_t work_time, const int64_t payment, Positions position)
    : Personal(id, name, work_time, payment, position) {}

void Driver::calcSalary() {
    salary_ = calcBaseSalary(payment_, work_time_) + calcBonusSalary();
}

int64_t Driver::calcBonusSalary(int64_t night_hours) {
    return night_hours * 2000;
}

Cleaner::Cleaner(const int64_t id, const std::string& name,
                 const int64_t work_time, const int64_t payment, Positions position)
    : Personal(id, name, work_time, payment, position) {}

void Cleaner::calcSalary() {
    salary_ = calcBaseSalary(payment_, work_time_);
}
