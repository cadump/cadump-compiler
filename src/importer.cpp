#include "importer.hpp"

Importer::Importer(std::fstream* entry_file)
{
  master_file.path = "./temp/temp" + std::to_string(rand());
  master_file.rw = new std::fstream(master_file.path, std::fstream::in | std::fstream::out);

  this->entry_file = entry_file;
}

std::fstream* Importer::import()
{

  while(entry_file->eof())
  {
    std::vector<std::string>* this_import = parse_imports(find_next_import_command());
    for(uint i = 0; i < this_import->size(); i++)
    {
      this_import->at(i) = satisfy_import_scope(this_import->at(i),'l');
    }
  }

  master_file.rw->close();
  master_file.r  = new std::fstream(master_file.path, std::fstream::in);
  return master_file.r;
}

Importer::~Importer()
{
  master_file.rw->close();
  master_file.r->close();
  delete[] &master_file.path;
}
