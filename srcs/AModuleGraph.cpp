#include <ft_gkrellm.hpp>

AModuleGraph::AModuleGraph(void) {
	setTitle("Module Graph");
	setType(GRAPH);
	return ;
}

AModuleGraph::AModuleGraph(AModuleGraph const & src) {
	*this = src;
	return ;
}

AModuleGraph::~AModuleGraph(void) {
	return ;
}

AModuleGraph 				& AModuleGraph::operator=(AModuleGraph const & rhs) {
	setTitle(rhs.getTitle());
	setType(rhs.getType());
	setContent(rhs.getContent());
	setGraphs(rhs.getGraphs());
	setHeight(rhs.getHeight());
	return *this;
}

std::ostream 				& operator<<(std::ostream & out, AModuleGraph const & rhs){
	out << rhs.toString();
	return out;
}

std::string 				AModuleGraph::toString(void) const {
	std::ostringstream 		out;

	out << "\033[36m";
	out << "Module Graph:" << std::endl;
	out << "\tTitle: " << getTitle() << std::endl;
	out << "\tType: " << getType() << std::endl;
	out << "\tHeight: " << getHeight() << std::endl;
	out << "\033[0m";
	return out.str();
}

void						AModuleGraph::fillHeight(void) {
	int						contentSize = getContent().size();
	int						graphsSize = getGraphs().size();

	setHeight(contentSize + (graphsSize * 10));
	return ;
}

std::string const			& AModuleGraph::getTitle(void) const {
	return _title;
}

displayType_e const			& AModuleGraph::getType(void) const {
	return _type;
}

StringList const			& AModuleGraph::getContent(void) const {
	return _content;
}

GraphList const				& AModuleGraph::getGraphs(void) const {
	return _graphs;
}

int const					& AModuleGraph::getHeight(void) const {
	return _height;
}

void						AModuleGraph::setTitle(std::string title) {
	_title = title;
	return ;
}

void						AModuleGraph::setType(displayType_e type) {
	_type = type;
	return ;
}

void						AModuleGraph::setContent(StringList content) {
	_content = content;
	return ;
}

void						AModuleGraph::setGraphs(GraphList graphs) {
	_graphs = graphs;
	return ;
}

void						AModuleGraph::setHeight(int height) {
	_height = height;
	return ;
}
