#include <iostream>
#include <fstream>
#include <ctime>

#include "../lib/namedfstream.hpp"

int main(int argc, char** argv)
{
  //Initialize seed for truly unique numbers for file names
  srand(time(NULL));

  if (argc > 0)
  {
    //This expects that first argument is entry point file name
    //TODO change it for more robust checking
    CadumpLibs::NamedFstream* entry_file(argv[0], std::ios_base::in);

    for( int param_index = 0; param_index < argc; param_index ++)
    {
      char* opt = argv[param_index];
      //TODO: make struct for translating long flags to short flags
    }
  }
}
