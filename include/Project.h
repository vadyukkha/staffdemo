#pragma once
#ifndef INCLUDE_PROJECT_H_
#define INCLUDE_PROJECT_H_

#include <iostream>
#include "Employee.h"
#include "Interfaces.h"

class Project {
 public:
   Project() = default;
   Project(const int64_t id, const int64_t budget);
    
    int64_t getBudget() const;
    int64_t getId() const;

 private:
   int64_t id_;
   int64_t budget_;
};

class ProjectManager : public Project, public Employee, public ProjectBudget {
 public:
   ProjectManager(const int64_t id, const std::string& name,
             const int64_t workTime, Positions position, const std::vector<Project*>& project);
   ~ProjectManager() override = default;

   int64_t calcProAdditions(int64_t bonus = 1) override;
   int64_t calcBudgetPart() override;
   void calcSalary() override;
   void printInfo() override;
 private:
   std::vector<Project*> projects_;
   uint8_t max_count_of_projects_ = 1;
};

class SeniorManager : public ProjectManager {
 public:
   SeniorManager(const int64_t id, const std::string& name,
             const int64_t workTime, Positions position, const std::vector<Project*>& project);
   ~SeniorManager() override = default;

   int64_t calcProAdditions(int64_t bonus = 1) override;
   int64_t calcBudgetPart() override;
   void calcSalary() override;
   void printInfo() override;
 private:
   std::vector<Project*> projects_;
};

#endif  // INCLUDE_PROJECT_H_
