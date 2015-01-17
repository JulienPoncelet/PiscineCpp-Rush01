#ifndef FT_GKRELLM_HPP
# define FT_GKRELLM_HPP

# include <iostream>
# include <sstream>

enum displayType_e{
	SIMPLE = 1, POURCENTAGE, GRAPHICAL
};

class IMonitorModule;
class IMonitorDisplay;
class ModuleHostname;

# include <IMonitorModule.hpp>
# include <IMonitorDisplay.hpp>
# include <ModuleHostname.hpp>

#endif