//
// Created by wangjianjun on 19/3/5.
//

#include "WorkExperience.h"


WorkExperience* WorkExperience::CreateFromJsonStr(const char *jsonStr) {
    WorkExperience * workExperience = nullptr;

    Json::CharReaderBuilder builder;
    Json::CharReader * reader = builder.newCharReader();
    Json::Value jsonRoot;
    JSONCPP_STRING errs;

    //从字符串中读取数据
    if (reader->parse(jsonStr, jsonStr + strlen(jsonStr), &jsonRoot, &errs)) {
        workExperience = new WorkExperience();
        workExperience->setCompanyName(jsonRoot[KEY_COMPANY_NAME].asString());
        workExperience->setRole(jsonRoot[KEY_ROLE].asString());
        workExperience->setTimeInMonths(jsonRoot[KEY_TIME_IN_MONTHS].asInt());

        // 解析数组
        Json::Value jsonProjectList= jsonRoot[KEY_PROJECT_LIST];
        for (int i = 0; i < jsonProjectList.size(); ++i) {
            workExperience->addProject(jsonProjectList[i].asString());
        }
    }

    return workExperience;
}

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
    jsonRoot[KEY_COMPANY_NAME] = companyName;
    jsonRoot[KEY_ROLE] = role;
    jsonRoot[KEY_TIME_IN_MONTHS] = timeInMonths;

    for (int i = 0; i < projectList.size(); ++i) {
        jsonProjectList[i] = projectList.at(i);
    }
    jsonRoot[KEY_PROJECT_LIST] = jsonProjectList;

    return jsonRoot;
}