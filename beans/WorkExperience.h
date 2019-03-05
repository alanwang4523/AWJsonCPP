//
// Created by wangjianjun on 19/3/5.
//

#ifndef JSONCPPDEMO_WORKEXPERIENCE_H
#define JSONCPPDEMO_WORKEXPERIENCE_H

#include <cstdio>
#include <string>
#include <vector>
#include "json.h"

using namespace std;

#define KEY_COMPANY_NAME "CompanyName"
#define KEY_ROLE "Role"
#define KEY_TIME_IN_MONTHS "TimeInMonths"
#define KEY_PROJECT_LIST "ProjectList"

class WorkExperience {
public:
    static WorkExperience * CreateFromJsonStr(const char * jsonStr);

public:
    WorkExperience();
    ~WorkExperience();

public:
    void setCompanyName(string companyName);
    void addProject(string project);
    void setRole(string role);
    void setTimeInMonths(int timeInMonths);

    Json::Value toJsonObject();

    string getCompanyName() {
        return companyName;
    }

    vector<string> getProjectList() {
        return projectList;
    }

    string getRole() {
        return role;
    }

    int getTimeInMonths() {
        return timeInMonths;
    }

private:
    string companyName;// 公司
    vector<string> projectList;// 项目列表
    string role;// 角色
    int timeInMonths;// 项目耗时
};


#endif //JSONCPPDEMO_WORKEXPERIENCE_H
