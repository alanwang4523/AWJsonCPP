#include <iostream>
#include <sstream>
#include <fstream>
#include "json.h"

#include "WorkExperience.h"
#include "WorkerInfo.h"

/**
 * 将 json 转成字符串并输出
 * @param jsonRoot
 */
std::string funJsonToString(Json::Value jsonRoot);

/**
 * 将 json 转成字符串并保存到文件
 * @param jsonRoot
 * @param filePath
 */
void funJsonToFile(Json::Value jsonRoot, std::string filePath);

/**
 * 测试：解析 json 字符串
 */
void testParseJsonStr();

/**
 * 测试：由 json object 生成 json 字符串
 */
void testGenerateJsonStr();

/**
 * 测试：生成 json 字符串 到文件
 */
void testGenerateJsonStrToFile();

/**
 * 将数据对象转成 json 字符串
 */
void testDataObjectToJsonStr();

/**
 * 从 json 字符串中解析出数据对象
 */
void testParseObjectFromJsonStr();

/**
 * 测试将复杂对象转成 json 字符串
 */
void testComplexObjectToJsonStr();

int main() {
    std::cout << "<-----JsonCPPDemo---->" << std::endl;

    testParseJsonStr();
    testGenerateJsonStr();
    testGenerateJsonStrToFile();

    testDataObjectToJsonStr();
    testParseObjectFromJsonStr();

    testComplexObjectToJsonStr();

    return 0;
}


/**
 * 将 json 转成字符串并输出
 * @param jsonRoot
 */
std::string funJsonToString(Json::Value jsonRoot) {
    Json::StreamWriterBuilder writerBuilder;
    Json::StreamWriter * streamWriter = writerBuilder.newStreamWriter();
    std::ostringstream os;

    streamWriter->write(jsonRoot, &os);
    std::string jsonStr = os.str();
    delete streamWriter;

    return jsonStr;
}

/**
 * 将 json 转成字符串并保存到文件
 * @param jsonRoot
 * @param filePath
 */
void funJsonToFile(Json::Value jsonRoot, std::string filePath) {

    Json::StreamWriterBuilder writerBuilder;
    Json::StreamWriter * streamWriter = writerBuilder.newStreamWriter();
    std::ofstream os;

    os.open(filePath);
    streamWriter->write(jsonRoot, &os);
    os.close();

    delete streamWriter;
}

/**
 * 测试：解析 json 字符串
 */
void testParseJsonStr() {
    std::cout << "<-----JsonCPPDemo---->testParseJsonStr()--->>" << std::endl;

    const char * jsonStr = "{\n"
            "  \"Name\": \"AlanWang\",\n"
            "  \"Email\": \"alanwang4523@gmail.com\",\n"
            "  \"Age\": 27,\n"
            "  \"Weight\": 66.6,\n"
            "  \"Language\": [\n"
            "    \"Java\",\n"
            "    \"C/C++\",\n"
            "    \"Python\"\n"
            "  ],\n"
            "  \"isTest\": true\n"
            "}";

    /*
    {
          "Name": "AlanWang",
          "Email": "alanwang4523@gmail.com",
          "Age": 27,
          "Weight": 66.6,
          "Language": [
                "Java",
                "C/C++",
                "Python"
          ],
          "isTest": true
    }
     **/


    Json::CharReaderBuilder builder;
    Json::CharReader * reader = builder.newCharReader();
    Json::Value jsonRoot;
    JSONCPP_STRING errs;

    //从字符串中读取数据
    if (reader->parse(jsonStr, jsonStr + strlen(jsonStr), &jsonRoot, &errs)) {
        // 解析字符串
        std::string name = jsonRoot["Name"].asString();
        std::cout << "name = " << name << std::endl;

        std::string email = jsonRoot["Email"].asString();
        std::cout << "email = " << email << std::endl;

        // 解析 int 型
        int age = jsonRoot["Age"].asInt();
        std::cout << "age = " << age << std::endl;

        // 解析 float 型
        float weight = jsonRoot["Weight"].asFloat();
        std::cout << "weight = " << weight << std::endl;

        // 解析 bool 类型
        bool isTest = jsonRoot["isTest"].asBool();
        std::cout << "isTest = " << isTest << std::endl;

        // 解析数组
        Json::Value jsonLanguage = jsonRoot["Language"];
        for (int i = 0; i < jsonLanguage.size(); ++i) {
            std::cout << "[" << i << "] = " << jsonLanguage[i] << std::endl;
        }

    } else {
        std::cout << "Json parse error : " << errs.data() <<  std::endl;
    }

    delete reader;
}

/**
 * 测试：由 json object 生成 json 字符串
 */
void testGenerateJsonStr() {
    std::cout << "<-----JsonCPPDemo---->testGenerateJsonStr()--->>" << std::endl;

    Json::Value jsonObjRoot;
    jsonObjRoot["Name"] = "AlanWang";
    jsonObjRoot["Email"] = "alanwang4523@gmail.com";
    jsonObjRoot["Age"] = 27;
    jsonObjRoot["Weight"] = 66.6f;
    jsonObjRoot["isTest"] = true;

    Json::Value jsonObjLanguage;
    jsonObjLanguage[0] = "Java";
    jsonObjLanguage[1] = "C/C++";
    jsonObjLanguage[2] = "Python";
    jsonObjRoot["Language"] = jsonObjLanguage;

    std::string jsonStr = funJsonToString(jsonObjRoot);

    std::cout << "Generate Json:\n" << jsonStr << std::endl;
}

/**
 * 测试：生成 json 字符串 到文件
 */
void testGenerateJsonStrToFile() {
    std::cout << "<-----JsonCPPDemo---->testGenerateJsonStrToFile()--->>" << std::endl;

    Json::Value jsonObjRoot;
    jsonObjRoot["Name"] = "AlanWang";
    jsonObjRoot["Email"] = "alanwang4523@gmail.com";
    jsonObjRoot["Age"] = 27;
    jsonObjRoot["Weight"] = 66.6f;
    jsonObjRoot["isTest"] = true;

    Json::Value jsonObjLanguage;
    jsonObjLanguage[0] = "Java";
    jsonObjLanguage[1] = "C/C++";
    jsonObjLanguage[2] = "Python";
    jsonObjRoot["Language"] = jsonObjLanguage;

    funJsonToFile(jsonObjRoot, "test.json");
}

/**
 * 将数据对象转成 json 字符串
 */
void testDataObjectToJsonStr() {
    std::cout << "<-----JsonCPPDemo---->testDataObjectToJsonStr()--->>" << std::endl;
    WorkExperience workExperience;
    workExperience.setCompanyName("Google");
    workExperience.addProject("Project_01");
    workExperience.addProject("Project_02");
    workExperience.setRole("Engineer");
    workExperience.setTimeInMonths(26);

    std::string jsonStr = funJsonToString(workExperience.toJsonObject());

    std::cout << "Json:\n" << jsonStr << std::endl;
}


/**
 * 从 json 字符串中解析出数据对象
 */
void testParseObjectFromJsonStr() {
    std::cout << "<-----JsonCPPDemo---->testParseObjectFromJsonStr()--->>" << std::endl;

    const char * jsonStr = "{\n"
            "\t\"CompanyName\" : \"Google\",\n"
            "\t\"ProjectList\" : \n"
            "\t[\n"
            "\t\t\"Project_01\",\n"
            "\t\t\"Project_02\"\n"
            "\t],\n"
            "\t\"Role\" : \"Engineer\",\n"
            "\t\"TimeInMonths\" : 26\n"
            "}";
    WorkExperience * workExperience = new WorkExperience();
    int ret = WorkExperience::CreateFromJsonStr(workExperience, jsonStr);
    if (0 == ret) {
        std::cout << "getCompanyName = " << workExperience->getCompanyName() << std::endl;
        std::cout << "getRole = " << workExperience->getRole() << std::endl;
        std::cout << "getTimeInMonths = " << workExperience->getTimeInMonths() << std::endl;

        vector<std::string> projectList = workExperience->getProjectList();
        for (int i = 0; i < projectList.size(); ++i) {
            std::cout << "project = " << projectList.at(i) << std::endl;
        }
    } else {
        std::cout << "Json parse error! " <<  std::endl;
    }
}


/**
 * 测试将负责对象转成 json 字符串
 */
void testComplexObjectToJsonStr() {
    std::cout << "<-----JsonCPPDemo---->testComplexObjectToJsonStr()--->>" << std::endl;

    WorkerInfo workerInfo;
    workerInfo.setName("Alan");
    workerInfo.setEmail("alanwang4523@gmail.com");
    workerInfo.setAge(27);

    // 添加一个对象
    WorkExperience workExperience_01;
    workExperience_01.setCompanyName("Google");
    workExperience_01.addProject("Project_01");
    workExperience_01.addProject("Project_02");
    workExperience_01.setRole("Engineer");
    workExperience_01.setTimeInMonths(26);
    workerInfo.addExperience(workExperience_01);

    // 添加一个对象
    WorkExperience workExperience_02;
    workExperience_02.setCompanyName("FaceBook");
    workExperience_02.addProject("Project_01");
    workExperience_02.setRole("Leader");
    workExperience_02.setTimeInMonths(20);
    workerInfo.addExperience(workExperience_02);

    std::string jsonStr = funJsonToString(workerInfo.toJsonObject());

    std::cout << "Json:\n" << jsonStr << std::endl;

    /* output:
     {
        "Age" : 27,
        "Email" : "alanwang4523@gmail.com",
        "ExperienceList" :
        [
            {
                "CompanyName" : "Google",
                "ProjectList" :
                [
                    "Project_01",
                    "Project_02"
                ],
                "Role" : "Engineer",
                "TimeInMonths" : 26
            },
            {
                "CompanyName" : "FaceBook",
                "ProjectList" :
                [
                    "Project_01"
                ],
                "Role" : "Leader",
                "TimeInMonths" : 20
            }
        ],
        "Name" : "Alan"
    }

     */
}