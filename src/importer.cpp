#include "importer.hpp"

#include "../lib/namedfstream.hpp"

Importer::Importer(CadumpLibs::NamedFstream* entry_file)
{
  //TODO: add this when async std::hash<std::thread::id>{}(std::this_thread::get_id())
  //generate truly unique file name based on pseudorandom number
  master_file_.path = "./temp/temp" + std::to_string(rand());

  master_file_.rw = new CadumpLibs::NamedFstream(master_file_.path.c_str(), std::fstream::in | std::fstream::out);

  this->entry_file_ = entry_file;
}

CadumpLibs::NamedFstream* Importer::import()
{
  //NOT WORKING TODO RETHINK HOW THIS SHOULD WORK
  while(!entry_file_->eof())
  {
    std::string import_command = get_next_import_command();

    ImportList import_list;

    std::vector<CadumpLibs::NamedFstream*> child_import_list = {};

    if (!import_command.empty())
    {
      import_list = parse_imports(import_command);

      for(uint i = 0; i < import_list.size(); i++)
      {
        import_list.at(i) = satisfy_import_scope(import_list.at(i));

        child_import_list.push_back(spawn_if_doesnt_exist(import_list.at(i)));
      }

      write_to_master_file(child_import_list);
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
