#include "UserCtrl.h"
#include "Products.h"
using namespace drogon::orm;
using namespace drogon_model::test;
using namespace demo;

// Add definition of your processing function here

void Aboba::login(const HttpRequestPtr &req,
                 std::function<void (const HttpResponsePtr &)> &&callback,
                 std::string &&userId,
                 const std::string &password)
{
    LOG_DEBUG<<"User "<<userId<<" login";

    //Authentication algorithm, read database, verify, identify, etc...
    //...
    Json::Value ret;
    ret["result"]="ok";
    ret["token"]=drogon::utils::getUuid();
    auto resp=HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

void Aboba::hello(const HttpRequestPtr &req,
                   std::function<void (const HttpResponsePtr &)> &&callback) const
{
    LOG_DEBUG<<"Hello,world !";
    Json::Value ret;
    auto clientPtr = drogon::app().getDbClient();
    Mapper<Products> mp(clientPtr);
    auto products = mp.findAll();
    

    for (auto &obj : products) {
        ret.append(obj.toJson());

    }
    
    // auto dbClientPtr = getDbClient();
    // drogon::orm::Mapper<Products> mapper(dbClientPtr);
    // LOG_DEBUG<< products;

    // ret["result"]=  "ok";
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}
void Aboba::getInfo(const HttpRequestPtr &req,
                   std::function<void (const HttpResponsePtr &)> &&callback,
                   std::string userId,
                   const std::string &token) const
{
    LOG_DEBUG<<"User "<<userId<<" get his information";

    //Verify the validity of the token, etc.
    //Read the database or cache to get user information
    Json::Value ret;
    ret["result"]="ok";
    ret["user_name"]="Jack";
    ret["user_id"]=userId;
    ret["gender"]=1;
    auto resp=HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}