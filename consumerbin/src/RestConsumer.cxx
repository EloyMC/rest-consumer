// Copyright 2018 Uncle Ben

#include <curl/curl.h>
#include <string>
#include <iostream>
#include "../include/RestConsumer.h"

RestConsumer::RestConsumer(std::string url): apiUrl(std::move(url)) {}

size_t RestConsumer::requestParser(void *ptr, size_t size, size_t nmemb, void *data) {
    ((std::string*)data)->append(
        reinterpret_cast<char*>(ptr), size * nmemb);
    return size * nmemb;
}

std::string RestConsumer::getRequest(int id = 0) {
    CURL* curl = curl_easy_init();
    CURLcode res;
    std:: string targetUrl = id == 0 ? apiUrl : apiUrl + std::to_string(id);
    std::string request_data;

    
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, targetUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, requestParser);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &request_data);
        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res);
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

    return request_data;
}

// post params: "title=todo02&details=details02&isDone=false"
void RestConsumer::postRequest(std::string params) {
    CURL* curl = curl_easy_init();
    CURLcode res;

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, params.c_str());
        res = curl_easy_perform(curl);
        
        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res);
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

void RestConsumer::deleteRequest(int id) {
    CURL* curl = curl_easy_init();
    CURLcode res;

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, id);
        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res);
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

void RestConsumer::putRequest(std::string params) {
    CURL* curl = curl_easy_init();
    CURLcode res;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, params.c_str());
        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res);
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}