//
//  tokenizer.h
//  dsahw3
//
//  Created by WILLIAM on 4/21/14.
//  Copyright (c) 2014 吳瑞洋公司. All rights reserved.
//

#ifndef dsahw3_tokenizer_h
#define dsahw3_tokenizer_h

#pragma once

#include <fstream>
#include <string>

class Tokenizer {
    std::istream& input;
    std::string next_token;
    std::string token_buf;
    std::string::const_iterator cur, end;
    bool is_eof;
    
    void fillToken();
public:
    /*
     @param input_stream: the input of the tokenizer
     @description:
     create a tokenizer that takes the input from
     `input_stream`. `input_stream` should be alive
     through the lifetime of the Tokenizer.
     */
    Tokenizer(std::istream& input_stream)
    : input(input_stream), is_eof(false)
    {
        this->cur = token_buf.cend();
        this->end = token_buf.cend();
    }
    
    /*
     @description: return if there are any tokens
     */
    bool hasMore();
    
    /*
     @description:
     remove the next token from the buffer and return it
     */
    std::string nextToken();
};


#endif
