// Copyright 2018 Uncle Ben

#ifndef CONSUMERBIN_INCLUDE_RESTCONSUMER_H_
#define CONSUMERBIN_INCLUDE_RESTCONSUMER_H_

#include <string>

class RestConsumer {
    private: std::string apiUrl;
    
    public: static size_t requestParser(void *ptr, size_t size, size_t nmemb, void *data);

    explicit RestConsumer(std::string url);

    std::string getRequest(int id);
   
    void postRequest(std::string params);
    
    void putRequest(std::string params);
    
    void deleteRequest(int id);
};

#endif