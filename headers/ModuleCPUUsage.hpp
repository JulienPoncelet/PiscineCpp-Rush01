#ifndef MODULECPUUSAGE_HPP
# define MODULECPUUSAGE_HPP

# include <ft_gkrellm.hpp>

class ModuleCPUUsage : public AModuleGraph {

public:

	ModuleCPUUsage(void);
	ModuleCPUUsage(ModuleCPUUsage const & src);
	virtual ~ModuleCPUUsage(void);

	ModuleCPUUsage			& operator=(ModuleCPUUsage const & src);

	std::string				toString(void) const;

	void					fillContent(void);
	void					fillGraph(StringList content);

};

std::ostream				& operator<<(std::ostream & out, ModuleCPUUsage const & src);


#endif
