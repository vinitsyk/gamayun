#ifndef html_content_hxx
#define html_content_hxx

#pragma once

#include <string>
#include <fstream>

struct HTML
{
    static std::string Render(const std::string& filename )
    {
        std::string content;
        std::ifstream file(filename.c_str());

        if( file.is_open() )
        {
            std::string line;
            while (std::getline(file, line))
            {
                content.append(line);
            }

            file.close();
        }

        return content;

    }
};

#endif