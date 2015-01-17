#include <ft_gkrellm.hpp>

int						main(void) {
	ModuleHostname		* module0 = new ModuleHostname();

	std::cout << *module0 << std::endl;

	delete module0;

	return 0;
}
