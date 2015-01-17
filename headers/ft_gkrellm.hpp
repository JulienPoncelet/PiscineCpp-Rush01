#ifndef FT_GKRELLM_HPP
# define FT_GKRELLM_HPP

# include <iostream>
# include <sstream>
# include <unistd.h>

enum displayType_e{
	SIMPLE = 1, POURCENTAGE, GRAPHICAL
};

class IMonitorModule;
class AModuleSimple;
class ModuleHostname;

# include <IMonitorModule.hpp>
# include <AModuleSimple.hpp>
# include <ModuleHostname.hpp>

#endif