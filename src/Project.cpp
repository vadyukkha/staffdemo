#include "../include/Project.h"

Project::Project(const int64_t id, const int64_t budget)
    : id_(id), budget_(budget) {}

int64_t Project::getBudget() const {
    return budget_;
}

int64_t Project::getId() const {
    return id_;
}

ProjectManager::ProjectManager(const int64_t id, const std::string& name,
             const int64_t workTime, Positions position, const std::vector<Project*>& project)
    : Employee(id, name, workTime, position, 0) {
        if (position == Positions::project_manager) {
            projects_ = std::move(project);
        }
    }

int64_t ProjectManager::calcProAdditions(int64_t bonus) {
    return projects_.size() * bonus * 20000;
}

int64_t ProjectManager::calcBudgetPart() {
    return 0.5 * projects_[0]->getBudget();
}

void ProjectManager::calcSalary() {
    payment_ = calcProAdditions() + calcBudgetPart();
}

SeniorManager::SeniorManager(const int64_t id, const std::string& name,
             const int64_t workTime, Positions position, const std::vector<Project*>& project)
    : ProjectManager(id, name, workTime, position, project) {
        if (position == Positions::senior_manager) {
            projects_ = std::move(project);
        }
    }

int64_t SeniorManager::calcProAdditions(int64_t bonus) {
    return projects_.size() * bonus * 100000;
}

int64_t SeniorManager::calcBudgetPart() {
    int64_t salary = 0;
    for (size_t i = 0; i < projects_.size(); i++) {
        salary += 0.5 * projects_[0]->getBudget();
    }
    return salary;
}

void SeniorManager::calcSalary() {
    payment_ = calcProAdditions() + calcBudgetPart();
}

void ProjectManager::printInfo() {
    std::cout << "Name: " << name_ << std::endl;
    std::cout << "Position: " << enum_print_[position_] << std::endl;
    std::cout << "Work time: " << work_time_ << std::endl;
    std::cout << "Salary: " << payment_ << std::endl;
    std::cout << "Projects: [" << projects_[0]->getId() << "]" << std::endl;
}

void SeniorManager::printInfo() {
    std::cout << "Name: " << name_ << std::endl;
    std::cout << "Position: " << enum_print_[position_] << std::endl;
    std::cout << "Work time: " << work_time_ << std::endl;
    std::cout << "Salary: " << payment_ << std::endl;
    std::cout << "Projects: [";
    for (size_t i = 0; i < projects_.size(); i++) {
        std::cout << projects_[i]->getId() << ", ";
    }
    std::cout << "]" << std::endl;
}
