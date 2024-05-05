#pragma once
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <string>
#include <map>
#include "Personal.h"
#include "../include/json/include/nlohmann/json.hpp"

using json = nlohmann::json;

class Factory_Staff {
 public:
    static std::map<int64_t, Employee *> make_staff();
    ~Factory_Staff() = default;
};

#endif  // INCLUDE_FACTORY_H_
