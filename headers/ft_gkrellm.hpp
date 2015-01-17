#ifndef FT_GKRELLM_HPP
# define FT_GKRELLM_HPP

# include <iostream>
# include <sstream>
# include <vector>
# include <list>
# include <map>
# include <cstdlib>
# include <unistd.h>
# include <ncurses.h>
# include <algorithm>

typedef std::list< std::string > StringList;

enum displayType_e{
	SIMPLE = 1, POURCENTAGE, GRAPHICAL
};

class IMonitorModule;
class AModuleSimple;
class ModuleHostname;
class ModuleOSInfo;
class ModuleTime;
class ModuleCPU;
class ModuleRAM;

# include <IMonitorModule.hpp>
# include <AModuleSimple.hpp>
# include <ModuleHostname.hpp>
# include <ModuleOSInfo.hpp>
# include <ModuleTime.hpp>
# include <ModuleCPU.hpp>
# include <ModuleRAM.hpp>

class Position;
class NWindow;
class IMonitorDisplay;
class NcursesDisplay;

# include <Position.hpp>
# include <NWindow.hpp>
# include <IMonitorDisplay.hpp>
# include <NcursesDisplay.hpp>

#endif