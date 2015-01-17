#include <ft_gkrellm.hpp>

int						main(void) {
	ModuleHostname		* module0 = new ModuleHostname();
	NcursesDisplay		*display = new NcursesDisplay();
	ModuleOSInfo		* module1 = new ModuleOSInfo();
	ModuleTime			* module2 = new ModuleTime();

	std::cout << *module0 << std::endl;
	std::cout << *module1 << std::endl;
	std::cout << *module2 << std::endl;

	display->init();
	display->displayWindow(Position(0, 0), "Title", 10, 50, 2);
	display->displayWindow(Position(10, 0), "Other title", 20, 50, 2);
	display->displayWindow(Position(30, 0), "Last title", 10, 50, 2);
	getch();
	display->restore();
	delete module0;
	delete display;
	delete module1;
	delete module2;
	return 0;
}
