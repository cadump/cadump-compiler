#ifndef CADUMP_IMPORTER
#define CADUMP_IMPORTER

#include <fstream>
//This class creates instance of itself for every file importing
//Then searches the file for 'import' keywords and uses them for creating for recursive importing
//TODO: make array of every file that is being imported and search them first before creating another instance

class Importer
{
  //This file is used for satisfying all the imports and inserting them into one file, later returned
  std::fstream* master_file;

  //This class searches for the files that should be imported and returns their full path
  //TODO: substitute relative paths to importing files to absolute paths (in case of multiple imports with same names)
  char* satisfy_import_scope(char* file_name, char mode); //Modes are l (for local) and g (for global)

public:
  Importer(std::ifstream* entry_file);

  ~Importer();
};

#endif
