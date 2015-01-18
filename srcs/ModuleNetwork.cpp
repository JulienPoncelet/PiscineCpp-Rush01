#include <ft_gkrellm.hpp>

ModuleNetwork::ModuleNetwork(void) : AModuleSimple() {
	setTitle("Network");
	setType(SIMPLE);
	fillContent();
	fillHeight(getContent());
	return ;
}

ModuleNetwork::ModuleNetwork(ModuleNetwork const & src) : AModuleSimple(src) {
	*this = src;
	return ;
}

ModuleNetwork::~ModuleNetwork(void) {
	return ;
}

ModuleNetwork 						& ModuleNetwork::operator=(ModuleNetwork const & rhs) {
	setTitle(rhs.getTitle());
	setType(rhs.getType());
	setContent(rhs.getContent());
	return *this;
}

std::ostream 					& operator<<(std::ostream & out, ModuleNetwork const & rhs){
	out << rhs.toString();
	return out;
}

std::string 					ModuleNetwork::toString(void) const {
	std::ostringstream 			out;

	out << "\033[36m";
	out << "Module Network:" << std::endl;
	out << "\tTitle: " << getTitle() << std::endl;
	out << "\tType: " << getType() << std::endl;
	out << "\tHeight: " << getHeight() << std::endl;
	out << "\033[0m";
	return out.str();
}

void							ModuleNetwork::fillContent(void) {
    FILE 						*in;
    char						buffer[512];
    std::stringstream			sstr;

    if(not (in = popen("netstat -bi | grep 'loca '", "r")))
        return ;

    while(fgets(buffer, sizeof(buffer), in))
        sstr << buffer;

    pclose(in);

    std::string 				str = sstr.str();
    std::string                 inBytes;
    std::string                 outBytes;

    inBytes = str.substr(0, str.find("-"));
    str.replace(0, inBytes.size() + 2, "");
    inBytes = str.substr(0, str.find(" "));
    str.replace(0, inBytes.size(), "");

    outBytes = str.substr(0, str.find("-"));
    str.replace(0, outBytes.size() + 2, "");
    outBytes = str.substr(0, str.find(" "));    

    StringList      			content;

    str = "Total Incoming Network: ";
    str.append(inBytes);
    str.append(" Bytes");
    content.push_back(str);
    str = "Total Outcoming Network: ";
    str.append(outBytes);
    str.append(" Bytes");
    content.push_back(str);

    setContent(content);

    return ;
}
