#include <ft_gkrellm.hpp>

ModuleCPUInfo::ModuleCPUInfo(void) : AModuleSimple() {
	setTitle("CPU Info");
	setType(SIMPLE);
	fillContent();
	fillHeight(getContent());
	return ;
}

ModuleCPUInfo::ModuleCPUInfo(ModuleCPUInfo const & src) : AModuleSimple(src) {
	*this = src;
	return ;
}

ModuleCPUInfo::~ModuleCPUInfo(void) {
	return ;
}

ModuleCPUInfo 						& ModuleCPUInfo::operator=(ModuleCPUInfo const & rhs) {
	setTitle(rhs.getTitle());
	setType(rhs.getType());
	setContent(rhs.getContent());
	return *this;
}

std::ostream 					& operator<<(std::ostream & out, ModuleCPUInfo const & rhs){
	out << rhs.toString();
	return out;
}

std::string 					ModuleCPUInfo::toString(void) const {
	std::ostringstream 			out;

	out << "\033[36m";
	out << "ModuleCPUInfo:" << std::endl;
	out << "\tTitle: " << getTitle() << std::endl;
	out << "\tType: " << getType() << std::endl;
	out << "\tHeight: " << getHeight() << std::endl;
	out << "\033[0m";
	return out.str();
}

void							ModuleCPUInfo::fillContent(void) {
    FILE 						*in;
    char						buffer[512];
    std::stringstream			sstr;

    if(not (in = popen("system_profiler SPHardwareDataType", "r")))
        return ;

    while(fgets(buffer, sizeof(buffer), in))
        sstr << buffer;

    pclose(in);

    std::string 				str = sstr.str();
    StringList					data;
    std::string 				sub;
    size_t						n;

    while (str.find("\n") != std::string::npos) {
    	n = str.find("\n");
    	sub = str.substr(0, n);
    	data.push_back(sub);
    	str.replace(0, n + 1, "");
    }

    StringList::iterator		it = data.begin();
    StringList::iterator		ite = data.end();

    std::string 				name;
    std::string 				speed;
    std::string 				processorsAmount;
    std::string 				coresAmount;

    for (; it != ite; it++) {
    	str = *it;
    	if (str.find("Processor Name: ") != std::string::npos) {
    		n = str.find(":");
    		name = str.substr(n + 2, str.size());
    	}
    	else if (str.find("Processor Speed: ") != std::string::npos) {
    		n = str.find(":");
    		speed = str.substr(n + 2, str.size());
    	}
    	else if (str.find("Number of Processors: ") != std::string::npos) {
    		n = str.find(":");
    		processorsAmount = str.substr(n + 2, str.size());
    	}
    	else if (str.find("Total Number of Cores:") != std::string::npos) {
    		n = str.find(":");
    		coresAmount = str.substr(n + 2, str.size());
    	}    	
    }

    StringList      			content;

    str = "CPU Model name: ";
    str.append(name);
    content.push_back(str);
    str = "CPU clock speed: ";
    str.append(speed);
    content.push_back(str);
    str = "Amount of processors: ";
    str.append(processorsAmount);
    content.push_back(str);
    str = "Amount of cores: ";
    str.append(coresAmount);
    content.push_back(str);

    setContent(content);

    return ;
}
