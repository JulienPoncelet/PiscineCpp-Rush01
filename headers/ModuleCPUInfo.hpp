#ifndef MODULECPUINFO_HPP
# define MODULECPUINFO_HPP

# include <ft_gkrellm.hpp>

class ModuleCPUInfo : public AModuleSimple {

public:

	ModuleCPUInfo(void);
	ModuleCPUInfo(ModuleCPUInfo const & src);
	virtual ~ModuleCPUInfo(void);

	ModuleCPUInfo				& operator=(ModuleCPUInfo const & src);

	std::string				toString(void) const;

	void					fillContent(void);

};

std::ostream				& operator<<(std::ostream & out, ModuleCPUInfo const & src);


#endif
