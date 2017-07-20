#ifndef _LEONHARD_PROBLEM_HPP_
#define _LEONHARD_PROBLEM_HPP_

#include <memory>
#include <ostream>
#include <sstream>
#include <string>

namespace leonhard {

class
problem
{
public:
    problem();
    virtual ~problem() = default;

private:
    std::string solution_cache, answer_cache;
    bool solution_cache_flag = false, answer_cache_flag = false;

private:
    std::ostringstream out_buffer;
protected:
    std::ostream &out();

public:
    const std::string &get_solution();
    const std::string &get_answer();

public:
    virtual int number() const = 0;

protected:
    virtual void solve() = 0;
    virtual void answer() = 0;
};

typedef std::shared_ptr<problem> problem_ptr;

}

#endif // _LEONHARD_PROBLEM_HPP_

// vim:set sw=4 ts=4 et:
