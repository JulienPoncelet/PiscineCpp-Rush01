#include <ft_gkrellm.hpp>

std::ostream 				& operator<<(std::ostream & out, IMonitorModule const & rhs){
	out << rhs.toString();
	return out;
}

int						main(void) {
	IMonitorModule					* module0 = new ModuleHostname();
	IMonitorModule					* module1 = new ModuleOSInfo();
	IMonitorModule					* module2 = new ModuleTime();
	IMonitorModule					* module3 = new ModuleCPU();

	std::list< IMonitorModule * >	moduleList;

	moduleList.push_back(module0);
	moduleList.push_back(module1);
	moduleList.push_back(module2);
	moduleList.push_back(module3);

	std::cout << *module0 << std::endl;
	std::cout << *module1 << std::endl;
	std::cout << *module2 << std::endl;
	std::cout << *module3 << std::endl;

	// NcursesDisplay		*display = new NcursesDisplay();

	// display->init();
	// display->displayText(Position(10, 10), "Hello world!");
	// getch();
	// display->restore();

	// delete display;

	delete module2;
	delete module1;
	delete module0;

	return 0;

}

