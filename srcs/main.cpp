#include <ft_gkrellm.hpp>

int						main(void) {
	ModuleHostname		* module0 = new ModuleHostname();
	ModuleOSInfo		* module1 = new ModuleOSInfo();
	ModuleTime			* module2 = new ModuleTime();

	std::cout << *module0 << std::endl;
	std::cout << *module1 << std::endl;
	std::cout << *module2 << std::endl;

	delete module0;
	delete module1;
	delete module2;

	return 0;
}
