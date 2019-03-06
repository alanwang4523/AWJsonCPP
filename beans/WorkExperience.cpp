//
// Created by wangjianjun on 19/3/5.
//

#include "WorkExperience.h"


int WorkExperience::CreateFromJsonStr(WorkExperience * workExperience, const char *jsonStr) {

    int errorCode = 0;
    Json::CharReaderBuilder builder;
    Json::CharReader * reader = builder.newCharReader();
    Json::Value jsonRoot;
    JSONCPP_STRING errs;

    //从字符串中读取数据
    if (reader->parse(jsonStr, jsonStr + strlen(jsonStr), &jsonRoot, &errs)) {
        errorCode = WorkExperience::CreateFromJsonValue(workExperience, jsonRoot);
    }
    delete reader;

    return errorCode;
}

int WorkExperience::CreateFromJsonValue(WorkExperience * workExperience, Json::Value jsonValue) {
    workExperience->setCompanyName(jsonValue[KEY_COMPANY_NAME].asString());
    workExperience->setRole(jsonValue[KEY_ROLE].asString());
    workExperience->setTimeInMonths(jsonValue[KEY_TIME_IN_MONTHS].asInt());

    // 解析数组
    Json::Value jsonProjectList= jsonValue[KEY_PROJECT_LIST];
    for (int i = 0; i < jsonProjectList.size(); ++i) {
        workExperience->addProject(jsonProjectList[i].asString());
    }
    return 0;
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