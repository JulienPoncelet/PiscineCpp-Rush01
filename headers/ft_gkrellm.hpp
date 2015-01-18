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
# include <time.h>
# include <algorithm>
# include <iomanip>

enum displayType_e{
	SIMPLE = 1, GRAPH
};

class IMonitorModule;
class AModuleSimple;
class AModuleGraph;
class ModuleHostname;
class ModuleOSInfo;
class ModuleTime;
class ModuleCPUInfo;
class ModuleCPUUsage;
class ModuleRAM;
class ModuleNetwork;

typedef std::list< std::string > StringList;
typedef std::list< int > IntList;
typedef std::list< IntList > GraphList;
typedef std::map< char, bool > Options;
typedef std::list< IMonitorModule * > ModuleList;

# include <IMonitorModule.hpp>
# include <AModuleSimple.hpp>
# include <AModuleGraph.hpp>
# include <ModuleHostname.hpp>
# include <ModuleOSInfo.hpp>
# include <ModuleTime.hpp>
# include <ModuleCPUInfo.hpp>
# include <ModuleCPUUsage.hpp>
# include <ModuleRAM.hpp>
# include <ModuleNetwork.hpp>

class Position;
class NWindow;
class IMonitorDisplay;
class NcursesDisplay;

# include <Position.hpp>
# include <NWindow.hpp>
# include <IMonitorDisplay.hpp>
# include <NcursesDisplay.hpp>

Options				getOptions(int ac, char **av);
void				printHelp(void);
ModuleList			fillModules(Options options);

#endif
