//
// Created by wangjianjun on 19/3/6.
//

#include "WorkerInfo.h"

int WorkerInfo::CreateFromJsonStr(WorkerInfo * workerInfo, const char *jsonStr) {

    Json::CharReaderBuilder builder;
    Json::CharReader * reader = builder.newCharReader();
    Json::Value jsonRoot;
    JSONCPP_STRING errs;

    //从字符串中读取数据
    if (reader->parse(jsonStr, jsonStr + strlen(jsonStr), &jsonRoot, &errs)) {
        workerInfo->name = jsonRoot[KEY_NAME].asString();
        workerInfo->email = jsonRoot[KEY_EMAIL].asString();
        workerInfo->age = jsonRoot[KEY_AGE].asInt();

        // 解析数组
        Json::Value jsonExperienceList= jsonRoot[KEY_EXPERIENCE_LIST];
        for (int i = 0; i < jsonExperienceList.size(); ++i) {
            WorkExperience workExperience ;
            WorkExperience::CreateFromJsonValue(&workExperience, jsonExperienceList[i]);
            workerInfo->addExperience(workExperience);
        }

        delete reader;
    }
    return 0;
}

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