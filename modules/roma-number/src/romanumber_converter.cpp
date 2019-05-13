// Copyright 2019 Pinaev Danil

#include "include/romanumber.h"
#include "include/romanumber_converter.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

RomaNumberConverter::RomaNumberConverter() : message_("") {}

std::string RomaNumberConverter::Help(const char* appname) {
    return "This is application for roma number converter.\n"
        "Usage:\n"
        "Enter positive integer arabic or roma number.\n";
}


bool RomaNumberConverter::validateNumberOfArguments(int argc,
	                                         const char** argv) {
    if (argc != 2) {
        return false;
    }

    if (!(converter_.IsArabStringCorrect(argv[1]) ||
        converter_.IsRomaStringCorrect(argv[1])))
        return false;

    return true;
}

std::string parseRoma(const char* arg) { return std::string(arg); }

int parseArab(const char* arg) { return atoi(arg); }

std::string RomaNumberConverter::operator()(int argc, const char** argv) {
    RomaNumber converter;
    std::ostringstream stream;

    if (!validateNumberOfArguments(argc, argv)) {
        return Help("");
    }

    if (converter.IsArabStringCorrect(argv[1])) {
        try {
            converter.ArabToRoma(atoi(argv[1]));
        }
        catch (std::string& str) {
            return str;
        }
        stream << "Roma number is " << converter.GetRoma() << std::endl;
    } else if (converter.IsRomaStringCorrect(argv[1])) {
        try {
            converter.RomaToArab(std::string(argv[1]));
        }
        catch (std::string& str) {
            return str;
        }
        stream << "Arabic number is " << converter.GetArabic() << std::endl;
    }
    message_ = stream.str();

    return message_;
}