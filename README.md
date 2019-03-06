## JsonCPPDemo

### A demo of jsoncpp



#### 包含以下测试，详情及测试代码情况 main.cpp：

```c++
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

/**
 * 测试从 json 字符串中解析出复杂的数据对象
 */
void testParseComplexObjectFromJsonStr();
```

**将对象转成 Json::Value**
```c++
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
```


**将 json string 转成 C++ 类对象**
```c++
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
```

### 参考：


[jsoncpp](https://github.com/open-source-parsers/jsoncpp) 
