#ifndef CADUMP_IMPORTER
#define CADUMP_IMPORTER

#include <fstream>
//This class creates instance of itself for every file importing
//Then searches the file for 'import' keywords and uses them for creating for recursive importing
//TODO: make array of every file importing and search them first before creating another instance

class Importer
{
  std::fstream master_file;

  //TODO: substitute relative paths to importing files to absolute paths (in case of multiple imports with same names)
  char* satisfy_import_scope();

public:
  Importer(std::ifstream* entry_file);

  ~Importer();
};

#endif
