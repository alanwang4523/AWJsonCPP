#include <iostream>

#include "json.h"

void testParseJsonStr();

int main() {
    std::cout << "<-----JsonCPPDemo---->" << std::endl;

    testParseJsonStr();

    return 0;
}

void testParseJsonStr() {
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