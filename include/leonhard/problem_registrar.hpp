#ifndef _LEONHARD_PROBLEM_REGISTRAR_HPP_
#define _LEONHARD_PROBLEM_REGISTRAR_HPP_

#include <leonhard/problem.hpp>

#include <memory>

namespace leonhard {

class
problem_registrar
{
public:
    problem_registrar(problem_ptr p);
};

}

#define LEONHARD_REGISTER_PROBLEM(T) \
    static leonhard::problem_registrar leonhard_problem_registrar_##T(std::make_shared<T>());

#endif // _LEONHARD_PROBLEM_REGISTRAR_HPP_

// vim:set sw=4 ts=4 et:
