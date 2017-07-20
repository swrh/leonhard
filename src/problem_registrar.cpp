#include <leonhard/problem_registrar.hpp>

#include <leonhard/problems_container.hpp>

using namespace leonhard;

problem_registrar::problem_registrar(problem_ptr p)
{
    problems_container::register_problem(p);
}

// vim:set sw=4 ts=4 et:
