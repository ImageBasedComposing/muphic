#include "launcher.h"

Launcher::Launcher()
{
}

Launcher::~Launcher()
{
}

void Launcher::add_strtoarray(char ***str_array, int *num_elements, const char *my_string)
{
	(*num_elements)++;
	*str_array = (char **) realloc(*str_array, (*num_elements)*sizeof(char *));
	(*str_array)[(*num_elements) - 1] = strdup(my_string);
}


std::string Launcher::parseConfFile(std::string file, Program pname)
{
    std::ifstream f(file.c_str(), std::ios::in);

	std::string tmpstring;
	std::string tmpPath = "";
	int i;
	int j;

	// read lines in file until we find de path
	if (f.is_open())
	{

		// skip first three line-comments &
		// skip lines until we reach the one we want (pname)
		j = 0;
		while (f.good() && (j < pname + 3))
		{
			std::getline(f, tmpstring);
			j++;
		}

		if (j < pname + 3)
		{
			std::cout << "Error reading " << file;
			f.close();
			return tmpPath;
		}

		// reading desired line
		if (f.good())
		{
			// take away everything but the path
			std::getline(f, tmpstring);
			i = tmpstring.find_first_of('=');


            #ifdef __WINDOWS
                tmpPath = tmpstring.substr(i + 1, tmpstring.size());
            #endif

            #ifdef __LINUX
                // second parameter means length of the substring here, AND we take care of the \r at the end
                tmpPath = tmpstring.substr(i + 1, tmpstring.size() - (i+2));
            #endif



			f.close();
			return tmpPath;
		}
	}
	else
	{
		std::cout << "Error reading " << file;
		return tmpPath;
	}
}

void Launcher::launch(int argc, std::string argv[], Options options)
{
    #ifdef __WINDOWS

		std::string exeFile = argv[0];

		for (int i = 1; i < argc; i++)
		{
                    exeFile += " \"" + argv[i] + "\"";
		}

		system(exeFile.c_str());

	#endif


    #ifdef __LINUX

		int argvSize = 0;
		for (int i = 1; i < argc; i++)
		{
			argvSize += 1 + argv[i].length();
		}

		char **args = NULL;
		int n = 0;

        // crear lista de parámetros
		for (int i = 0; i < argc; i++)
		{
			add_strtoarray(&args,&n,argv[i].c_str());
			/*n++;
            args = (char **) realloc(args,n*sizeof(char *));
            args[n - 1] = strdup(argv[i].c_str());*/
		}

        // añadir 0 al final, importante
		n++;
        args = (char **) realloc(args,n*sizeof(char *));
        args[n - 1] = (char*) 0;


        pid_t pid;

        if ((pid = fork()) ==-1)
            std::cout << "fork error";
         else if (pid == 0) {
            execv(args[0], args);
            std::cout << "Return not expected. Must be an execv error.";
         }
         else
         {
            int status;
            while(waitpid(pid, &status, 0) > 0);
         }

         free(args);

     #endif
}


int Launcher::launchAndGo(int argc, std::string argv[], Options options)
{
    #ifdef __WINDOWS

	std::vector<wchar_t> exeFile(argv[0].begin(), argv[0].end());

		for (int i = 1; i < argc; i++)
		{
			exeFile.push_back(' ');
			exeFile.push_back('\"');
			exeFile.insert(exeFile.end(), argv[i].begin(), argv[i].end());
			exeFile.push_back('\"');
		}
		exeFile.push_back('\0');

		//system(exeFile.c_str());

		STARTUPINFOW si;
		PROCESS_INFORMATION pi;

		ZeroMemory( &si, sizeof(si) );
		si.cb = sizeof(si);
		ZeroMemory( &pi, sizeof(pi) );

		// Start the child process.
		if( !CreateProcessW( NULL,   // No module name (use command line)
            &(exeFile[0]),        // Command line
            NULL,           // Process handle not inheritable
            NULL,           // Thread handle not inheritable
			FALSE,          // Set handle inheritance to FALSE
			0,              // No creation flags
			NULL,           // Use parent's environment block
			NULL,           // Use parent's starting directory
			&si,            // Pointer to STARTUPINFO structure
			&pi )           // Pointer to PROCESS_INFORMATION structure
		)
		{
                        printf( "Error launching binary file:%d", GetLastError() );
			return -1;
		}


		return (int) pi.hProcess;


		/*
		// Wait until child process exits.
		WaitForSingleObject( pi.hProcess, INFINITE );

		// Close process and thread handles.
		CloseHandle( pi.hProcess );
		CloseHandle( pi.hThread );*/

	#endif


    #ifdef __LINUX


		int argvSize = 0;
		for (int i = 1; i < argc; i++)
		{
			argvSize += 1 + argv[i].length();
		}

		char **args = NULL;
		int n = 0;

        // crear lista de parámetros
		for (int i = 0; i < argc; i++)
		{
			add_strtoarray(&args,&n,argv[i].c_str());
			/*n++;
            args = (char **) realloc(args,n*sizeof(char *));
            args[n - 1] = strdup(argv[i].c_str());*/
		}

        // añadir 0 al final, importante
		n++;
        args = (char **) realloc(args,n*sizeof(char *));
        args[n - 1] = (char*) 0;


        pid_t pid;

        if ((pid = fork()) ==-1)
            std::cout << "fork error";
         else if (pid == 0) {
            execv(args[0], args);
            std::cout << "Return not expected. Must be an execv error.";
         }
        else
        {
            free(args);
            return pid;
        }

     #endif

        return 0;
}

void Launcher::launch(int argc, Program pname, std::string argv[], Options options)
{
		#ifdef __WINDOWS
			std::string confFile = ".\\conf.win";
		#endif

		#ifdef __LINUX
			std::string confFile = "./conf.lin";
		#endif

		//std::string* argv2 = static_cast<std::string*>(malloc((argc + 1)*sizeof(std::string)));
		std::string * argv2;
		argv2 = new std::string[argc + 1];

		argv2[0] = parseConfFile(confFile, pname);
		for (int i = 0; i < argc; i++)
		{
			argv2[i+1] = argv[i];
		}
		argc++;

		launch(argc, argv2);

		delete [] argv2;
}

int Launcher::launchAndGo(int argc, Program pname, std::string argv[], Options options)
{
	#ifdef __WINDOWS
		std::string confFile = ".\\conf.win";
	#endif

	#ifdef __LINUX
		std::string confFile = "./conf.lin";
	#endif

	//std::string* argv2 = static_cast<std::string*>(malloc((argc + 1)*sizeof(std::string)));
	std::string * argv2 = new std::string[argc + 1];

	argv2[0] = parseConfFile(confFile, pname);
	for (int i = 0; i < argc; i++)
	{
		argv2[i+1] = argv[i];
	}
	argc++;

	int out = launchAndGo(argc, argv2);

	delete [] argv2;

	return out;
}


bool Launcher::killProcess(int pid)
{
	#ifdef __WINDOWS
		bool out = TerminateProcess((HANDLE) pid, 0);

                CloseHandle( (HANDLE) pid );

		// thread handle should DEFINITELY be closed, but
		// this works for now and linux only needs one integer, so yeah
		// sorry :\
		// CloseHandle( pi_hThread );

		return out;
	#endif

        #ifdef __LINUX

                if (pid > 0)
                        kill(pid, SIGKILL);

	#endif

	return true;
}
