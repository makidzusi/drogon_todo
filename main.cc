#include <drogon/drogon.h>
using namespace drogon;

void indexHandler(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback) {
    // Формируем JSON-объект
    Json::Value jsonBody;
    jsonBody["message"] = "Hello, world";

    // Формируем и отправляем ответ с JSON-объектом
    auto response = HttpResponse::newHttpJsonResponse(jsonBody);
    callback(response);
}

int main() {
    //Set HTTP listener address and port
    drogon::app().addListener("0.0.0.0",80);
    //Load config file
    //drogon::app().loadConfigFile("../config.json");
    //Run HTTP framework,the method will block in the internal event loop
    drogon::app().registerHandler("/", &indexHandler, {drogon::Get});
    drogon::app().run();
    return 0;
}
