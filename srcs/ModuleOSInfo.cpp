#include <ft_gkrellm.hpp>

ModuleOSInfo::ModuleOSInfo(void) : AModuleSimple() {
	setTitle("OS Info");
	setType(SIMPLE);
	fillContent();
	fillHeight(getContent());
	return ;
}

ModuleOSInfo::ModuleOSInfo(ModuleOSInfo const & src) : AModuleSimple(src) {
	*this = src;
	return ;
}

ModuleOSInfo::~ModuleOSInfo(void) {
	return ;
}

ModuleOSInfo 				& ModuleOSInfo::operator=(ModuleOSInfo const & rhs) {
	setTitle(rhs.getTitle());
	setType(rhs.getType());
	setContent(rhs.getContent());
	return *this;
}

std::ostream 				& operator<<(std::ostream & out, ModuleOSInfo const & rhs){
	out << rhs.toString();
	return out;
}

std::string 				ModuleOSInfo::toString(void) const {
	std::ostringstream 		out;

	out << "\033[36m";
	out << "ModuleOSInfo:" << std::endl;
	out << "\tTitle: " << getTitle() << std::endl;
	out << "\tType: " << getType() << std::endl;
	out << "\tHeight: " << getHeight() << std::endl;
	out << "\033[0m";
	return out.str();
}

void						ModuleOSInfo::fillContent(void) {
    StringList				content;

    #ifdef _WIN32
    	content.push_back("Windows 32-bit");
    #elif _WIN64
    	content.push_back("Windows 64-bit");
    #elif __unix || __unix__
    	content.push_back("Unix");
    #elif __APPLE__ || __MACH__
    	content.push_back("Mac OSX");
    #elif __linux__
    	content.push_back("Linux");
    #elif __FreeBSD__
    	content.push_back("FreeBSD");
    #else
    	content.push_back("Other");
    #endif

    setContent(content);

	return ;
}
