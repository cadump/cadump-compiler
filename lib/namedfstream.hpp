#ifndef CADUMP_LIB_NAMEDFSTREAM_H_
#define CADUMP_LIB_NAMEDFSTREAM_H_
#include <fstream>
#include <sstream>
#include <string>

namespace CadumpLibs
{
  // Extend fstream that holds it's path (why is this not default)
  class NamedFstream : public std::fstream
  {
    // Path in the filesystem
   std::string filename_;

    // extend contructor of fstream with setting the filename
   public:
     NamedFstream(const char* filename, ios_base::openmode mode = ios_base::in | ios_base::out) : std::fstream(filename, mode)
     {
       this->filename_ = std::string(filename);
     }

    // I wonder what this does
    std::string getFilename() {return this->filename_;}

    // Returns a line without moving the pointer
    // TOFO are you stupid or you are, because this won't work
    std::string peekline()
    {
      bool is_before_linebreak = true;
      std::string line = "";
      while ( is_before_linebreak )
	{
	  char read_char = this->peek();
	  if( read_char == '\n' || read_char == '\r')
	    is_before_linebreak = false;
	  else
	    line += read_char;
	}

      return line;
    }
  };
}
#endif
