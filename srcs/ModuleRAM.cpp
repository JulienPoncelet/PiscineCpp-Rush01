#include <ft_gkrellm.hpp>

ModuleRAM::ModuleRAM(void) : AModuleSimple() {
	setTitle("RAM");
	setType(SIMPLE);
	fillContent();
	fillHeight(getContent());
	return ;
}

ModuleRAM::ModuleRAM(ModuleRAM const & src) : AModuleSimple(src) {
	*this = src;
	return ;
}

ModuleRAM::~ModuleRAM(void) {
	return ;
}

ModuleRAM 						& ModuleRAM::operator=(ModuleRAM const & rhs) {
	setTitle(rhs.getTitle());
	setType(rhs.getType());
	setContent(rhs.getContent());
	return *this;
}

std::ostream 					& operator<<(std::ostream & out, ModuleRAM const & rhs){
	out << rhs.toString();
	return out;
}

std::string 					ModuleRAM::toString(void) const {
	std::ostringstream 			out;

	out << "\033[36m";
	out << "ModuleRAM:" << std::endl;
	out << "\tTitle: " << getTitle() << std::endl;
	out << "\tType: " << getType() << std::endl;
	out << "\tHeight: " << getHeight() << std::endl;
	out << "\033[0m";
	return out.str();
}

void							ModuleRAM::fillContent(void) {
    FILE 						*in;
    char						buffer[512];
    std::stringstream			sstr;

    if(not (in = popen("top -l 1 | head -n 10 | grep PhysMem", "r")))
        return ;

    while(fgets(buffer, sizeof(buffer), in))
        sstr << buffer;

    pclose(in);

    std::string 				str = sstr.str();
    std::string                 used;
    std::string                 wired;
    std::string                 unused;

    str.replace(0, 9, "");
    used = str.substr(0, str.find("used"));
    str.replace(0, used.size() + 6, "");
    wired = str.substr(0, str.find("wired"));
    str.replace(0, wired.size() + 8, "");
    unused = str.substr(0, str.find("unused"));

    StringList      			content;

    str = "RAM Used: ";
    str.append(used);
    content.push_back(str);
    str = "Ram Wired: ";
    str.append(wired);
    content.push_back(str);
    str = "RAM unused: ";
    str.append(unused);
    content.push_back(str);

    setContent(content);

    return ;
}
