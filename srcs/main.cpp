#include <ft_gkrellm.hpp>

int						main(void) {
	NcursesDisplay		*display = new NcursesDisplay();
	ModuleHostname		* module0 = new ModuleHostname();
	ModuleOSInfo		* module1 = new ModuleOSInfo();
	ModuleTime			* module2 = new ModuleTime();
	ModuleTime			* module3 = new ModuleTime();
	ModuleTime			* module4 = new ModuleTime();
	ModuleTime			* module5 = new ModuleTime();
	ModuleTime			* module6 = new ModuleTime();

	std::list<IMonitorModule*> lst;

	display->init();
	lst.push_back(module0);
	lst.push_back(module1);
	lst.push_back(module2);
	lst.push_back(module3);
	lst.push_back(module4);
	lst.push_back(module5);
	lst.push_back(module6);
	display->initWindows(lst);
	getch();
	display->restore();
	delete module0;
	delete display;
	delete module1;
	delete module2;
	return 0;
}
