#include <ft_gkrellm.hpp>

AModuleSimple::AModuleSimple(void) {
	setTitle("Module Simple");
	setType(SIMPLE);
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
	setHeight(rhs.getHeight());
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
	out << "\tHeight: " << getHeight() << std::endl;
	out << "\033[0m";
	return out.str();
}

void						AModuleSimple::fillHeight(StringList const & content) {
	setHeight(content.size());
	return ;
}


std::string const			& AModuleSimple::getTitle(void) const {
	return _title;
}

displayType_e const			& AModuleSimple::getType(void) const {
	return _type;
}

StringList const			& AModuleSimple::getContent(void) const {
	return _content;
}

int const					& AModuleSimple::getHeight(void) const {
	return _height;
}

void						AModuleSimple::setTitle(std::string title) {
	_title = title;
	return ;
}

void						AModuleSimple::setType(displayType_e type) {
	_type = type;
	return ;
}

void						AModuleSimple::setContent(StringList content) {
	_content = content;
	return ;
}

void						AModuleSimple::setHeight(int height) {
	_height = height;
	return ;
}
