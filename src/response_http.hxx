#ifndef response_http_hxx
#define response_http_hxx

#pragma once

#include "status_code.hxx"
#include "html_content.hxx"
#include "headers_http.hxx"

struct ResponseHttp
{
    static std::string callback() {

        std::string callback;
        callback.append(StatusCode::K200OK());
        callback.append(HTML::Render("index.html"));

        return callback;
    }
};


#endif