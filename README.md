# forensictool-plugin-skype
A Skype plug-in for forensictool. Just run the application. The program resides in the source directory.

Requirements: Qt5

## Build plugin for forensictool:
	
	$ ./build_lib.sh

## Build single app:

	$ ./build_app.sh
	
### run single app:

	$ ./bin/forensictool-skype 

	Task is search logs of Skype for WINDOWS

	  Usage: ./bin/forensictool-skype [OPTIONS] 

	  OPTIONS:

		-i <fullpath>      - Input folder, required parameter
		-o <fullpath>      - Output folder, required parameter
		-h/--help          - this help
	  
	  Version: 0.3.0
	  Author: Igor Polyakov

	$ ./bin/forensictool-skype -i ../forensictool-testdata/Windows7_Ult/ -o ../output 

	===============TaskSkype================


	Debug mode ON

	InputFolder:  "../forensictool-testdata/Windows7_Ult/" 


	 :: ../forensictool-testdata/Windows7_Ult/Users/UserVlad/AppData/Roaming/Skype/fox.user.3/main.dbConnected!
