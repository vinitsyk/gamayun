#ifndef status_code_hxx
#define status_code_hxx

#pragma once
#include <string>

struct StatusCode
{
    static std::string K200OK()
    {
        return std::string ("HTTP/3 200 OK\r\nContent-Type: text/html\r\n\r\n");
    }
};


#endif