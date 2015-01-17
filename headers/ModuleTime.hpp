#ifndef MODULETIME_HPP
# define MODULETIME_HPP

# include <ft_gkrellm.hpp>

class ModuleTime : public AModuleSimple {

public:

	ModuleTime(void);
	ModuleTime(ModuleTime const & src);
	virtual ~ModuleTime(void);

	ModuleTime				& operator=(ModuleTime const & src);

	std::string				toString(void) const;

	void					fillContent(void);

};

std::ostream				& operator<<(std::ostream & out, ModuleTime const & src);


#endif
