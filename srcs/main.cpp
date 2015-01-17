#include <ft_gkrellm.hpp>

std::ostream 				& operator<<(std::ostream & out, IMonitorModule const & rhs){
	out << rhs.toString();
	return out;
}

int						main(void) {
	NcursesDisplay		*display = new NcursesDisplay();
	ModuleHostname		* module0 = new ModuleHostname();
	ModuleOSInfo		* module1 = new ModuleOSInfo();
	IMonitorModule		* module3 = new ModuleCPU();

	std::list<IMonitorModule*> lst;

	display->init();
	lst.push_back(module0);
	lst.push_back(module1);
	lst.push_back(module2);
	lst.push_back(module3);

	display->initWindows(lst);
	getch();
	display->restore();
	delete display;
	delete module0;
	delete module1;
	delete module2;
	delete module3;

	return 0;
}

