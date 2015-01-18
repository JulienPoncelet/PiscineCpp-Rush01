#include <ft_gkrellm.hpp>

ModuleCPUUsage::ModuleCPUUsage(void) : AModuleGraph() {
	setTitle("CPU Usage");
	setType(GRAPH);
    fillContent();
	fillGraph(getContent());
	fillHeight();
	return ;
}

ModuleCPUUsage::ModuleCPUUsage(ModuleCPUUsage const & src) : AModuleGraph(src) {
	*this = src;
	return ;
}

ModuleCPUUsage::~ModuleCPUUsage(void) {
	return ;
}

ModuleCPUUsage 						& ModuleCPUUsage::operator=(ModuleCPUUsage const & rhs) {
	setTitle(rhs.getTitle());
	setType(rhs.getType());
    setContent(rhs.getContent());
    setGraphs(rhs.getGraphs());
	setHeight(rhs.getHeight());
	return *this;
}

std::ostream 					& operator<<(std::ostream & out, ModuleCPUUsage const & rhs){
	out << rhs.toString();
	return out;
}

std::string 					ModuleCPUUsage::toString(void) const {
	std::ostringstream 			out;

	out << "\033[36m";
	out << "Module CPU Usage:" << std::endl;
	out << "\tTitle: " << getTitle() << std::endl;
	out << "\tType: " << getType() << std::endl;
	out << "\tHeight: " << getHeight() << std::endl;
	out << "\033[0m";
	return out.str();
}

void							ModuleCPUUsage::fillContent(void) {
    FILE                        *in;
    char                        buffer[512];
    std::stringstream           sstr;

    if(not (in = popen("top -l 1 | head -n 10 | grep 'CPU usage'", "r")))
        return ;

    while(fgets(buffer, sizeof(buffer), in))
        sstr << buffer;

    pclose(in);

    std::string                 str = sstr.str();
    std::string                 user;
    std::string                 sys;
    std::string                 idle;

    str.replace(0, 11, "");
    user = str.substr(0, str.find("\%"));
    str.replace(0, user.size() + 8, "");
    sys = str.substr(0, str.find("\%"));
    str.replace(0, sys.size() + 7, "");
    idle = str.substr(0, str.find("\%"));

    StringList                  content;

    str = "User usage: ";
    str.append(user);
    str.append("%%");
    content.push_back(str);
    str = "System usage: ";
    str.append(sys);
    str.append("%%");
    content.push_back(str);
    str = "Available: ";
    str.append(idle);
    str.append("%%");
    content.push_back(str);

    setContent(content);

    return ;
}

void                            ModuleCPUUsage::fillGraph(StringList content) {
    GraphList                   graphs = getGraphs();

    if (graphs.size() == 0) {
        IntList                 user;
        IntList                 sys;
        graphs.push_back(user);
        graphs.push_back(sys);
    }

    GraphList::iterator         graphIterator = graphs.begin();
    IntList                     userGraph = *graphIterator;
    StringList::iterator        stringIterator = content.begin();
    std::string 				userString = *stringIterator;
    std::string 				sub;
 	int 						n;

    userString.replace(0, 12, "");
    sub = userString.substr(0, userString.find("\%"));
	n = (strtol(sub.c_str(),0,10) / 10) + 1;

	if (userGraph.size() >= 70)
		userGraph.pop_back();
	userGraph.push_front(n);

	graphs.push_back(userGraph);
    
    ++graphIterator;
    IntList                     sysGraph = *graphIterator;
    stringIterator = ++content.begin();
    std::string 				sysString = *stringIterator;

    sysString.replace(0, 14, "");

    sub = sysString.substr(0, sysString.find("\%"));
	n = (strtol(sub.c_str(),0,10) / 10) + 1;

	if (sysGraph.size() >= 70)
		sysGraph.pop_back();
	sysGraph.push_front(n);

	graphs.push_back(sysGraph);

    graphs.pop_front();
    graphs.pop_front();
    setGraphs(graphs);

    return ;
}









