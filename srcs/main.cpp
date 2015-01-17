#include <ft_gkrellm.hpp>

int						main(void) {
	ModuleHostname		* module0 = new ModuleHostname();
	NcursesDisplay		*display = new NcursesDisplay();

	std::cout << *module0 << std::endl;

	delete module0;
	delete display;

	return 0;
}
