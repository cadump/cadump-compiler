#include "importer.hpp"

#include "../lib/namedfstream.hpp"

//PRIVATE METHODS

std::string
Importer::merge_filestreams(std::vector<CadumpLibs::NamedFstream *> filestreams,
                            std::string separator) {
  std::string return_string = "";
  for (int i = 0; i < filestreams.size(); i++) {
    // Get lenght of the file
    filestreams[i]->seekg(0, filestreams[i]->end);
    int lenght = filestreams[i]->tellg();
    filestreams[i]->seekg(0, filestreams[i]->beg);

    char read_block[lenght];
    filestreams[i]->read(read_block, lenght);

    if ( i < filestreams.size() - 1)
      return_string += read_block + separator;
    else
      return_string += read_block;
  }

  return return_string;
}

//PUBLIC METHODS

Importer::Importer(CadumpLibs::NamedFstream *entry_file) {
  // TODO: add this when async
  // std::hash<std::thread::id>{}(std::this_thread::get_id()) generate truly
  // unique file name based on pseudorandom number
  master_file_.path = "./temp/temp" + std::to_string(rand());

  master_file_.rw = new CadumpLibs::NamedFstream(
      master_file_.path.c_str(), std::fstream::in | std::fstream::out);

  this->entry_file_ = entry_file;
}

CadumpLibs::NamedFstream *Importer::import() {
  while (!entry_file_->eof()) {
    char line_char[500];
    entry_file_->getline(line_char, 500);
    std::string line(line_char);

    if (line.find("import") != std::string::npos) {
      std::string import_command = get_whole_import_command(line);

      ImportList import_list;

      std::vector<CadumpLibs::NamedFstream *> child_import_list = {};

      if (!import_command.empty()) {
        import_list = parse_imports(import_command);

        for (uint i = 0; i < import_list.size(); i++) {
          import_list.at(i) = satisfy_import_scope(import_list.at(i));

          child_import_list.push_back(spawn_if_doesnt_exist(import_list.at(i)));
        }

        write_to_master_file(merge_filestreams(child_import_list, "\n"));
      }
    }

    master_file_.rw->close();
    master_file_.r = new CadumpLibs::NamedFstream(master_file_.path.c_str(),
                                                  std::fstream::in);
    return master_file_.r;
  }
  return NULL;
}

Importer::~Importer() {
  master_file_.rw->close();
  master_file_.r->close();
  delete[] & master_file_.path;
}
