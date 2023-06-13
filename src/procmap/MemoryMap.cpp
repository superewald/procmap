#include "procmap/MemoryMap.hpp"
#include <string>
#include <fstream>

namespace procmap {

MemoryMap::MemoryMap() {
  std::string line;

  // open maps file
  std::ifstream maps("/proc/self/maps");
  if(!maps.is_open())
    throw std::exception("Error opening maps file");

  // parse the maps file
  while (std::getline(maps, line)) {
    emplace_back(line);
  }

  // cleanup
  maps.close();
}

}  // namespace procmap
