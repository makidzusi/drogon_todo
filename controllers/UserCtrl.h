#pragma once

#include <drogon/HttpController.h>
#include "Products.h"

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::test;


namespace demo
{

class Aboba : public drogon::HttpController<Aboba>
{
  public:
    METHOD_LIST_BEGIN
    // use METHOD_ADD to add your custom processing function here;
    METHOD_ADD(Aboba::login,"/token?userId={1}&passwd={2}",Post);
    METHOD_ADD(Aboba::getInfo,"/{1}/info?token={2}",Get);
    METHOD_ADD(Aboba::hello, "/hello", Get);
    METHOD_LIST_END
    // your declaration of processing function maybe like this:
    void login(const HttpRequestPtr &req,
               std::function<void (const HttpResponsePtr &)> &&callback,
               std::string &&userId,
               const std::string &password);
    void getInfo(const HttpRequestPtr &req,
                 std::function<void (const HttpResponsePtr &)> &&callback,
                 std::string userId,
                 const std::string &token) const;
    void hello(const HttpRequestPtr &req,
               std::function<void (const HttpResponsePtr &)> &&callback) const;
               
    // orm::DbClientPtr getDbClient() 
    // {
    //     return drogon::app().getDbClient("default");
    // }
};
}