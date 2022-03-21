/*
** EPITECH PROJECT, 2021
** Error.hpp
** File description:
** header file for the Error class
*/

#ifndef _ERROR_H_
#define _ERROR_H_

namespace Arcade {

    /**
     ** \class Error
     ** The purpose of this class is to make error management
     ** more clear. Just like we did in the paradigm pool.
     **/
    class Error
    {
    public:
        Error(void); ///< default constructor
        Error(const std::string &error, const std::string &location); ///< parameterized constructor
        ///< @param error : description of the error that occured
        ///< @param location : the location where the error occured
        virtual ~Error(void); ///< destructor
        const char *what(void) const noexcept override; ///< function returning which error occured
        ///< @return c-style string containing the error description
        const std::string where(void) const; ///< function returning where the error occured
        ///< @return c-style string containing the error's location
    private:
        std::string errorMessage;
        std::string errorLocation;
    };

}

#endif
