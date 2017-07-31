#ifndef _LEONHARD_PROBLEMS_DESCRIPTIONS_HPP_
#define _LEONHARD_PROBLEMS_DESCRIPTIONS_HPP_

#include <map>
#include <string>

namespace leonhard {

class
problems_descriptions
: protected std::map<unsigned int, std::string>
{
public:
    const std::string invalid;

private:
    problems_descriptions();

public:
    static const std::string &describe(unsigned int number);
    static problems_descriptions &instance();
};

}

#endif // _LEONHARD_PROBLEMS_DESCRIPTIONS_HPP_

// vim:set sw=4 ts=4 et:
