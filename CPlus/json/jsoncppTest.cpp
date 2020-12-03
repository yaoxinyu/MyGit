#include "jsoncppTest.h"
#include "json/json.h"
#include <iostream>
#include <fstream>

int readFromString()
{
    const std::string rawJson = R"({"Age": 20, "Name": "colin"})";
    const auto rawJsonLength = static_cast<int>(rawJson.length());
    JSONCPP_STRING err;
    Json::Value root;

    Json::CharReaderBuilder builder;
    const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
    if (!reader->parse(rawJson.c_str(), rawJson.c_str() + rawJsonLength, &root,
        &err)) {
        std::cout << "error" << std::endl;
        return EXIT_FAILURE;
    }
    const std::string name = root["Name"].asString();
    const int age = root["Age"].asInt();

    std::cout << name << std::endl;
    std::cout << age << std::endl;

    return 0;
}

int readFromStream()
{
    //Json::Value root;
    //std::ifstream ifs;
    //ifs.open(argv[1]);

    //Json::CharReaderBuilder builder;
    //builder["collectComments"] = true;
    //JSONCPP_STRING errs;
    //if (!parseFromStream(builder, ifs, &root, &errs)) {
    //    std::cout << errs << std::endl;
    //    return EXIT_FAILURE;
    //}
    //std::cout << root << std::endl;

    return EXIT_SUCCESS;
}

int writeStream() 
{
    Json::Value root;
    Json::StreamWriterBuilder builder;
    const std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());

    root["Name"] = "robin";
    root["Age"] = 20;
    writer->write(root, &std::cout);

    return EXIT_SUCCESS;
}

int writeString()
{
    Json::Value root;
    Json::Value data;
    constexpr bool shouldUseOldWay = false;
    root["action"] = "run";
    data["number"] = 1;
    root["data"] = data;

    Json::StreamWriterBuilder builder;
    const std::string json_file = Json::writeString(builder, root);
    std::cout << json_file << std::endl;

    return EXIT_SUCCESS;
}