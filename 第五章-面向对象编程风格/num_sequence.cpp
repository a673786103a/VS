#include "num_sequence.h"

#include <string>



ostream& operator<< (ostream& os, const num_sequence& ns) {
	return ns.print(os);
}
void display(ostream& os, const num_sequence* ns, int pos) {
	os << "The element at position " << pos << " for the ";
	os << ns->what_am_i();
	os << " sequence is " << ns->elem(pos) << endl;
}