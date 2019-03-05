#include <iostream>
#include <sstream>

#include "json.h"

void testParseJsonStr();

void testGenerateJsonStr();

int main() {
    std::cout << "<-----JsonCPPDemo---->" << std::endl;

    testParseJsonStr();
    testGenerateJsonStr();

    return 0;
}

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

    Json::StreamWriterBuilder writerBuilder;
    Json::StreamWriter * streamWriter = writerBuilder.newStreamWriter();
    std::ostringstream os;

    streamWriter->write(jsonObjRoot, &os);
    std::string jsonStr = os.str();

    std::cout << "Generate Json:\n" << jsonStr << std::endl;
}