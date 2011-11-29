#include "launcher.h"

Launcher::Launcher()
{
}

Launcher::~Launcher()
{
}

void add_strtoarray(char ***str_array, int *num_elements, const char *my_string)
{
	(*num_elements)++;
	*str_array = (char **) realloc(*str_array, (*num_elements)*sizeof(char *));
	(*str_array)[(*num_elements) - 1] = strdup(my_string);
}

void Launcher::launch(int argc, string argv[], Options options)
{
    #ifdef __WINDOWS

		std::string exeFile = argv[0];

		for (int i = 1; i < argc; i++)
		{
			exeFile += ".exe " + argv[i];
		}

		system(exeFile.c_str());

	#endif


    #ifdef __LINUX

		std::string binFile = argv[0];


		int argvSize = 0;
		for (int i = 1; i < argc; i++)
		{
			argvSize += 1 + argv[i].length();
		}


		const char *name = argv[0].c_str();
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
            cout << "fork error";
         else if (pid == 0) {
            execv(args[0], args);
            cout << "Return not expected. Must be an execv error.";
         }
         else
         {
            int status;
            while(wait(&status) > 0);
         }

     #endif
}
