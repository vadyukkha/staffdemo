#include "../include/Factory.h"
#include "../include/Engineer.h"
#include "../include/Project.h"
#include "fstream"

Project* find_project(const std::map<int64_t, Project*>& prjs, const int64_t& id) {
    for (const auto& it : prjs) {
        if (it.second->getId() == id) {
            return it.second;
        }
    }
    return nullptr;
}

Positions finder_pos(const std::string &pos) {
    if (pos == "Programmer") {
        return Positions::programmer;
    } else if (pos == "Team leader") {
        return Positions::team_leader;
    } else if (pos == "Project Manager") {
        return Positions::project_manager;
    } else if (pos == "Senior Manager") {
        return Positions::senior_manager;
    } else if (pos == "Cleaner") {
        return Positions::cleaner;
    } else if (pos == "Driver") {
        return Positions::driver;
    } else if (pos == "Tester") {
        return Positions::tester;
    }
    return Positions::cleaner;
}

std::map<int64_t, Employee *> Factory_Staff::make_staff() {
    std::ifstream file("../bd/staff.json", std::ifstream::binary);
    json j;
    file >> j;
    file.close();
    std::map<int64_t, Employee *> staff;
    std::map<int64_t, Project*> projects_from_file;
    for (const auto &project : j["projects"]) {
        int64_t id = static_cast<int64_t>(project["id"]);
        int64_t budget = static_cast<int64_t>(project["budget"]);
        projects_from_file[id] = new Project(id, budget);
    }

    for (const auto &person : j["employees"]) {
        int64_t id = static_cast<int64_t>(person["id"]);
        std::string name = static_cast<std::string>(person["name"]);
        std::string pos_str = static_cast<std::string>(person["position"]);
        Positions position = finder_pos(pos_str);
        int64_t work_time = static_cast<int64_t>(person["worktime"]);
        int64_t payment = 0;
        if (position != Positions::project_manager && position != Positions::senior_manager) {
            payment = static_cast<int64_t>(person["payment"]);
        }

        if (position == Positions::programmer) {
            int64_t id_prjs = static_cast<int64_t>(person["project"]);
            Project* prjs = find_project(projects_from_file, id_prjs);
            staff[id] = new Programmer(id, name, work_time, payment, position, prjs);
        }
        else if (position == Positions::team_leader) {
            int64_t id_prjs = static_cast<int64_t>(person["project"]);
            Project* prjs = find_project(projects_from_file, id_prjs);
            staff[id] = new TeamLeader(id, name, work_time, payment, position, prjs);
        }
        else if (position == Positions::tester) {
            int64_t id_prjs = static_cast<int64_t>(person["project"]);
            Project* prjs = find_project(projects_from_file, id_prjs);
            staff[id] = new Tester(id, name, work_time, payment, position, prjs);
        }
        else if (position == Positions::project_manager) {
            std::vector<int64_t> projects_per_person = static_cast<std::vector<int64_t>>(person["projects"]);
            Project* prjs = find_project(projects_from_file, projects_per_person[0]);
            std::vector<Project*> project(1, prjs);
            staff[id] = new ProjectManager(id, name, work_time, position, project);
        }
        else if (position == Positions::senior_manager) {
            std::vector<int64_t> projects_per_person = static_cast<std::vector<int64_t>>(person["projects"]);
            std::vector<Project*> projects;
            for (size_t i = 0; i < projects_per_person.size(); i++) {
                Project* prjs = find_project(projects_from_file, projects_per_person[i]);
                projects.push_back(prjs);
            }
            staff[id] = new SeniorManager(id, name, work_time, position, projects);
        }
        else if (position == Positions::cleaner) {
            staff[id] = new Cleaner(id, name, work_time, payment, position);
        }
        else if (position == Positions::driver) {
            staff[id] = new Driver(id, name, work_time, payment, position);
        }
        
    }
    return staff;
}
