#ifndef _SRC_INDEX_HPP_
#define _SRC_INDEX_HPP_

#include "FileSystem.hpp"
#include <map>

namespace Sit {

/**
 * Index maps a file to its hash.
 * Index contains all the paths that will be committed
 */
namespace Index {
    

///**
// * The index map. Should not be accessed outside of Index.cc
// */
//extern std::map<boost::filesystem::path, std::string> _index;
//
// Maybe we can try not to maintain the `index` variable,
// instead,  `Read()` whenever needed and then `Save()`


/**
 * Check whether the `path` in the index or not
 */
bool InIndex(const boost::filesystem::path& path);


/**
 * Load the index from `.sit/index`
 */
void Load();


/**
 * Save the index to `.sit/index`
 */
void Save();


/**
 * Remove `path` from the index and its object file
 */
unsigned Remove(const boost::filesystem::path &path);


/**
 * Insert `file` and the sha1 of `content` to the index,
 * and write `content` to the object file
 */
void Insert(const boost::filesystem::path & file, const std::string & content);

/**
 * Index type
 */
typedef std::map<boost::filesystem::path, std::string> Index;

/**
 * Return the whole index
 */
Index GetIndex();
}
}
#endif