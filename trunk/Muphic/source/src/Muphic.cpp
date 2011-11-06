#include "Muphic.h"

#ifdef __LINUX
    #include <unistd.h>
    #include <sys/wait.h>
#endif

Muphic::Muphic()
{
    //ctor
}

Muphic::~Muphic()
{
    //dtor
}

void showUsage()
{
	cout << "Muphic.exe userConfPath imagePath" << endl;
}

int main( int argc, const char* argv[] )
{
    /* Toma de parámetros de entrada */

	if (argc < 3)
	{
		cout << "Too few arguments in function call" << endl;
		showUsage();
		cin.get();
		cin.ignore(cin.rdbuf()->in_avail());

		return 1;
	}

    std::string usrConfPath = argv[1];
    std::string picPath = argv[2];

	std::string executionPath = getPath(argv[0]);

    std::string phicExe = executionPath + "Phic";
    std::string muExe = executionPath + "Mu";

    /* Ejecutar phic */

        cout << "Image analysis beginning" << endl << endl;

        #ifdef __WINDOWS

            std::string picExeFile = phicExe + " " + usrConfPath + " " + picPath;
            system(picExeFile.c_str());

        #endif


        #ifdef __LINUX

            char *const phicParams[] = {const_cast<char*>(phicExe.c_str()), const_cast<char*>(usrConfPath.c_str()), const_cast<char*>(picPath.c_str()), NULL};

            pid_t pid;

            if ((pid = fork()) ==-1)
            {
                cout << "fork error";
                return 2;
            }
             else if (pid == 0) {
                execv(phicParams[0], phicParams);
                cout << phicParams[0] << " " << phicParams[1] << " " << phicParams[2];
                cout << "Return not expected. Must be an execv error.";
                return 3;
            }
             else
            {
                int status;
                while(wait(&status) > 0);
            }

        #endif


        cout << endl << "Image analysis completed" << endl;
        cin.get();
        cin.ignore(cin.rdbuf()->in_avail());

    /* Ejecutar mu*/

        cout << "Image-based composing beginning" << endl << endl;

        std::string analyzedPicPath = changeExtension(picPath, "");

        #ifdef __WINDOWS

            std::string muExeFile = muExe + " " + usrConfPath + " " + analyzedPicPath;
            system(muExeFile.c_str());

        #endif

        #ifdef __LINUX

            char *const muParams[] = {const_cast<char*>(muExe.c_str()), const_cast<char*>(usrConfPath.c_str()), const_cast<char*>(analyzedPicPath.c_str()), NULL};

            pid;

            if ((pid = fork()) ==-1)
            {
                cout << "fork error";
                return 2;
            }
             else if (pid == 0) {
                execv(muParams[0], muParams);
                cout << muParams[0] << " " << muParams[1] << " " << muParams[2];
                cout << "Return not expected. Must be an execv error.";
            }
             else
            {
                int status;
                while(wait(&status) > 0);
                return 3;
            }

        #endif


        cout << endl << "Image-based composing completed" << endl;
        cin.get();
        cin.ignore(cin.rdbuf()->in_avail());

	return 0;
}
