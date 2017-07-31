#include <iostream>
#include <string>
#include <vector>

#include <boost/program_options/errors.hpp>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/positional_options.hpp>
#include <boost/program_options/variables_map.hpp>

#include <leonhard/problems_container.hpp>

using namespace std;

namespace program_options = boost::program_options;

using namespace leonhard;

extern const char *__progname;

int
main(int argc, char *argv[])
{
    program_options::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "produce help message")
        ("number,n", program_options::value<vector<unsigned int>>()->composing(), "the problems numbers")
        ;

    program_options::options_description commands("Commands");
    commands.add_options()
        ("list,l", "list all implemented problems")
        ("solve,s", "solve one or more problems")
        ;

    desc.add(commands);

    program_options::positional_options_description p;
    p.add("number", -1);

    program_options::variables_map vm;

    try {
        program_options::store(program_options::command_line_parser(argc, argv).options(desc).positional(p).run(), vm);
    } catch (program_options::error &e) {
        cerr << __progname << ": " << e.what() << endl;
        return EXIT_FAILURE;
    }

    program_options::notify(vm);

    if (vm.count("help")) {
        cout << desc << endl;
        return EXIT_SUCCESS;
    }

    problems_container &problems = problems_container::instance();

    vector<unsigned int> numbers;
    if (vm.count("number"))
        numbers = vm["number"].as<vector<unsigned int>>();

    if (vm.count("list")) {
        for (const auto &kv : problems) {
            cout << kv.first << "\t" << kv.second->get_description() << endl;
        }
    } else if (vm.count("solve")) {
        for (unsigned int n : numbers) {
            auto it = problems.find(n);
            if (it == problems.end()) {
                cerr << __progname << ": " << n << ": problem not implemented" << endl;
                return EXIT_FAILURE;
            }
            cout << it->second->get_solution() << endl;
        }
    } else {
        cerr << __progname << ": missing command argument" << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

// vim:set sw=4 ts=4 et:
