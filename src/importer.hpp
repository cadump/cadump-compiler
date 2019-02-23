#ifndef CADUMP_SRC_IMPORTER_H_
#define CADUMP_SRC_IMPORTER_H_

#include <fstream>
#include <string>
#include <vector>
#include <thread>
#include <future>

#include "../lib/namedfstream.hpp"

//This class creates instance of itself for every file importing
//Then searches the file for 'import' keywords and uses them for creating for recursive importing
//TODO: make array of every file that is being imported and search them first before creating another instance

class Importer
{
  struct
  {
    CadumpLibs::NamedFstream* rw;
    CadumpLibs::NamedFstream* r;

    std::string path;
  } master_file_;

  struct
  {
    std::string import_name;
    char mode;
  }typedef ImportEntry;

  CadumpLibs::NamedFstream* entry_file_;

  std::string get_next_import_command();

  std::vector<ImportEntry>* parse_imports(std::string import_command);

  //This class searches for the files that should be imported and returns their full path
  //TODO: substitute relative paths to importing files to absolute paths (in case of multiple imports with same names)
  std::string satisfy_import_scope(ImportEntry import_entry);

  CadumpLibs::NamedFstream* spawn_if_doesnt_exist();

public:
  Importer(CadumpLibs::NamedFstream* entry_file);

  CadumpLibs::NamedFstream* import();

  ~Importer();
};

#endif
