#include <leonhard/problems_container.hpp>

using namespace leonhard;

void
problems_container::register_problem(problem_ptr p)
{
    problems_container::instance()[p->number()] = p;
}

problems_container::problems_container()
{
}

problems_container &
problems_container::instance()
{
    static problems_container instance;
    return instance;
}

// vim:set sw=4 ts=4 et:
