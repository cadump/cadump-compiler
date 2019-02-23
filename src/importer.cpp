#include "importer.hpp"

#include "../lib/namedfstream.hpp"

Importer::Importer(CadumpLibs::NamedFstream* entry_file)
{
  //generate truly unique file name based on hash of the current thread_id and pseudorandom number
  master_file_.path = "./temp/temp" + std::to_string(std::hash<std::thread::id>{}(std::this_thread::get_id()) + rand());

  master_file_.rw = new CadumpLibs::NamedFstream(master_file_.path.c_str(), std::fstream::in | std::fstream::out);

  this->entry_file_ = entry_file;
}

CadumpLibs::NamedFstream* Importer::import()
{
  while(!entry_file_->eof())
  {
    std::vector<ImportEntry>* imports = NULL;

    std::string import_command = get_next_import_command();

    if (!import_command.empty())
    {
      imports = parse_imports(import_command);

      for(uint i = 0; i < imports->size(); i++)
      {
        imports->at(i).import_name = satisfy_import_scope(imports->at(i));

        //TODO: acturally maybe call the function and parse the results
        std::async(std::launch::async, spawn_if_doesnt_exist());
      }
    }
  }

  master_file_.rw->close();
  master_file_.r  = new CadumpLibs::NamedFstream(master_file_.path.c_str(), std::fstream::in);
  return master_file_.r;
}

Importer::~Importer()
{
  master_file_.rw->close();
  master_file_.r->close();
  delete[] &master_file_.path;
}
