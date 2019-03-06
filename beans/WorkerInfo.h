//
// Created by wangjianjun on 19/3/6.
//

#ifndef JSONCPPDEMO_WORKERINFO_H
#define JSONCPPDEMO_WORKERINFO_H

#include <cstdio>
#include <string>
#include <vector>
#include "WorkExperience.h"

using namespace std;

#define KEY_NAME "Name"
#define KEY_EMAIL "Email"
#define KEY_AGE "Age"
#define KEY_EXPERIENCE_LIST "ExperienceList"

class WorkerInfo {
public:
    WorkerInfo();
    ~WorkerInfo();

public:
    void setName(string name);
    void setEmail(string email);
    void setAge(int age);
    void addExperience(WorkExperience experience);

    Json::Value toJsonObject();

    string getName() {
        return name;
    }

    string getEmail() {
        return email;
    }

    int getAge() {
        return age;
    }

    vector<WorkExperience> getExperienceList() {
        return experienceList;
    }

private:
    string name;
    string email;
    int age;
    vector<WorkExperience> experienceList;
};


#endif //JSONCPPDEMO_WORKERINFO_H
