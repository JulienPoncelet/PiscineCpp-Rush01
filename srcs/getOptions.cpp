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

Options					getOptions(int ac, char **av) {
	Options 			options;

	options['n'] = true;  // ncurse (default)
	options['g'] = false; // GTK
	options['a'] = true;  // all modules
	options['u'] = false; // Hostname Module
	options['o'] = false; // OS Info Module
	options['t'] = false; // Time Module
	options['i'] = false; // CPU Info Module
	options['u'] = false; // CPU Usage Moduel
	options['r'] = false; // RAM Module
	options['h'] = false; // Help

	std::string			str;

	for (int i = 0; i < ac; i++) {
		str = av[i];
		if (str[0] == "-" and str.size() == 2)
			options[str[1]] = true;
	}

	return options;
}

void					printHelp(void) {
	std::cout << "Diplay options: " << std::endl;
	std::cout << "\t -n: Diplay the modules with ncurse (default)" << std::endl;
	std::cout << "\t -g: Diplay the modules with GTK" << std::endl << std::endl;
	std::cout << "Modules options: " << std::endl;
	std::cout << "\t -a: Add all the modules (default)" << std::endl;
	std::cout << "\t -u: Add the Hostname Module" << std::endl;
	std::cout << "\t -o: Add the Hostname Module" << std::endl;
	std::cout << "\t -t: Add the Hostname Module" << std::endl;
	std::cout << "\t -i: Add the Hostname Module" << std::endl;
	std::cout << "\t -u: Add the Hostname Module" << std::endl;
	std::cout << "\t -r: Add the Hostname Module" << std::endl << std::endl;
	std::cout << "\t -h: Display this help" << std::endl;


	return ;
}