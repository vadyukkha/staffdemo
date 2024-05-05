#pragma once
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>
#include <vector>

enum Positions {
   programmer,
   team_leader,
   project_manager,
   senior_manager,
   cleaner,
   driver,
   tester,
};

class Employee {
 public:
   Employee(const int64_t id, const std::string& name,
            const int64_t work_time, const Positions position, const int64_t payment);
   virtual ~Employee() = default;
   
   // work time for week
   void setWorkTime(const int64_t hours);

   virtual void calcSalary() = 0;
   virtual void printInfo() = 0;
 protected:
   Positions position_;
   int64_t payment_;
   int64_t work_time_;
   std::string name_;
   std::vector<std::string> enum_print_ = {"programmer",
                                          "team_leader",
                                          "project_manager",
                                          "senior_manager",
                                          "cleaner",
                                          "driver",
                                          "tester"};                               
 private:
   int64_t id_;
};

#endif  // INCLUDE_EMPLOYEE_H_
