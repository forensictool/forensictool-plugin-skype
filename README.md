# coex-plugin-task-skype
A Forensic plug-in for Skype. Just run the application. The program resides in the source directory.

Requirements: Qt5

## Build plugin for coex:
	
	$ ./build_lib.sh

## Build single app:

	$ ./build_app.sh
	
### run single app:

	$ ./bin/coex-skype 

	Task is search logs of Skype for WINDOWS

	  Usage: ./bin/coex-skype [OPTIONS] 

	  OPTIONS:

		-i <fullpath>      - Input folder, required parameter
		-o <fullpath>      - Output folder, required parameter
		-h/--help          - this help
	  
	  Version: 0.1.0
	  Author: Igor Polyakov

	$ ./bin/coex-skype --input-folder ../coex-testdata/Windows7_Ult/ --output-folder ../output 

	===============TaskSkype================


	Debug mode ON

	InputFolder:  "../coex-testdata/Windows7_Ult/" 


	 :: ../coex-testdata/Windows7_Ult//Users/UserVlad/AppData/Roaming/Skype/fox.user.3/main.dbConnected!
