#ifdef USE_BOOST
#include <boost/algorithm/string/join.hpp>
#else
#include <sstream>
#include <iterator>
#endif
#include <string>
#include <iostream>
#include <vector>

main() {
	std::vector<std::string> elems = { "abcd", "efgh", "ijkl", "lmnop", "qrst" } ;
	std::string delim = ":" ;

#ifdef USE_BOOST
	std::string joinedString = boost::algorithm::join(elems, delim);
	std::cout << joinedString << std::endl ;
#else

	std::ostringstream joinedString;
	copy(elems.begin(),elems.end(),
	           std::ostream_iterator<std::string>(joinedString, delim.c_str()));
	std::cout << joinedString.str() << std::endl ;
#endif
}
