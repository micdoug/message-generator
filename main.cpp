#include "boost/program_options.hpp"

#include <iostream>
#include <string>
#include "UniformRandom.h"
#include "MessageEvent.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

namespace po = boost::program_options;

namespace
{
    const size_t ERROR_IN_COMMAND_LINE = 1;
    const size_t SUCCESS = 0;
    const size_t ERROR_UNHANDLED_EXCEPTION = 2;

} // namespace

/*!
 * Show the help message with parameter options.
*/
size_t showHelp(po::options_description desc)
{
    std::cout << "message generator parameters:" << std::endl
              << desc << std::endl;
    return SUCCESS;
}


int main(int argc, const char** argv)
{
    try
    {
        /** Define and parse the program options
        */

        po::options_description desc("Options");
        desc.add_options()
                ("help", "Print help messages")
                ("msgs,m", po::value<int>(), "Number of messages per period")
                ("period,p", po::value<int>(), "Period of message generation in seconds")
                ("minsize", po::value<int>(), "Minimum size of the messages in bytes")
                ("maxsize", po::value<int>(), "Maximum size of the messages in bytes")
                ("nodes", po::value<int>(), "Number of nodes in the simulation")
                ("duration", po::value<int>(), "The duration of the simulation in seconds")
                ("warmup", po::value<int>()->default_value(0), "The warmup period in seconds. In this period messages won't be generated")
                ("seed", po::value<int>(), "Seed for random number generation");

        po::positional_options_description p;
        //p.add("trace", -1);
        po::variables_map vm;
        try
        {
            po::store(po::command_line_parser(argc, argv).options(desc).positional(p).run(),
                      vm); // can throw

            /** --help option
            */
            if (vm.count("help"))
            {
                return showHelp(desc);
            }

            po::notify(vm); // throws on error, so do after help in case
            // there are any problems
        }
        catch(po::error& e)
        {
            std::cerr << "ERROR: " << e.what() << std::endl << std::endl;
            std::cerr << desc << std::endl;
            return ERROR_IN_COMMAND_LINE;
        }

        if (vm.count("msgs") != 1) {
            cout << "You need to pass the number of messages per period" << endl;
            return showHelp(desc);
        }
        if (!vm.count("period")) {
            cout << "You need to pass the period of messages generation" << endl;
            return showHelp(desc);
        }
        if (!vm.count("minsize")) {
            cout << "You need to pass the minimum size of the messages" << endl;
            return showHelp(desc);
        }
        if (!vm.count("maxsize")) {
            cout << "You need to pass the maximum size of the messages" << endl;
            return showHelp(desc);
        }
        if (!vm.count("nodes")) {
            cout << "You need to pass the number of nodes" << endl;
            return showHelp(desc);
        }
        if (!vm.count("duration")) {
            cout << "You need to pass the duration" << endl;
            return showHelp(desc);
        }
        if (!vm.count("seed")) {
            cout << "You need to pass the seed" << endl;
            return showHelp(desc);
        }

        int msgs = vm["msgs"].as<int>();
        int period = vm["period"].as<int>();
        int minsize = vm["minsize"].as<int>();
        int maxsize = vm["maxsize"].as<int>();
        int nodes = vm["nodes"].as<int>();
        int duration = vm["duration"].as<int>();
        int seed = vm["seed"].as<int>();
        int warmup = vm["warmup"].as<int>();

        UniformRandom randomNodes(seed, 0, nodes-1);
        UniformRandom randomSize(seed, minsize, maxsize);

        for (int time = warmup; time <= duration; time+=period) {
            int remaining = msgs;
            while (remaining) {
                MessageEvent msge;
                // Sorteia uma origem e um destino
                msge.setOrigin(randomNodes.next());
                msge.setDestiny(randomNodes.next());
                if (msge.getOrigin() == msge.getDestiny()) {
                    continue;
                }

                // Sorteia um tamanho de mensagem
                msge.setSize(randomSize.next());

                // Ajusta o tempo
                msge.setTime(time);

                cout << msge;
                --remaining;
            }
        }



//        std::string temp;
//        getline(cin, temp);

    }
    catch(std::exception& e)
    {
        std::cerr << "Unhandled Exception reached the top of main: "
                  << e.what() << ", application will now exit" << std::endl;
        return ERROR_UNHANDLED_EXCEPTION;

    }

    return SUCCESS;

} // main