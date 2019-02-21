#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
  if (argc > 0)
  {
    //This expects that first argument is entry point file name
    //TODO change it for more robust checking
    std::ifstream entry_file(argv[0]);

    for( int param_index = 0; param_index < argc; param_index ++)
    {
      char* opt = argv[param_index];
      //TODO: make struct for translating long flags to short flags
    }
  }
}
