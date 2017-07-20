#include <iostream>

#include <boost/program_options.hpp>

extern const char *__progname;

using namespace std;

namespace program_options = boost::program_options;

int
main(int argc, char *argv[])
{
    program_options::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "produce help message")
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

    return EXIT_SUCCESS;
}

// vim:set sw=4 ts=4 et:
