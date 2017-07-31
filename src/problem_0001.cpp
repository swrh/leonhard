#include <leonhard/problem.hpp>
#include <leonhard/problem_registrar.hpp>

using namespace leonhard;

class
problem_0001
: public problem
{
public:
    unsigned int
    number() const override
    {
        return 1;
    }

protected:
    void
    solve() override
    {
        unsigned int sum = 0;

        for (unsigned int i = 0; i < 1000; i++) {
            if ((i % 3) == 0 || (i % 5) == 0)
                sum += i;
        }

        out() << sum;
    }

    void
    answer() override
    {
        out() << 233168;
    }
};

LEONHARD_REGISTER_PROBLEM(problem_0001)

// vim:set sw=4 ts=4 et:
