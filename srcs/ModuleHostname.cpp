#include <ft_gkrellm.hpp>

ModuleHostname::ModuleHostname(void) {
	setTitle("Hostname");
	setType(SIMPLE);
	return ;
}

ModuleHostname::ModuleHostname(ModuleHostname const & src) {
	*this = src;
	return ;
}

ModuleHostname::~ModuleHostname(void) {
	return ;
}

ModuleHostname 				& ModuleHostname::operator=(ModuleHostname const & rhs) {
	setTitle(rhs.getTitle());
	setType(rhs.getType());
	return *this;
}

std::ostream 				& operator<<(std::ostream & out, ModuleHostname const & rhs){
	out << rhs.toString();
	return out;
}

std::string 				ModuleHostname::toString(void) const {
	std::ostringstream 		out;

	out << "\033[36m";
	out << "ModuleHostname:" << std::endl;
	out << "\tTitle: " << getTitle() << std::endl;
	out << "\tType: " << getType() << std::endl;
	out << "\033[0m";
	return out.str();
}

std::string const			& ModuleHostname::getTitle(void) const {
	return _title;
}

displayType_e const			& ModuleHostname::getType(void) const {
	return _type;
}

void						ModuleHostname::setTitle(std::string title) {
	_title = title;
	return ;
}

void						ModuleHostname::setType(displayType_e type) {
	_type = type;
	return ;
}
