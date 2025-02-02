#ifndef HTTP_HANDLER_HPP
#define HTTP_HANDLER_HPP

#include <HTTPClient.h>
#include <ArduinoJson.h>

class HTTPHandler 
{
private:
    String server_post = "";
    String server_login = "";
    String api_username = "";
    String api_password = "";
    String token;
    bool authenticate();
public:
    HTTPHandler(const String& server_post, const String& server_login, const String& api_username, const String& api_password);
    void sendData(double temperature, double humidity, double doseRate);
};

#endif