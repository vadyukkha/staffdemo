#pragma once
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include <iostream>
#include <string>

#include "Employee.h"
#include "Interfaces.h"

class Personal : public Employee, public WorkBaseTime {
 public:
    Personal(const int64_t id, const std::string& name,
             const int64_t workTime, const int64_t payment, Positions position);
    
    ~Personal() override = default;
    
    int64_t calcBonusSalary(int64_t bonus = 5) override;
    int64_t calcBaseSalary(const int64_t salary, const int64_t work_time_salary) override;
    void printInfo() override;
 protected:
    int64_t salary_;
};

class Driver : public Personal {
 public:
    Driver(const int64_t id, const std::string& name,
           const int64_t work_time, const int64_t payment, Positions position);

    void calcSalary() override;
    int64_t calcBonusSalary(int64_t night_hours = 8) override;
};

class Cleaner : public Personal {
 public:
    Cleaner(const int64_t id, const std::string& name,
            const int64_t work_time, const int64_t payment, Positions position);

    void calcSalary() override;
};

#endif  // INCLUDE_PERSONAL_H_
