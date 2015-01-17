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
	out << "\tContent: " << getContent() << std::endl;
	out << "\tHeight: " << getHeight() << std::endl;
	out << "\033[0m";
	return out.str();
}

void						ModuleOSInfo::fillContent(void) {
    #ifdef _WIN32
    	setContent("Windows 32-bit");
    #elif _WIN64
    	setContent("Windows 64-bit");
    #elif __unix || __unix__
    	setContent("Unix");
    #elif __APPLE__ || __MACH__
    	setContent("Mac OSX");
    #elif __linux__
    	setContent("Linux");
    #elif __FreeBSD__
    	setContent("FreeBSD");
    #else
    	setContent("Other");
    #endif
	return ;
}
