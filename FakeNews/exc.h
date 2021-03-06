#pragma once

// This file contains various exceptions for use within this program.

// #################################################################################################
// # NOTE: THIS FILE HAS BEEN USED IN A PREVIOUS ASSIGNMENT CMP2090M-1718 - OBJECT-ORIENTED        #
// #       PROGRAMMING ITEM 1, BY ETHAN ANSELL ANS15595025.                                        #
// #       IT HAS HAD ONLY MINOR MODIFICATIONS HERE.                                               #
// #################################################################################################

#include <string>

namespace fakenews
{

namespace exc
{

class exception
// An abstract exception type. Any exception thrown by us should derive from this. Any exceptions
// which make it to main() uncaught, and do not derive from this, are a bug. This exception should
// NOT be thrown, only caught.
{
    public:
    exception(const std::string& what) : _what(what) { }
    const std::string& what() const { return _what; }

    protected:
    std::string _what;
};

class unimplemented : public exception
// To throw when something is not yet implemented. This should act as a placeholder while building
// the program and should not be thrown in any release version.
{
    public:
    // Prepends 'UNIMPLEMENTED: ' to `what` so that messages are clearer when printed.
    unimplemented(const std::string& what) : exception(std::string("UNIMPLEMENTED: ") + what) { }
};

class file : public exception
// To throw when some kind of file operation has failed.
{
    public:
    file(const std::string& what) : exception(what) { }
};

}

}