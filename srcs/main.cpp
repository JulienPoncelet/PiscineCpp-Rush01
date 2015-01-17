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
	display->displayText(Position(10, 10), "Hello world!", 3);
	display->displayUnit(Position(30, 12), "123", "%%", 2);
	getch();
	display->restore();
	delete module0;
	delete display;
	delete module1;
	delete module2;
	return 0;
}
