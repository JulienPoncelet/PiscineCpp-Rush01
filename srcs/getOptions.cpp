/*

-n ncurse default
-g GTK

-a all modules default

-h hostname
-o osinfo
-t time
-i CPU Info
-u CPU usage
-r RAM 

-h help

*/

#include <ft_gkrellm.hpp>

Options							getOptions(int ac, char **av) {
	Options 					options;

	options['c'] = true;  // ncurse (default)
	options['g'] = false; // GTK
	options['a'] = true;  // all modules
	options['k'] = false; // Hostname Module
	options['o'] = false; // OS Info Module
	options['t'] = false; // Time Module
	options['i'] = false; // CPU Info Module
	options['u'] = false; // CPU Usage Moduel
	options['r'] = false; // RAM Module
	options['n'] = false; // Network Module
	options['h'] = false; // Help

	std::string			str;

	for (int i = 0; i < ac; i++) {
		str = av[i];
		if (str[0] == '-' and str.size() == 2)
			options[str[1]] = true;
	}

	return options;
}

void							printHelp(void) {
	std::cout << "Diplay options: " << std::endl;
	std::cout << "\t -c: Diplay the modules with ncurse (default)" << std::endl;
	std::cout << "\t -g: Diplay the modules with GTK" << std::endl << std::endl;
	std::cout << "Modules options: " << std::endl;
	std::cout << "\t -a: Add all the modules (default)" << std::endl;
	std::cout << "\t -k: Add the Hostname Module" << std::endl;
	std::cout << "\t -o: Add the OS Info Module" << std::endl;
	std::cout << "\t -t: Add the Time Module" << std::endl;
	std::cout << "\t -i: Add the CPU Info Module" << std::endl;
	std::cout << "\t -u: Add the CPU Usage Module" << std::endl;
	std::cout << "\t -r: Add the RAM Module" << std::endl << std::endl;
	std::cout << "\t -n: Add the Network Module" << std::endl << std::endl;
	std::cout << "Others: " << std::endl;
	std::cout << "\t-h: Display this help" << std::endl;

	return ;
}

ModuleList						fillModules(Options options) {
	ModuleList					modules;

	IMonitorModule				* module0 = new ModuleHostname();
	IMonitorModule				* module1 = new ModuleOSInfo();
	IMonitorModule				* module2 = new ModuleTime();
	IMonitorModule				* module3 = new ModuleCPUInfo();
	ModuleCPUUsage				* module4 = new ModuleCPUUsage();
	IMonitorModule				* module5 = new ModuleRAM();	
	IMonitorModule				* module6 = new ModuleNetwork();	

	if (options['k'])
		modules.push_back(module0);
	if (options['o'])
		modules.push_back(module1);
	if (options['t'])
		modules.push_back(module2);
	if (options['i'])
		modules.push_back(module3);
	if (options['u'])
		modules.push_back(module4);
	if (options['r'])
		modules.push_back(module5);
	if (options['n'])
		modules.push_back(module6);	

	if (modules.size() == 0) {
		modules.push_back(module0);
		modules.push_back(module1);
		modules.push_back(module2);
		modules.push_back(module3);
		modules.push_back(module4);
		modules.push_back(module5);
		modules.push_back(module6);
	}

	return modules;
}
