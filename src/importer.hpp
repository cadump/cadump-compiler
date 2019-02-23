#ifndef CADUMP_IMPORTER
#define CADUMP_IMPORTER

#include <fstream>
#include <string>
#include <vector>
//This class creates instance of itself for every file importing
//Then searches the file for 'import' keywords and uses them for creating for recursive importing
//TODO: make array of every file that is being imported and search them first before creating another instance

class Importer
{
  //This file is used for satisfying all the imports and inserting them into one file, later returned
  struct
  {
    std::fstream* rw;
    std::fstream* r;

    std::string path;
  } master_file;

  std::fstream* entry_file;

  std::string find_next_import_command();

  std::vector<std::string>* parse_imports(std::string import_command);

  //This class searches for the files that should be imported and returns their full path
  //TODO: substitute relative paths to importing files to absolute paths (in case of multiple imports with same names)
  std::string satisfy_import_scope(std::string file_name, char mode); //Modes are l (for local) and g (for global)

  std::fstream* spawn_if_doesnt_exist();

public:
  Importer(std::fstream* entry_file);

  std::fstream* import();

  ~Importer();
};

#endif
