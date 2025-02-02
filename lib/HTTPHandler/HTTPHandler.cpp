#include "HTTPHandler.hpp"

HTTPHandler::HTTPHandler(const String& server_post, const String& server_login, const String& api_username, const String& api_password) :
    server_post(server_post), server_login(server_login), api_username(api_username), api_password(api_password) 
{}

bool HTTPHandler::authenticate()
{
    HTTPClient http;
    http.begin(this->server_login);
    http.addHeader("Content-Type", "application/json");
    
    JsonDocument doc;
    doc["username"] = this->api_username;
    doc["password"] = this->api_password;
    
    String requestBody;
    serializeJson(doc, requestBody);
    int httpResponseCode = http.POST(requestBody);
    
    if (httpResponseCode == 200) {
        String response = http.getString();
        JsonDocument responseDoc;
        deserializeJson(responseDoc, response);
        this->token = responseDoc["token"].as<String>();
        http.end();
        return true;
    }
    
    http.end();
    return false;
}

void HTTPHandler::sendData(double temperature, double humidity, double doseRate) 
{
    if (WiFi.status() == WL_CONNECTED) {
        if (this->token.isEmpty() && !this->authenticate()) {
            return;
        }
        
        HTTPClient http;
        http.begin(this->server_post);
        http.addHeader("Content-Type", "application/json");
        http.addHeader("Authorization", "Bearer " + this->token);
        
        JsonDocument doc;
        doc["temperature"] = temperature;
        doc["humidity"] = humidity;
        doc["dose_rate"] = doseRate;
        
        String requestBody;
        serializeJson(doc, requestBody);
        http.POST(requestBody);
        http.end();
    }
}