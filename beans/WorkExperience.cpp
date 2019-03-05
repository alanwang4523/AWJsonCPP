//
// Created by wangjianjun on 19/3/5.
//

#include "WorkExperience.h"

WorkExperience::WorkExperience() {

}

WorkExperience::~WorkExperience() {

}

void WorkExperience::setCompanyName(string companyName) {
    this->companyName = companyName;
}

void WorkExperience::addProject(string project) {
    this->projectList.push_back(project);
}

void WorkExperience::setRole(string role) {
    this->role = role;
}

void WorkExperience::setTimeInMonths(int timeInMonths) {
    this->timeInMonths = timeInMonths;
}

Json::Value WorkExperience::toJsonObject() {
    Json::Value jsonRoot, jsonProjectList;
    jsonRoot["CompanyName"] = companyName;
    jsonRoot["Role"] = role;
    jsonRoot["TimeInMonths"] = timeInMonths;

    for (int i = 0; i < projectList.size(); ++i) {
        jsonProjectList[i] = projectList.at(i);
    }
    jsonRoot["ProjectList"] = jsonProjectList;

    return jsonRoot;
}