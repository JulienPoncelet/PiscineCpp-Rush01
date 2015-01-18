#include <ft_gkrellm.hpp>

ModuleTime::ModuleTime(void) : AModuleSimple() {
	setTitle("Time");
	setType(SIMPLE);
	fillContent();
	fillHeight(getContent());
	return ;
}

ModuleTime::ModuleTime(ModuleTime const & src) : AModuleSimple(src) {
	*this = src;
	return ;
}

ModuleTime::~ModuleTime(void) {
	return ;
}

ModuleTime 				& ModuleTime::operator=(ModuleTime const & rhs) {
	setTitle(rhs.getTitle());
	setType(rhs.getType());
	setContent(rhs.getContent());
	return *this;
}

std::ostream 				& operator<<(std::ostream & out, ModuleTime const & rhs){
	out << rhs.toString();
	return out;
}

std::string 				ModuleTime::toString(void) const {
	std::ostringstream 		out;

	out << "\033[36m";
	out << "ModuleTime:" << std::endl;
	out << "\tTitle: " << getTitle() << std::endl;
	out << "\tType: " << getType() << std::endl;
	out << "\tHeight: " << getHeight() << std::endl;
	out << "\033[0m";
	return out.str();
}

void						ModuleTime::fillContent(void) {
    time_t					t = time(0);
    struct tm 				* now = localtime(& t);
    std::stringstream		sstr;

	if (now->tm_hour < 10)
	    sstr << "0" << now->tm_hour << ":";
	else
	    sstr << now->tm_hour << ":";
	if (now->tm_min < 10)
	    sstr << "0" << now->tm_min << ":";
	else
	    sstr << now->tm_min << ":";
	if (now->tm_sec < 10)
    	sstr << "0" << now->tm_sec;
	else
	    sstr << now->tm_sec;

    StringList				content;

    content.push_back(sstr.str());

    setContent(content);
    return ;
}
