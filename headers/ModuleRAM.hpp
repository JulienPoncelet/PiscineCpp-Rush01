#ifndef MODULERAM_HPP
# define MODULERAM_HPP

# include <ft_gkrellm.hpp>

class ModuleRAM : public AModuleSimple {

public:

	ModuleRAM(void);
	ModuleRAM(ModuleRAM const & src);
	virtual ~ModuleRAM(void);

	ModuleRAM				& operator=(ModuleRAM const & src);

	std::string				toString(void) const;

	void					fillContent(void);

};

std::ostream				& operator<<(std::ostream & out, ModuleRAM const & src);


#endif
