#pragma once
#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

#include <iostream>

class Heading {
 public:
    virtual ~Heading() = default;
    virtual int64_t calcHeads() = 0;
};

class WorkBaseTime {
 public:
    virtual ~WorkBaseTime() = default;
    virtual int64_t calcBonusSalary(int64_t bonus) = 0;
    virtual int64_t calcBaseSalary(int64_t salaryValue, int64_t workTimeValue) = 0;
};

class ProjectBudget {
 public:
    virtual ~ProjectBudget() = default;
    virtual int64_t calcBudgetPart() = 0;
    virtual int64_t calcProAdditions(int64_t bonus) = 0;
};

#endif  // INCLUDE_INTERFACES_H_
