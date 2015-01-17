#ifndef MODULECPU_HPP
# define MODULECPU_HPP

# include <ft_gkrellm.hpp>

class ModuleCPU : public AModuleSimple {

public:

	ModuleCPU(void);
	ModuleCPU(ModuleCPU const & src);
	virtual ~ModuleCPU(void);

	ModuleCPU				& operator=(ModuleCPU const & src);

	std::string				toString(void) const;

	void					fillContent(void);

};

std::ostream				& operator<<(std::ostream & out, ModuleCPU const & src);


#endif
