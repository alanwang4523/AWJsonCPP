# JsonCPPDemo
A demo of jsoncpp


### 包含以下测试，详情及测试代码情况 main.cpp：
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

### 参考：
[jsoncpp](https://github.com/open-source-parsers/jsoncpp) 
