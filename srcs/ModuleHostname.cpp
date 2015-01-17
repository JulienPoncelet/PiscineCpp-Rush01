#include <ft_gkrellm.hpp>

ModuleHostname::ModuleHostname(void) : AModuleSimple() {
	setTitle("Hostname");
	setType(SIMPLE);
	fillContent();
	fillHeight(getContent());
	return ;
}

ModuleHostname::ModuleHostname(ModuleHostname const & src) : AModuleSimple(src) {
	*this = src;
	return ;
}

ModuleHostname::~ModuleHostname(void) {
	return ;
}

ModuleHostname 				& ModuleHostname::operator=(ModuleHostname const & rhs) {
	setTitle(rhs.getTitle());
	setType(rhs.getType());
	setContent(rhs.getContent());
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
	out << "\tHeight: " << getHeight() << std::endl;
	out << "\033[0m";
	return out.str();
}

void						ModuleHostname::fillContent(void) {
	char					buffer[400];
	StringList				content;

	gethostname(buffer, 400);
	content.push_back(buffer);

	setContent(content);
	return ;
}
