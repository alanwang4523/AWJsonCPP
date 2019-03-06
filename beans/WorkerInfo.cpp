//
// Created by wangjianjun on 19/3/6.
//

#include "WorkerInfo.h"

WorkerInfo::WorkerInfo() {

}

WorkerInfo::~WorkerInfo() {

}

void WorkerInfo::setName(string name) {
    this->name = name;
}

void WorkerInfo::setEmail(string email) {
    this->email = email;
}

void WorkerInfo::setAge(int age) {
    this->age = age;
}

void WorkerInfo::addExperience(WorkExperience experience) {
    this->experienceList.push_back(experience);
}

Json::Value WorkerInfo::toJsonObject() {
    Json::Value jsonRoot, jsonExperienceList;
    jsonRoot[KEY_NAME] = name;
    jsonRoot[KEY_EMAIL] = email;
    jsonRoot[KEY_AGE] = age;

    for (int i = 0; i < experienceList.size(); ++i) {
        jsonExperienceList[i] = experienceList.at(i).toJsonObject();
    }
    jsonRoot[KEY_EXPERIENCE_LIST] = jsonExperienceList;

    return jsonRoot;
}