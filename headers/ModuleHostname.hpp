#ifndef MODULEHOSTNAME_HPP
# define MODULEHOSTNAME_HPP

# include <ft_gkrellm.hpp>

class ModuleHostname : public AModuleSimple {

public:

	ModuleHostname(void);
	ModuleHostname(ModuleHostname const & src);
	virtual ~ModuleHostname(void);

	ModuleHostname			& operator=(ModuleHostname const & src);

	std::string				toString(void) const;

	void					fillContent(void);

};

std::ostream				& operator<<(std::ostream & out, ModuleHostname const & src);


#endif
