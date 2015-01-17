#include <ft_gkrellm.hpp>

AModuleSimple::AModuleSimple(void) {
	setTitle("Module Simple");
	setType(SIMPLE);
	setContent("Default Content");
	return ;
}

AModuleSimple::AModuleSimple(AModuleSimple const & src) {
	*this = src;
	return ;
}

AModuleSimple::~AModuleSimple(void) {
	return ;
}

AModuleSimple 				& AModuleSimple::operator=(AModuleSimple const & rhs) {
	setTitle(rhs.getTitle());
	setType(rhs.getType());
	setContent(rhs.getContent());
	return *this;
}

std::ostream 				& operator<<(std::ostream & out, AModuleSimple const & rhs){
	out << rhs.toString();
	return out;
}

std::string 				AModuleSimple::toString(void) const {
	std::ostringstream 		out;

	out << "\033[36m";
	out << "Module Simple:" << std::endl;
	out << "\tTitle: " << getTitle() << std::endl;
	out << "\tType: " << getType() << std::endl;
	out << "\tContent: " << getContent() << std::endl;
	out << "\033[0m";
	return out.str();
}

std::string const			& AModuleSimple::getTitle(void) const {
	return _title;
}

displayType_e const			& AModuleSimple::getType(void) const {
	return _type;
}

std::string const			& AModuleSimple::getContent(void) const {
	return _content;
}

void						AModuleSimple::setTitle(std::string title) {
	_title = title;
	return ;
}

void						AModuleSimple::setType(displayType_e type) {
	_type = type;
	return ;
}

void						AModuleSimple::setContent(std::string content) {
	_content = content;
	return ;
}
