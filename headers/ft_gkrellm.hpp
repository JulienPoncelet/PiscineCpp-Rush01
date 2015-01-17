#ifndef FT_GKRELLM_HPP
# define FT_GKRELLM_HPP

# include <iostream>
# include <sstream>
# include <vector>
# include <list>
# include <unistd.h>

enum displayType_e{
	SIMPLE = 1, POURCENTAGE, GRAPHICAL
};

struct Data {

};

class IMonitorModule;
class AModuleSimple;
class ModuleHostname;

# include <IMonitorModule.hpp>
# include <AModuleSimple.hpp>
# include <ModuleHostname.hpp>

class IMonitorModule;
class NcursesDisplay;

# include <NcursesDisplay.hpp>
# include <IMonitorModule.hpp>
#endif