#include "importer.hpp"

#include "../lib/namedfstream.hpp"

// PRIVATE METHODS

std::string
Importer::merge_filestreams(std::vector<CadumpLibs::NamedFstream *> filestreams,
                            std::string separator) {
  std::string return_string = "";
  for (int i = 0; i < filestreams.size(); i++) {

    // Get lenght of the file, because C++ is just too optimized
    filestreams[i]->seekg(0, filestreams[i]->end);
    int lenght = filestreams[i]->tellg();
    filestreams[i]->seekg(0, filestreams[i]->beg);

    // Get the filestream contents and put them into a char array
    char read_block[lenght];
    filestreams[i]->read(read_block, lenght);

    // Add separator only if it is not the last filestream
    if (i < filestreams.size() - 1)
      return_string += read_block + separator;
    else
      return_string += read_block;
  }

  return return_string;
}

// PUBLIC METHODS

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
  // Read the file until it's end
  while (!entry_file_->eof()) {
    // Read one line of the filestream in max lenght of 500 chars
    char line_char[500];
    entry_file_->getline(line_char, 500);
    std::string line(line_char);

    // If the line contans 'import' do some magic
    if (line.find("import") != std::string::npos) {
      // Magic method that finds the whole command with all the brackets and
      // stuff
      std::string import_command = get_whole_import_command(line);

      // This is array of entries for importing
      ImportList import_list;

      // This is array of filestreams returned by the child Import.import()
      std::vector<CadumpLibs::NamedFstream *> child_import_list = {};

      // Parse the import entries from the whole import command
      import_list = parse_imports(import_command);

      // Just run this bazillion times to iterate all the entries
      for (uint i = 0; i < import_list.size(); i++) {
	// Search the file (specified in the entries themself)
        import_list.at(i) = satisfy_import_scope(import_list.at(i));

	// Add new filestream of the child import if doesn't exist
	// If in a deeper layer just get it's pointer
        child_import_list.push_back(spawn_if_doesnt_exist(import_list.at(i)));
      }

      // Merge all the filestreams and add linebreak between them
      std::string data_to_write = merge_filestreams(child_import_list, "\n");

      // Write the data to the master file
      master_file_.rw->write(data_to_write.c_str(), data_to_write.length());
    }

    // Close the rw filestream and open it only for reads before returning it
    master_file_.rw->close();
    master_file_.r = new CadumpLibs::NamedFstream(master_file_.path.c_str(),
                                                  std::fstream::in);
    return master_file_.r;
  }
  return entry_file_;
}

Importer::~Importer() {
  //We don't want memory leaks do we?
  // No
  // We don't
  // So that's why this is here
  master_file_.rw->close();
  master_file_.r->close();
  delete[] & master_file_.path;
}
