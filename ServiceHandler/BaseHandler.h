/*
* File: BaseHandler.h
* Author: trung.la
* Date: 01-15-2025
* Description: Implementation for Base Handler
*/

#ifndef BASE_HANDLER_H
#define BASE_HANDLER_H

class BaseHandler
{
public:
    BaseHandler() = default;
    virtual ~BaseHandler() = default;

    BaseHandler(const BaseHandler&) = delete;
    BaseHandler& operator=(const BaseHandler&) = delete;
    BaseHandler(BaseHandler&&) = delete;
    BaseHandler& operator=(BaseHandler&&) = delete;
};

#endif // BASE_HANDLER_H