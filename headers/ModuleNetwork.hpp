#ifndef MODULENETWORK_HPP
# define MODULENETWORK_HPP

# include <ft_gkrellm.hpp>

class ModuleNetwork : public AModuleSimple {

public:

	ModuleNetwork(void);
	ModuleNetwork(ModuleNetwork const & src);
	virtual ~ModuleNetwork(void);

	ModuleNetwork			& operator=(ModuleNetwork const & src);

	std::string				toString(void) const;

	void					fillContent(void);

};

std::ostream				& operator<<(std::ostream & out, ModuleNetwork const & src);


#endif
