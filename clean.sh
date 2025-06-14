#!/bin/bash

echo "Directories:"

list_exec() {
	for file in *;
  	do
 			if file -b mach-o "$file" | grep -q "Mach-O 64-bit object arm64";
		    then 
				echo "$file is mach-o object file and needs to be yeeted" 
				rm $file 
			fi 
			if file -b mach-o "$file" | grep -q "Mach-O 64-bit executable arm64";
	  		then echo "$file is mach-o executable file and needs to be yeeted" rm $file
			fi
		done
}

expand() {
        list_exec
	for directory in *;do
		if [[ -d "$directory" && "$directory" != "build" ]];
			then 
				echo "Files: in $directory"
				list_exec
				cd "$directory" echo "going into $directory" 
				expand 
				cd ..
		fi
	done
}
expand