#include <iostream>

#include <boost/program_options/errors.hpp>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
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
        ("list,l", "list all problems available")
        ;

    program_options::variables_map vm;

    try {
        program_options::store(program_options::parse_command_line(argc, argv, desc), vm);
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

    if (vm.count("list")) {
        for (auto &kv : problems) {
            cout << kv.first << endl;
        }
    } else {
        cerr << __progname << ": missing command argument" << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

// vim:set sw=4 ts=4 et:
