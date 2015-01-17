#ifndef MODULEHOSTNAME_HPP
# define MODULEHOSTNAME_HPP

# include <ft_gkrellm.hpp>

class ModuleHostname : public IMonitorModule {

public:

	ModuleHostname(void);
	ModuleHostname(ModuleHostname const & src);
	virtual ~ModuleHostname(void);

	ModuleHostname			& operator=(ModuleHostname const & src);

	std::string				toString(void) const;

	std::string const		& getTitle(void) const;
	displayType_e const		& getType(void) const;

	void					setTitle(std::string title);
	void					setType(displayType_e type);

};

std::ostream				& operator<<(std::ostream & out, ModuleHostname const & src);


#endif
