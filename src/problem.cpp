#include <leonhard/problem.hpp>

using namespace std;

using namespace leonhard;

problem::problem()
{
}

ostream &
problem::out()
{
    out_buffer.str("");
    return out_buffer;
}

const string &
problem::get_solution()
{
    if (!solution_cache_flag) {
        out();
        solve();
        solution_cache = out_buffer.str();
        solution_cache_flag = true;
    }
    return solution_cache;
}

const string &
problem::get_answer()
{
    if (!answer_cache_flag) {
        out();
        answer();
        answer_cache = out_buffer.str();
        answer_cache_flag = true;
    }
    return answer_cache;
}

// vim:set sw=4 ts=4 et:
