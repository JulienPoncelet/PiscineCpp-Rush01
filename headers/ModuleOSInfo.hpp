#ifndef MODULEOSINFO_HPP
# define MODULEOSINFO_HPP

# include <ft_gkrellm.hpp>

class ModuleOSInfo : public AModuleSimple {

public:

	ModuleOSInfo(void);
	ModuleOSInfo(ModuleOSInfo const & src);
	virtual ~ModuleOSInfo(void);

	ModuleOSInfo			& operator=(ModuleOSInfo const & src);

	std::string				toString(void) const;

	void					fillContent(void);

};

std::ostream				& operator<<(std::ostream & out, ModuleOSInfo const & src);


#endif
