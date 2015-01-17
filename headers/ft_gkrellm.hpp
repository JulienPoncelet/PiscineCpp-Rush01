#ifndef FT_GKRELLM_HPP
# define FT_GKRELLM_HPP

# include <iostream>
# include <sstream>
# include <vector>
# include <list>

enum displayType_e{
	SIMPLE = 1, POURCENTAGE, GRAPHICAL
};

struct Data {

};
class IMonitorModule;
class IMonitorDisplay;
class ModuleHostname;

# include <IMonitorModule.hpp>
# include <IMonitorDisplay.hpp>
# include <ModuleHostname.hpp>
# include <NcursesDisplay.hpp>
#endif