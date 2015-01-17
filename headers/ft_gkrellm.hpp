#ifndef FT_GKRELLM_HPP
# define FT_GKRELLM_HPP

# include <iostream>
# include <sstream>
# include <vector>
# include <list>
# include <cstdlib>
# include <unistd.h>
# include <ncurses.h>

enum displayType_e{
	SIMPLE = 1, POURCENTAGE, GRAPHICAL
};

class IMonitorModule;
class AModuleSimple;
class ModuleHostname;

# include <IMonitorModule.hpp>
# include <AModuleSimple.hpp>
# include <ModuleHostname.hpp>

class IMonitorDisplay;
class NcursesDisplay;
class Position;

# include <Position.hpp>
# include <IMonitorDisplay.hpp>
# include <NcursesDisplay.hpp>
#endif