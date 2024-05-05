#include "../include/Engineer.h"
#include "../include/Project.h"

Engineer::Engineer(const int64_t id, const std::string& name,
             const int64_t workTime, const int64_t payment, Positions position)
    : Personal(id, name, workTime, payment, position) {}

void Engineer::calcSalary() {
    salary_ = calcBaseSalary(payment_, work_time_) + calcBudgetPart();
}

int64_t Engineer::calcBudgetPart() {
    return project_->getBudget() * 0.2;
}

void Engineer::printInfo() {
    std::cout << "Name: " << name_ << std::endl;
    std::cout << "Position: " << enum_print_[position_] << std::endl;
    std::cout << "Work time: " << work_time_ << std::endl;
    std::cout << "Payment: " << payment_ << std::endl;
    std::cout << "Salary: " << salary_ << std::endl;
    std::cout << "Project: " << project_->getId() << std::endl;
}

Tester::Tester(const int64_t id, const std::string& name,
               const int64_t workTime, const int64_t payment, Positions position, const Project* project)
    : Engineer(id, name, workTime, payment, position) {
        project_ = const_cast<Project*>(project);
    }

int64_t Tester::calcProAdditions(int64_t bags) {
    return 2000 * bags;
}

void Tester::calcSalary() {
    salary_ = calcBaseSalary(payment_, work_time_) + calcBudgetPart() + calcProAdditions(10);
}

Programmer::Programmer(const int64_t id, const std::string& name,
             const int64_t workTime, const int64_t payment, Positions position, const Project* project)
    : Engineer(id, name, workTime, payment, position) {
        project_ = const_cast<Project*>(project);
    }

int64_t Programmer::calcProAdditions(int64_t bonus = 10000) {
    return bonus;
}

void Programmer::calcSalary() {
    salary_ = calcBaseSalary(payment_, work_time_) + calcBudgetPart() + calcProAdditions();
}

TeamLeader::TeamLeader(const int64_t id, const std::string& name,
             const int64_t workTime, const int64_t salary, Positions position, const Project* project)
    : Programmer(id, name, workTime, salary, position, project) {}

int64_t TeamLeader::calcHeads() {
    return 2 * payment_;
}

void TeamLeader::calcSalary() {
    salary_ = calcBaseSalary(payment_, work_time_) + calcHeads() + calcBudgetPart();
}
