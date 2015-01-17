#include <ft_gkrellm.hpp>

ModuleCPU::ModuleCPU(void) : AModuleSimple() {
	setTitle("CPU");
	setType(SIMPLE);
	fillContent();
	fillHeight(getContent());
	return ;
}

ModuleCPU::ModuleCPU(ModuleCPU const & src) : AModuleSimple(src) {
	*this = src;
	return ;
}

ModuleCPU::~ModuleCPU(void) {
	return ;
}

ModuleCPU 				& ModuleCPU::operator=(ModuleCPU const & rhs) {
	setTitle(rhs.getTitle());
	setType(rhs.getType());
	setContent(rhs.getContent());
	return *this;
}

std::ostream 				& operator<<(std::ostream & out, ModuleCPU const & rhs){
	out << rhs.toString();
	return out;
}

std::string 				ModuleCPU::toString(void) const {
	std::ostringstream 		out;

	out << "\033[36m";
	out << "ModuleCPU:" << std::endl;
	out << "\tTitle: " << getTitle() << std::endl;
	out << "\tType: " << getType() << std::endl;
	out << "\tContent: " << getContent() << std::endl;
	out << "\tHeight: " << getHeight() << std::endl;
	out << "\033[0m";
	return out.str();
}

void						ModuleCPU::fillContent(void) {
    FILE 					*in;
    char					buffer[512];
    std::stringstream		sstr;

    if(not (in = popen("system_profiler SPHardwareDataType", "r")))
        return ;

    while(fgets(buffer, sizeof(buffer), in))
        sstr << buffer;

    pclose(in);

    setContent(sstr.str());

    return ;
}
