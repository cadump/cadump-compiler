#ifndef CADUMP_SRC_IMPORTER_H_
#define CADUMP_SRC_IMPORTER_H_

#include <fstream>
#include <string>
#include <vector>

#include "../lib/namedfstream.hpp"

//This class creates instance of itself for every file importing
//Then searches the file for 'import' keywords and uses them for creating for recursive importing
//TODO: make array of every file that is being imported and search them first before creating another instance

class Importer
{
  // This is master file THE MASTER OF ALL
  // And the return object of this abomination
  // Also like everything in life, it's temporary
  struct
  {
    CadumpLibs::NamedFstream* rw;
    CadumpLibs::NamedFstream* r;

    std::string path;
  } master_file_;

  // Struct for easier manipulation within this class
  struct
  {
    std::string import_name;
    // This is telling satisfy_import_scope() how to satisfy it
    // Oh god, that sounds weird
    enum { local, global, url } mode;
  }typedef ImportEntry;

  // I need to save destination object string so I made this
  // To make it easier on myself
  class ImportList : public std::vector<ImportEntry>
  {
    public:
      std::string destination_object;
  };

  // File that the creator of this class provides (basically the file to process)
  CadumpLibs::NamedFstream* entry_file_;

  // Magic stuff, don't even try to implement it
  // I hope some hobits will do this for me
  // Should find the whole import
  // All the multi line [] and stuff, you name it
  std::string get_whole_import_command(std::string import_keyword_line);

  // From the magically retrieved import command create a bunch of import entries
  // Do I really need to explain it?
  ImportList parse_imports(std::string import_command);

  // This class searches for the files that should be imported and returns their full path
  // Or some magit to prioritize some source over the other by the import entry mode
  ImportEntry satisfy_import_scope(ImportEntry import_entry);

  // This method should:
  // Loook into an static array, get the index of import layer
  // Spawn if the file can't be found in deeper layer
  // Else return pointer to existing import specified in the array
  // this method probably will:
  // Just spawn new import
  CadumpLibs::NamedFstream* spawn_if_doesnt_exist(ImportEntry import_entry);

  // Merge more filestreams so they can live hapily ever after
  std::string merge_filestreams (std::vector<CadumpLibs::NamedFstream*> filestreams, std::string separator);

 public:
  // The beaty of birth
  // Of a new class
  Importer(CadumpLibs::NamedFstream* entry_file);

  // Do the work and return the result
  CadumpLibs::NamedFstream* import();

  // The fear of death is real here
  ~Importer();
};

#endif
