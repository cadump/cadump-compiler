#ifndef CADUMP_LIB_NAMEDFSTREAM_H_
#define CADUMP_LIB_NAMEDFSTREAM_H_
#include <fstream>
#include <string>

namespace CadumpLibs
{
  class NamedFstream : public std::fstream
  {
   std::string filename_;

   public:
     NamedFstream(const char* filename, ios_base::openmode mode = ios_base::in | ios_base::out) : std::fstream(filename, mode)
     {
       this->filename_ = std::string(filename);
     }

     std::string getFilename() {return this->filename_;}
  };
}
#endif
