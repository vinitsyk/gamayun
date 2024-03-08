#ifndef headers_http_hxx
#define headers_http_hxx

#pragma once

#include <string>

struct Headers {

    static std::string DefaultHeaders()
    {
        return std::string("GET / HTTP/3 \r\nAccept: text/html\r\n");

    }
};

#endif