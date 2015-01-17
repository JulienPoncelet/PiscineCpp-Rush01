#ifndef AMODULEGRAPH_HPP
# define AMODULEGRAPH_HPP

# include <ft_gkrellm.hpp>

class AModuleGraph : public IMonitorModule {

public:

	AModuleGraph(void);
	AModuleGraph(AModuleGraph const & src);
	virtual ~AModuleGraph(void);

	AModuleGraph			& operator=(AModuleGraph const & src);

	std::string				toString(void) const;

	virtual void			fillContent(void) = 0;
	virtual void			fillGraph(StringList content) = 0;
	void					fillHeight(void);

	std::string const		& getTitle(void) const;
	displayType_e const		& getType(void) const;
	StringList const		& getContent(void) const;
	GraphList const			& getGraphs(void) const;
	int const				& getHeight(void) const;

	void					setTitle(std::string title);
	void					setType(displayType_e type);
	void					setContent(StringList content);
	void					setGraphs(GraphList graph);
	void					setHeight(int height);

protected:

	StringList 				_content;
	GraphList				_graphs;

};

std::ostream				& operator<<(std::ostream & out, AModuleGraph const & src);

#endif
