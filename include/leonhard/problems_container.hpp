#ifndef _LEONHARD_PROBLEMS_CONTAINER_HPP_
#define _LEONHARD_PROBLEMS_CONTAINER_HPP_

#include <map>

#include <leonhard/problem.hpp>

namespace leonhard {

class
problems_container
: public std::map<int, problem_ptr>
{
public:
    static void register_problem(problem_ptr p);

private:
    problems_container();

public:
    static problems_container &instance();
};

}

#endif // _LEONHARD_PROBLEMS_CONTAINER_HPP_

// vim:set sw=4 ts=4 et:
